/**************************************************************************//**
 * @file     pac5xxx_driver_rtc_clear_if.c
 * @brief    Firmware driver for the PAC5XXX Watchdog Timer
 *
 * @note
 * Copyright (C) 2015, Active-Semi International
 *
 * THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
 * AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
 * APPLICATION TO PAC PROCESSORS SUPPLIED BY ACTIVE-SEMI INTERNATIONAL;
 * (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
 * ACTIVE-SEMICONDUCTOR IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
 * DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
 * ONLY BY CERTAIN AUTHORIZED PERSONS.
 *
 ******************************************************************************/

#include "pac5xxx_driver_rtc.h"

RAMFUNC_RTC void pac5xxx_rtc_clear_if()
{
	uint32_t word;

	word = (PAC5XXX_RTC->RTCCTL & 0x0000FFF8) | (RTCCTL_PASS_WRITE | RTCCTL_IF_MASK | RTCCTL_RST_VAL);

	RTC_WAIT_WRITE_BLOCK;   // Blocking wait for register write

	PAC5XXX_RTC->RTCCTL = word;
}



