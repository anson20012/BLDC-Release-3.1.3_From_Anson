/**************************************************************************//**
 * @file     pac5xxx_driver_socbridge_config.c
 * @brief    Firmware driver for the PAC5XXX SOC Bridge
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

#include "pac5xxx_driver_socbridge.h"

RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_config(int enable, int int_enable)
{

	PAC5XXX_SOCBRIDGE->SOCBCTL.SETTO3 = 3;				// Need to set these bits to 3 for SOCBCTL write
	PAC5XXX_SOCBRIDGE->SOCBCTL.SIE = int_enable;		// Interrupts enabled

	PAC5XXX_SOCBRIDGE->SOCBCFG.SETTO3 = 3;				// Need to set these bits to 3 for SOCBCFG write
	PAC5XXX_SOCBRIDGE->SOCBCFG.SETTO0 = 0;				// Need to set this bit to 0 for SOCBCFG write

	PAC5XXX_SOCBRIDGE->SOCBCFG.WL = 1;                  // Set Word Length to 16 bits.

	PAC5XXX_SOCBRIDGE->SOCBCLKDIV.VAL = 1;   			// SPI CLK = 12.5 MHz = 50 MHz/ ((CLKDIV + 1) * 2)

	PAC5XXX_SOCBRIDGE->SOCBINT_EN.w = 0;				// Clear interrupt enables

	PAC5XXX_SOCBRIDGE->SOCBCTL.SSEN = enable;			// enable peripheral

}

RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_config_chip_select(unsigned char chip_select_setup,
										                  unsigned char chip_select_hold,
										                  unsigned char chip_select_wait)
{
	PAC5XXX_SOCBRIDGE->SOCBCSSTR.CSSETUP = chip_select_setup;
	PAC5XXX_SOCBRIDGE->SOCBCSSTR.CSHOLD = chip_select_hold;
	PAC5XXX_SOCBRIDGE->SOCBCSSTR.CSWAIT = chip_select_wait;
}

