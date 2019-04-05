
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


//======================================================================================================================
/// @brief  This is the interrupt handler for Timer D, which gets serviced 30 degrees after zero crossing.
///		   When this interrupt is serviced, it will set the current state to the next state.  The current
///		   state needs to change to the next state 30 degrees after the zero crossing has been detected.
///		   In this interrupt, mos state commutate, calculate speed and blanking time
/// @param  None
/// @return None
//======================================================================================================================
PAC5XXX_RAMFUNC void TimerD_IRQHandler(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
	volatile fix16_t temp_auto_blanking_fix16;


	if(PAC5XXX_TIMERD->CCTRL0.CCINT == 1)// cctrl0.ccint==1 is eq to check. cctrl0.ccint=1 is eq to clears interrupt flag.
	{
		// Only do call commutation when this is set, flag is set inside zero cross detection function
		if (motor_ptr->wait_30degree_enable)
		{
			motor_ptr->wait_30degree_enable = 0;
			motor_ptr->sl_current_state = motor_ptr->sl_next_state;								// Change current state to the next state

			if(motor_ptr->reverse_tune_flag)
				motor_ptr->sl_next_state = slcomp_next_state_rev[motor_ptr->sl_current_state];	// Determine next state
			else
				motor_ptr->sl_next_state = slcomp_next_state[motor_ptr->sl_current_state];		// Determine next state

			// Here we update state variable associated bemf state and call commutaion function
			if(bldc_align_go.align_and_go_state == STATE_STARTUP_DONE)
			{
				commutate(motor_ptr->sl_current_state);
				motor_ptr->call_speed_loop_delay_count++;
				#ifdef LOSE_ANGLE_RESTART
				motor_ptr->motor_lose_angle_count = 0;
				#endif
			}

//			pac5xxx_tile_register_write(ADDR_CFGAIO9, slcomp_mux[motor_ptr->sl_current_state]);	// MODE9[1:0] = 01b (CT Vfilt), OPT9[1:0] = 0bxx (AIO7), POL9 = 0 (act high), MUX[2:0] = n/a
			#ifndef USE_ADC_GET_BEMF_MODE_ENABLE
				pac5xxx_tile_register_write(ADDR_CFGAIO9, slcomp_mux[motor_ptr->sl_current_state]);	// MODE9[1:0] = 01b (CT Vfilt), OPT9[1:0] = 0bxx (AIO7), POL9 = 0 (act high), MUX[2:0] = n/a
			#endif
			
			









			// Do calculation for 6 sample moving average filter used for speed PI
			motor_ptr->motorspeed_sum -= motor_ptr->motorspeed_buffer[motor_ptr->speed_sample_index];
			motor_ptr->motorspeed_buffer[motor_ptr->speed_sample_index] = motor_ptr->motorspeed;
			motor_ptr->motorspeed_sum += motor_ptr->motorspeed;
			// Do rest of 6 sample moving average filter speed calculation
			motor_ptr->motor_speed_sum_fix16 = fix16_from_int(motor_ptr->motorspeed_sum);
			motor_ptr->motor_speed_sum_fix16 = fix16_mul_new_16_16(motor_ptr->motor_speed_sum_fix16, MATH_ONE_DIV_SIX_FIX16);
			motor_ptr->average_speed = motor_ptr->motor_speed_sum_fix16 >> 16;
			motor_ptr->app_measured_speed = motor_ptr->average_speed;

			// If we max out array index reset it to 0
			if (++motor_ptr->speed_sample_index >= NUM_SPEED_SAMPLES)
				motor_ptr->speed_sample_index = 0;


			// Calculate automatic blanking time using motor last two commutation times using moving average filter
			temp_auto_blanking_fix16 = fix16_mul_new_16_16(RATIO_BW_TIMERC_FREQ_TIMERD_FREQ, motor_ptr->motorspeed_sum_blanking_fix16);
			temp_auto_blanking_fix16 = fix16_mul_new_16_16(temp_auto_blanking_fix16, motor_ptr->motor_auto_blank_percent);
			motor_ptr->blanking_sample_counts = temp_auto_blanking_fix16 >> 16;

			// Reset blanking time temp variable
			motor_ptr->commutation_blanking_time = 0;
			get_zero_cross_point_state = STATE_TIMERC_BLANKING_CYCLE_TIME;


			NVIC_EnableIRQ(TimerC_IRQn);
			NVIC_DisableIRQ(TimerD_IRQn);
		}
		//  Clear interrupt flag before exit
		pac5xxx_timer_d_cctrl_0_int_clear();
	}

	if(PAC5XXX_TIMERD->CTL.INT == 1)
	{
		#ifndef PPD_START_UP_ENABLE
		if((bldc_align_go.align_and_go_state == STATE_STARTUP_GO)||(bldc_align_go.align_and_go_state == STATE_STARTUP_SWITCH_TO_BEMF))
		{
			//sine wave start up ,look table and change duty cycle
			#ifdef SINE_WAVE_START_UP_ENABLE
				if(motor_ptr->reverse_tune_flag)
				{
					if(bldc_align_go.sine_wave_index > SINE_WAVE_ARRAY_INDEX_MIN)
					{
						bldc_align_go.sine_wave_index -= 1;
					}
					else
					{
						bldc_align_go.sine_wave_index = SINE_WAVE_ARRAY_INDEX_MAX;
					}
				}
				else
				{
					if(bldc_align_go.sine_wave_index < SINE_WAVE_ARRAY_INDEX_MAX)
					{
						bldc_align_go.sine_wave_index += 1;
					}
					else
					{
						bldc_align_go.sine_wave_index = SINE_WAVE_ARRAY_INDEX_MIN;
					}
				}
				bldc_align_go.wave_pwm_duty_u = sine_wave_3phase[bldc_align_go.sine_wave_index][2];
				bldc_align_go.wave_pwm_duty_v = sine_wave_3phase[bldc_align_go.sine_wave_index][1];
				bldc_align_go.wave_pwm_duty_w = sine_wave_3phase[bldc_align_go.sine_wave_index][0];
			#else
				//square wave start up ,commutate
				if(motor_ptr->reverse_tune_flag)
				{
					bldc_align_go.go_step -= 1;
					if (bldc_align_go.go_step <= 0)
						bldc_align_go.go_step = 6;
				}
				else
				{
					bldc_align_go.go_step += 1;
					if (bldc_align_go.go_step > 6)
						bldc_align_go.go_step = 1;
				}
				commutate(bldc_align_go.go_step);
			#endif
				// Clear interrupt flag before exit
		}
		#endif
		PAC5XXX_TIMERD->CTL.INT = 1;
	}
}
