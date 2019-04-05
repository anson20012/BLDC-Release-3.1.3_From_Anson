
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

#ifndef PAC523x_APP_H
#define PAC523x_APP_H

#include "pac52XX.h"
#include "config_board.h"

	#ifdef PAC523x


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
	#define VDC_60V    60
	#define VDC_80V    80
	#define VDC_100V   100
	#define VDC_120V   120
	#define VDC_150V   150
	#define VDC_160V   160

	// ADC Support
	#define ADC_CHANNEL_MASK					(1L << ADCCTL_ADMUX_AD0)			// Mask of ADC channels to perform conversions for
	#define ADC_SEQ_SH_START_EDATA				SIGMGR_MSPI_SH_DIFFAMP				// S/H start EMUX data
	#define ADC_SEQ_M1_VU_EDATA				(SIGMGR_AB7)				// Phase U Voltage In EMUX data (AIO7/AB7)
	#define ADC_SEQ_M1_VV_EDATA				(SIGMGR_AB8)				// Phase V Voltage In EMUX data (AIO8/AB8)
	#define ADC_SEQ_M1_VW_EDATA				(SIGMGR_AB9)				// Phase W Voltage In EMUX data (AIO9/AB9)
	#define ADC_SEQ_M1_VIN_EDATA				(SIGMGR_AB1)				// Vin EMUX data (AIO6/AB4)
	#define ADC_SEQ_M1_VR_EDATA				(SIGMGR_AB1)				// PC2
	#define ADC_SEQ_M1_IBUS_EDATA			    (SIGMGR_AIO10)		        // M1-Ibus EMUX data (AIO10)

	#define BRAKING_BEMF_AIO7_ADC     	        (PAC5XXX_ADC->AS0R1.VAL)
	#define BRAKING_BEMF_AIO8_ADC     	        (PAC5XXX_ADC->AS0R2.VAL)
	#define BRAKING_BEMF_AIO9_ADC     	        (PAC5XXX_ADC->AS0R3.VAL)

	// MODULE MISC CAFE REGISTER
	#define HIB_BIT_DEFAULT			0								                                    //0 = Normal; 1 = Hibernate
	#define PBEN_BIT_DEFAULT			0								                                    //0 = Push Button Disabled; 1 = Push Button Enabled (AIO6)
	#define VREFSET_BIT_DEFAULT		0								                                    //0 = ADC VREF is 2.5V; 1 = ADC VREF is 3.0V
	#define CLKOUTEN_BIT_DEFAULT		0								                                    //0 = Disabled; 1 = Enabled
	#define MCUALIVE_BIT_DEFAULT		1								                                    //0 = Disabled; 1 = Enabled
	#define TPBD_BIT_DEFAULT           0                                                                   //0 = Disabled; 1 = Enabled
	#define RFU_BIT_DEFAULT            0                                                                   //0 = Disabled; 1 = Enabled
	#define ENSIG_BIT_DEFAULT			1								                                    //0 = Disabled; 1 = Enabled
	#define MODULE_MISC_BITS_DEFAULT	((HIB_BIT_DEFAULT << 7) + (PBEN_BIT_DEFAULT << 6) + (VREFSET_BIT_DEFAULT << 5) + (CLKOUTEN_BIT_DEFAULT << 4) + (MCUALIVE_BIT_DEFAULT << 3) + (TPBD_BIT_DEFAULT << 2) + (RFU_BIT_DEFAULT << 1) + (ENSIG_BIT_DEFAULT << 0))


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
