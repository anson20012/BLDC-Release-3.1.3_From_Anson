/**************************************************************************//**
 * @file     pac5xxx_driver_spi_config_int.c
 * @brief    Firmware driver for the PAC5XXX SPI Peripheral
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

#include "pac5xxx_driver_spi.h"

RAMFUNC_SPI void pac5xxx_spi_int_enable(int enable)
{
	PAC5XXX_SPI->SPISTAT.s = 0xFF;   // write to clear any active interrupt flags
	PAC5XXX_SPI->SPICTL.SIE = enable;
}

RAMFUNC_SPI void pac5xxx_spi_int_enable_RDOFL(int enable)
{
	PAC5XXX_SPI->SPISTAT.RDOFL = 1; // Write to Clear
	PAC5XXX_SPI->SPIINT_EN.RDOFL_EN = enable;
}

RAMFUNC_SPI void pac5xxx_spi_int_enable_LE(int enable)
{   
	PAC5XXX_SPI->SPISTAT.LE = 1; // Write to Clear
	PAC5XXX_SPI->SPIINT_EN.LE_EN = enable;
}

RAMFUNC_SPI void pac5xxx_spi_int_enable_UCLK(int enable)
{
	PAC5XXX_SPI->SPISTAT.UCLK = 1; // Write to Clear
	PAC5XXX_SPI->SPIINT_EN.UCLK_EN = enable;
}

RAMFUNC_SPI void pac5xxx_spi_int_enable_CYC_DONE(int enable)
{
	PAC5XXX_SPI->SPISTAT.CYC_DONE = 1; // Write to Clear
	PAC5XXX_SPI->SPIINT_EN.CYC_DONE_EN = enable;
}

RAMFUNC_SPI void pac5xxx_spi_int_enable_TE(int enable)
{
	PAC5XXX_SPI->SPISTAT.TE = 1; // Write to Clear
	PAC5XXX_SPI->SPIINT_EN.TE_EN = enable;
}

RAMFUNC_SPI void pac5xxx_spi_int_enable_WRUFL(int enable)
{
	PAC5XXX_SPI->SPISTAT.WRUFL = 1; // Write to Clear
	PAC5XXX_SPI->SPIINT_EN.WRUFL_EN = enable;
}
