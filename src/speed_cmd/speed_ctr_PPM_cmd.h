
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

#ifndef SPEED_CTR_PPM_CMD_H
#define SPEED_CTR_PPM_CMD_H

#include "include.h"


#define SPEED_CTR_PPM_CMD_MAX			(400<<16)
#define ONE_SECOND_TIMERB_COUNTS		(0x2FAF0800)    // 0x2FAF0800 = (50M/64)<<10


extern	uint16_t	low2high_capture_read_count_value;
extern	uint16_t	high2low_capture_read_count_value;
extern	fix16_t		speed_ctr_PPM_duty_fix16;
extern	fix16_t		speed_ctr_PPM_freq_fix16;
extern	fix16_t		speed_ctr_PPM_hz_fix16;


void speed_ctr_PPM_init(void);
void get_speed_ctr_PPM_cmd(void);
#endif

