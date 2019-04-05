/**************************************************************************//**
 * @file     pac5xxx_driver_gpio_io_enable.c
 * @brief    Firmware driver for the PAC5XXX GPIO IO Enable
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

#include "pac5xxx_driver_gpio.h"

RAMFUNC_GPIO void pac5xxx_gpio_io_enable_a(unsigned char port_mask)
{
  if (port_mask & 0x01)
    PAC5XXX_GPIOA->PSEL.P0 = 0;
  if (port_mask & 0x02)
	  PAC5XXX_GPIOA->PSEL.P1 = 0;
  if (port_mask & 0x04)
	  PAC5XXX_GPIOA->PSEL.P2 = 0;
  if (port_mask & 0x08)
	  PAC5XXX_GPIOA->PSEL.P3 = 0;
  if (port_mask & 0x10)
	  PAC5XXX_GPIOA->PSEL.P4 = 0;
  if (port_mask & 0x20)
	  PAC5XXX_GPIOA->PSEL.P5 = 0;
  if (port_mask & 0x40)
	  PAC5XXX_GPIOA->PSEL.P6 = 0;
  if (port_mask & 0x80)
	  PAC5XXX_GPIOA->PSEL.P7 = 0;
}

RAMFUNC_GPIO void pac5xxx_gpio_io_enable_b(unsigned char port_mask)
{
  if (port_mask & 0x01)
    PAC5XXX_GPIOB->PSEL.P0 = 0;
  if (port_mask & 0x02)
    PAC5XXX_GPIOB->PSEL.P1 = 0;
  if (port_mask & 0x04)
    PAC5XXX_GPIOB->PSEL.P2 = 0;
  if (port_mask & 0x08)
    PAC5XXX_GPIOB->PSEL.P3 = 0;
  if (port_mask & 0x10)
    PAC5XXX_GPIOB->PSEL.P4 = 0;
  if (port_mask & 0x20)
    PAC5XXX_GPIOB->PSEL.P5 = 0;
  if (port_mask & 0x40)
    PAC5XXX_GPIOB->PSEL.P6 = 0;
  if (port_mask & 0x80)
    PAC5XXX_GPIOB->PSEL.P7 = 0;
}

RAMFUNC_GPIO void pac5xxx_gpio_io_enable_c(unsigned char port_mask)
{
  if (port_mask & 0x01)
    PAC5XXX_GPIOC->PSEL.P0 = 0;
  if (port_mask & 0x02)
    PAC5XXX_GPIOC->PSEL.P1 = 0;
  if (port_mask & 0x04)
    PAC5XXX_GPIOC->PSEL.P2 = 0;
  if (port_mask & 0x08)
    PAC5XXX_GPIOC->PSEL.P3 = 0;
  if (port_mask & 0x10)
    PAC5XXX_GPIOC->PSEL.P4 = 0;
  if (port_mask & 0x20)
    PAC5XXX_GPIOC->PSEL.P5 = 0;
  if (port_mask & 0x40)
    PAC5XXX_GPIOC->PSEL.P6 = 0;
  if (port_mask & 0x80)
    PAC5XXX_GPIOC->PSEL.P7 = 0;
}

RAMFUNC_GPIO void pac5xxx_gpio_io_enable_d(unsigned char port_mask)
{
  if (port_mask & 0x01)
    PAC5XXX_GPIOD->PSEL.P0 = 0;
  if (port_mask & 0x02)
    PAC5XXX_GPIOD->PSEL.P1 = 0;
  if (port_mask & 0x04)
    PAC5XXX_GPIOD->PSEL.P2 = 0;
  if (port_mask & 0x08)
    PAC5XXX_GPIOD->PSEL.P3 = 0;
  if (port_mask & 0x10)
    PAC5XXX_GPIOD->PSEL.P4 = 0;
  if (port_mask & 0x20)
    PAC5XXX_GPIOD->PSEL.P5 = 0;
  if (port_mask & 0x40)
    PAC5XXX_GPIOD->PSEL.P6 = 0;
  if (port_mask & 0x80)
    PAC5XXX_GPIOD->PSEL.P7 = 0;
}

RAMFUNC_GPIO void pac5xxx_gpio_io_enable_e(unsigned char port_mask)
{
  if (port_mask & 0x01)
    PAC5XXX_GPIOE->PSEL.P0 = 0;
  if (port_mask & 0x02)
    PAC5XXX_GPIOE->PSEL.P1 = 0;
  if (port_mask & 0x04)
    PAC5XXX_GPIOE->PSEL.P2 = 0;
  if (port_mask & 0x08)
    PAC5XXX_GPIOE->PSEL.P3 = 0;
  if (port_mask & 0x10)
    PAC5XXX_GPIOE->PSEL.P4 = 0;
  if (port_mask & 0x20)
    PAC5XXX_GPIOE->PSEL.P5 = 0;
  if (port_mask & 0x40)
    PAC5XXX_GPIOE->PSEL.P6 = 0;
  if (port_mask & 0x80)
    PAC5XXX_GPIOE->PSEL.P7 = 0;
}
