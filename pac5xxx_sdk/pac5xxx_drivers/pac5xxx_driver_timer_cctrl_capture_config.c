/**************************************************************************//**
 * @file     pac5xxx_driver_timer_cctrl_capture_config.c
 * @brief    Firmware driver for the PAC5XXX capture/compare unit
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

  // 
  // GPIO settings for timer capture modules
  //
  // PWMA0 capture input: GPIOASEL0=01b (PA0)
  // PWMA1 capture input: GPIOASEL1=01b (PA1)
  // PWMA2 capture input: GPIOASEL2=01b (PA2)
  // PWMA3 capture input: GPIOASEL3=01b (PA3)
  // PWMA4 capture input: GPIOASEL6=01b (PA6)
  // PWMA5 capture input: GPIOASEL4=01b (PA4)
  // PWMA6 capture input: GPIOASEL5=01b (PA5)
  // PWMA7 capture input: GPIODSEL6=01b (PD6)
  //
  // PWMB0 capture input: GPIODSEL2=11b (PD2)
  // PWMB1 capture input: GPIODSEL3=11b (PD3)
  //
  // PWMC0 capture input: GPIOASEL4=10b (PA4)
  // PWMC1 capture input: GPIOASEL7=11b (PA7)
  //
  // PWMD0 capture input: GPIODSEL7=10b (PD7)
  // PWMD1 capture input: GPIODSEL4=01b (PD4)


RAMFUNC_TIMER void pac5xxx_timer_cctrl_capture_config(TimerInstance timer, int enabled, int cc_num, int int_en, TXCCTRL_CAPEDGE_Type cap_edge_det)
{
  volatile PAC5XXX_TIMERCC_TypeDef* pCC;
  
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
  
  // Configure CCTRL register
  
  pCC->CCINT = 1; // Write to clear
  pCC->CCINTEN = int_en;
  pCC->CCEDGE = cap_edge_det;
  pCC->CCMODE = enabled;
  
}


