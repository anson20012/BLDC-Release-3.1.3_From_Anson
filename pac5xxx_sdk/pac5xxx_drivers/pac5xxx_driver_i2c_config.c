/**************************************************************************//**
 * @file     pac5xxx_driver_i2c_config.c
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

RAMFUNC_I2C void pac5xxx_i2c_master_config(I2C_AddrMode_Type addr_type, int disable_pulse_filter)
{
	PAC5XXX_I2C->CFG.ADDR_MODE = addr_type;
	PAC5XXX_I2C->CFG.DSBL_PULSE_FILTER = disable_pulse_filter;
	PAC5XXX_I2C->CFG.SLV_ENBL = 0;
	PAC5XXX_I2C->CFG.MST_ENBL = 1;
	}

RAMFUNC_I2C void pac5xxx_i2c_set_baud(int scl_low_clocks, int scl_high_clocks)
{
	PAC5XXX_I2C->BAUD.SCL_LOW_CLOCKS = scl_low_clocks;
	PAC5XXX_I2C->BAUD.SCL_HIGH_CLOCKS = scl_high_clocks;
}

RAMFUNC_I2C void pac5xxx_i2c_slave_config(I2C_AddrMode_Type addr_type, int disable_pulse_filter)
{
	PAC5XXX_I2C->CFG.SLV_ENBL = 1;
	PAC5XXX_I2C->CFG.MST_ENBL = 0;
	PAC5XXX_I2C->CFG.ADDR_MODE = addr_type;
	PAC5XXX_I2C->CFG.DSBL_PULSE_FILTER = disable_pulse_filter;
}

RAMFUNC_I2C void pac5xxx_i2c_disable()
{
	PAC5XXX_I2C->CFG.SLV_ENBL = 0;
	PAC5XXX_I2C->CFG.MST_ENBL = 0;
}

RAMFUNC_I2C void pac5xxx_i2c_io_config(int master)
{
  PAC5XXX_GPIOE->PSEL.P4 = 2;       // I2CSCL
  PAC5XXX_GPIOE->PSEL.P5 = 2;       // I2CSDA
  
  PAC5XXX_GPIOE->OUTEN.P5 = 1;      // I2CSDA output, even for slave mode
  
  if (master)
    PAC5XXX_GPIOE->OUTEN.P4 = 1;    // I2CSCL (master)
  else
    PAC5XXX_GPIOE->OUTEN.P4 = 0;    // I2CSCL (slave)

  PAC5XXX_GPIOE->PU.P4 = 1;			// I2CSCL internal pull-up on
  PAC5XXX_GPIOE->PU.P5 = 1;			// I2CSDA internal pull-up on

}


 
