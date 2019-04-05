
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

#ifndef SPEED_CTR_ADC_CMD_H
#define SPEED_CTR_ADC_CMD_H

#include "include.h"


#define FULL_ADC_VALUE				(900<<16)
#define SPEED_CTR_ADC_CMD_MAX		(400<<16)
#define ENABLE_MOTOR_ADC_VALUE		100
#define DISABLE_MOTOR_ADC_VALUE	50

extern uint16_t		speed_ctr_adc_value_sum;
extern uint16_t		speed_ctr_adc_value_average;
extern fix16_t		speed_ctr_adc_hz_fix16;
extern uint16_t		speed_adc_index;


void get_speed_ctr_adc_cmd(void);
#endif

