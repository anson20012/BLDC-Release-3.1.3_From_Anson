
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



// Copy "Hall to Mos Array" number that display on GUI here
const uint8_t hall_to_mos_state[] = {9,5,1,6,3,4,2,9};






Hall_Sensor bldc_hall_sensor_m1;

// Hall detect in CL
uint32_t debug_Array_1[8] = {9,9,9,9,9,9,9,9};

uint8_t next_mos_state[8] = {9,2,3,4,5,6,1,9};
uint8_t next_mos_state_rev[8] = {9,6,1,2,3,4,5,9};
//=============================================================================
/// @brief  This function store Hall value,in order to display on GUI
/// @param  None
/// @return None
//=============================================================================
#if defined(Hall_MODE_ENABLE)||defined(Hall_Detect_IN_BEMF_MODE)
PAC5XXX_RAMFUNC void hall_detect_array_display_on_gui(void)
{
	Hall_Sensor* hall_ptr;
	hall_ptr = &bldc_hall_sensor_m1;

	hall_ptr->hall_to_mos_state_detect =
								10000000 * debug_Array_1[0] +
								1000000 * debug_Array_1[1] +
								100000 * debug_Array_1[2] +
								10000 * debug_Array_1[3] +
								1000 * debug_Array_1[4] +
								100 * debug_Array_1[5] +
								10 * debug_Array_1[6] +
								1 * debug_Array_1[7];
}
#endif

//=============================================================================
/// @brief  This function study hall,and store
/// @param  None
/// @return None
//=============================================================================
#if defined(Hall_MODE_ENABLE)||defined(Hall_Detect_IN_BEMF_MODE)
PAC5XXX_RAMFUNC void hall_detect_in_bemf_mode(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
	Hall_Sensor* hall_ptr;
	hall_ptr = &bldc_hall_sensor_m1;

	hall_ptr->hall_value = HALL_VALUE_GPIO;

	debug_Array_1[hall_ptr->hall_value] = motor_ptr->sl_current_state;
	hall_detect_array_display_on_gui();
}
#endif

//=============================================================================
/// @brief  This function get hall value,then commutate
/// @param  None
/// @return None
//=============================================================================
#if defined(Hall_MODE_ENABLE)||defined(Hall_BEMF_SWITCH_MODE_ENABLE)
PAC5XXX_RAMFUNC void get_hall_value_and_change_mos_state(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
	Hall_Sensor* hall_ptr;
	hall_ptr = &bldc_hall_sensor_m1;


	hall_ptr->hall_value = HALL_VALUE_GPIO;
	if((hall_ptr->hall_value == ERRO_HALL_VALUE_0)||(hall_ptr->hall_value == ERRO_HALL_VALUE_7))
	{
		pwm_disable();
		motor_ptr->motor_enable_cmd = DISABLE;
		main_machine_state = STATE_MAIN_STOP_STANDBY;
		motor_ptr->app_status |= status_hall_error;
	}


	if(!motor_ptr->reverse_tune_flag)
	{
		hall_ptr->sensored_current_state = hall_to_mos_state[hall_ptr->hall_value];
	}
	else
	{
		hall_ptr->sensored_current_state = hall_to_mos_state[7-hall_ptr->hall_value];
	}

	if(control_machine_state == STATE_CONTROL_OL_SWITCH_CL_WAIT)
	{
		commutate(hall_ptr->sensored_current_state);
	}


	if((next_mos_state[hall_ptr->sensored_current_state_pre] == hall_ptr->sensored_current_state)||\
		(next_mos_state_rev[hall_ptr->sensored_current_state_pre] == hall_ptr->sensored_current_state))
	{
		motor_ptr->call_speed_loop_delay_count++;

		commutate(hall_ptr->sensored_current_state);


		// Calculate motor speed average
		// Read last commutation value from timer D
		motor_ptr->motorspeed = PAC5XXX_TIMERD->CTR;	// Determine motor speed to calculate 30 degree delay
		// Disable timer D
		PAC5XXX_TIMERD->CTL.SYNC = 0; // Be sure to set sync bit first
		PAC5XXX_TIMERD->PRD = TIMERD_TICKS_30DEG_PLL;
		PAC5XXX_TIMERD->CTL.MODE = TxCTL_MODE_DISABLED;
		PAC5XXX_TIMERD->CTL.CLR = 1;
		PAC5XXX_TIMERD->CTL.MODE = TxCTL_MODE_UP;
		PAC5XXX_TIMERD->CTL.CLR = 0;

		// Do calculation for 6 sample moving average filter used for speed PI
		motor_ptr->motorspeed_sum -= motor_ptr->motorspeed_buffer[motor_ptr->speed_sample_index];
		motor_ptr->motorspeed_buffer[motor_ptr->speed_sample_index] = motor_ptr->motorspeed;
		motor_ptr->motorspeed_sum += motor_ptr->motorspeed;

		// Do rest of 6 sample moving average filter speed calculation
		motor_ptr->motor_speed_sum_fix16 = fix16_from_int(motor_ptr->motorspeed_sum);
		motor_ptr->motor_speed_sum_fix16 = fix16_mul_new_16_16(motor_ptr->motor_speed_sum_fix16, MATH_ONE_DIV_SIX_FIX16);
		motor_ptr->motor_speed_sum_fix16 = motor_ptr->motor_speed_sum_fix16 >> 16;
		motor_ptr->average_speed = motor_ptr->motor_speed_sum_fix16;
		motor_ptr->app_measured_speed = motor_ptr->average_speed;

		// If we max out array index reset it to 0
		motor_ptr->speed_sample_index++;
		if (motor_ptr->speed_sample_index >= NUM_SPEED_SAMPLES)
			motor_ptr->speed_sample_index = 0;


		#ifdef LOSE_ANGLE_RESTART
		motor_ptr->motor_lose_angle_count = 0;
		#endif
	}

	hall_ptr->sensored_current_state_pre = hall_ptr->sensored_current_state;
}
#endif

//=============================================================================
/// @brief  This function low speed use hall,high speed use bemf
/// @param  None
/// @return None
//=============================================================================
#ifdef 	Hall_BEMF_SWITCH_MODE_ENABLE
PAC5XXX_RAMFUNC void hall_bemf_switch_mode(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
	Hall_Sensor* hall_ptr;
	hall_ptr = &bldc_hall_sensor_m1;
	fix16_t blanking_sample_counts_temp;

	hall_ptr->hall_bemf_switch_speed = HertzToTicks(bldc_align_go.switch_speed_hz, TIMER_D_FREQ_F16)>>1 ;
	switch(hall_bemf_switch_state)
	{
		case STATE_HALL_STARTUP:
			get_hall_value_and_change_mos_state();
			if(motor_ptr->app_measured_speed <= (hall_ptr->hall_bemf_switch_speed - HALL_BEMF_SWISH_SPEED_OFFSET))
			{
				motor_ptr->sl_current_state = hall_ptr->sensored_current_state;

				PAC5XXX_TIMERD->PRD = TIMERD_TICKS_30DEG_PLL;
			    PAC5XXX_TIMERD->CTL.INTEN = 0;
				NVIC_EnableIRQ(TimerC_IRQn);
				NVIC_EnableIRQ(TimerD_IRQn);
				pac5xxx_timer_d_clear_assert();													// Clear timer
				pac5xxx_timer_d_clear_deassert();
				motor_ptr->sl_next_state = motor_ptr->sl_current_state;
				pac5xxx_tile_register_write(ADDR_CFGAIO9, slcomp_mux[motor_ptr->sl_current_state]);		// MODE9[1:0] = 01b (CT Vfilt), OPT9[1:0] = 0bxx (AIO7), POL9 = 0 (act high), MUX[2:0] = n/a
				motor_ptr->samplecounter = 0;
				motor_ptr->wait_30degree_enable = 1;
				motor_ptr->motorspeed_buffer_blanking[0] = motor_ptr->app_measured_speed;
				motor_ptr->motorspeed_buffer_blanking[1] = motor_ptr->app_measured_speed;
				motor_ptr->speed_sample_index_blanking = 0;
				motor_ptr->motorspeed_sum_blanking = motor_ptr->app_measured_speed << 1;
				/* Calculate automatic blanking time using motor last two commutation times using moving average filter */
				blanking_sample_counts_temp = fix16_mul_new_16_16(RATIO_BW_TIMERC_FREQ_TIMERD_FREQ,(motor_ptr->motorspeed_sum_blanking<<16) );
				motor_ptr->blanking_sample_counts = fix16_mul_new_16_16(blanking_sample_counts_temp,motor_ptr->motor_auto_blank_percent ) >> 16;


				bldc_align_go.align_and_go_state = STATE_STARTUP_DONE;
				get_zero_cross_point_state = STATE_TIMERC_BLANKING_CYCLE_TIME;
				hall_bemf_switch_state = STATE_HALL_SWITCH_TO_BEMF;
			}
			break;
		case STATE_HALL_SWITCH_TO_BEMF:
			get_zero_crossing_point();
			break;
		default:
			break;
	}
}
#endif
