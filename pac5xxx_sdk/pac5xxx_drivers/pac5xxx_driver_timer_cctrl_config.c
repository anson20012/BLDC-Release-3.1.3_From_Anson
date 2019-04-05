/**************************************************************************//**
 * @file     pac5xxx_driver_timer_cctrl_config.c
 * @brief    Firmware driver for the PAC5XXX capture/compare unit configuration
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

RAMFUNC_TIMER void pac5xxx_timer_cctrl_config(TimerInstance timer, int cc_num, uint16_t compare_value, int int_en)
{
  volatile PAC5XXX_TIMERCC_TypeDef* pCC;
  
  switch (timer)
  {
  case TimerA:
    switch (cc_num)
    {
    case 0:
      pCC = &PAC5XXX_TIMERA->CCTRL0;
      PAC5XXX_TIMERA->CTR0 = compare_value;
      break;
    case 1:
      pCC = &PAC5XXX_TIMERA->CCTRL1;
      PAC5XXX_TIMERA->CTR1 = compare_value;
      break;
    case 2:
      pCC = &PAC5XXX_TIMERA->CCTRL2;
      PAC5XXX_TIMERA->CTR2 = compare_value;
      break;
    case 3:
      pCC = &PAC5XXX_TIMERA->CCTRL3;
      PAC5XXX_TIMERA->CTR3 = compare_value;
      break;
    case 4:
      pCC = &PAC5XXX_TIMERA->CCTRL4;
      PAC5XXX_TIMERA->CTR4 = compare_value;
      break;
    case 5:
      pCC = &PAC5XXX_TIMERA->CCTRL5;
      PAC5XXX_TIMERA->CTR5 = compare_value;
      break;
    case 6:
      pCC = &PAC5XXX_TIMERA->CCTRL6;
      PAC5XXX_TIMERA->CTR6 = compare_value;
      break;
    case 7:
      pCC = &PAC5XXX_TIMERA->CCTRL7;
      PAC5XXX_TIMERA->CTR7 = compare_value;
      break;
    }
    break;
    
  case TimerB:
    switch (cc_num)
    {
    case 0:
      pCC = &PAC5XXX_TIMERB->CCTRL0;
      PAC5XXX_TIMERB->CTR0 = compare_value;
      break;
    case 1:
      pCC = &PAC5XXX_TIMERB->CCTRL1;
      PAC5XXX_TIMERB->CTR1 = compare_value;
      break;
    case 2:
      pCC = &PAC5XXX_TIMERB->CCTRL2;
      PAC5XXX_TIMERB->CTR2 = compare_value;
      break;
    case 3:
      pCC = &PAC5XXX_TIMERB->CCTRL3;
      PAC5XXX_TIMERB->CTR3 = compare_value;
      break;
    }
    break;
    
  case TimerC:
    switch (cc_num)
    {
    case 0:
      pCC = &PAC5XXX_TIMERC->CCTRL0;
      PAC5XXX_TIMERC->CTR0 = compare_value;
      break;
    case 1:
      pCC = &PAC5XXX_TIMERC->CCTRL1;
      PAC5XXX_TIMERC->CTR1 = compare_value;
      break;
    }
    break;

  case TimerD:
    switch (cc_num)
    {
    case 0:
      pCC = &PAC5XXX_TIMERD->CCTRL0;
      PAC5XXX_TIMERD->CTR0 = compare_value;
      break;
    case 1:
      pCC = &PAC5XXX_TIMERD->CCTRL1;
      PAC5XXX_TIMERD->CTR1 = compare_value;
      break;
    }
    break;
  } 

  pCC->CCINT = 1; // write to clear
  pCC->CCINTEN = int_en;
}

