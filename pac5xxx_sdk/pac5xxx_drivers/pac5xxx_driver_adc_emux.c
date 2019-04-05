/**************************************************************************//**
 * @file     pac5xxx_driver_adc_emux.c
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

RAMFUNC_ADC void pac5xxx_adc_emux_config(ADC_EMUX_CTL_Type control_type, ADC_EMUX_DIV_Type divider)
{
	PAC5XXX_ADC->EMUXCTL.EMUXC = control_type;
	PAC5XXX_ADC->EMUXCTL.EMUXDIV = divider;
}

RAMFUNC_ADC void pac5xxx_adc_config_emux_io()
{
  PAC5XXX_GPIOB->PSEL.P5 = 1;
  PAC5XXX_GPIOB->PSEL.P6 = 1;
}
