
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

#ifndef BRAKING_CONTROL_H
#define BRAKING_CONTROL_H

#define BRAKING_SAMPLE_BEMF_TIME_COUNTS      20
#define BRAKING_INCREASE_PWM_COUNTS          5
#define BRAKING_DECREASE_PWM_COUNTS          10
#define BRAKING_VBUS_OVER_PERCENT            (0xAAAA)//(0x1999)
#define BRAKING_STOP_THRESHOLD_ADC_VALUE     25
#define BRAKING_STOP_DETECT_TIME_COUNTS      10
#define IN_BRAKING_STATE_TIMEOUT             160000
#define BRAKING_RESTART_WAIT_TIMES           2

void braking_init(void);
PAC5XXX_RAMFUNC void braking_PWM_control(uint16_t braking_depth);
PAC5XXX_RAMFUNC void braking_charge_vbus_control(void);
PAC5XXX_RAMFUNC void braking_detect_motor_state(void);

#endif
