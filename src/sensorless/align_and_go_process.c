
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
/// @brief  This function align motor,then align go motor,when reach the switch speed
///         set point, switch into BEMF mode
/// @param  None
/// @return None
//===================================================================================
#ifndef SINE_WAVE_START_UP_ENABLE
void square_wave_start_up_process(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;


	switch (bldc_align_go.align_and_go_state)
	{
		case STATE_STARTUP_INIT:
			motor_ptr->app_status &= ~status_closed_loop;
			motor_ptr->app_status &= ~status_motor_stall;
			motor_ptr->app_status &= ~status_lose_angle;
			motor_ptr->app_status &= ~status_open_phase;

			bldc_align_go.go_step = 3;
			bldc_align_go.align_ticks_temp = 0;
			bldc_align_go.start_speed_ticks_temp = 0;
			bldc_align_go.current_speed_hz = 0;
			bldc_align_go.accel_rate_factor = 65536;          	//1Hz
			motor_ptr->auto_open_to_close_loop_sw_count = 0;


			// Initialize Speed
			motor_ptr->wait_30degree_enable = 0;
			motor_ptr->samplecounter = 0;
			motor_ptr->motorspeed_sum = 0;
			for (motor_ptr->speed_sample_index = 0; motor_ptr->speed_sample_index < NUM_SPEED_SAMPLES; motor_ptr->speed_sample_index++)
				motor_ptr->motorspeed_buffer[motor_ptr->speed_sample_index] = 0;
			motor_ptr->speed_sample_index = 0;
			pid_reset(&motor_ptr->speed_pid);

			bldc_align_go.align_and_go_state = STATE_STARTUP_ALIGN;
			break;

		case STATE_STARTUP_ALIGN:
			commutate(bldc_align_go.go_step);
			bldc_align_go.align_and_go_state = STATE_STARTUP_ALIGN_DELAY;
			break;

		case STATE_STARTUP_ALIGN_DELAY:
			// align delay
			if (bldc_align_go.align_ticks_temp++ > bldc_align_go.align_ticks)
		    {
				bldc_align_go.current_speed_hz = bldc_align_go.start_speed_hz;

    			// Perform first commutation after Align
    			if(motor_ptr->reverse_tune_flag)
    			{
    				bldc_align_go.go_step = 1;
    			}
				else
				{
					bldc_align_go.go_step = 5;
				}
    			commutate(bldc_align_go.go_step);
    			bldc_align_go.start_speed_ticks_period = HertzToTicks(bldc_align_go.current_speed_hz,TIMER_D_FREQ_F16);
    			PAC5XXX_TIMERD->PRD = bldc_align_go.start_speed_ticks_period ;
    			pac5xxx_timer_base_int_enable(TimerD, 1);
    			NVIC_EnableIRQ(TimerD_IRQn);
    			bldc_align_go.align_and_go_state = STATE_STARTUP_GO;
            }
            break;

		case STATE_STARTUP_GO:
			// Call this motor speed acceleration in open loop align and go mode
			// Convert ramp up-down rate to  current speed
			if (bldc_align_go.current_speed_hz < (bldc_align_go.switch_speed_hz + bldc_align_go.accel_rate_time_base))
				bldc_align_go.current_speed_hz += bldc_align_go.accel_rate_time_base;
			else if (bldc_align_go.current_speed_hz > (bldc_align_go.switch_speed_hz  - bldc_align_go.accel_rate_time_base))
				bldc_align_go.current_speed_hz -= bldc_align_go.accel_rate_time_base;
			else
				bldc_align_go.current_speed_hz = bldc_align_go.switch_speed_hz;


			bldc_align_go.start_speed_ticks_period = HertzToTicks(bldc_align_go.current_speed_hz,TIMER_D_FREQ_F16);
			PAC5XXX_TIMERD->PRD = bldc_align_go.start_speed_ticks_period ;


			motor_ptr->app_speed_ref = HertzToTicks(bldc_align_go.switch_speed_hz, TIMER_D_FREQ_F16) ;
			motor_ptr->app_measured_speed = HertzToTicks(bldc_align_go.current_speed_hz, TIMER_D_FREQ_F16) ;

			if (bldc_align_go.auto_acceleration_mode)
			{
				if (bldc_align_go.current_speed_hz >= bldc_align_go.switch_speed_hz)
			    {
			    	if (motor_ptr->auto_open_to_close_loop_sw_count++ >= OPEN_TO_CLOSE_LOOP_GOOD_SPEED_COUNT)
			    	{
			    		motor_ptr->auto_open_to_close_loop_sw_count = 0;
			    		PAC5XXX_TIMERD->PRD = (bldc_align_go.start_speed_ticks_period>>1) + (bldc_align_go.start_speed_ticks_period>>2);
			    		bldc_align_go.align_and_go_state = STATE_STARTUP_SWITCH_TO_BEMF;
                    }	    		
			    }
			    else
			    {
			    	motor_ptr->auto_open_to_close_loop_sw_count = 0;

			    }
			}
			else
		    {
		    	   motor_ptr->auto_open_to_close_loop_sw_count = 0;
		    }
			break;

		case STATE_STARTUP_SWITCH_TO_BEMF:
			motor_ptr->sl_current_state = bldc_align_go.go_step;
			ready_for_bemf_mode();
			bldc_align_go.align_and_go_state = STATE_STARTUP_DONE;
			get_zero_cross_point_state = STATE_TIMERC_BLANKING_CYCLE_TIME;
			break;

		case STATE_STARTUP_DONE:
			break;

		default:
			bldc_align_go.align_and_go_state = STATE_STARTUP_INIT;
			break;
	}
}
#endif

//===================================================================================
/// @brief  This function sine waveform start-up then switching into
///         BEMF mode
/// @param  None
/// @return None
//===================================================================================
#ifdef SINE_WAVE_START_UP_ENABLE
void sine_wave_start_up_process(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;


	switch (bldc_align_go.align_and_go_state)
	{
	case STATE_STARTUP_INIT:
		motor_ptr->app_status &= ~status_closed_loop;
		motor_ptr->app_status &= ~status_motor_stall;
		motor_ptr->app_status &= ~status_lose_angle;
		motor_ptr->app_status &= ~status_open_phase;

		bldc_align_go.go_step = 3;
		bldc_align_go.sine_wave_index = 0;
		bldc_align_go.align_ticks_temp = 0;
		bldc_align_go.start_speed_ticks_temp = 0;
		bldc_align_go.current_speed_hz = 0;
		motor_ptr->auto_open_to_close_loop_sw_count = 0;

		// Initialize Speed
		motor_ptr->wait_30degree_enable = 0;
		motor_ptr->samplecounter = 0;
		motor_ptr->motorspeed_sum = 0;
		for (motor_ptr->speed_sample_index = 0; motor_ptr->speed_sample_index < NUM_SPEED_SAMPLES; motor_ptr->speed_sample_index++)
			motor_ptr->motorspeed_buffer[motor_ptr->speed_sample_index] = 0;
		motor_ptr->speed_sample_index = 0;
		pid_reset(&motor_ptr->speed_pid);

		bldc_align_go.align_and_go_state = STATE_STARTUP_ALIGN;
		break;

	case STATE_STARTUP_ALIGN:
		bldc_align_go.sine_wave_index = 0;
		bldc_align_go.wave_pwm_duty_u = sine_wave_3phase[bldc_align_go.sine_wave_index][2];
		bldc_align_go.wave_pwm_duty_v = sine_wave_3phase[bldc_align_go.sine_wave_index][1];
		bldc_align_go.wave_pwm_duty_w = sine_wave_3phase[bldc_align_go.sine_wave_index][0];
		pwm_enable();
		bldc_align_go.align_and_go_state = STATE_STARTUP_ALIGN_DELAY;
		break;

	case STATE_STARTUP_ALIGN_DELAY:
		// align delay
		if (bldc_align_go.align_ticks_temp++ > bldc_align_go.align_ticks)
	    {
			bldc_align_go.current_speed_hz = bldc_align_go.start_speed_hz;
			bldc_align_go.start_speed_ticks_period = HertzToTicks(bldc_align_go.current_speed_hz,TIMER_D_FREQ_F16);
			bldc_align_go.start_speed_ticks_period = fix16_mul_new_16_16((bldc_align_go.start_speed_ticks_period<<16),6553)>>16;
			PAC5XXX_TIMERD->PRD = bldc_align_go.start_speed_ticks_period ;

			pac5xxx_timer_base_int_enable(TimerD, 1);
			NVIC_EnableIRQ(TimerD_IRQn);
			bldc_align_go.align_and_go_state = STATE_STARTUP_GO;
        }
        break;

	case STATE_STARTUP_GO:
		// Call this motor speed acceleration in open loop align and go mode
		// Convert ramp up-down rate to current speed
		if (bldc_align_go.current_speed_hz < (bldc_align_go.switch_speed_hz + bldc_align_go.accel_rate_time_base))
			bldc_align_go.current_speed_hz += bldc_align_go.accel_rate_time_base;
		else if (bldc_align_go.current_speed_hz > (bldc_align_go.switch_speed_hz  - bldc_align_go.accel_rate_time_base))
			bldc_align_go.current_speed_hz -= bldc_align_go.accel_rate_time_base;
		else
			bldc_align_go.current_speed_hz = bldc_align_go.switch_speed_hz;

		bldc_align_go.start_speed_ticks_period = HertzToTicks(bldc_align_go.current_speed_hz,TIMER_D_FREQ_F16);
		bldc_align_go.start_speed_ticks_period = fix16_mul_new_16_16((bldc_align_go.start_speed_ticks_period<<16),MATH_ZERO_DOT_ONE_FIX16)>>16;
		PAC5XXX_TIMERD->PRD = bldc_align_go.start_speed_ticks_period ;


		motor_ptr->app_speed_ref = HertzToTicks(bldc_align_go.switch_speed_hz, TIMER_D_FREQ_F16) ;
		motor_ptr->app_measured_speed = HertzToTicks(bldc_align_go.current_speed_hz, TIMER_D_FREQ_F16) ;

		if (bldc_align_go.auto_acceleration_mode)
		{
		    if (bldc_align_go.current_speed_hz >= bldc_align_go.switch_speed_hz)
		    {
		    	if (motor_ptr->auto_open_to_close_loop_sw_count++ >= OPEN_TO_CLOSE_LOOP_GOOD_SPEED_COUNT)
		    	{
		    		motor_ptr->auto_open_to_close_loop_sw_count = 0;
		    		PAC5XXX_TIMERD->PRD = (bldc_align_go.start_speed_ticks_period>>1) + (bldc_align_go.start_speed_ticks_period>>2);
		    		bldc_align_go.align_and_go_state = STATE_STARTUP_SWITCH_TO_BEMF;
                }
		    }
		    else
		    {
		    	 motor_ptr->auto_open_to_close_loop_sw_count = 0;
		    }
		}
		else
	    {
	    	   motor_ptr->auto_open_to_close_loop_sw_count = 0;
	    }
		break;

	case STATE_STARTUP_SWITCH_TO_BEMF:
		motor_ptr->sl_current_state = (fix16_mul_new_16_16((bldc_align_go.sine_wave_index<<16),MATH_ZERO_DOT_ONE_FIX16)>>16) + 1;
		ready_for_bemf_mode();
		bldc_align_go.align_and_go_state = STATE_STARTUP_DONE;
		get_zero_cross_point_state = STATE_TIMERC_BLANKING_CYCLE_TIME;
		break;

	case STATE_STARTUP_DONE:
		break;

	default:
		bldc_align_go.align_and_go_state = STATE_STARTUP_INIT;
		break;
	}
}
#endif

//===================================================================================
/// @brief  This function initialize some parameter and status before switching into
///         BEMF mode
/// @param  None
/// @return None
//===================================================================================
void ready_for_bemf_mode(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	fix16_t blanking_sample_counts_temp;


//	motor_ptr->sl_next_state = motor_ptr->sl_current_state;

	if(motor_ptr->reverse_tune_flag)
		motor_ptr->sl_next_state = slcomp_next_state_rev[motor_ptr->sl_current_state];	// Determine next state
	else
		motor_ptr->sl_next_state = slcomp_next_state[motor_ptr->sl_current_state];		// Determine next state

#ifndef USE_ADC_GET_BEMF_MODE_ENABLE
	pac5xxx_tile_register_write(ADDR_CFGAIO9, slcomp_mux[motor_ptr->sl_current_state]);		// MODE9[1:0] = 01b (CT Vfilt), OPT9[1:0] = 0bxx (AIO7), POL9 = 0 (act high), MUX[2:0] = n/a
#endif

	motor_ptr->motorspeed_buffer_blanking[0] = motor_ptr->app_measured_speed;
	motor_ptr->motorspeed_buffer_blanking[1] = motor_ptr->app_measured_speed;
	motor_ptr->speed_sample_index_blanking = 0;
	motor_ptr->motorspeed_sum_blanking = motor_ptr->app_measured_speed<<1;
	// Calculate automatic blanking time using motor last two commutation times using moving average filter
	blanking_sample_counts_temp = fix16_mul_new_16_16(RATIO_BW_TIMERC_FREQ_TIMERD_FREQ,(motor_ptr->motorspeed_sum_blanking<<16) );
	motor_ptr->blanking_sample_counts = fix16_mul_new_16_16(blanking_sample_counts_temp,motor_ptr->motor_auto_blank_percent ) >> 16;

	// Disable timer D
	PAC5XXX_TIMERD->CTL.SYNC = 0; // Be sure to set sync bit first
	PAC5XXX_TIMERD->PRD = TIMERD_TICKS_30DEG_PLL;
	PAC5XXX_TIMERD->CTL.MODE = TxCTL_MODE_DISABLED;
	PAC5XXX_TIMERD->CTL.CLR = 1;
	PAC5XXX_TIMERD->CTL.MODE = TxCTL_MODE_UP;
	PAC5XXX_TIMERD->CTL.CLR = 0;

	NVIC_EnableIRQ(TimerC_IRQn);
}


