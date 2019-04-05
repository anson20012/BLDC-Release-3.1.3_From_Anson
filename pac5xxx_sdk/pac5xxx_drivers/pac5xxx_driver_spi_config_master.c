/**************************************************************************//**
 * @file     pac5xxx_driver_spi_config_master.c
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

RAMFUNC_SPI void pac5xxx_spi_master_config(int int_enable,
                                           int loopback,
		          					       int mtrans,
							               int mtrans_rearm, 
							               int single_master, 
							               int rtrans)
{
	  PAC5XXX_SPI->SPICTL.SSEN = 0;
	  PAC5XXX_SPI->SPICTL.SIE = int_enable;
	  PAC5XXX_SPI->SPICTL.LPBK = loopback;
	  PAC5XXX_SPI->SPICTL.SE = 0;
	  PAC5XXX_SPI->SPICTL.MTRANS = mtrans;
	  PAC5XXX_SPI->SPICTL.MMST_N = single_master;
	  PAC5XXX_SPI->SPICTL.RTRANS = rtrans;
	  PAC5XXX_SPI->SPICTL.MTRARM = mtrans_rearm;
}
							 
RAMFUNC_SPI void pac5xxx_spi_master_config2(SPISCFG_WordLength_Type wl_select,
							                int reset,
							                int lsb_first,
							                SPISCFG_ClockPolarity_Type clock_polarity,
							                SPISCFG_ClockPhase_Type clock_phase,
							                SPICFG_EarlyXmitDataPhase_Type xmit_data_phase)
{
    PAC5XXX_SPI->SPICFG.WL = wl_select;
    PAC5XXX_SPI->SPICFG.MRST = reset;
    PAC5XXX_SPI->SPICFG.LB1ST = lsb_first;
    PAC5XXX_SPI->SPICFG.CP = clock_polarity;
    PAC5XXX_SPI->SPICFG.CPH = clock_phase;
    PAC5XXX_SPI->SPICFG.TDAT_PH = xmit_data_phase;
    PAC5XXX_SPI->SPICFG.TXDBUF = 1;
    PAC5XXX_SPI->SPICFG.MTURBO = 1;
}

RAMFUNC_SPI void pac5xxx_spi_master_config_chip_select(SPICS_ChipSelectNumber_Type cs_num,
										               SPICS_ChipSelectPolarity_Type cs_polarity,
										               unsigned char chip_select_setup,
										               unsigned char chip_select_hold,
										               unsigned char chip_select_wait,
										               unsigned char spi_clock_wait)
{
	PAC5XXX_SPI->SPICCSTR.CSNUM = cs_num;
	PAC5XXX_SPI->SPICCSTR.CSL = cs_polarity;
	PAC5XXX_SPI->SPICCSTR.CSSETUP = chip_select_setup;
	PAC5XXX_SPI->SPICCSTR.CSHOLD = chip_select_hold;
	PAC5XXX_SPI->SPICCSTR.CSWAIT = chip_select_wait;
	PAC5XXX_SPI->SPICCSTR.CKWAIT = spi_clock_wait;
}

