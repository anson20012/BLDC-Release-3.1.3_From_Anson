
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


// Commutation state table with Analog MAUX setting
const uint8_t slcomp_mux[7] = { 0, SLCOMP9 | 0xC0, SLCOMP8 | 0xC0, SLCOMP7 | 0xC0, SLCOMP9 | 0xC0, SLCOMP8 | 0xC0, SLCOMP7 | 0xC0 };
const uint8_t slcomp_next_state[7] = { 0, 2, 3, 4, 5, 6, 1 };
const uint8_t slcomp_last_state[7] = { 0, 6, 1, 2, 3, 4, 5 };
const uint8_t slcomp_cross_polarity[7] = { 0, AIO9_HIGH2LOW, AIO8_LOW2HIGH, AIO7_HIGH2LOW, AIO9_LOW2HIGH, AIO8_HIGH2LOW, AIO7_LOW2HIGH };//POLx = 0,active High
const uint8_t slcomp_next_state_rev[7] = { 0, 6, 1, 2, 3, 4, 5 };	//reverse
const uint8_t slcomp_last_state_rev[7] = { 0, 2, 3, 4, 5, 6, 1 };
const uint8_t slcomp_cross_polarity_rev[7] = { 0, AIO9_LOW2HIGH, AIO8_HIGH2LOW, AIO7_LOW2HIGH, AIO9_HIGH2LOW, AIO8_LOW2HIGH, AIO7_HIGH2LOW };	//reverse
const uint8_t aio789_adc_to_slcomp_state[] = {9,1,1,0,1,0,0,9};



//===================================================================================
/// @brief  This function sample the state of the sensorless phase voltage adc value and
///         determines if a zero crossing has occured.  If a zero-crossing occurs
///         the 30 degree timer is started which will determine when the state change
///         should occur.
/// @param  None
/// @return None
//===================================================================================
PAC5XXX_RAMFUNC void adc_get_rotor_position(void)
{
#ifdef USE_ADC_GET_BEMF_MODE_ENABLE
	Hall_Sensor* hall_ptr;
	hall_ptr = &bldc_hall_sensor_m1;

	pwm_dac_debug_variable.aio7_adc_value_fix16 = BRAKING_BEMF_AIO7_ADC<<16;
	pwm_dac_debug_variable.aio8_adc_value_fix16 = BRAKING_BEMF_AIO8_ADC<<16;
	pwm_dac_debug_variable.aio9_adc_value_fix16 = BRAKING_BEMF_AIO9_ADC<<16;
	pwm_dac_debug_variable.centre_adc_value_fix16 = fix16_mul_new_16_16(((BRAKING_BEMF_AIO7_ADC + BRAKING_BEMF_AIO8_ADC + BRAKING_BEMF_AIO9_ADC)<<16),0x5555);

	if(pwm_dac_debug_variable.aio7_adc_value_fix16 >=pwm_dac_debug_variable.centre_adc_value_fix16)
	{
		pwm_dac_debug_variable.sl_current_step_position |= 0x01;
	}
	else
	{
		pwm_dac_debug_variable.sl_current_step_position &= ~0x01;
	}

	if(pwm_dac_debug_variable.aio8_adc_value_fix16 >=pwm_dac_debug_variable.centre_adc_value_fix16)
	{
		pwm_dac_debug_variable.sl_current_step_position |= 0x02;
	}
	else
	{
		pwm_dac_debug_variable.sl_current_step_position &= ~0x02;
	}

	if(pwm_dac_debug_variable.aio9_adc_value_fix16 >=pwm_dac_debug_variable.centre_adc_value_fix16)
	{
		pwm_dac_debug_variable.sl_current_step_position |= 0x04;
	}
	else
	{
		pwm_dac_debug_variable.sl_current_step_position &= ~0x04;
	}
	pwm_dac_debug_variable.phase_comparator_output = aio789_adc_to_slcomp_state[pwm_dac_debug_variable.sl_current_step_position];
#endif
}



//===================================================================================
/// @brief  This function polls the state of the sensorless comparators and
///         determines if a zero crossing has occured.  If a zero-crossing occurs
///         the 30 degree timer is started which will determine when the state change
///         should occur.
/// @param  None
/// @return None
//===================================================================================
PAC5XXX_RAMFUNC void get_zero_crossing_point(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;


#ifdef USE_ADC_GET_BEMF_MODE_ENABLE
	adc_get_rotor_position();
	motor_ptr->sample = pwm_dac_debug_variable.phase_comparator_output;
#else
	motor_ptr->sample = AIO789_COMP_OUTPUT;							// Sample sensorless comparator output on nIRQ2
//	motor_ptr->sample = ((pac5xxx_gpio_in_b() & NIRQ2_PIN_MASK) >> 7);							// Sample sensorless comparator output on nIRQ2
#endif
	
	
	switch(get_zero_cross_point_state)
	{
		case STATE_TIMERC_FIRST_SAMPLE:
		// Determine if state needs to change.  We look for the sampled comparator to trip to the expected level and
		// the we collect 3 consecutive samples before declaring BEMF zero crossing to filter out comparator chatter
			if(motor_ptr->reverse_tune_flag)													//reverse
			{
				if (motor_ptr->sample == slcomp_cross_polarity_rev[motor_ptr->sl_current_state])
				{
					motor_ptr->target_sample = motor_ptr->sample;											// Store good comm state
					get_zero_cross_point_state = STATE_TIMERC_GOOD_SAMPLES;
				}
			}
			else
			{
				if (motor_ptr->sample == slcomp_cross_polarity[motor_ptr->sl_current_state])
				{
					motor_ptr->target_sample = motor_ptr->sample;											// Store good comm state
					get_zero_cross_point_state = STATE_TIMERC_GOOD_SAMPLES;
				}
			}
			break;
		case STATE_TIMERC_GOOD_SAMPLES:
			if (motor_ptr->target_sample == motor_ptr->sample)
			{
				// Check is we received enough valid samples
				if ((++motor_ptr->samplecounter) >= motor_ptr->num_of_good_zc_samples)			// Increment sample counter
				{
					motor_ptr->timer_d_base_timer_first = PAC5XXX_TIMERD->CTR;					// Read last commutation value from timer D
					get_zero_cross_point_state = STATE_TIMERC_ZERO_CROSS_POINT;
				}
			}
			else
			{
				motor_ptr->samplecounter = 0;
				get_zero_cross_point_state = STATE_TIMERC_FIRST_SAMPLE;
			}
			break;
		case STATE_TIMERC_ZERO_CROSS_POINT:
			// Add time offset, determine motor speed to calculate 30 degree delay
			motor_ptr->motorspeed = motor_ptr->timer_d_base_timer_first + motor_ptr->timer_d_base_timer_offset;


			// do calculation for 2 sample moving average filter for motor automatic blanking time
			motor_ptr->motorspeed_sum_blanking -= motor_ptr->motorspeed_buffer_blanking[motor_ptr->speed_sample_index_blanking];
			motor_ptr->motorspeed_buffer_blanking[motor_ptr->speed_sample_index_blanking] = motor_ptr->motorspeed;
			motor_ptr->motorspeed_sum_blanking += motor_ptr->motorspeed;
			if (++motor_ptr->speed_sample_index_blanking >= NUM_SPEED_SAMPLES_BLANKING)
				motor_ptr->speed_sample_index_blanking = 0;
			motor_ptr->motorspeed_sum_blanking_fix16 = fix16_mul_new_16_16(fix16_from_int(motor_ptr->motorspeed_sum_blanking), 0x00008000);

			//========================================================================================================
			// Use to calculate commutation advanced delay
			// GUI sends a number from 0 to 60 which corresponds to 0 to 30 degrees in 0.5 degrees increment (GUI# / 2)
			// Commutation Advance Delay = motorspeed * half_degree_adv_delay_factor * GUI#
			// half_degree_adv_delay_factor = 0.00833333 = 1/2 * 1/60
			//========================================================================================================

			// Use 2 sample moving sample value or cycle to cycle commutation time for angle advanced
			motor_ptr->comm_advanced_delay_temp = fix16_mul_new_16_16(motor_ptr->motorspeed_sum_blanking_fix16, HALF_DEGREE_ADV_DLY);      // 60degree divide 120
			// Depending on bemf slope, go from low to high or coming form high to low different angle advanced value
			if (slcomp_cross_polarity[motor_ptr->sl_current_state])			//Polarity is HI (1)
			{
				motor_ptr->comm_advanced_delay_temp = fix16_mul_new_16_16(motor_ptr->comm_advanced_delay_temp, motor_ptr->commutation_advanced_rise);
			}
			else													//Polarity is LO (0)
			{
				motor_ptr->comm_advanced_delay_temp = fix16_mul_new_16_16(motor_ptr->comm_advanced_delay_temp, motor_ptr->commutation_advanced_fall);
			}

			// From fix16 convert it to back int for timer D counts
			motor_ptr->comm_advanced_delay = motor_ptr->comm_advanced_delay_temp >> 16;

			if (motor_ptr->comm_advanced_delay > 0)
			{
				// Do limit check on timer D value, it not suppose to exceed more the 50000
				if (motor_ptr->comm_advanced_delay > 50000)
				{
					motor_ptr->comm_advanced_delay = 50000;
				}
			}
			else
			{
				// If timer D calculated count is less the 0 then set it to 1
				motor_ptr->comm_advanced_delay = 1;
			}




		   // Initialize timer D for commutation time
			PAC5XXX_TIMERD->CTR0 = motor_ptr->comm_advanced_delay;
			PAC5XXX_TIMERD->CCTRL0.CCINT = 1;
			PAC5XXX_TIMERD->CCTRL0.CCINTEN = 1;

			motor_ptr->timer_d_base_timer_second = PAC5XXX_TIMERD->CTR;
			motor_ptr->timer_d_base_timer_offset = motor_ptr->timer_d_base_timer_second - motor_ptr->timer_d_base_timer_first;

			// Disable timer D
			PAC5XXX_TIMERD->CTL.SYNC = 0; // Be sure to set sync bit first
			PAC5XXX_TIMERD->PRD = TIMERD_TICKS_30DEG_PLL;
			PAC5XXX_TIMERD->CTL.MODE = TxCTL_MODE_DISABLED;
			PAC5XXX_TIMERD->CTL.CLR = 1;
			PAC5XXX_TIMERD->CTL.MODE = TxCTL_MODE_UP;
			PAC5XXX_TIMERD->CTL.CLR = 0;


			NVIC_DisableIRQ(TimerC_IRQn);
			NVIC_EnableIRQ(TimerD_IRQn);


			// for very high speed these variables need reset before we turn timer D start
			motor_ptr->samplecounter = 0;										// Reset sample counter
			motor_ptr->wait_30degree_enable = 1;


			#ifdef Hall_Detect_IN_BEMF_MODE
				hall_detect_in_bemf_mode();
			#endif
				get_zero_cross_point_state = STATE_TIMERC_WAIT_COMMUTATE;
			break;
		case STATE_TIMERC_WAIT_COMMUTATE:
			break;
		case STATE_TIMERC_BLANKING_CYCLE_TIME:
			// Only call zero cross check and process function when blanking time is over
			if (motor_ptr->commutation_blanking_time++ >= motor_ptr->blanking_sample_counts)
			{
				get_zero_cross_point_state = STATE_TIMERC_FIRST_SAMPLE;
			}
			break;
		default:
			break;
	}
}

