/**************************************************************************//**
 * @file     pac5xxx_driver_rtc_config.c
 * @brief    Firmware driver for the PAC5XXX Real-Time Clock
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

RAMFUNC_RTC void pac5xxx_rtc_config(int ie_en, uint32_t cdv, RTCCTL_PS_Type pre_scaler)
{
  // Read CTL word, clear interrupt bits, set write password and correct reset value
  uint32_t word = (PAC5XXX_RTC->RTCCTL & 0x00FFFC00) | RTCCTL_PASS_WRITE | RTCCTL_RST_VAL;

  word |= (pre_scaler << RTCCTL_PS_SHIFT); // Add pre-scale bits

  if (ie_en)
     word |= (RTCCTL_IE_MASK); //  | 0x20); // TODO: Add POR bit to IE mask

  RTC_WAIT_WRITE_BLOCK;   // Blocking wait for register write

  PAC5XXX_RTC->RTCCDV = (RTCCTL_PASS_WRITE | (cdv & 0x00FFFFFF));
  
  RTC_WAIT_WRITE_BLOCK;   // Blocking wait for register write
  
  PAC5XXX_RTC->RTCCTL = word;
  
}


