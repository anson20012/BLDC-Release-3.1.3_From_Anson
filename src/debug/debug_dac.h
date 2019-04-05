
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

#ifndef DEBUG_H
#define DEBUG_H

#define PWM_DEBUG_ARRAY_LENGTH 15          // max array index is 15, PWM debug variables can go from 0 to 14

typedef struct
{
	fix16_t *ptr1_value;
	fix16_t *ptr2_value;
}My_Debug_PWM_DAC;

extern fix16_t debug_scale_factor1;
extern fix16_t debug_scale_factor2;


extern My_Debug_PWM_DAC* test_ptr1;
extern My_Debug_PWM_DAC* test_ptr2;
extern My_Debug_PWM_DAC Test_PWM_FIX16 [PWM_DEBUG_ARRAY_LENGTH];

void debug_dac_init(void);
void bldc_send_data_set_out_using_pwm(void);
void pwm_dac_debug_variable_to_fix16(void);
#endif
