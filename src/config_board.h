
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

#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include "include.h"
#include "math.h"
//=============================================
// Board selection (choose only one)
//=============================================

// Low voltage board (PAC522x)
//#define PAC5223_SMT_REV2_1
//#define EPPAC5223LVM1_1
//#define EP_HYDRA_X23S_EH_BLDCM1_1
//#define EP_HYDRA_X23S_EH_FOCM1_1

// Medium voltage board (PAC523x)
#define EP5232MVM1

// High voltage board (PAC525x)
//#define PAC5250_SMT_REV2_0
//#define EP5250HPHVM1_1






// Low voltage board (PAC522x)
#ifdef PAC5223_SMT_REV2_1
	#define PAC522x
	#include "PAC522x_app.h"
	#define  R1_PLUS_R2_BY_R2_RATIO_VBUS	(26.50f*65536)
	#define  R1_PLUS_R2_BY_R2_RATIO_BEMF	(13.20f*65536)
	#define  VBUS_ADC_SAMPLE_CHANEL		(ADCCTL_ADMUX_AD3)          //Vbus ADC sample use PC3
	#define  VBUS_ADC_RESULT_CHANEL		(PAC5XXX_ADC->AS0R4.VAL)
	#define  MIN_VBUS    					VDC_12V                 //origanal is VDC_12V
	#define  MAX_VBUS    					VDC_50V
	#define  AUTO_START_VBUS   	 		    VDC_20V
	#define  AUTO_STOP_VBUS     			VDC_12V
	#define  DT_LED_TICKS					50     						//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  DT_TED_TICKS					50							//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  AIO789_COMP_OUTPUT			((((pac5xxx_gpio_in_b()) & NIRQ2_PIN_MASK) >> 7))
	//#define  HALL_VALUE_FROM_GPIOE
	//#define  HALL_VALUE_GPIO 				((PAC5XXX_GPIOE->IN.b>>3)&0x07)
	//#define  R_3_SHUNT
	//#define  ADC_SEQ_M1_IU_EDATA			SIGMGR_AIO10  //just use in 3_R_Shunt
	//#define  ADC_SEQ_M1_IV_EDATA		    SIGMGR_AIO54  //just use in 3_R_Shunt
	//#define  ADC_SEQ_M1_IW_EDATA		    SIGMGR_AIO32  //just use in 3_R_Shunt
#endif

#ifdef EPPAC5223LVM1_1
	#define  PAC522x
	#include "PAC522x_app.h"
	#define  R1_PLUS_R2_BY_R2_RATIO_VBUS	(26.5f*65536)
	#define  R1_PLUS_R2_BY_R2_RATIO_BEMF	(13.2f*65536)
	#define  VBUS_ADC_SAMPLE_CHANEL		(ADCCTL_ADMUX_AD4)          //Vbus ADC sample use PC4
	#define  VBUS_ADC_RESULT_CHANEL		(PAC5XXX_ADC->AS0R4.VAL)
	#define  MIN_VBUS    					VDC_6V
	#define  MAX_VBUS    					VDC_50V
	#define  AUTO_START_VBUS   	 		VDC_20V
	#define  AUTO_STOP_VBUS     			VDC_12V
	#define  DT_LED_TICKS					50     						//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  DT_TED_TICKS					50							//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  AIO789_COMP_OUTPUT			((((pac5xxx_gpio_in_b()) & NIRQ2_PIN_MASK) >> 7))
	#define  HALL_VALUE_FROM_GPIOD
	#define  HALL_VALUE_GPIO 				(((PAC5XXX_GPIOD->IN.P2)|(PAC5XXX_GPIOD->IN.P3<<1)|(PAC5XXX_GPIOD->IN.P7<<2))&0x07)
	//#define  R_3_SHUNT
	//#define  ADC_SEQ_M1_IU_EDATA			SIGMGR_AIO10  //just use in 3_R_Shunt
	//#define  ADC_SEQ_M1_IV_EDATA			SIGMGR_AIO32  //just use in 3_R_Shunt
	//#define  ADC_SEQ_M1_IW_EDATA			SIGMGR_AIO54  //just use in 3_R_Shunt
#endif

#ifdef EP_HYDRA_X23S_EH_BLDCM1_1
	#define PAC522x
	#include "PAC522x_app.h"
	#define  R1_PLUS_R2_BY_R2_RATIO_VBUS	(16.00f*65536)
	#define  R1_PLUS_R2_BY_R2_RATIO_BEMF	(16.00f*65536)
	#define  VBUS_ADC_SAMPLE_CHANEL		(ADCCTL_ADMUX_AD3)          //Vbus ADC sample use PC3
	#define  VBUS_ADC_RESULT_CHANEL		(PAC5XXX_ADC->AS0R4.VAL)
	#define  MIN_VBUS    					VDC_12V
	#define  MAX_VBUS    					VDC_50V
	#define  AUTO_START_VBUS   	 		VDC_20V
	#define  AUTO_STOP_VBUS     			VDC_12V
	#define  DT_LED_TICKS					50     						//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  DT_TED_TICKS					50							//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  AIO789_COMP_OUTPUT			((((pac5xxx_gpio_in_b()) & NIRQ2_PIN_MASK) >> 7))
	#define  HALL_VALUE_FROM_GPIOD
	#define  HALL_VALUE_GPIO 				(((PAC5XXX_GPIOD->IN.P2)|(PAC5XXX_GPIOD->IN.P3<<1)|(PAC5XXX_GPIOD->IN.P7<<2))&0x07)
#endif

#ifdef EP_HYDRA_X23S_EH_FOCM1_1
	#define PAC522x
	#include "PAC522x_app.h"
	#define  R1_PLUS_R2_BY_R2_RATIO_VBUS	(10.00f*65536)
	#define  R1_PLUS_R2_BY_R2_RATIO_BEMF	(10.00f*65536)
	#define  VBUS_ADC_SAMPLE_CHANEL		(ADCCTL_ADMUX_AD4)          //Vbus ADC sample use PC4
	#define  VBUS_ADC_RESULT_CHANEL		(PAC5XXX_ADC->AS0R4.VAL)
	#define  MIN_VBUS    					VDC_12V
	#define  MAX_VBUS    					VDC_50V
	#define  AUTO_START_VBUS   	 		VDC_20V
	#define  AUTO_STOP_VBUS     			VDC_12V
	#define  DT_LED_TICKS					50     						//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  DT_TED_TICKS					50							//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  AIO789_COMP_OUTPUT			((((pac5xxx_gpio_in_b()) & NIRQ2_PIN_MASK) >> 7))
	#define  HALL_VALUE_FROM_GPIOD
	#define  HALL_VALUE_GPIO 				(((PAC5XXX_GPIOD->IN.P2)|(PAC5XXX_GPIOD->IN.P3<<1)|(PAC5XXX_GPIOD->IN.P7<<2))&0x07)
	//#define  R_3_SHUNT
	//#define  ADC_SEQ_M1_IU_EDATA			SIGMGR_AIO10  //just use in 3_R_Shunt
	//#define  ADC_SEQ_M1_IV_EDATA			SIGMGR_AIO32  //just use in 3_R_Shunt
	//#define  ADC_SEQ_M1_IW_EDATA			SIGMGR_AIO54  //just use in 3_R_Shunt
#endif


// Medium voltage board (PAC523x)
#ifdef EP5232MVM1
	#define CAFE_ARCH2
	#define PAC523x
	#include "PAC523x_app.h"
	#define  R1_PLUS_R2_BY_R2_RATIO_VBUS	(57.00f*65536)
	#define  R1_PLUS_R2_BY_R2_RATIO_BEMF	(57.00f*65536)
	#define  VBUS_ADC_SAMPLE_CHANEL		(ADCCTL_ADMUX_AD3)          //Vbus ADC sample use PC3
	#define  VBUS_ADC_RESULT_CHANEL		(PAC5XXX_ADC->AS0R4.VAL)
	#define  MIN_VBUS    					VDC_12V
	#define  MAX_VBUS    					VDC_150V
	#define  AUTO_START_VBUS   	 		VDC_120V
	#define  AUTO_STOP_VBUS     			VDC_12V
	#define  DT_LED_TICKS					50     						//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  DT_TED_TICKS					50							//50count = 1 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  AIO789_COMP_OUTPUT			((((pac5xxx_gpio_in_b()) & NIRQ2_PIN_MASK) >> 7))
	#define  HALL_VALUE_FROM_GPIOD
	#define  HALL_VALUE_GPIO 				(((PAC5XXX_GPIOD->IN.P2)|(PAC5XXX_GPIOD->IN.P3<<1)|(PAC5XXX_GPIOD->IN.P7<<2))&0x07)
	//#define  R_3_SHUNT
	//#define  ADC_SEQ_M1_IU_EDATA			(SIGMGR_AIO10)			// M1-Iu EMUX data (AIO10)
	//#define  ADC_SEQ_M1_IV_EDATA			(SIGMGR_AIO32)			// M1-Iv EMUX data (AIO32)
	//#define  ADC_SEQ_M1_IW_EDATA			(SIGMGR_AIO54)			// M1-Iv EMUX data (AIO54)
#endif


// High voltage board (PAC525x)
#ifdef PAC5250_SMT_REV2_0
	#define PAC525x
	#include "PAC525x_app.h"
	#define  R1_PLUS_R2_BY_R2_RATIO_VBUS	(201.00f*65536)
	#define  R1_PLUS_R2_BY_R2_RATIO_BEMF	(167.00f*65536)
	#define  VBUS_ADC_SAMPLE_CHANEL		(ADCCTL_ADMUX_AD0)
	#define  VBUS_ADC_RESULT_CHANEL		(PAC5XXX_ADC->AS0R4.VAL)
	#define  MIN_VBUS    					VDC_50V
	#define  MAX_VBUS    					VDC_350V
	#define  AUTO_START_VBUS    			VDC_250V
	#define  AUTO_STOP_VBUS     			VDC_200V
	#define  DT_LED_TICKS					50							//100count = 2 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  DT_TED_TICKS					50							//100count = 2 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  AIO789_COMP_OUTPUT			((((pac5xxx_gpio_in_b()) & NIRQ2_PIN_MASK) >> 7))
	#define  HALL_VALUE_FROM_GPIOE
	#define  HALL_VALUE_GPIO 				((PAC5XXX_GPIOE->IN.b>>3)&0x07)
//	#define  R_3_SHUNT
//	#define  ADC_SEQ_M1_IU_EDATA			SIGMGR_AIO10  //just use in 3_R_Shunt
//	#define  ADC_SEQ_M1_IV_EDATA			SIGMGR_AIO32  //just use in 3_R_Shunt
//	#define  ADC_SEQ_M1_IW_EDATA			SIGMGR_AIO54  //just use in 3_R_Shunt
#endif

#ifdef EP5250HPHVM1_1
	#define PAC525x
	#include "PAC525x_app.h"
	#define  R1_PLUS_R2_BY_R2_RATIO_VBUS	(201.00f*65536)
	#define  R1_PLUS_R2_BY_R2_RATIO_BEMF	(167.00f*65536)
	#define  VBUS_ADC_SAMPLE_CHANEL		(ADCCTL_ADMUX_AD2)
	#define  VBUS_ADC_RESULT_CHANEL		(PAC5XXX_ADC->AS0R4.VAL)
	#define  MIN_VBUS    					VDC_50V
	#define  MAX_VBUS    					VDC_350V
	#define  AUTO_START_VBUS    			VDC_250V
	#define  AUTO_STOP_VBUS     			VDC_200V
	#define  DT_LED_TICKS					50							//100count = 2 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  DT_TED_TICKS					50							//100count = 2 usec, with 50MHz clock input, 1 count equals to 0.02usec
	#define  AIO789_COMP_OUTPUT			((((pac5xxx_gpio_in_b()) & NIRQ2_PIN_MASK) >> 7))
	#define  HALL_VALUE_FROM_GPIOD
	#define  HALL_VALUE_GPIO 				((PAC5XXX_GPIOD->IN.b>>2)&0x07)
//	#define  R_3_SHUNT
//	#define  ADC_SEQ_I_U_EDATA			    SIGMGR_MSPI(SIGMGR_AIO10)  //just use in 3_R_Shunt
//	#define  ADC_SEQ_I_V_EDATA			    SIGMGR_MSPI(SIGMGR_AIO32)  //just use in 3_R_Shunt
//	#define  ADC_SEQ_I_W_EDATA			    SIGMGR_MSPI(SIGMGR_AIO54)  //just use in 3_R_Shunt
#endif

#endif
