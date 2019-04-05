
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


uint16_t	speed_ctr_adc_value_sum = 0;
uint16_t	speed_ctr_adc_value_average = 0;
fix16_t		speed_ctr_adc_hz_fix16;
uint16_t	speed_adc_index;

//===================================================================================
/// @brief  This function get adc value and transform to speed reference
/// @param  None
/// @return None
//===================================================================================
void get_speed_ctr_adc_cmd(void)
{
#ifdef SPEED_CTR_ADC_CMD_ENABLE
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
	fix16_t	speed_adc_temp_fix16;

	if(speed_adc_index < 8)
	{
		speed_adc_index++;
		speed_ctr_adc_value_sum += PAC5XXX_ADC->AS0R5.VAL;
	}
	else
	{
		speed_adc_index = 0;
		speed_ctr_adc_value_average = speed_ctr_adc_value_sum>>3 ;
		speed_adc_temp_fix16 = speed_ctr_adc_value_average;
		speed_adc_temp_fix16 = fix16_div((speed_adc_temp_fix16<<16),FULL_ADC_VALUE);
		speed_ctr_adc_hz_fix16 = fix16_mul_new_16_16(speed_adc_temp_fix16,SPEED_CTR_ADC_CMD_MAX);
		motor_ptr->motor_close_loop_speed = speed_ctr_adc_hz_fix16;
		speed_ctr_adc_value_sum = 0;
	}


	if(speed_ctr_adc_value_average >= ENABLE_MOTOR_ADC_VALUE)
	{
		motor_ptr->motor_enable_cmd = ENABLE;
	}

	if(speed_ctr_adc_value_average <= DISABLE_MOTOR_ADC_VALUE)
	{
		motor_ptr->motor_enable_cmd = DISABLE;
	}
#endif
}
