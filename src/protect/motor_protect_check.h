
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

#ifndef MOTOR_PROTECT_CHECK_H
#define MOTOR_PROTECT_CHECK_H

#include "include.h"

#define STALL_CHECK_1_COUNTS						12
#define STALL_CHECK_2_COUNTS						3
#define STALL_ERROR_SPEED_COUNTS                   50
#define STALL_ERROR_PWM_DUTY_COUNTS                200

#define OVER_LOAD_KEEP_IQ                	        10
#define OVER_LOAD_KEEP_TIME_COUNTS                 6000
#define LOSE_ANGLE_TIME_COUNTS                     10

extern Pwm_Dac_Debug   pwm_dac_debug_variable;

extern uint16_t opd_u_phase_voltage;
extern uint16_t opd_v_phase_voltage;
extern uint16_t opd_w_phase_voltage;

extern uint8_t  stall_detect_keep_counts_1,stall_detect_keep_counts_2;
extern uint32_t over_load_keep_counts;



void vbus_voltage_Max_Min_protect(void);
void stall_check_1(void);
void stall_check_2(void);
void over_load_check(void);
void lose_angle_no_commutate_check(void);
void open_phase_detect(void);

#endif
