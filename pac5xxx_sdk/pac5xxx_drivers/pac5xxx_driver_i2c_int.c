/**************************************************************************//**
 * @file     pac5xxx_driver_i2c_int.c
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

RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_TX_EMPTIED(int enable)
{
	volatile int dummy = PAC5XXX_I2C->STATUS.MST_TX_EMPTIED;   // Force read (RTC)
	PAC5XXX_I2C->IE.MST_TX_EMP_IE = enable;
}

RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_ACC_CTL_EMP(int enable)
{
	volatile int dummy = PAC5XXX_I2C->STATUS.MST_ACC_CTL_EMP;   // Force read (RTC)
	PAC5XXX_I2C->IE.MST_ACC_CTL_EMP_IE = enable;
}

RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_RX_FILLED(int enable)
{
	volatile int dummy = PAC5XXX_I2C->STATUS.MST_RX_FILLED;   // Force read (RTC)
	PAC5XXX_I2C->IE.MST_RX_FILLED_IE = enable;
}

RAMFUNC_I2C void pac5xxx_i2c_int_enable_MST_XFER_DONE(int enable)
{
	volatile int dummy = PAC5XXX_I2C->STATUS.MST_XFER_DONE;   // Force read (RTC)
	PAC5XXX_I2C->IE.MST_XFER_DONE_IE = enable;
}

RAMFUNC_I2C void pac5xxx_i2c_int_enable_SLV_ADDR_MATCH(int enable)
{
	volatile int dummy = PAC5XXX_I2C->STATUS.SLV_ADDR_MATCH;   // Force read (RTC)
	PAC5XXX_I2C->IE.SLV_ADDR_MATCH_IE = enable;
}

RAMFUNC_I2C void pac5xxx_i2c_int_enable_SLV_TX_EMPTIED(int enable)
{
	volatile int dummy = PAC5XXX_I2C->STATUS.SLV_TX_EMPTIED;   // Force read (RTC)
	PAC5XXX_I2C->IE.SLV_TX_EMP_IE = enable;
}

RAMFUNC_I2C void pac5xxx_i2c_int_enable_SLV_RX_FILLED(int enable)
{
	volatile int dummy = PAC5XXX_I2C->STATUS.SLV_RX_FILLED;   // Force read (RTC)
	PAC5XXX_I2C->IE.SLV_RX_FILLED_IE = enable;
}

RAMFUNC_I2C void pac5xxx_i2c_int_enable_SLV_XFER_DONE(int enable)
{
	volatile int dummy = PAC5XXX_I2C->STATUS.SLV_XFER_DONE;   // Force read (RTC)
	PAC5XXX_I2C->IE.SLV_XFER_DONE_IE = enable;
}



