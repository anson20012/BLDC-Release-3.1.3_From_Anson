
//=============================================================================
// Copyright (C) 2017, Active-Semi International
//
// THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
// AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
// APPLICATION TO PAC PROCESSORS SUPPLIED BY ACTIVE-SEMI INTERNATIONAL;
// (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
// ACTIVE-SEMICONDUCTOR IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
// DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
// ONLY BY CERTAIN AUTHORIZED PERSONS.
//
//=============================================================================

#include "include.h"

//===================================================================================
/// @brief  This function increase or decrease PWM duty counts
/// @param  None
/// @return None
//===================================================================================
PAC5XXX_RAMFUNC void pwm_duty_control(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	motor_ptr->app_status &= ~status_closed_loop;
	motor_ptr->app_status |= status_pwm_duty_loop;

	if(motor_ptr->pwm_duty_Fall_buf++ > motor_ptr->pwm_control_duty_change_delay_counts) //change_delay_counts=5
	{
 		motor_ptr->final_pwm_duty = motor_ptr->pwm_control_duty_cycle; // target=234
		if(motor_ptr->temp_pwm_duty < motor_ptr->final_pwm_duty)
		{
			motor_ptr->temp_pwm_duty += 1;
		}
		else if(motor_ptr->temp_pwm_duty > motor_ptr->final_pwm_duty)
		{
			motor_ptr->temp_pwm_duty -= 1;
		}
		else
		{
			motor_ptr->temp_pwm_duty = motor_ptr->final_pwm_duty;
		}
		motor_ptr->pwm_duty_Fall_buf = 0 ;
	}
}

//===================================================================================
/// @brief  Digital filter
/// @param  current data, previous data and filter coefficient data
/// @return fix16_t digital filter value
//===================================================================================
PAC5XXX_RAMFUNC fix16_t digital_low_pass_filter_for_Iq(fix16_t digital_low_pass_filter_input)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
	fix16_t temp;

	motor_ptr->Iq_prev_non_filtered = digital_low_pass_filter_input;

	// y(i) = y(i-1) + alpha * (x(i) -y(i-1)), where alpha = dt / (tau + dt) and tau = 1/alpha
    temp = fix16_sub(motor_ptr->Iq_prev_non_filtered, motor_ptr->Iq_previous); // z_gamma - lp_gamma_previous
    temp = fix16_mul_new_16_16(temp, motor_ptr->Iq_filter_gain);  // lp_gamma_alpha * (z_gamma - lp_gamma_previous)
    temp = fix16_add(motor_ptr->Iq_previous, temp);  // lp_gamma_previous + lp_gamma_alpha * (z_gamma - lp_gamma_previous)
    motor_ptr->Iq_previous = temp;

    return temp;
}


//===================================================================================
/// @brief  Ramp updown generic function
/// @param  fix16_t* value1, fix16_t* value2, fix16_t* ramp_rate
/// @return None
//===================================================================================
void bldc_motor_generic_ramp(fix16_t* value1, fix16_t* value2, fix16_t* ramp_rate)
{
	fix16_t temp_diff;

	// Use to ramp up and down value
	temp_diff = fix16_sub(*value1, *value2);
	if (temp_diff > 0)
	{
		if (temp_diff <= *ramp_rate)
		    *value1 = *value2;
		else
			*value1 = fix16_sub(*value1, *ramp_rate);
	}
	else if (temp_diff < 0)
	{
		if (-temp_diff <= *ramp_rate)
			*value1 = *value2;
		else
			*value1 = fix16_add(*value1, *ramp_rate);
	}
}

//===================================================================================
/// @brief  Ramp_down_up Iq ref to Iq ref sp
/// @param  iq
/// @return None
//===================================================================================
void bldc_motor_iq_ref_ramp(BLDC_Controller* motor_ptr)
{
	static volatile unsigned int iq_ramp_loop_count;

	// Use to ramp Iq_ref to Iq_ref_sp
	if (iq_ramp_loop_count++ > CURRENT_RAMP_COUNTS)
	{
		iq_ramp_loop_count = 0;

        // it's a generic ramp function used for Iq
		bldc_motor_generic_ramp((fix16_t *) (&motor_ptr->Iq_ref), (fix16_t *) (&motor_ptr->Iq_ref_sp), (fix16_t *) (&motor_ptr->Iq_ramp_rate));
	}
}

//===================================================================================
/// @brief  Ramp_down_up Speed ref to speed ref sp
/// @param  speed
/// @return None
//===================================================================================
void bldc_motor_speed_ref_ramp(BLDC_Controller* motor_ptr)
{
	static volatile unsigned int speed_ramp_loop_count;

	// Use to ramp Iq_ref to Iq_ref_sp
	if (speed_ramp_loop_count++ > SPEED_RAMP_COUNTS)
	{
		speed_ramp_loop_count = 0;

		bldc_motor_generic_ramp((fix16_t *) (&motor_ptr->motor_close_loop_speed_temp), (fix16_t *) (&motor_ptr->motor_close_loop_speed), (fix16_t *) (&motor_ptr->motor_close_loop_speed_ramp));
		motor_ptr->app_speed_command = HertzToTicks(motor_ptr->motor_close_loop_speed_temp, TIMER_D_FREQ_F16) ;
		motor_ptr->app_speed_ref = motor_ptr->app_speed_command;
	}
}

//===================================================================================
/// @brief  get current ADC value
/// @param  None
/// @return None
//===================================================================================
PAC5XXX_RAMFUNC void get_curent_adc_value(BLDC_Controller* motor_ptr)
{
#ifdef 	Hall_MODE_ENABLE
	Hall_Sensor* hall_ptr;
	hall_ptr = &bldc_hall_sensor_m1;

	if((hall_ptr->sensored_current_state == 1)||(hall_ptr->sensored_current_state == 6))
	{
		motor_ptr->Ibus_ADC = PAC5XXX_ADC->AS0R5.VAL;
	}
	else if((hall_ptr->sensored_current_state == 4)||(hall_ptr->sensored_current_state == 5))
	{
		motor_ptr->Ibus_ADC = PAC5XXX_ADC->AS0R0.VAL;
	}
	else if((hall_ptr->sensored_current_state == 2)||(hall_ptr->sensored_current_state == 3))
	{
		motor_ptr->Ibus_ADC = PAC5XXX_ADC->AS0R6.VAL;
	}
	else
	{
		motor_ptr->Ibus_ADC = 0;
	}
#else
	if((motor_ptr->sl_current_state == 1)||(motor_ptr->sl_current_state == 6))
	{
		motor_ptr->Ibus_ADC = PAC5XXX_ADC->AS0R5.VAL;
	}
	else if((motor_ptr->sl_current_state == 4)||(motor_ptr->sl_current_state == 5))
	{
		motor_ptr->Ibus_ADC = PAC5XXX_ADC->AS0R0.VAL;
	}
	else if((motor_ptr->sl_current_state == 2)||(motor_ptr->sl_current_state == 3))
	{
		motor_ptr->Ibus_ADC = PAC5XXX_ADC->AS0R6.VAL;
	}
	else
	{
		motor_ptr->Ibus_ADC = 0;
	}
#endif
}


//===================================================================================
/// @brief  Initialize motor parameters
/// @param  None
/// @return None
//===================================================================================
void bldc_motor_init_parameters(BLDC_Controller* motor_ptr)
{
	// Initialize PI and control parameters
	pid_reset(&motor_ptr->speed_pid);
	motor_ptr->blanking_sample_counts = COMMUTATION_BLANKING_COUNT;
	motor_ptr->num_of_good_zc_samples = DEFAULT_GOOD_ZERO_CROSS_SAMPLES;
	motor_ptr->motor_close_loop_speed = DEFAULT_CLOSE_LOOP_SPEED;
    motor_ptr->motor_close_loop_speed_ramp = SPEED_RAMP_RATE_1HZ_SEC;
	// Reset PI parameters for 1st timer power up
	pid_reset(&motor_ptr->Iq_pid);
	// Initialize motor initialize parameters
	motor_ptr->Iq_pid.Td = TD_FOR_IQ_PID;
	motor_ptr->Iq_ramp_rate = IQ_RAMP_RATE;
	motor_ptr->Iq_ref_sp = IQ_REFERENCE;
	motor_ptr->Iq_ref = 0;
	motor_ptr->blanking_sample_counts = COMMUTATION_BLANKING_COUNT;
	motor_ptr->num_of_good_zc_samples = DEFAULT_GOOD_ZERO_CROSS_SAMPLES;
	motor_ptr->motor_close_loop_speed = DEFAULT_CLOSE_LOOP_SPEED;
	motor_ptr->motor_auto_blank_percent = DEFAULT_AUTO_BLANKING_PERCENT;
}


//===================================================================================
/// @brief  This function reset some parameter and status when motor stop
/// @param  None
/// @return None
//===================================================================================
void motor_stop_state_reset(void)
{
	Sim_Detect* sim_ptr;
	sim_ptr = &bldc_sim_m1;

	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	// Disable PWM output
	pwm_disable();

	// initialize variable
	motor_ptr->call_speed_loop_delay_count = 0;
	motor_ptr->charge_delay_count = 0 ;
	motor_ptr->average_speed = 65535;
	motor_ptr->app_measured_speed = 65535;
	motor_ptr->app_speed_ref = 65535;

	// Initialize current control PI
	motor_ptr->Iq_ref = 0;
	motor_ptr->Iq_pid.PI_sat = 0xa0000;//?1010 0000 0000 0000 0000?
	motor_ptr->Iq_pid.I_prev = 0xa0000;
	pid_reset(&motor_ptr->Iq_pid);
	motor_ptr->temp_pwm_duty = 0 ;
	motor_ptr->temp_pwm_duty_u = 0 ;
	motor_ptr->temp_pwm_duty_v = 0 ;
	motor_ptr->temp_pwm_duty_w = 0 ;

#if defined(SIM_ENABLE)||defined(MOTOR_STOP_BRAKING_ENABLE)
	sim_ptr->motor_in_motion_flag = 0;
	sim_ptr->bemf_u_init = BRAKING_BEMF_AIO7_ADC;
	sim_ptr->bemf_v_init = BRAKING_BEMF_AIO8_ADC;
	sim_ptr->bemf_w_init = BRAKING_BEMF_AIO9_ADC;
	sim_ptr->bemf_uvw_init_center_tap_voltage = sim_ptr->bemf_u_init + sim_ptr->bemf_v_init + sim_ptr->bemf_w_init;
	sim_ptr->bemf_uvw_init_center_tap_voltage = fix16_mul_new_16_16((sim_ptr->bemf_uvw_init_center_tap_voltage<<16),MATH_ONE_DIV_THREE_FIX16)>>16;
	sim_ptr->braking_vbus_voltage_ref = VBUS_ADC_RESULT_CHANEL;
	sim_ptr->braking_vbus_voltage_ref = fix16_mul_new_16_16((sim_ptr->braking_vbus_voltage_ref<<16),BRAKING_VBUS_OVER_PERCENT)>>16;
	sim_ptr->braking_vbus_voltage_ref = sim_ptr->braking_vbus_voltage_ref + VBUS_ADC_RESULT_CHANEL;
#endif

	//Disable TimerC&TimerD interrupt
	NVIC_DisableIRQ(TimerC_IRQn);
//	NVIC_EnableIRQ(TimerC_IRQn);
	NVIC_DisableIRQ(TimerD_IRQn);

	// Set motor status to disable
	motor_ptr->app_status &= ~status_open_loop;
	motor_ptr->app_status &= ~status_closed_loop;
	motor_ptr->app_status &= ~status_motor_enabled;
	motor_ptr->app_status &= ~status_pwm_duty_loop;

	// reset state
	bldc_align_go.align_and_go_state = STATE_STARTUP_INIT;
	get_zero_cross_point_state = STATE_TIMERC_WAIT_COMMUTATE;
	control_machine_state = STATE_CONTROL_IDLE;

#ifdef PPD_START_UP_ENABLE
	motor_control_ppd.ppd_running_state = MOTOR_STATE_PPD_INIT;
#endif
#ifdef	Hall_BEMF_SWITCH_MODE_ENABLE
	hall_bemf_switch_state = STATE_HALL_STARTUP;
#endif
}


//===================================================================================
/// @brief  This function configures the fault state by enabling a timer
///         that will periodically expire to toggle the on-board LED.
/// @param  blink_timer_ticks The number of timer ticks at which to toggle LED
/// @return None
//===================================================================================
void set_fault(uint16_t blink_timer_ticks)
{
	int counter;

	// Disable interrupts, disable PWM, toggle PE0
	__disable_irq();

	pwm_disable();

	while(1)
	{
		for (counter=0;counter<(blink_timer_ticks/2);counter++);

		pac5xxx_gpio_out_toggle_e(LED_PIN_MASK);		// Toggle PE0 state
	}
}


//===================================================================================
/// @brief  This function transforms the motor speed in Hz to the respective number of clock cycles required
/// 		   The equation on this function is # ticks = PWM_FREQ / (6 * SpeedInHz)
/// 		   The PWM_FREQ (units is KHz) is programmable and is computed in the UART module
/// @param  Frequency
/// @return The number of clock cycles corresponding to the desired frequency
//===================================================================================
PAC5XXX_RAMFUNC fix16_t HertzToTicks(int Hertz, fix16_t Freq)
{
	fix16_t tmp;

	tmp = fix16_mul_new_16_16(6 << 16, Hertz); // (6 * SpeedInHz)
	tmp = fix16_div(Freq, tmp);  //ticks = PWM_FREQ / (6 * SpeedInHz) PWM_FREQ (units is KHz) 
	tmp = fix16_mul_new_16_16(tmp, 1000 << 16); 
	return tmp >> 16;
}










