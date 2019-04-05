/**************************************************************************//**
 * @file     pac5xxx_driver_timer_cctrl_int.c
 * @brief    Firmware driver for the PAC5XXX capture/compare unit interrupt configuration
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

RAMFUNC_TIMER static volatile PAC5XXX_TIMERCC_TypeDef* timer_ccr_to_handle(TimerInstance timer, int cc_num)
{
  volatile PAC5XXX_TIMERCC_TypeDef* pCC = 0;
  
  switch (timer)
  {
  case TimerA:
    switch (cc_num)
    {
    case 0:
      pCC = &PAC5XXX_TIMERA->CCTRL0;
      break;
    case 1:
      pCC = &PAC5XXX_TIMERA->CCTRL1;
      break;
    case 2:
      pCC = &PAC5XXX_TIMERA->CCTRL2;
      break;
    case 3:
      pCC = &PAC5XXX_TIMERA->CCTRL3;
      break;
    case 4:
      pCC = &PAC5XXX_TIMERA->CCTRL4;
      break;
    case 5:
      pCC = &PAC5XXX_TIMERA->CCTRL5;
      break;
    case 6:
      pCC = &PAC5XXX_TIMERA->CCTRL6;
      break;
    case 7:
      pCC = &PAC5XXX_TIMERA->CCTRL7;
      break;
    }
    break;
    
  case TimerB:
    switch (cc_num)
    {
    case 0:
      pCC = &PAC5XXX_TIMERB->CCTRL0;
      break;
    case 1:
      pCC = &PAC5XXX_TIMERB->CCTRL1;
      break;
    case 2:
      pCC = &PAC5XXX_TIMERB->CCTRL2;
      break;
    case 3:
      pCC = &PAC5XXX_TIMERB->CCTRL3;
      break;
    }
    break;
    
  case TimerC:
    switch (cc_num)
    {
    case 0:
      pCC = &PAC5XXX_TIMERC->CCTRL0;
      break;
    case 1:
      pCC = &PAC5XXX_TIMERC->CCTRL1;
      break;
    }
    break;

  case TimerD:
    switch (cc_num)
    {
    case 0:
      pCC = &PAC5XXX_TIMERD->CCTRL0;
      break;
    case 1:
      pCC = &PAC5XXX_TIMERD->CCTRL1;
      break;
    }
    break;
  } 
  
  return pCC;
}

RAMFUNC_TIMER void pac5xxx_timer_cctrl_int_enable(TimerInstance timer, int ccr_num, int enable)
{
	volatile PAC5XXX_TIMERCC_TypeDef* pCC = timer_ccr_to_handle(timer, ccr_num);
	
	if (!pCC)
		return;
		
  	pCC->CCINT = 1; // write to clear
	pCC->CCINTEN = enable;
}

RAMFUNC_TIMER int pac5xxx_timer_cctrl_int(TimerInstance timer, int ccr_num)
{
  volatile PAC5XXX_TIMERCC_TypeDef* pCC = timer_ccr_to_handle(timer, ccr_num);
	
	if (!pCC)
		return 0;
		
  return (pCC->CCINT && pCC->CCINTEN);
}

RAMFUNC_TIMER void pac5xxx_timer_cctrl_int_clear(TimerInstance timer, int ccr_num)
{
  volatile PAC5XXX_TIMERCC_TypeDef* pCC = timer_ccr_to_handle(timer, ccr_num);
	
	if (!pCC)
		return;
		
  pCC->CCINT = 1;
}

