/**************************************************************************//**
 * @file     pac5xxx_driver_socbridge_data.c
 * @brief    Firmware driver for the PAC5XXX SOC Bridge data routines (soft version)
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

RAMFUNC_SOCBRIDGE uint8_t pac5xxx_socbridge_data_read_8b(uint8_t tx_data)
{
	uint8_t data;

	PAC5XXX_SOCBRIDGE->SOCBD.b = tx_data;

	// Wait for transmission to be complete
	while (!pac5xxx_socbridge_stat_CYC_DONE());
	PAC5XXX_SOCBRIDGE->SOCBSTAT.CYC_DONE = 0x1;

	data = PAC5XXX_SOCBRIDGE->SOCBD.b;

	return data;
}

