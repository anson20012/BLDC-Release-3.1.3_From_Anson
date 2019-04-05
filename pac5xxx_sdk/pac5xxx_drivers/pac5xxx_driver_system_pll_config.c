/**************************************************************************//**
 * @file     pac5xxx_driver_system_pll_config.c
 * @brief    Firmware driver for the PAC5XXX PLL
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

#include "pac5xxx_driver_system.h"

RAMFUNC_SYSTEM void pac5xxx_sys_pll_config_dividers(uint8_t input_div, uint16_t feedback_div, uint8_t output_div)
{
	PAC5XXX_SYSCTL->PLLCTL.PLLINDIV = input_div;
	PAC5XXX_SYSCTL->PLLCTL.PLLFBDIV = feedback_div;
	PAC5XXX_SYSCTL->PLLCTL.PLLOUTDIV = output_div;
}

RAMFUNC_SYSTEM void pac5xxx_sys_pll_enable(int delay)
{
  
  // Configure SysTick the number of SysTick clock ticks passed into this function.
  SysTick->LOAD = delay;
  SysTick->VAL = 0;
    
  // Enable PLL
  PAC5XXX_SYSCTL->PLLCTL.PLLEN = 1;
  
  // Enable SysTick timer countdown and set the clock to reference clock
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  
  // Wait until it reaches 0 and then return
  while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);
  
  
}

