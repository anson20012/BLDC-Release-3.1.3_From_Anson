/**************************************************************************//**
 * @file     pac5xxx_driver_tile_socbridge_validate.c
 * @brief    Firmware driver for the PAC5XXX tile read/write registers validate via SOC Bridge
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

#include "pac5xxx_driver_tile.h"
#include "pac5xxx_driver_socbridge.h"

RAMFUNC_TILE int pac5xxx_tile_register_write_validate(uint8_t address, uint8_t data)
{
	pac5xxx_tile_register_write(address, data);

	if (pac5xxx_tile_register_read(address) != data)
		return 1;

	return 0;
}

