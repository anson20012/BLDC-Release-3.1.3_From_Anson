/**************************************************************************//**
 * @file     pac5xxx_driver_watchdog_reset.c
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

RAMFUNC_WATCHDOG void pac5xxx_watchdog_reset()
{
  WDT_WAIT_WRITE_BLOCK;   // Blocking wait for register write
  
  PAC5XXX_WDT->WDTCTL = (PAC5XXX_WDT->WDTCTL & 0x00FFFFF8) | (WDTCTL_PASS_WRITE | WDTCTL_RST_VAL);
}

