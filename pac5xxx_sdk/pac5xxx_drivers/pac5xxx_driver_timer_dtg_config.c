/**************************************************************************//**
 * @file     pac5xxx_driver_timer_dtg_config.c
 * @brief    Firmware driver for the PAC5XXX DTG configuration
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

RAMFUNC_TIMER void pac5xxx_dtg_config(DtgInstance dtg, uint16_t led, uint16_t ted, int inv_a, int inv_b, int pass, int otp)
{
  volatile PAC5XXX_DTGCTL_TypeDef* pD;
  
  switch (dtg)
  {
  case DTGA0:
    pD = &PAC5XXX_TIMERA->DTGCTL0;
    PAC5XXX_TIMERA->DTGLED0 = led;
    PAC5XXX_TIMERA->DTGTED0 = ted;
    break;
  case DTGA1:
    pD = &PAC5XXX_TIMERA->DTGCTL1;
    PAC5XXX_TIMERA->DTGLED1 = led;
    PAC5XXX_TIMERA->DTGTED1 = ted;
    break;
  case DTGA2:
    pD = &PAC5XXX_TIMERA->DTGCTL2;
    PAC5XXX_TIMERA->DTGLED2 = led;
    PAC5XXX_TIMERA->DTGTED2 = ted;
    break;
  case DTGA3:
    pD = &PAC5XXX_TIMERA->DTGCTL3;
    PAC5XXX_TIMERA->DTGLED3 = led;
    PAC5XXX_TIMERA->DTGTED3 = ted;
    break;
  case DTGB:
    pD = &PAC5XXX_TIMERB->DTGCTL0;
    PAC5XXX_TIMERB->DTGLED0 = led;
    PAC5XXX_TIMERB->DTGTED0 = ted;
    break;
  case DTGC:
    pD = &PAC5XXX_TIMERC->DTGCTL0;
    PAC5XXX_TIMERC->DTGLED0 = led;
    PAC5XXX_TIMERC->DTGTED0 = ted;
    break;
  case DTGD:
    pD = &PAC5XXX_TIMERD->DTGCTL0;
    PAC5XXX_TIMERD->DTGLED0 = led;
    PAC5XXX_TIMERD->DTGTED0 = ted;
    break;
  }
  
  pD->INV_A = inv_a;
  pD->INV_B = inv_b;
  pD->OTP = otp;
  pD->BYPASS = pass;
}

RAMFUNC_TIMER void pac5xxx_dtg_clock_prescale(TimerInstance timer, int enabled)
{
  switch (timer)
  {
  case TimerA:
    PAC5XXX_TIMERA->CTL.DTGCLKDIVEN = enabled;
    break;
  case TimerB:
    PAC5XXX_TIMERB->CTL.DTGCLKDIVEN = enabled;
    break;
  case TimerC:
    PAC5XXX_TIMERC->CTL.DTGCLKDIVEN = enabled;
    break;
  case TimerD:
    PAC5XXX_TIMERD->CTL.DTGCLKDIVEN = enabled;
    break;
  }
}

