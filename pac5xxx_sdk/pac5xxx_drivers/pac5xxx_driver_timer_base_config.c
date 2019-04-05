/**************************************************************************//**
 * @file     pac5xxx_driver_timer_base_config.c
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

RAMFUNC_TIMER void pac5xxx_timer_base_config(TimerInstance timer, uint16_t period, int single_shot, TXCTRL_MODE_Type mode, int slave_sync)
{
  switch (timer)
  {
  case TimerA:
    PAC5XXX_TIMERA->CTL.SYNC = slave_sync; // Be sure to set sync bit first
    PAC5XXX_TIMERA->PRD = period;
    PAC5XXX_TIMERA->CTL.MODE = mode;
    
    if (single_shot)
      PAC5XXX_TIMERA->CTL.SS = 1;
    
    break;

  case TimerB:
    PAC5XXX_TIMERB->CTL.SYNC = slave_sync; // Be sure to set sync bit first
    PAC5XXX_TIMERB->PRD = period;
    PAC5XXX_TIMERB->CTL.MODE = mode;
    
    if (single_shot)
      PAC5XXX_TIMERB->CTL.SS = 1;
    
    break;

  case TimerC:
    PAC5XXX_TIMERC->CTL.SYNC = slave_sync; // Be sure to set sync bit first
    PAC5XXX_TIMERC->PRD = period;
    PAC5XXX_TIMERC->CTL.MODE = mode;
    
    if (single_shot)
      PAC5XXX_TIMERC->CTL.SS = 1;
    
    break;

  case TimerD:
    PAC5XXX_TIMERD->CTL.SYNC = slave_sync; // Be sure to set sync bit first
    PAC5XXX_TIMERD->PRD = period;
    PAC5XXX_TIMERD->CTL.MODE = mode;
    
    if (single_shot)
      PAC5XXX_TIMERD->CTL.SS = 1;
    
    break;
  }
}

