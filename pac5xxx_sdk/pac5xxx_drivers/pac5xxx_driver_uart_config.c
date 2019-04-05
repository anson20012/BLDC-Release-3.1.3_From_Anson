/**************************************************************************//**
 * @file     pac5xxx_driver_uart_config.c
 * @brief    Firmware driver for the PAC5XXX UART
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

#include "pac5xxx_driver_uart.h"

RAMFUNC_UART void pac5xxx_uart_config_LCR(UART_BitsPerChar_Type bpc,
                           UART_StopBits_Type stop_bits,
							             int parity_enabled,
						               UART_Parity_Type parity,
						               int stick_parity,
						               UART_BreakControl_Type break_control,
						               UART_DivLatchAccess_Type div_latch_access)
{
  PAC5XXX_UART->LCR.BPC = bpc;
  PAC5XXX_UART->LCR.STB = stop_bits;
  PAC5XXX_UART->LCR.PEN = parity_enabled;
  PAC5XXX_UART->LCR.EPS = parity;
  PAC5XXX_UART->LCR.SP = stick_parity;
  PAC5XXX_UART->LCR.SB = break_control;
  PAC5XXX_UART->LCR.DLAB = div_latch_access;
}

RAMFUNC_UART void pac5xxx_uart_config_MCR(int DTR_asserted,
                           int RTS_asserted,
						               int BIT1_asserted,
						               int BIT2_asserted,
						               int loopback_mode)
{
  PAC5XXX_UART->MCR.DTR = DTR_asserted;
  PAC5XXX_UART->MCR.RTS = RTS_asserted;
  PAC5XXX_UART->MCR.BIT1 = BIT1_asserted;
  PAC5XXX_UART->MCR.BIT2 = BIT2_asserted;
  PAC5XXX_UART->MCR.LP = loopback_mode;
}
						   
RAMFUNC_UART void pac5xxx_uart_config_divisor_latch(uint16_t latch_value)
{
	PAC5XXX_UART->DL_H.VAL = (latch_value >> 8);
	PAC5XXX_UART->DL_L.VAL = (latch_value & 0xFF);
}

RAMFUNC_UART void pac5xxx_uart_config_divisor_latch_remapped(uint16_t latch_value)
{
	  PAC5XXX_UART->DL_H2.VAL = (latch_value >> 8);
	  PAC5XXX_UART->DL_L2.VAL = (latch_value & 0xFF);
}

RAMFUNC_UART void pac5xxx_uart_config_fractional_divisor(unsigned char divisor_value)
{
  PAC5XXX_UART->FD_F.VAL = divisor_value;
}

RAMFUNC_UART void pac5xxx_uart_io_config()
{
  PAC5XXX_GPIOE->PSEL.P1 = 2;      // UARTTX
  PAC5XXX_GPIOE->OUTEN.P1 = 1;
  
  PAC5XXX_GPIOE->PSEL.P2 = 2;      // UARTRX
  PAC5XXX_GPIOE->OUTEN.P2 = 0;
}

