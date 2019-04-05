/**************************************************************************//**
 * @file     pac5xxx_driver_watchdog_config.c
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

#include "pac5xxx_driver_watchdog.h"

RAMFUNC_WATCHDOG void pac5xxx_watchdog_config(int ie_en, int por_en, uint32_t cdv)
{
  // Read CTL word, clear IE, IF and POREN bits, set write password and correct reset value
  uint32_t word = (PAC5XXX_WDT->WDTCTL & 0x00FFFFC0) | WDTCTL_PASS_WRITE | WDTCTL_RST_VAL;

  WDT_WAIT_WRITE_BLOCK;   // Blocking wait for register write

  PAC5XXX_WDT->WDTCDV = (WDTCTL_PASS_WRITE | (cdv & 0x00FFFFFF));
  
  if (ie_en)
    word |= WDTCTL_IE_MASK;
  
  if (por_en)
    word |= WDTCTL_POREN_MASK;

  WDT_WAIT_WRITE_BLOCK;   // Blocking wait for register write
  
  PAC5XXX_WDT->WDTCTL = word;
  
}


