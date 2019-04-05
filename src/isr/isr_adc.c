
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

//========================================================================================
/// ADC Interrupt Handler routine
/// ADC convert be triggered by PWMA0 low-to-high edge, completed trigger ADC interrupt,
/// the frequency is same with PWMA's frequency(32khz);
/// In ADC-ISR, get ADC value, process "main_state_machine", do PWM-DAC-debug
//========================================================================================
void ADC_IRQHandler(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	// control frequency division
	if(motor_ptr->timerA_isr_counts >= motor_ptr->main_machine_control_counts)
	{
		motor_ptr->timerA_isr_counts = 0;

	    // Call current calculate
		calculate_ibus_current();

	    // Call control state machine
		control_state_machine();
	}

    // Call PWM DAC for debugging scoped variable
#ifdef DEBUG_PWM_DAC_ENABLE
	pwm_dac_debug_variable_to_fix16();
	bldc_send_data_set_out_using_pwm();
#endif


	// Clear interrupt flag
	PAC5XXX_ADC->ADCINT.w = ((PAC5XXX_ADC->ADCINT.w & ~ADCINT_ALL) | ADCINT_AS0INT);

}


