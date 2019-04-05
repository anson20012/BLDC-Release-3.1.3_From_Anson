
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





//==================================================================================================
/// @brief  TThis is the interrupt handler for Timer A. This interrupt handler will execute at the beginning
///         of the PWMA1 compare. In this interrupt just, timerA_isr_counts added,
///         for ADC-isr division processing "main_state_machine"
/// @param  None
/// @return None
//==================================================================================================
PAC5XXX_RAMFUNC void TimerA_IRQHandler(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	if (PAC5XXX_TIMERA->CCTRL1.CCINT)
	{
		motor_ptr->timerA_isr_counts++;

		// Clear CCR1 interrupt flag
		pac5xxx_timer_a_cctrl_1_int_clear();
	}
}
