/**************************************************************************//**
 * @file     pac5xxx_driver_arm_sleep.c
 * @brief    Firmware driver for the PAC5XXX ARM sleep modes
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

#include "pac5xxx_driver_arm.h"

RAMFUNC_ARM void pac5xxx_arm_sleep_wfi()
{
  // Execute WFI to enter sleep mode
  __WFI();
}


RAMFUNC_ARM void pac5xxx_arm_sleep_wfe()
{
  // Execute WFE to enter sleep mode
  __WFE();
}

