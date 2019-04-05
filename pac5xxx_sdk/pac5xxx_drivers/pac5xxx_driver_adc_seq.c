/**************************************************************************//**
 * @file     pac5xxx_driver_adc_seq.c
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

RAMFUNC_ADC void pac5xxx_adc_as0_config_timer(ADCCTLX_SDEPTH_Type sample_depth,
                                             ADCCTLX_TRIGTIMER_Type trig_timer_source)
{
	PAC5XXX_ADC->ASCTL0.AS0TR = ADCCTLX_ASTR_TIMER;
	PAC5XXX_ADC->ASCTL0.AS0D = sample_depth;
	PAC5XXX_ADC->ASCTL0.AS0TRTMR = trig_timer_source;
	PAC5XXX_ADC->ASCTL0.AS0SEQEN = 1;
}
	
RAMFUNC_ADC void pac5xxx_adc_as0_config_pwm(ADCCTLX_SDEPTH_Type sample_depth,
                                           ADCCTLX_TRIGEDGE_Type trig_edge, 
						                               ADCCTLX_TRIGPWM_Type trig_pwm_source)
{
	PAC5XXX_ADC->ASCTL0.AS0TR = ADCCTLX_ASTR_PWM;
	PAC5XXX_ADC->ASCTL0.AS0D = sample_depth;
	PAC5XXX_ADC->ASCTL0.AS0TRE = trig_edge;
	PAC5XXX_ADC->ASCTL0.AS0TRPWM = trig_pwm_source;
	PAC5XXX_ADC->ASCTL0.AS0SEQEN = 1;
}


RAMFUNC_ADC void pac5xxx_adc_as1_config_timer(ADCCTLX_SDEPTH_Type sample_depth,
                                             ADCCTLX_TRIGTIMER_Type trig_timer_source)
{
	PAC5XXX_ADC->ASCTL1.AS1TR = ADCCTLX_ASTR_TIMER;
	PAC5XXX_ADC->ASCTL1.AS1D = sample_depth;
	PAC5XXX_ADC->ASCTL1.AS1TRTMR = trig_timer_source;
	PAC5XXX_ADC->ASCTL1.AS1SEQEN = 1;
}
	
RAMFUNC_ADC void pac5xxx_adc_as1_config_pwm(ADCCTLX_SDEPTH_Type sample_depth,
                                           ADCCTLX_TRIGEDGE_Type trig_edge, 
						                               ADCCTLX_TRIGPWM_Type trig_pwm_source)
{
	PAC5XXX_ADC->ASCTL1.AS1TR = ADCCTLX_ASTR_PWM;
	PAC5XXX_ADC->ASCTL1.AS1D = sample_depth;
	PAC5XXX_ADC->ASCTL1.AS1TRE = trig_edge;
	PAC5XXX_ADC->ASCTL1.AS1TRPWM = trig_pwm_source;
	PAC5XXX_ADC->ASCTL1.AS1SEQEN = 1;
}
							   
				   
RAMFUNC_ADC void pac5xxx_adc_as0_sequence_config(int seq_num,
									                              ADCCTL_ADMUX_Type mux_select,
                                                ASSEQ_MSPI_Type emux_control,
									                              unsigned char emux_data,
									                              ASSEQ_DELAY_Type seq_delay)
{
	volatile PAC5XXX_ADCSEQCTL_Type* pSeq;

	if (seq_num == 0)
		pSeq = &PAC5XXX_ADC->AS0S0;
	else if (seq_num == 1)
		pSeq = &PAC5XXX_ADC->AS0S1;
	else if (seq_num == 2)
		pSeq = &PAC5XXX_ADC->AS0S2;
	else if (seq_num == 3)
		pSeq = &PAC5XXX_ADC->AS0S3;
	else if (seq_num == 4)
		pSeq = &PAC5XXX_ADC->AS0S4;
	else if (seq_num == 5)
		pSeq = &PAC5XXX_ADC->AS0S5;
	else if (seq_num == 6)
		pSeq = &PAC5XXX_ADC->AS0S6;
	else if (seq_num == 7)
		pSeq = &PAC5XXX_ADC->AS0S7;
	
	pSeq->ADCMUX = mux_select;
	pSeq->EMUXS = emux_control;
	pSeq->EMUXD = emux_data;
	pSeq->DELAY = seq_delay;
}
									
RAMFUNC_ADC void pac5xxx_adc_as1_sequence_config(int seq_num,
									                              ADCCTL_ADMUX_Type mux_select,
                                                ASSEQ_MSPI_Type emux_control,
									                              unsigned char emux_data,
									                              ASSEQ_DELAY_Type seq_delay)
{
	volatile PAC5XXX_ADCSEQCTL_Type* pSeq;

	if (seq_num == 0)
		pSeq = &PAC5XXX_ADC->AS1S0;
	else if (seq_num == 1)
		pSeq = &PAC5XXX_ADC->AS1S1;
	else if (seq_num == 2)
		pSeq = &PAC5XXX_ADC->AS1S2;
	else if (seq_num == 3)
		pSeq = &PAC5XXX_ADC->AS1S3;
	else if (seq_num == 4)
		pSeq = &PAC5XXX_ADC->AS1S4;
	else if (seq_num == 5)
		pSeq = &PAC5XXX_ADC->AS1S5;
	else if (seq_num == 6)
		pSeq = &PAC5XXX_ADC->AS1S6;
	else if (seq_num == 7)
		pSeq = &PAC5XXX_ADC->AS1S7;
	
	pSeq->ADCMUX = mux_select;
	pSeq->EMUXS = emux_control;
	pSeq->EMUXD = emux_data;
	pSeq->DELAY = seq_delay;
}

RAMFUNC_ADC uint16_t pac5xxx_adc_as0_seq_get_result(int seq_num)
{
	volatile PAC5XXX_ADCRESULT_Type* pSeq;
	
	if (seq_num == 0)
		pSeq = &PAC5XXX_ADC->AS0R0;
	else if (seq_num == 1)
		pSeq = &PAC5XXX_ADC->AS0R1;
	else if (seq_num == 2)
		pSeq = &PAC5XXX_ADC->AS0R2;
	else if (seq_num == 3)
		pSeq = &PAC5XXX_ADC->AS0R3;
	else if (seq_num == 4)
		pSeq = &PAC5XXX_ADC->AS0R4;
	else if (seq_num == 5)
		pSeq = &PAC5XXX_ADC->AS0R5;
	else if (seq_num == 6)
		pSeq = &PAC5XXX_ADC->AS0R6;
	else if (seq_num == 7)
		pSeq = &PAC5XXX_ADC->AS0R7;
	
	return pSeq->VAL;
}

RAMFUNC_ADC uint16_t pac5xxx_adc_as1_seq_get_result(int seq_num)
{
	volatile PAC5XXX_ADCRESULT_Type* pSeq;
	
	if (seq_num == 0)
		pSeq = &PAC5XXX_ADC->AS1R0;
	else if (seq_num == 1)
		pSeq = &PAC5XXX_ADC->AS1R1;
	else if (seq_num == 2)
		pSeq = &PAC5XXX_ADC->AS1R2;
	else if (seq_num == 3)
		pSeq = &PAC5XXX_ADC->AS1R3;
	else if (seq_num == 4)
		pSeq = &PAC5XXX_ADC->AS1R4;
	else if (seq_num == 5)
		pSeq = &PAC5XXX_ADC->AS1R5;
	else if (seq_num == 6)
		pSeq = &PAC5XXX_ADC->AS1R6;
	else if (seq_num == 7)
		pSeq = &PAC5XXX_ADC->AS1R7;
	
	return pSeq->VAL;
}

