/**************************************************************************//**
 * @file     pac5xxx_driver_socbridge_config_io.c
 * @brief    Firmware driver for the PAC5XXX SOC Bridge Peripheral
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

RAMFUNC_SOCBRIDGE void pac5xxx_socbridge_config_io(void)
{
  // 
  // CS0:  GPIOBSEL1 = 01b (PB1 - output)
  // CLK:  GPIOBSEL4 = 01b (PB4 - output)
  // MOSI: GPIOBSEL2 = 01b (PB2 - output)
  // MISO: GPIOBSEL3 = 01b (PB3 - input)
  //
  
  PAC5XXX_GPIOB->PSEL.P1 = 1;         // CS0
  PAC5XXX_GPIOB->OUTEN.P1 = 1;		// output

  PAC5XXX_GPIOB->PSEL.P4 = 1;         // CLK
  PAC5XXX_GPIOB->OUTEN.P4 = 1;		// output

  PAC5XXX_GPIOB->PSEL.P2 = 1;         // MOSI
  PAC5XXX_GPIOB->OUTEN.P2 = 1;		// output

  PAC5XXX_GPIOB->PSEL.P3 = 1;         // MISO, input by default
}
