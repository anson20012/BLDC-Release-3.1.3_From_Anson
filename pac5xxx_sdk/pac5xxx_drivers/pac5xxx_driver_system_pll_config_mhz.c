/**************************************************************************//**
 * @file     pac5xxx_driver_system_pll_config_mhz.c
 * @brief    Configures and enables the PLL
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
#include "pac5xxx_driver_gpio.h"

RAMFUNC_SYSTEM void pac5xxx_sys_pll_config(int frequency_mhz)
{
	// Switch to the CLKREF input from internal oscillator, Configure FCLK /2, ACLK /1
	PAC5XXX_SYSCTL->CCSCTL.CLKIN = CCSCTL_CLKIN_CLKREF;

	// Turn off internal oscillator, we don't need it anymore
	pac5xxx_sys_osc_disable();

	// Enable PLL (carefully)

	//
	// PLLOUT = PLLIN * (PLLFD / (PLLID * PLLOD * 2))
	// Constraints:
	//   - PLLFD: 2-514
	//   - PLLID: 2-34
	//   - PLLOD: 0-16
	//
	// Configure PLL dividers: IN /2 [min], FDBK 100, OUT /1 [min]
	// should be PLLOUT at 100MHz: 4MHz * (100 / (2 * 100 * 2))
	pac5xxx_sys_pll_config_dividers(PLLCTL_INPUT_DIV(2), PLLCTL_FDBK_DIV(frequency_mhz), PLLCTL_OUTPUT_DIV(1));

	// SysTick is configured to use the reference clock (FRCLK)
	// The STCLK is CLKREF / 3, or 4MHz / 3 = 1.333MHz or 0.75us/tick. So to get a delay of 500us,
	// you need a count value of 500 / 0.75 = 666
	pac5xxx_sys_pll_enable(666);

	// Now we can switch to the PLLCLK for the ACLK and FCLK divider input
	pac5xxx_sys_ccs_pll_select();
}
