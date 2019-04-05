/**************************************************************************//**
 * @file     uart.c
 * @brief    Peripheral and initialization routines for the application.
 * @date     03 March 2017
 *
 * @note
 * Copyright (C) 2016, Active-Semi International
 *
 * THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
 * AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
 * APPLICATION TO PAC PROCESSORS SUPPLIED BY ACTIVE-SEMI INTERNATIONAL;
 * (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
 * ACTIVE-SEMICONDUCTOR IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
 * DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
 * ONLY BY CERTAIN AUTHORIZED PERSONS.
 *
 ******************************************************************************/
#include <stdio.h>
#include "uart.h"
#include "config_options.h"

#ifdef ENABLE_UART_COMMUNICATE

#define UART_MESSAGE_SIZE	9


uint8_t uart_rx_buffer[UART_MESSAGE_SIZE];
uint8_t uart_tx_buffer[UART_MESSAGE_SIZE];

static int uart_rx_byte_count = 0;
static int uart_tx_byte_count = 0;

int32_t debug_array[40], debug_index;

uint32_t debug_box1_int32;
uint32_t debug_box2_int32;
fix16_t  debug_box3_fix16;
fix16_t  debug_box4_fix16;


enum Uart_Message_Code
{
    cmd_version,
    cmd_set_address,
    cmd_read_word,
    cmd_write_word,
    cmd_set_buffer,
    cmd_parameter_read,
    cmd_parameter_write,
    cmd_cafe_reg_read
};

enum Uart_Parameter_Code
{
	// status commands
    parm_status,								//1
    parm_motor_speed,
    parm_speed_ref,
    parm_pi_out,
    parm_debug_1,

    parm_debug_2,
    parm_debug_3,
    parm_debug_4,
    parm_pwm_freq_khz,
    parm_admin_state,							//10

    parm_speed_command,							//11
    parm_over_current_limit,
    parm_dt,
    parm_speed_Kp,
    parm_speed_Ki,

    parm_speed_Ks,
    parm_speed_min,
    parm_speed_max,
    parm_align_go_duty_cycle,
    parm_align_time_count,						//20

    parm_start_speed_count,						//21
    parm_accel_time_base,
    parm_commutation_advanced_rise_delay,
    parm_commutation_advanced_fall_delay,
    parm_dt_leading_ticks,

    parm_dt_trailing_ticks,
    parm_auto_accel,
    parm_debug_array,
    parm_align_go_duty_factor,
    parm_align_go_duty_offset,					//30

    parm_dac_debug1_scale,						//31
    parm_dac_debug2_scale,
    parm_current_Kp,
    parm_current_Ki,
    parm_current_Ks,

    parm_current_min,
    parm_current_max,
    parm_current_control,
    parm_current_iq_ref,
    parm_num_of_zc_sample,           			//40

    parm_pwm_control_duty_change_delay_counts,	//41
    parm_close_loop_speed_command,
    parm_adc_zero_cross_offset,
    zero_cross_sampling_point,
    parm_current_iq_ramp_rate,

    parm_close_loop_ramp_rate,
    parm_automatic_balnking_time,
    parm_reverse_tune_flag,
    parm_over_current_resistor,
    parm_amplifier_gain,    					//50

    parm_oc_reset,             					//51
    parm_dac_debug_select,
    parm_debug_box1_int32,
    parm_debug_box2_int32,
    parm_debug_box3_fix16,

    parm_debug_box4_fix16,
    parm_control_freq,
    parm_pwm_duty_ticks_count,
    parm_hall_to_mos_array,
    parm_vbus_voltage ,     					//60
	
    parm_PPD_Charge_Duty,						//61
    parm_PPD_Discharge_Percent,
    parm_PPD_Pulse_Counts,
    parm_PPD_MAX_ADC,
    parm_PPD_MAX_ADC_Diff,

    parm_PPD_Current_Phase,
    parm_PPD_Smooth_Count_Target,
    parm_PPD_Tune_Duty_Ramp,
    parm_PPD_Tuning_Last_Count,
    parm_Current_Cutoff_Freq,					//70

    parm_PPD_Test_Mode,							//71

    control_mode_select_number,                 //72
    closed_loop_current_command ,               //73
    coasting_timeout                            //74
};



Uart_Status uart_message_process(void)
{
	uint32_t rx_data;
	Uart_Status status = success;
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
#ifdef SIM_ENABLE
	Sim_Detect* sim_ptr;
	sim_ptr = &bldc_sim_m1;
#endif
#if defined(Hall_MODE_ENABLE)||defined(Hall_Detect_IN_BEMF_MODE)
	Hall_Sensor* hall_ptr;
	hall_ptr = &bldc_hall_sensor_m1;
#endif
	fix16_t temp1;

	//====================================================================================================
	// Full message received in uart_rx_buffer, process and then queue up transmit (response) message
	//====================================================================================================
	uart_tx_buffer[0] = 0xEE;											// Response message type is always 0xEE
	uart_tx_buffer[1] = uart_rx_buffer[1] + 0x80;						// Response message code is received message code + 0x80

	//====================================================================================================
	// Put data from uart_rx_buffer into word for processing
	//====================================================================================================
	rx_data = (uart_rx_buffer[4] << 24);
	rx_data |= (uart_rx_buffer[5] << 16);
	rx_data |= (uart_rx_buffer[6] << 8);
	rx_data |= uart_rx_buffer[7];

	//====================================================================================================
	// Validate checksum
	//====================================================================================================
	if (uart_checksum((uint8_t*)&uart_rx_buffer) != uart_rx_buffer[8])
	{
		status = checksum_error;										// Put in checksum error
		uart_tx_buffer[8] = uart_checksum((uint8_t*)&uart_tx_buffer);	// Calculate checksum for outgoing message
	}
	else
	{
		switch (uart_rx_buffer[1])										// Switch on command code
		{
		case cmd_version:
			uart_tx_buffer[5] = VERSION_TYPE;
			uart_tx_buffer[6] = VERSION_MAJOR;
			uart_tx_buffer[7] = VERSION_MINOR;
			break;
#if 0
		case cmd_set_address:
			set_address = rx_data;
			if (uart_rx_buffer[2] & 1)
				set_addr_autoinc = 1;
			else
				set_addr_autoinc = 0;
			break;
		case cmd_read_word:
			int_to_buffer(*((uint32_t*)set_address));
			if (set_addr_autoinc)
				set_address += 4;
			break;
		case cmd_write_word:
			*((uint32_t*)set_address) = rx_data;
			if (set_addr_autoinc)
				set_address += 4;
			break;
#endif
		case cmd_cafe_reg_read:
			uart_tx_buffer[4] = 0;
			uart_tx_buffer[5] = 0;
			uart_tx_buffer[6] = 0;
			uart_tx_buffer[7] = pac5xxx_tile_register_read(uart_rx_buffer[7]);
			break;
		//===============================================================================================
		// Update firmware variable to GUI parameter
		//===============================================================================================
		case cmd_parameter_read:
			switch (uart_rx_buffer[2])
			{
			case parm_status:
				int_to_buffer(motor_ptr->app_status);
				break;
			case parm_motor_speed:
				int_to_buffer(motor_ptr->app_measured_speed);
				break;
			case parm_speed_ref:
				int_to_buffer(motor_ptr->app_speed_ref);
				break;
			case parm_pi_out:
				int_to_buffer(motor_ptr->speed_pid.PI_sat);
				break;
			case parm_pwm_duty_ticks_count:
				int_to_buffer((PAC5XXX_TIMERA->CTR4 ));
				break;
			case parm_hall_to_mos_array:
				#if defined(Hall_MODE_ENABLE)||defined(Hall_Detect_IN_BEMF_MODE)
				int_to_buffer((hall_ptr->hall_to_mos_state_detect));
				#endif
				break;
			case parm_vbus_voltage:
				int_to_buffer((motor_ptr->vbus_voltage_value));
				break;
			case parm_debug_1:
//				int_to_buffer(pwm_dac_debug_variable.app_speed_ref_fix16);
//				int_to_buffer(motor_control_ppd.ppd_running_state);
				int_to_buffer(BRAKING_BEMF_AIO7_ADC);
//				int_to_buffer((PAC5XXX_ADC->AS0R0.VAL));
				break;
			case parm_debug_2:
//				int_to_buffer(motor_ptr->coasting_timeout_counts);
//				int_to_buffer(opd_v_phase_voltage);
//				int_to_buffer(pwm_dac_debug_variable.app_measured_speed_fix16);
				int_to_buffer(BRAKING_BEMF_AIO8_ADC);
				break;
			case parm_debug_3:
//				int_to_buffer((PAC5XXX_ADC->AS0R6.VAL<<16));
//				int_to_buffer((opd_w_phase_voltage << 16));
				int_to_buffer(fix16_from_int(PAC5XXX_ADC->AS0R0.VAL));
				break;
			case parm_debug_4:
//				int_to_buffer(BRAKING_BEMF_AIO9_ADC << 16);
				int_to_buffer(motor_ptr->Iq_fb);
//				int_to_buffer(bldc_align_go.align_go_duty_cycle << 16);
				break;
			case parm_pwm_freq_khz:
				int_to_buffer(motor_ptr->app_pwm_freq_khz);
				break;
			case parm_admin_state:
				int_to_buffer(motor_ptr->motor_enable_cmd);
				break;
			case parm_speed_command:
				int_to_buffer(motor_ptr->app_speed_command);
				break;
			case parm_over_current_limit:
				int_to_buffer(motor_ptr->app_over_current_limit);
				break;
			case parm_dt:
				int_to_buffer(motor_ptr->speed_pid.Td);
				break;
			case parm_speed_Kp:
				int_to_buffer(motor_ptr->speed_pid.Kp);
				break;
			case parm_speed_Ki:
				int_to_buffer(motor_ptr->speed_pid.Ki);
				break;
			case parm_speed_Ks:
				int_to_buffer(motor_ptr->speed_pid.Ks);
				break;
			case parm_speed_min:
				int_to_buffer((motor_ptr->speed_pid.min_value) >> 16);
				break;
			case parm_speed_max:
				int_to_buffer((motor_ptr->speed_pid.max_value) >> 16);
				break;
			case parm_align_go_duty_cycle:
				int_to_buffer(bldc_align_go.align_go_duty_cycle);
				break;
			case parm_align_go_duty_factor:
				int_to_buffer(motor_ptr->align_pwm_duty_max >> 16);
				break;
			case parm_align_go_duty_offset:
				int_to_buffer(motor_ptr->pwm_control_duty_cycle >> 16);
				break;
			case parm_align_time_count:
				int_to_buffer(bldc_align_go.align_ticks);
				break;
			case parm_start_speed_count:
				int_to_buffer(bldc_align_go.start_speed_ticks_period);
				break;
			case parm_accel_time_base:
				int_to_buffer(bldc_align_go.accel_rate_time_base);
				break;
			case parm_commutation_advanced_rise_delay:
				int_to_buffer(motor_ptr->commutation_advanced_rise);
                break;
			case parm_commutation_advanced_fall_delay:
				int_to_buffer(motor_ptr->commutation_advanced_fall);
                break;
			case parm_dt_leading_ticks:
				int_to_buffer(1);
				break;
			case parm_dt_trailing_ticks:
				int_to_buffer(1);
				break;
			case parm_auto_accel:
				int_to_buffer(bldc_align_go.auto_acceleration_mode);
				break;
			case parm_debug_array:
				int_to_buffer(debug_array[debug_index]);
				break;

			case parm_current_Kp:
				int_to_buffer(motor_ptr->Iq_pid.Kp);
				break;
			case parm_current_Ki:
				int_to_buffer(motor_ptr->Iq_pid.Ki);
				break;
			case parm_current_Ks:
				int_to_buffer(motor_ptr->Iq_pid.Ks);
				break;

			case parm_current_min:
				int_to_buffer(motor_ptr->Iq_pid.min_value);
				break;

			case parm_current_max:
				int_to_buffer(motor_ptr->Iq_pid.max_value);
				break;

			case parm_current_control:
				break;

			case parm_current_iq_ref:
				int_to_buffer(motor_ptr->Iq_ref_sp);
			    break;

			case parm_num_of_zc_sample:
				int_to_buffer(motor_ptr->num_of_good_zc_samples);
				break;

			case parm_pwm_control_duty_change_delay_counts:
				int_to_buffer(motor_ptr->pwm_control_duty_change_delay_counts);
				break;

			case parm_close_loop_speed_command:
				int_to_buffer(motor_ptr->motor_close_loop_speed);
				break;

			case parm_adc_zero_cross_offset:
				int_to_buffer(motor_ptr->adc_zero_cross_offset_percentage);
                break;

			case parm_current_iq_ramp_rate:
				int_to_buffer(motor_ptr->Iq_ramp_rate);
				break;

			case parm_close_loop_ramp_rate:
				int_to_buffer(motor_ptr->motor_close_loop_speed_ramp);
                break;

			case parm_automatic_balnking_time:
				int_to_buffer(motor_ptr->motor_auto_blank_percent);
                break;

			case parm_reverse_tune_flag:
				int_to_buffer(motor_ptr->reverse_tune_flag);
				break;
#ifdef PPD_START_UP_ENABLE
			//=========================================================
			// PPD Function ADD
			//=========================================================
			case parm_PPD_MAX_ADC:
				int_to_buffer(motor_control_ppd.ppd_max_adc_two_phase);
				break;

			case parm_PPD_MAX_ADC_Diff:
				int_to_buffer(motor_control_ppd.ppd_max_adc_two_phase - motor_control_ppd.ppd_min_adc_two_phase);
				break;

			case parm_PPD_Current_Phase:
				int_to_buffer(motor_control_ppd.ppd_result_phase);
				break;
#endif
			default:
				status = host_write_error;
			}

			break;
		//===============================================================================================
		// Update GUI parameter to firmware variable
		//===============================================================================================
		case cmd_parameter_write:
			switch (uart_rx_buffer[2])
			{	
			case parm_pwm_freq_khz:
				if ((rx_data>>2) != motor_ptr->app_pwm_freq_khz)
				{
					motor_ptr->app_pwm_freq_khz = rx_data ;													//Number of KHz
					motor_ptr->pwm_timer_ticks = fix16_div((25000<<16), motor_ptr->app_pwm_freq_khz)>>16;     			//PLL 50MHz
					pac5xxx_timer_base_config(TimerA, motor_ptr->pwm_timer_ticks, 0, TxCTL_MODE_UPDOWN, 0);	// Configure Timer
					motor_ptr->Iq_pid.max_value = motor_ptr->pwm_timer_ticks << 16;
					pac5xxx_timer_cctrl_config(TimerA, 1, (motor_ptr->pwm_timer_ticks - 60), 1);
					motor_ptr->one_div_pwm_timer_ticks_fix16 = fix16_div(65536,(motor_ptr->pwm_timer_ticks<<16));
				}
				break;

			case parm_control_freq:
				motor_ptr->app_control_freq_khz = rx_data ;
				motor_ptr->main_machine_control_counts = fix16_div((motor_ptr->app_pwm_freq_khz),motor_ptr->app_control_freq_khz)>>16;
				temp1 = fix16_div(0x00010000, motor_ptr->app_control_freq_khz);								// x = 1 / control_freq
				temp1 = fix16_mul_new_16_16(temp1, FIX16_1DOT_024);									// x = x * 1.024
				motor_ptr->Iq_pid.Td = temp1;
				motor_ptr->speed_pid.Td = temp1;
				break ;
			case parm_admin_state:
				motor_ptr->motor_enable_cmd = rx_data;
				break;
			case parm_speed_command:
				bldc_align_go.switch_speed_hz = rx_data;
				if (bldc_align_go.align_and_go_state != STATE_STARTUP_DONE)
				{
                    /*!< Convert motor open loop speed to timer D ticks */
					motor_ptr->app_speed_command = HertzToTicks(bldc_align_go.switch_speed_hz, TIMER_D_FREQ_F16) ;
				}
				break;
			case parm_oc_reset :
				motor_ptr->oc_reset_flag = rx_data;
				if(motor_ptr->oc_reset_flag)
				{
					if(((motor_ptr->app_status&0x02)>>1) == 1)
					{
						oc_reset();
						motor_ptr->oc_reset_flag = 0;
					}
				}
				break;
			case parm_over_current_resistor:
				motor_ptr->app_over_current_resistor = rx_data;
				break;
			case parm_amplifier_gain:
				motor_ptr->app_amplifier_gain = rx_data;
				app_amplifier_gain_init(motor_ptr->app_amplifier_gain);
				motor_ptr->I_total_factor = fix16_mul_new_16_16(motor_ptr->app_over_current_resistor,(motor_ptr->app_amplifier_gain<<16));
				motor_ptr->I_total_factor = (fix16_div(0x27100,motor_ptr->I_total_factor));
				break;
			case parm_over_current_limit:
				motor_ptr->app_over_current_limit = rx_data ;
				if(motor_ptr->app_over_current_limit >=1023)
				{
					motor_ptr->app_over_current_limit = 1023;
				}
				init_over_current_limit(motor_ptr->app_over_current_limit);
				break;
			case parm_dt:
//				motor_ptr->speed_pid.Td = rx_data;
				break;
			case parm_speed_Kp:
				motor_ptr->speed_pid.Kp = rx_data;
				break;
			case parm_speed_Ki:
				motor_ptr->speed_pid.Ki = rx_data;
				break;
			case parm_speed_Ks:
				motor_ptr->speed_pid.Ks = rx_data;
				break;
			case parm_speed_min:
				motor_ptr->speed_pid.min_value = rx_data;
				break;
			case parm_speed_max:
				motor_ptr->speed_pid.max_value = rx_data;
				break;
			case parm_align_go_duty_cycle:
				break;
			case parm_align_time_count:
				bldc_align_go.align_ticks = rx_data;
				bldc_align_go.align_ticks_store = bldc_align_go.align_ticks;
				break;
			case parm_start_speed_count:
				bldc_align_go.start_speed_hz = rx_data;
				break;
			case parm_accel_time_base:
				bldc_align_go.accel_rate_time_base = rx_data;
				break;
			case parm_commutation_advanced_rise_delay:
				motor_ptr->commutation_advanced_rise = rx_data;
                break;
			case parm_commutation_advanced_fall_delay:
				motor_ptr->commutation_advanced_fall = rx_data;
                break;
			case parm_dt_leading_ticks:
				//=============================================================
				// Dead time is fixed, please change in sensoreless.h file
				//=============================================================
				break;
			case parm_dt_trailing_ticks:
				//=============================================================
				// Dead time is fixed, please change in sensoreless.h file
				//=============================================================
				break;
			case parm_auto_accel:
				if (rx_data)
				{
					bldc_align_go.auto_acceleration_mode = 1;
				}
				else
				{
					bldc_align_go.auto_acceleration_mode = 0;
				}
				break;
			case parm_debug_array:
				debug_index = rx_data >> 16;
				break;

			case parm_align_go_duty_factor:
				motor_ptr->align_pwm_duty_max = fix16_mul_new_16_16(rx_data, (motor_ptr->pwm_timer_ticks<<16))>>16;
				bldc_align_go.align_go_duty_cycle = motor_ptr->align_pwm_duty_max;
				bldc_align_go.align_go_duty_cycle_store = bldc_align_go.align_go_duty_cycle;
				break;

			case parm_align_go_duty_offset:
				motor_ptr->pwm_control_duty_cycle = rx_data;
				motor_ptr->pwm_control_duty_cycle = fix16_mul_new_16_16(motor_ptr->pwm_control_duty_cycle, (motor_ptr->pwm_timer_ticks<<16))>>16;
				break;
			case parm_current_Kp:
				motor_ptr->Iq_pid.Kp = rx_data;
				break;
			case parm_current_Ki:
				motor_ptr->Iq_pid.Ki = rx_data;
				break;
			case parm_current_Ks:
				motor_ptr->Iq_pid.Ks = rx_data;
				break;

			case parm_current_min:
				motor_ptr->Iq_pid.min_value = (rx_data) << 16;
				break;

			case parm_current_max:
				//=============================================================
				// Value calculated on the fly, not used form the GUI
				//=============================================================
				break;

			case parm_current_control:
				break;

			case parm_current_iq_ref:
				motor_ptr->Iq_ref_sp = rx_data;
			    break;

			case parm_num_of_zc_sample:
				motor_ptr->num_of_good_zc_samples = rx_data;
				break;

			case parm_pwm_control_duty_change_delay_counts:
				motor_ptr->pwm_control_duty_change_delay_counts = rx_data;
				break;

			case parm_close_loop_speed_command:
				motor_ptr->motor_close_loop_speed = rx_data;
				break;

			case parm_adc_zero_cross_offset:
				motor_ptr->adc_zero_cross_offset_percentage = rx_data;
				break;

			case parm_current_iq_ramp_rate:
                motor_ptr->Iq_ramp_rate = rx_data;
                motor_ptr->Iq_ramp_rate = fix16_mul_new_16_16(motor_ptr->Iq_ramp_rate,655);
				break;

			case parm_close_loop_ramp_rate:
				motor_ptr->motor_close_loop_speed_ramp = rx_data;
				break;

			case parm_automatic_balnking_time:
				//===========================================================================
				// Make sure it's not negative and not more the 100%, data type is fix16
				//===========================================================================
				if ((rx_data > 0) && (rx_data <= 0x10000))
				    motor_ptr->motor_auto_blank_percent = rx_data;
                break;

			case parm_reverse_tune_flag:
				if (rx_data)
				{
					motor_ptr->reverse_tune_flag = 1;
				}
				else
				{
					motor_ptr->reverse_tune_flag = 0;
				}
				break;
#ifdef DEBUG_PWM_DAC_ENABLE
			case parm_dac_debug_select:
				if ((rx_data >= 0) && (rx_data < PWM_DEBUG_ARRAY_LENGTH))
				{
					motor_ptr->debug_buffer_command = rx_data;
					test_ptr1 = &Test_PWM_FIX16[motor_ptr->debug_buffer_command];    // make sure pointer is pointing to array index 0 at power up
				}
				break;
			case parm_dac_debug1_scale:
				debug_scale_factor1 = rx_data;
				break;

			case parm_dac_debug2_scale:
				debug_scale_factor2 = rx_data;
				break;
#endif
			case parm_debug_box1_int32:
				debug_box1_int32 = rx_data;
				break;

			case parm_debug_box2_int32:
				debug_box2_int32 = rx_data;
				break;

			case parm_debug_box3_fix16:
				debug_box3_fix16 = rx_data;
				break;

			case parm_debug_box4_fix16:
				debug_box4_fix16 = rx_data;
				break;

#ifdef PPD_START_UP_ENABLE
			//=====================================================
			// PPD Function ADD
			//=====================================================
			case parm_PPD_Charge_Duty:
				motor_control_ppd.ppd_detect_rising_tick = rx_data;
				break;

			case parm_PPD_Discharge_Percent:
				motor_control_ppd.ppd_detect_falling_tick = rx_data;
				break;

			case parm_PPD_Pulse_Counts:
				motor_control_ppd.ppd_detect_count = rx_data;
				break;

			case parm_PPD_Smooth_Count_Target:
				motor_control_ppd.ppd_smooth_count_target = rx_data;
				break;

			case parm_PPD_Tune_Duty_Ramp:
				motor_control_ppd.ppd_tune_duty_ramp = rx_data;
				motor_control_ppd.ipd_tune_duty = rx_data;
				break;

			case parm_PPD_Tuning_Last_Count:
				motor_control_ppd.ppd_tuning_last_count = rx_data;
				break;

			case parm_PPD_Test_Mode:
				motor_control_ppd.ppd_test_mode_on = rx_data;
				break;
#endif

			case parm_Current_Cutoff_Freq:
				motor_ptr->Iq_filter_gain = rx_data;
				break;

			case control_mode_select_number:
				motor_ptr->control_mode_select_number = rx_data;
				break;

			case closed_loop_current_command:
				motor_ptr->closed_loop_current_command = rx_data;
				break;

			case coasting_timeout:
				motor_ptr->coasting_timeout = rx_data;
				break;

			default:
				status = host_write_error;
			}

			break;

		default:
			status = host_write_error; 									// Do not respond - invalid command
		}
	}

	uart_tx_buffer[2] = status;
	uart_tx_buffer[8] = uart_checksum((uint8_t*)&uart_tx_buffer);		// Calculate checksum for outgoing message

	return status;
}

static uint8_t uart_checksum(uint8_t* pBuffer)
{
	uint8_t checksum = 0;
	int i;

	for (i = 0; i < 8; i++)
		checksum += *pBuffer++;

	return checksum;
}

static void int_to_buffer(uint32_t data)
{
	uart_tx_buffer[4] = ((data >> 24) & 0xFF);
	uart_tx_buffer[5] = ((data >> 16) & 0xFF);
	uart_tx_buffer[6] = ((data >> 8)  & 0xFF);
	uart_tx_buffer[7] = (data & 0xFF);
}



void UART_IRQHandler(void)
{
	uint8_t int_type = PAC5XXX_UART->IIR.IID;
	uint8_t data = pac5xxx_uart_read();

	if (int_type == UARTIIR_IID_TX_HOLD_EMPTY)
	{
		pac5xxx_uart_write(uart_tx_buffer[uart_tx_byte_count++]);	// Send next byte from uart_tx_buffer

		if (uart_tx_byte_count == UART_MESSAGE_SIZE)				// Last byte of message to transmit
		{
			pac5xxx_uart_int_enable_THREI(0);						// Disable transmit interrupt
			pac5xxx_uart_int_enable_RDAI(1);						// Enable receive data interrupt for next incoming message
			uart_tx_byte_count = 0;
		}
	}
	else
	//else if (int_type == UARTIIR_IID_RX_DATA_AVAIL)				// TODO: Still not able to get this IID code...
	{
		if (uart_rx_byte_count == 0)								// For the first byte received, the start byte must be 0x89
		{
			if (data != 0x89)
				return;
		}

		uart_rx_buffer[uart_rx_byte_count++] = data;				// Store data in buffer and increment index

		if (uart_rx_byte_count == UART_MESSAGE_SIZE)				// Received all bytes of message
		{
			uart_message_process();									// Process incoming message in uart_rx_buffer and put response in uart_tx_buffer
			uart_rx_byte_count = 0;
			uart_tx_byte_count = 0;

			pac5xxx_uart_int_enable_RDAI(0);						// Disable receive data interrupt
			pac5xxx_uart_rx_fifo_reset();							// Reset RX FIFO, to clear RDAI interrupt

			pac5xxx_uart_int_enable_THREI(1);						// Enable transmit interrupt to send response to host
		}
	}
}
#endif


