/**************************************************************************//**
 * @file     pac5xxx_driver_i2c_write.c
 * @brief    Firmware driver for the PAC5XXX I2C Peripheral
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

RAMFUNC_I2C int pac5xxx_i2c_master_write(uint8_t address, uint8_t *write_data, int bytes_to_write)
{
	int i;

	for (i = 0; i < bytes_to_write; i++)
	{
        /* Verify that the full flag for the MCTRL register is clear */
    
        while (PAC5XXX_I2C->MCTRL.REG_FULL_FLAG);

        /* Write first data byte to transmit in MTXDATA register */
    
		PAC5XXX_I2C->MTXDATA.VAL = *write_data++;

		/* See if last byte of transfer, and write MCTRL accordingly. This will start transfer */
    
		if (i == (bytes_to_write - 1))
			PAC5XXX_I2C->MCTRL.w = (address | 0xC00);      /* XFER_TYPE = write, AUTONO_XFER = 1 [stop] */
        else
            PAC5XXX_I2C->MCTRL.w = (address | 0x400);      /* XFER_TYPE = write */
	}

	/* Check for bad status */
  
	if (PAC5XXX_I2C->STATUS.w & 0xFFFF)						/* Any I2C master status bit set */
		return 1;

	return 0;
}

RAMFUNC_I2C int pac5xxx_i2c_master_write_byte(uint8_t data)
{
    /* Verify that the full flag for the MCTRL register is clear */
  
    while (PAC5XXX_I2C->MCTRL.REG_FULL_FLAG);

    /* Write first data byte to transmit in MTXDATA register */
  
    PAC5XXX_I2C->MTXDATA.VAL = data;

    /* See if last byte of transfer, and write MCTRL accordingly. This will start transfer */
  
    PAC5XXX_I2C->MCTRL.w = 0xC00;           /* XFER_TYPE = write, AUTONO_XFER = 1 [stop] */

    /* Check for bad status */
  
    if (PAC5XXX_I2C->STATUS.w & 0xFFFF)		/* Any I2C master status bit set */
        return 1;

    return 0;
}
