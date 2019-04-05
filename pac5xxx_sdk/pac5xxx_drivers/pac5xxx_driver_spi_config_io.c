/**************************************************************************//**
 * @file     pac5xxx_driver_spi_config_io.c
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

RAMFUNC_SPI void pac5xxx_spi_config_io(int master, unsigned char cs_mask)
{
  // 
  // SPICS0:  GPIOESEL3 = 01b (PE3 - output [master], input [slave])
  // SPICS1:  GPIOESEL4 = 01b (PE4 - output [master], input [slave])
  // SPICS2:  GPIOESEL5 = 01b (PE5 - output [master], input [slave])
  // SPICLK:  GPIOESEL0 = 01b (PE0 - output [master], input [slave])
  // SPIMOSI: GPIOESEL1 = 01b (PE1 - output [master], input [slave])
  // SPIMISO: GPIOESEL2 = 01b (PE2 - input [master], output [slave])
  //
  
  PAC5XXX_GPIOE->PSEL.P0 = 1;         // SPICLK
  PAC5XXX_GPIOE->PSEL.P1 = 1;         // SPIMOSI
  PAC5XXX_GPIOE->PSEL.P2 = 1;         // SPIMISO
  
  if (cs_mask & 0x01)
  {
    PAC5XXX_GPIOE->PSEL.P3 = 1;       // SPICS0
    PAC5XXX_GPIOE->OUTEN.P3 = 0;      // Assume slave, correct below
  }
  if (cs_mask & 0x02)
  {
    PAC5XXX_GPIOE->PSEL.P4 = 1;       // SPICS1
    PAC5XXX_GPIOE->OUTEN.P4 = 0;      // Assume slave, correct below
  }
  if (cs_mask & 0x04)
  {
    PAC5XXX_GPIOE->PSEL.P5 = 1;       // SPICS2
    PAC5XXX_GPIOE->OUTEN.P5 = 0;      // Assume slave, correct below
  }
  
  if (master)
  {
    if (cs_mask & 0x01)
      PAC5XXX_GPIOE->OUTEN.P3 = 1;    // SPICS0
    if (cs_mask & 0x02)
      PAC5XXX_GPIOE->OUTEN.P4 = 1;    // SPICS1
    if (cs_mask & 0x04)
      PAC5XXX_GPIOE->OUTEN.P5 = 1;    // SPICS2
  }
}

