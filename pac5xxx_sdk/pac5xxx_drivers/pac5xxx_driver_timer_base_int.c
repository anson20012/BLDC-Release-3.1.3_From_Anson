/**************************************************************************//**
 * @file     pac5xxx_driver_timer_base_int.c
 * @brief    Firmware driver for the PAC5XXX base timer interrupt configuration
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

RAMFUNC_TIMER int pac5xxx_timer_base_int(TimerInstance timer)
{
  switch (timer)
  {
  case TimerA:
    return (PAC5XXX_TIMERA->CTL.INT && PAC5XXX_TIMERA->CTL.INTEN);
  case TimerB:
    return (PAC5XXX_TIMERB->CTL.INT && PAC5XXX_TIMERB->CTL.INTEN);
  case TimerC:
    return (PAC5XXX_TIMERC->CTL.INT && PAC5XXX_TIMERC->CTL.INTEN);
  case TimerD:
    return (PAC5XXX_TIMERD->CTL.INT && PAC5XXX_TIMERD->CTL.INTEN);
  default:
    return 0;
  }  
}

