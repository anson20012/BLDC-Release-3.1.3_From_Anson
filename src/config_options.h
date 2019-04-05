
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

#ifndef BLDC_CONFIG_H
#define BLDC_CONFIG_H

#include "include.h"


#define ENABLE_USER_PARAMETER                 	//Use user parameters instead of GUI parameters
//#define ENABLE_POWER_ON_START_MOTOR               //When power on start up motor
#define ENABLE_UART_COMMUNICATE                    //UART communicate with GUI

//Mode Select
//#define Hall_MODE_ENABLE                       	//use Hall information to commutate,if no define hall mode, use BEMF mode to run motor

#ifdef  Hall_MODE_ENABLE
//	#define Hall_BEMF_SWITCH_MODE_ENABLE        	//start up using hall ,then change to BEMF mode, low speed use hall,high speed use BEMF
#else
	#define  Hall_Detect_IN_BEMF_MODE               //detect the relationship between the hall and MOS status,and display on GUI
//	#define  USE_ADC_GET_BEMF_MODE_ENABLE           //sample phase voltage adc value to get zero point
	
#ifndef R_3_SHUNT
	  #define  PPD_START_UP_ENABLE					//Period Position Detect Function Enable,Now PPD is only support Single Shunt
	  #define IPD_IN_PPD_ENABLE                       //Initial Position Detect Function Enable,Now IPD is only support Single Shunt
#endif

	//#define  SINE_WAVE_START_UP_ENABLE				//sine wave start up Function Enable
#endif


#define  SIM_ENABLE								//start in motion
//#define  MOTOR_STOP_BRAKING_ENABLE         		//Stop motor braking function enable
#define  LOSE_ANGLE_RESTART            			//if no commutate too long time in BEMF mode ,then restart motor
#define  VBUS_MAX_MIN_CHECK_ENABLE				    //Vbus over voltage or under voltage protect
#define  DIGITAL_LOW_PASS_FILTER_ENABLE			//digital low pass filter enable
#define  DEBUG_PWM_DAC_ENABLE             		//DAC debug ,can use scope display variable
//#define  SPEED_CTR_ADC_CMD_ENABLE					//change speed through change resistor value
//#define  SPEED_CTR_PPM_CMD_ENABLE					//change speed through change PWM duty or frequency
#endif
