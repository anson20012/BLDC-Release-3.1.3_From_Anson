
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


#ifdef PAC522x
//=============================================================================
/// @brief  This function config braking pwm mode
/// @param  None
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void braking_init(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	__disable_irq();
	// Set IO state of all pins to 0
	PAC5XXX_GPIOA->OUT.b &= (~0x3F);  /* PA[0,1,2,] UL, VL, WL, PA[3,4,5] UH, VH, WH */

	// Turn off output enables
	PAC5XXX_GPIOA->OUTEN.b &= ~(0x38 | 0x07);

	// Select GPIO peripheral for Port A
	PAC5XXX_GPIOA->PSEL.s &= (~0x0595);
	PAC5XXX_GPIOA->PSEL.s |= 0x0015;       										//PA0 PA1 PA2 to PWM mode

	PAC5XXX_TIMERA->CTR4 = motor_ptr->pwm_timer_ticks ;									// Set 0 braking duty
	PAC5XXX_TIMERA->CTR5 = motor_ptr->pwm_timer_ticks ;									// Set 0 braking duty
	PAC5XXX_TIMERA->CTR6 = motor_ptr->pwm_timer_ticks ;									// Set 0 braking duty

	// Turn on output enables
	PAC5XXX_GPIOA->OUTEN.b |= 0x07;

    // Enable driver manager and verify active - need to enable even in PAC5210 to get ENHS pin to work
    pac5xxx_tile_register_write(ADDR_ENDRV, 1);
	__enable_irq();
}
#endif

#ifdef PAC523x
//=============================================================================
/// @brief  This function config braking pwm mode
/// @param  None
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void braking_init(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;


	__disable_irq();
	// Set IO state of all pins to 0
	PAC5XXX_GPIOA->OUT.b &= (~0x3F);  /* PA[0,1,2,] UL, VL, WL, PA[3,4,5] UH, VH, WH */

	// Turn off output enables
	PAC5XXX_GPIOA->OUTEN.b &= ~(0x38 | 0x07);

	// Select GPIO peripheral for Port A
	PAC5XXX_GPIOA->PSEL.s &= (~0x0595);
	PAC5XXX_GPIOA->PSEL.s |= 0x0015;       										//PA0 PA1 PA2 to PWM mode

	PAC5XXX_TIMERA->CTR4 = motor_ptr->pwm_timer_ticks ;									// Set 0 braking duty
	PAC5XXX_TIMERA->CTR5 = motor_ptr->pwm_timer_ticks ;									// Set 0 braking duty
	PAC5XXX_TIMERA->CTR6 = motor_ptr->pwm_timer_ticks ;									// Set 0 braking duty

	// Turn on output enables
	PAC5XXX_GPIOA->OUTEN.b |= 0x07;

    // Enable driver manager and verify active - need to enable even in PAC5210 to get ENHS pin to work
    pac5xxx_tile_register_write(ADDR_ENDRV, 1);
	__enable_irq();
}
#endif


#ifdef PAC525x
//=============================================================================
// @brief  This function config braking pwm mode
// @param  None
// @return None
//=============================================================================
PAC5XXX_RAMFUNC void braking_init(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	__disable_irq();
	// Turn off output enables
	PAC5XXX_GPIOA->OUTEN.b &= ~(0xc0 | 0x07);
	PAC5XXX_GPIOD->OUTEN.b &= ~(0x80 | 0x00);

	// Select GPIO peripheral for Port A and D
	PAC5XXX_GPIOA->PSEL.s &= ~0x5015;
	PAC5XXX_GPIOD->PSEL.s &= ~0x4000;
	PAC5XXX_GPIOA->PSEL.s |= 0x0015;      										//PA0 PA1 PA2 to PWM mode

	PAC5XXX_TIMERA->CTR4 = motor_ptr->pwm_timer_ticks ;									// Set 0 braking duty
	PAC5XXX_TIMERA->CTR5 = motor_ptr->pwm_timer_ticks ;									// Set 0 braking duty
	PAC5XXX_TIMERA->CTR6 = motor_ptr->pwm_timer_ticks ;									// Set 0 braking duty

	/* Turn on output enables */
	PAC5XXX_GPIOA->OUTEN.b |= 0x07;
	__enable_irq();
}
#endif

//=============================================================================
/// @brief  This function config braking pwm duty cycle control
/// @param  brakin_depth(pwm duty cycle)
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void braking_PWM_control(uint16_t braking_depth)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
	uint16_t braking_duty;

	if(braking_depth <=motor_ptr->pwm_timer_ticks)
	{
		braking_duty = motor_ptr->pwm_timer_ticks - braking_depth;

	//	PAC5XXX_GPIOA->OUT.b |= 0x07;
		PAC5XXX_TIMERA->CTR4 = braking_duty ;									// Set 0 duty
		PAC5XXX_TIMERA->CTR5 = braking_duty ;									// Set 0 duty
		PAC5XXX_TIMERA->CTR6 = braking_duty ;									// Set 0 duty
	}
}


//=============================================================================
/// @brief  This function increase or decrease braking low mosFET PWM duty counts
/// @param  None
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void braking_charge_vbus_control(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
	Sim_Detect* sim_ptr;
	sim_ptr = &bldc_sim_m1;

	//Read vbus voltage
	sim_ptr->braking_vbus_voltage_fdb = VBUS_ADC_RESULT_CHANEL;

	//If vbus voltage lower than vbus_ref, increase braking pwm duty cycle counts
	if(sim_ptr->braking_vbus_voltage_fdb < sim_ptr->braking_vbus_voltage_ref)
	{
		if(sim_ptr->braking_depth_pwm_duty_counts < (motor_ptr->pwm_timer_ticks - BRAKING_SAMPLE_BEMF_TIME_COUNTS))
		{
			sim_ptr->braking_depth_pwm_duty_counts = sim_ptr->braking_depth_pwm_duty_counts + BRAKING_INCREASE_PWM_COUNTS;
		}
	}
	//If vbus voltage higher than vbus_ref, decrease braking pwm duty cycle counts
	else
	{
		if(sim_ptr->braking_depth_pwm_duty_counts >= BRAKING_DECREASE_PWM_COUNTS)
		{
			sim_ptr->braking_depth_pwm_duty_counts = sim_ptr->braking_depth_pwm_duty_counts - BRAKING_DECREASE_PWM_COUNTS;
		}
	}

	if(((sim_ptr->braking_depth_pwm_duty_counts) <= motor_ptr->pwm_timer_ticks )&&(sim_ptr->braking_depth_pwm_duty_counts >0))
	{
		braking_PWM_control(sim_ptr->braking_depth_pwm_duty_counts);
	}
}


//=============================================================================
/// @brief  This function detect whether the motor is braking to stop
/// @param  None
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void braking_detect_motor_state(void)
{
	Sim_Detect* sim_ptr;
	sim_ptr = &bldc_sim_m1;


	sim_ptr->braking_bemf_u = BRAKING_BEMF_AIO7_ADC;
	sim_ptr->braking_bemf_v = BRAKING_BEMF_AIO8_ADC;
	sim_ptr->braking_bemf_w = BRAKING_BEMF_AIO9_ADC;

	sim_ptr->braking_bemf_uvw_center_tap_voltage = sim_ptr->braking_bemf_u  + sim_ptr->braking_bemf_v  + sim_ptr->braking_bemf_w ;

	//If back EMF voltage lower than the threshold,we consider the motor is stop
	if(sim_ptr->braking_bemf_uvw_center_tap_voltage <= BRAKING_STOP_THRESHOLD_ADC_VALUE)
	{
		if(sim_ptr->braking_stop_counts++ >BRAKING_STOP_DETECT_TIME_COUNTS)
		{
			sim_ptr->braking_stop_counts = 0;
			sim_ptr->braking_detect_motor_stop_flag = 1;
		}
	}
	else
	{
		sim_ptr->braking_stop_counts = 0;
		if(sim_ptr->in_braking_state_counts++ >= IN_BRAKING_STATE_TIMEOUT)
		{
			sim_ptr->braking_detect_motor_stop_flag = 1;
		}
		else
		{
			sim_ptr->braking_detect_motor_stop_flag = 0;
		}
	}
}

