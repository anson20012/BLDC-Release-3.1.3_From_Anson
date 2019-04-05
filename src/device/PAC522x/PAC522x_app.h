
//=============================================================================
// Copyright (C) 2017, Active-Semi International
//
// THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
// AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
// APPLICATION TO PAC PROCESSORS SUPPLIED BY ACTIVE-SEMI INTERNATIONAL;
// (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
// ACTIVE-SEMICONDUCTOR IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
// DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
// ONLY BY CERTAIN AUTHORIZED PERSONS.
//
//=============================================================================

#ifndef PAC522x_APP_H
#define PAC522x_APP_H

#include "pac52XX.h"
#include "config_board.h"

	#ifdef PAC522x


	#define  VDD2P5DIV1023FIX16    	163          				 //(2.5/1023)<<16


	#define VDC_6V     6
	#define VDC_12V    12
	#define VDC_15V    15
	#define VDC_20V    20
	#define VDC_25V    25
	#define VDC_30V    30
	#define VDC_35V    35
	#define VDC_40V    40
	#define VDC_45V    45
	#define VDC_50V    50

	// ADC Support
	#define ADC_CHANNEL_MASK					(1L << ADCCTL_ADMUX_AD0)			// Mask of ADC channels to perform conversions for
	#define ADC_SEQ_SH_START_EDATA				SIGMGR_MSPI_SH_DIFFAMP				// S/H start EMUX data
	#define ADC_SEQ_IBUS_EDATA				SIGMGR_MSPI(SIGMGR_AIO10)				// M1-Imotor EMUX data (AIO6/AB1)
	#define ADC_SEQ_M2_IMOTOR_EDATA			SIGMGR_MSPI(SIGMGR_AB2)				// M2-Imotor EMUX data (AIO7/AB2)
	#define ADC_SEQ_IPFC_EDATA					SIGMGR_MSPI(SIGMGR_AIO54)			// Ipfc EMUX data (AIO54)
	#define ADC_SEQ_VIN_EDATA					SIGMGR_MSPI(SIGMGR_AB3)				// Vin EMUX data (AIO8/AB3)
	#define ADC_SEQ_VOUT_EDATA					SIGMGR_MSPI(SIGMGR_AB4)				// Vout EMUX data (AIO9/AB4)
	#define ADC_SEQ_VOUT_EDATA_REG				SIGMGR_MSPI(SIGMGR_AB4)				// Vout EMUX data (AIO6/AB4)
	#define ADC_SEQ_P_UIN_EDATA_REG			SIGMGR_MSPI(SIGMGR_AB7)				// Phase U Voltage In EMUX data (AIO7/AB7)
	#define ADC_SEQ_P_VIN_EDATA_REG			SIGMGR_MSPI(SIGMGR_AB8)				// Phase V Voltage In EMUX data (AIO8/AB8)
	#define ADC_SEQ_P_WIN_EDATA_REG			SIGMGR_MSPI(SIGMGR_AB9)				// Phase W Voltage In EMUX data (AIO9/AB9)

	#define  BRAKING_BEMF_AIO7_ADC     	(PAC5XXX_ADC->AS0R1.VAL)
	#define  BRAKING_BEMF_AIO8_ADC     	(PAC5XXX_ADC->AS0R2.VAL)
	#define  BRAKING_BEMF_AIO9_ADC     	(PAC5XXX_ADC->AS0R3.VAL)

	PAC5XXX_RAMFUNC void calculate_ibus_current(void);
	PAC5XXX_RAMFUNC void calculate_vbus_voltage(void);
	PAC5XXX_RAMFUNC void set_duty(uint16_t temp_pwm_duty);
	PAC5XXX_RAMFUNC void sine_start_up_set_duty(uint16_t u_temp_pwm_duty,uint16_t v_temp_pwm_duty,uint16_t w_temp_pwm_duty);
	PAC5XXX_RAMFUNC void commutate(int hs);
	PAC5XXX_RAMFUNC void app_amplifier_gain_init(uint32_t app_amplifier_gain);
	void init_over_current_limit(uint32_t current_limit);
	PAC5XXX_RAMFUNC void oc_reset(void);
	void pwm_enable(void);
	PAC5XXX_RAMFUNC void pwm_disable(void) ;
	void sensored_gpio_init(void);


	#endif

#endif
