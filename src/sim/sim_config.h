
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

#ifndef SIM_CONFIG_H
#define SIM_CONFIG_H

#include "include.h"


#define  SIM_EACH_PHASE_BEMF_DELTA_THRESHOLD    5
#define  SIM_DETECT_PERIOD_COUNTS               10

#define  SIM_MOTOR_FORWARD           1
#define  SIM_MOTOR_BACKWARD          0
#define  SIM_MOTOR_DEFAULT           0xFF

#define  U_PHASE_OVER_CENTER_POINT    0x01
#define  V_PHASE_OVER_CENTER_POINT    0x02
#define  W_PHASE_OVER_CENTER_POINT    0x04

#define  VDD2P5DIV1023MUL5FIX16       800           //(2*(2.5/0.4/1023))<<16


extern Sim_Detect  bldc_sim_m1;
extern const uint8_t sim_to_mos_state[];
extern const uint8_t sim_to_mos_state_rev[];

PAC5XXX_RAMFUNC void sim_variable_init(void);
PAC5XXX_RAMFUNC void sim_bemf_adc_read(void);
PAC5XXX_RAMFUNC void sim_detect_move_or_stop(void);
PAC5XXX_RAMFUNC void sim_detect_bemf_position(void);
PAC5XXX_RAMFUNC void sim_detect_direction(void);
PAC5XXX_RAMFUNC void sim_mos_state_and_pwm_duty(void);
PAC5XXX_RAMFUNC void sim_into_bemf_mode(void);
PAC5XXX_RAMFUNC void sim_process(void);

#endif
