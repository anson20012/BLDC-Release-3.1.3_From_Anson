/**************************************************************************//**
 * @file     pac5xxx_driver_tile_socbridge_config.c
 * @brief    Firmware driver for the PAC5XXX tile configuration
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

RAMFUNC_TILE void pac5xxx_tile_socbridge_config(int enable, int int_enable)
{
	  // Configure SOC Bridge

	  pac5xxx_socbridge_config(enable, int_enable);      	// Enabled

	  pac5xxx_socbridge_config_chip_select(1,              	// CS setup time (clock cycles from assertion of chip select to first assertion of clock)
										   1,				// CS hold time (clock cycles from last assertion of clock to de-assertion of chip select)
										   5);          	// CS wait time (clock cycles between back to back transfers of data)

	  pac5xxx_socbridge_config_io();					    // Enable SPI IOs
}


