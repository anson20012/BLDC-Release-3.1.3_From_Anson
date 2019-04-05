
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

#ifndef HALL_H
#define HALL_H

#include "include.h"


#define HALL_START_COMMUTATE_VECTER_MUN     12
#define HALL_START_TO_BEMF_ONE_VECTER_DELAY_TIME    100
#define BEMF_TO_HALL_START_ONE_VECTER_DELAY_TIME    150
#define HALL_BEMF_SWISH_SPEED_OFFSET                100
#define ERRO_HALL_VALUE_0                             0
#define ERRO_HALL_VALUE_7                             7

extern Hall_Sensor     bldc_hall_sensor_m1;
extern const uint8_t  hall_to_mos_state[];


PAC5XXX_RAMFUNC void hall_detect_array_display_on_gui(void);
PAC5XXX_RAMFUNC void hall_detect_in_bemf_mode(void);
PAC5XXX_RAMFUNC void get_hall_value_and_change_mos_state(void);
PAC5XXX_RAMFUNC void hall_bemf_switch_mode(void);

#endif
