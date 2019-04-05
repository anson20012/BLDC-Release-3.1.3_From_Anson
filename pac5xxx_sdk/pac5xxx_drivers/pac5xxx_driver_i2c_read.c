/**************************************************************************//**
 * @file     pac5xxx_driver_i2c_read.c
 * @brief    Perform I2C read
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

#include "pac5xxx_driver_i2c.h"

RAMFUNC_I2C int pac5xxx_i2c_master_read(uint8_t address, uint8_t *write_data, int bytes_to_write, uint8_t *read_data, int bytes_to_read)
{
	int i;

	/* Write bytes first */

	for (i = 0; i < bytes_to_write; i++)
	{
		/* Wait for bus TX register to be free */
		while (PAC5XXX_I2C->MTXDATA.REG_FULL_FLAG == 1);

		/* Send next byte of I2C data */
		PAC5XXX_I2C->MTXDATA.VAL = *write_data++;			/* Data to write */

		/* Write control register to initiate transfer */
		PAC5XXX_I2C->MCTRL.b = address;						/* XFER_TYPE = I2C Read */

		/* Test for register to be empty (indicating transfer is done) */
		while (PAC5XXX_I2C->MTXDATA.REG_FULL_FLAG == 1);

		/* Read status register for status of transfer */
		if (PAC5XXX_I2C->STATUS.w & 0xFFFF)
		{
			PAC5XXX_I2C->MCTRL.w = 0x400;
			return 1;
		}
	}

	// Read bytes

	/* Read bytes */

	for (i = 0; i < bytes_to_read; i++)
	{
		/* Wait for RX data register to be empty */
		while (!PAC5XXX_I2C->MRXDATA.REG_FULL_FLAG);

		/* Store byte */
		*read_data++ = PAC5XXX_I2C->MRXDATA.VAL;
	}

	return 0;
}

