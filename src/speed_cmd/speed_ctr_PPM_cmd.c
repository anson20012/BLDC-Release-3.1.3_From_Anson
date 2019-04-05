
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

#include "include.h"


uint16_t	low2high_capture_read_count_value;
uint16_t	high2low_capture_read_count_value;
fix16_t		speed_ctr_PPM_duty_fix16;
fix16_t		speed_ctr_PPM_freq_fix16;
fix16_t		speed_ctr_PPM_hz_fix16;

//===================================================================================
/// @brief  This function initialize timerB as capture mode
/// @param  None
/// @return None
//===================================================================================
void speed_ctr_PPM_init(void)
{
#ifdef SPEED_CTR_PPM_CMD_ENABLE
	/* Configure timerB for PPM */
	pac5xxx_timer_clock_config(TimerB,TxCTL_CS_HCLK,TxCTL_PS_DIV64);
	pac5xxx_timer_base_config(TimerB,TIMERB_PERIOD_TICKS_PPM,0,TxCTL_MODE_UP,0);
	pac5xxx_timer_io_select_pwmb0_pd2();
	pac5xxx_timer_cctrl_capture_config(TimerB, 1, 0, 1, TxCCTL_CED_BOTH);
	NVIC_SetPriority(TimerB_IRQn, 1);
	NVIC_EnableIRQ(TimerB_IRQn);

	PAC5XXX_GPIOD->PU.P2 = 1;
	PAC5XXX_GPIOD->OUTEN.P2 = 0;

	low2high_capture_read_count_value = high2low_capture_read_count_value>>10;
	high2low_capture_read_count_value = 0;
#endif
}

//===============================================================================================
/// @brief  This function capture pwm duty or frequency value and transform to speed reference
/// @param  None
/// @return None
//===============================================================================================
void get_speed_ctr_PPM_cmd(void)
{
#ifdef SPEED_CTR_PPM_CMD_ENABLE
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	/* please choose one way for PPM control speed */
	#if 1  //PPM duty control speed
		speed_ctr_PPM_duty_fix16 = fix16_div((high2low_capture_read_count_value<<10),\
				((high2low_capture_read_count_value + low2high_capture_read_count_value)<<10));
		speed_ctr_PPM_hz_fix16 = fix16_mul_new_16_16(speed_ctr_PPM_duty_fix16,SPEED_CTR_PPM_CMD_MAX);
		motor_ptr->motor_close_loop_speed = speed_ctr_PPM_hz_fix16;
	#endif

	#if 0  //PPM frequency control speed
		speed_ctr_PPM_freq_fix16 = fix16_div(ONE_SECOND_TIMERB_COUNTS,\
				((high2low_capture_read_count_value + low2high_capture_read_count_value)<<10));
		speed_ctr_PPM_hz_fix16 = speed_ctr_PPM_freq_fix16;
		motor_ptr->motor_close_loop_speed = speed_ctr_PPM_hz_fix16;
	#endif

#endif
}
