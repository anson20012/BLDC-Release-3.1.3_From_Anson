/**************************************************************************//**
 * @file     pac5xxx_driver_timer_clear.c
 * @brief    Firmware driver for the PAC5XXX base timer configuration
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

#include "pac5xxx_driver_timer.h"


RAMFUNC_TIMER void pac5xxx_timer_clear(TimerInstance timer, int assert)
{
  switch (timer)
  {
  case TimerA:
    PAC5XXX_TIMERA->CTL.CLR = assert;
    break;
  case TimerB:
    PAC5XXX_TIMERB->CTL.CLR = assert;
    break;
  case TimerC:
    PAC5XXX_TIMERC->CTL.CLR = assert;
    break;
  case TimerD:
    PAC5XXX_TIMERD->CTL.CLR = assert;
    break;
  }
}

