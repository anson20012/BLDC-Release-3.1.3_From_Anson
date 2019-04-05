
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

#ifndef PPD_CONFIG_H
#define PPD_CONFIG_H


#include "include.h"



//==============================================
///	Defines
//==============================================

//#define TRUE	(1)
//#define FALSE	(0)

// Chose to make the PPD Functions into RAM or not
//#define PPD_FUNC_IN_RAM

#ifdef PPD_FUNC_IN_RAM
	#define PPD_RAMFUNC PAC5XXX_RAMFUNC
#else
	#define PPD_RAMFUNC //PAC5XXX_RAMFUNC
#endif

// The default Values of PPD parameters
#define DF_PPD_DETECT_RISING_TICK 					(400)
#define DF_PPD_DETECT_FALLING_TICK 				(100)
#define DF_PPD_DETECT_COUNT 						(5)
#define DF_PPD_BLANK_COUNT 						(2)

#define DF_PPD_TUNING_LAST_COUNT 					(100)
#define DF_PPD_SMOOTH_COUNT 						(10)
#define DF_PPD_DUTY_RAMP 							(2)

#define DF_PPD_MINMUN_ADC_DIFF 					(10)

#define DF_PPD_DETECT_TO_TUNE_WAIT_COUNT 			(20)
#define DF_PPD_TUNE_TO_DETECT_WAIT_COUNT 			(20)

#define DF_PPD_GET_ADC 							(PAC5XXX_ADC->AS0R0.VAL)

// the enums of PPD whole Process
typedef enum
{
	MOTOR_STATE_PPD_INIT,

	MOTOR_STATE_PPD_DETECT,
	MOTOR_STATE_PPD_DETECT_TO_TUNE_DELAY,
	MOTOR_STATE_PPD_TUNE,
	MOTOR_STATE_PPD_TUNE_TO_DETECT_DELAY,

	MOTOR_STATE_PPD_TUNE_TO_CLOSED_LOOP,
	MOTOR_STATE_PPD_DONE,

}eMotor_State_PPD;


//==============================================
///	Variables
//==============================================
// The main Struct of PPD
typedef struct
{
	eMotor_State_PPD ppd_running_state ;

	uint8_t ppd_detect_one_phase_done_flag ;
	uint8_t ppd_detect_one_flag ;

	uint16_t ppd_detect_rising_tick ;
	uint16_t ppd_detect_falling_tick ;
	uint16_t ppd_detect_count ;
	uint16_t ppd_detect_blank_count ;


	volatile uint16_t ppd_adc_value_one_phase[8] ;
	volatile uint16_t ppd_adc_value_two_phase[8] ;

	uint16_t ppd_result_phase ;
	uint16_t ppd_result_phase_p ;


	uint16_t ppd_min_phase_one_phase ;
	uint16_t ppd_min_adc_one_phase ;
	uint16_t ppd_min_phase_two_phase ;
	uint16_t ppd_min_adc_two_phase ;

	uint16_t ppd_max_phase_one_phase ;
	uint16_t ppd_max_adc_one_phase ;
	uint16_t ppd_max_phase_two_phase ;
	uint16_t ppd_max_adc_two_phase ;

	uint16_t ppd_smooth_count ;
	uint16_t ppd_smooth_count_target ;

	uint16_t ppd_tuning_last_count ;

	uint16_t ppd_tune_duty ;
	uint16_t ppd_tune_duty_ramp ;

	uint16_t ppd_test_mode_on ;

	// PPD parameters used in the process
	uint16_t ppd_tune_count ;
	uint16_t ppd_number_rolling ;

	uint8_t ppd_detect_current_phase ;
	uint8_t ppd_detect_current_num ;
	uint8_t ppd_detect_current_one_phase_done_flag ;
	uint8_t ppd_detect_current_two_phase_done_flag ;

	uint16_t ipd_tune_duty ;
	uint16_t ipd_mode ;


}PPD_Variables;

// const group of PPD
extern const uint16_t ppd_phase_test[7];
extern const uint16_t ppd_phase_forhead[7];
extern const uint16_t ppd_phase_backward[7];

extern volatile PPD_Variables motor_control_ppd ;


//    U/V----U/W---V/W---V/U---W/U---W/V
extern const uint8_t ppd_pwm_io_state_one_phase[7];
extern const uint16_t ppd_psel_mask_port_a_one_phase[7];
extern const uint16_t ppd_psel_mask_port_d_one_phase[7];

//    U/VW-----UV/W----V/UW----VW/U----W/UV-----UW/V
extern const uint8_t ppd_pwm_io_state_two_phase[7];
extern const uint16_t ppd_psel_mask_port_a_two_phase[7];
extern const uint16_t ppd_psel_mask_port_d_two_phase[7];


extern PPD_RAMFUNC void ppd_settings_init(void);
extern PPD_RAMFUNC void ppd_values_init(void);
extern PPD_RAMFUNC void ppd_steps_init(void);
extern PPD_RAMFUNC void ppd_set_duty(uint16_t duty_value);
extern PPD_RAMFUNC void ppd_commutate_one_phase(int hs);
extern PPD_RAMFUNC void ppd_commutate_two_phase(int hs);

extern PPD_RAMFUNC void ppd_enable_driver();
extern PPD_RAMFUNC void ppd_enable_AIO9();

// The whole process of PPD
extern PPD_RAMFUNC void ppd_state_process(void);


#endif
