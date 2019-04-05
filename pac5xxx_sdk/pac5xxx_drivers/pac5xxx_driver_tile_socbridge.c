/**************************************************************************//**
 * @file     pac5xxx_driver_tile_socbridge.c
 * @brief    Firmware driver for the PAC5XXX tile read/write registers via SOC Bridge
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

// To optimize only the tile write, force function in RAM by replacing RAMFUNC_TILE with PAC5XXX_RAMFUNC
RAMFUNC_TILE void pac5xxx_tile_register_write(uint8_t address, uint8_t data)
{

    // Write 16-bits containing Addr, R/W=1, Data
    // Format: Addr(15:9) | R/W(8) | Data(7:0)
    PAC5XXX_SOCBRIDGE->SOCBD.w = (address << 9) | (1 << 8) | data;

    // Wait for transmission to be complete
    while (!PAC5XXX_SOCBRIDGE->SOCBSTAT.CYC_DONE);
    PAC5XXX_SOCBRIDGE->SOCBSTAT.CYC_DONE = 0x1;
}

// To optimize only the tile read, force function in RAM by replacing RAMFUNC_TILE with PAC5XXX_RAMFUNC
RAMFUNC_TILE uint8_t pac5xxx_tile_register_read(uint8_t address)
{
    uint8_t data;

    // Write the Address to be read; R/W =0 and data is don't care
    // Format: Addr(15:9) | R/W(8) | Data(7:0)
    PAC5XXX_SOCBRIDGE->SOCBD.w = address << 9;

    // Wait for transmission to be complete
    while (!PAC5XXX_SOCBRIDGE->SOCBSTAT.CYC_DONE);
    PAC5XXX_SOCBRIDGE->SOCBSTAT.CYC_DONE = 0x1;

    // Read the data
    data = PAC5XXX_SOCBRIDGE->SOCBD.w;

    // Return read data
    return data;
}
