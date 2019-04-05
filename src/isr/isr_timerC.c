
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


//======================================================================================================================
/// @brief  This timerC interrupt frequency is 100Khz, in this interrupt, scan BEMF cross-zero-o-point in BEMF mode;
///         scan hall value and commutate in HALL mode;
/// @param  None
/// @return None
//======================================================================================================================
PAC5XXX_RAMFUNC void TimerC_IRQHandler(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

#ifdef 	Hall_MODE_ENABLE
	#ifdef	Hall_BEMF_SWITCH_MODE_ENABLE
		hall_bemf_switch_mode();
	#else
		motor_ptr->sample = AIO789_COMP_OUTPUT;
		get_hall_value_and_change_mos_state();
	#endif
#else
	get_zero_crossing_point();
#endif


	// Clear interrupt flag before exit
	PAC5XXX_TIMERC->CTL.INT = 1;
}
