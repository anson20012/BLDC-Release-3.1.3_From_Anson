/**************************************************************************//**
 * @file     pac5xxx_driver_adc_config.c
 * @brief    Firmware driver for the PAC5XXX ADC
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

#include "pac5xxx_driver_adc.h"

RAMFUNC_ADC void pac5xxx_adc_config(ADCCTL_ADMODE_Type adc_mode, ADCCTL_CLKDIV_Type clock_divider, int repeat)
{
	PAC5XXX_ADC->ADCCTL.ADCMODE = adc_mode;
	PAC5XXX_ADC->ADCCTL.ADCDIV = clock_divider;
	PAC5XXX_ADC->ADCCTL.ADCREPEAT = repeat;
}


RAMFUNC_ADC void pac5xxx_adc_config_io(unsigned char channel_mask)
{
  // Need to explictly disable OUTEN and INEN
  PAC5XXX_GPIOC->OUTEN.b &= ~channel_mask;
  PAC5XXX_GPIOC->INE.b &= ~channel_mask;
 
}
