/**************************************************************************//**
 * @file     pac5xxx_driver_system_ccs_config.c
 * @brief    Firmware driver for the PAC5XXX System Clock Control
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

#include "PAC5XXX_driver_system.h"

RAMFUNC_SYSTEM void pac5xxx_sys_ccs_config(CCSCTL_CLKIN_Type clock_select, CCSCTL_ACLKDIV_Type aclk_div, CCSCTL_HCLKDIV_Type fclk_div)
{
	PAC5XXX_SYSCTL->CCSCTL.CLKIN = clock_select;
	PAC5XXX_SYSCTL->CCSCTL.ACLKDIV = aclk_div;
	PAC5XXX_SYSCTL->CCSCTL.HCLKDIV = fclk_div;
}
