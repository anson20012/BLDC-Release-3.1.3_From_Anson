
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

Pwm_Dac_Debug   pwm_dac_debug_variable;

#ifdef  DEBUG_PWM_DAC_ENABLE

fix16_t debug_scale_factor1;
fix16_t debug_scale_factor2;


My_Debug_PWM_DAC Test_PWM_FIX16 [PWM_DEBUG_ARRAY_LENGTH] =
{
		// Case 0: SEND_SP_REF_SP_FEEDBACK_SP_PI_SAT_OUT_USING_PWM
		{&bldc_m1.Iq_ref, &bldc_m1.Iq_fb},
		// Case 1: SEND_IQ_REF_IQ_FB_IQ_PI_SAT_OUT_USING_PWM
		{&bldc_m1.Iq_ref, &bldc_m1.Iq_fb},
		// Case 2: SEND_REAL_ANGLE_EST_ANGLE_VQ_OUT_USING_PWM
		{&bldc_m1.Iq_ref, &bldc_m1.Iq_fb},
		// Case 3: SEND_ID_REF_ID_FB_ID_PI_SAT_OUT_USING_PWM
		{&bldc_m1.Iq_ref, &bldc_m1.Iq_fb},
		// Case 4: SEND_IALPHA_IBETA_VQ_OUT_USING_PWM
		{&bldc_m1.Iq_ref, &bldc_m1.Iq_fb},
		// Case 5: SEND_VQ_VD_VALPHA_USING_PWM
		{&bldc_m1.Iq_ref, &bldc_m1.Iq_fb},
		// Case 6: SEND_VQ_VD_VALPHA_USING_PWM
		{&bldc_m1.Iq_ref, &bldc_m1.Iq_fb},
		// Case 7: SEND_VQ_VD_VALPHA_USING_PWM
		{&bldc_m1.Iq_ref, &bldc_m1.Iq_fb},
		// Case 8: SEND_VQ_VD_VALPHA_USING_PWM
		{&bldc_m1.Iq_ref, &bldc_m1.Iq_fb},
		// Case 9: SEND_VQ_VD_VALPHA_USING_PWM
		{&bldc_m1.Iq_ref, &pwm_dac_debug_variable.ibus_adc_fix16},
		// Case 10: SEND_IQ_NON_FILT_AND_FILT_VALUES
		{&pwm_dac_debug_variable.app_speed_ref_fix16, &pwm_dac_debug_variable.app_measured_speed_fix16},
};

My_Debug_PWM_DAC* test_ptr1 = (My_Debug_PWM_DAC*) &Test_PWM_FIX16[0];

//=============================================================================
/// @brief  some variable format need change for DAC debug
/// @param  None
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void pwm_dac_debug_variable_to_fix16(void)
{

//	pwm_dac_debug_variable.app_speed_ref_fix16 = fix16_div(TIMER_D_FREQ_F16,(app_speed_ref<<6));
//	pwm_dac_debug_variable.app_measured_speed_fix16 = fix16_div(TIMER_D_FREQ_F16,(app_measured_speed<<6));

//	pwm_dac_debug_variable.sl_current_state_fix16 = sl_current_state<<16;

	pwm_dac_debug_variable.ibus_adc_fix16 = PAC5XXX_ADC->AS0R0.VAL<<16;
}

//=============================================================================
/// @brief  TimerB config for DAC debug
/// @param  None
/// @return None
//=============================================================================
void debug_dac_init(void)
{
	PAC5XXX_GPIOD->OUTEN.P2 = 1;
	PAC5XXX_GPIOD->OUTEN.P3 = 1;

	PAC5XXX_GPIOD->PU.P2 = 1;
	PAC5XXX_GPIOD->PU.P3 = 1;

	pac5xxx_timer_clock_config(TimerB, TxCTL_CS_HCLK, TxCTL_PS_DIV1);
	pac5xxx_timer_base_config(TimerB, TIMERB_TICKS_DEBUG_DAC_45KHZ, 0, TxCTL_MODE_UP, 0);	// Configure TimerB
	pac5xxx_timer_cctrl_config(TimerB, 0, 0, 1);
	pac5xxx_timer_cctrl_config(TimerB, 1, 0, 1);

	pac5xxx_timer_io_select_pwmb0_pd2();
	pac5xxx_timer_io_select_pwmb1_pd3();
}

//=============================================================================
/// @brief  set pwm duty cycle for DAC debug
/// @param  None
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void bldc_send_data_set_out_using_pwm(void)
{
	fix16_t Debug_pwm_duty_pd2;
	fix16_t Debug_pwm_duty_pd3;

	Debug_pwm_duty_pd2 = fix16_div((*test_ptr1->ptr1_value), (debug_scale_factor1<<16));
	Debug_pwm_duty_pd2 = fix16_mul_new_16_16(Debug_pwm_duty_pd2, (TIMERB_TICKS_DEBUG_DAC_45KHZ<<16));
	Debug_pwm_duty_pd2 = Debug_pwm_duty_pd2>>16;

	Debug_pwm_duty_pd3 = fix16_div((*test_ptr1->ptr2_value), (debug_scale_factor2<<16));
	Debug_pwm_duty_pd3 = fix16_mul_new_16_16(Debug_pwm_duty_pd3, (TIMERB_TICKS_DEBUG_DAC_45KHZ<<16));
	Debug_pwm_duty_pd3 = Debug_pwm_duty_pd3>>16;

	PAC5XXX_TIMERB->CTR0 = (TIMERB_TICKS_DEBUG_DAC_45KHZ>>1) + Debug_pwm_duty_pd2;
	PAC5XXX_TIMERB->CTR1 = (TIMERB_TICKS_DEBUG_DAC_45KHZ>>1) + Debug_pwm_duty_pd3;
}

#endif
