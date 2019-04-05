
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
/// @brief  This is the interrupt handler for Timer B, which is used for a 1ms time tick.
///         When this interrupt is serviced, it will run the control loop for the motor then
///          clear the interrupt flag.
/// @param  None
/// @return None
//==================================================================================================
void TimerB_IRQHandler(void)
{
#ifdef SPEED_CTR_PPM_CMD_ENABLE
	if(PAC5XXX_TIMERB->CCTRL0.CCINT)
	{
		if(PAC5XXX_GPIOD->IN.P2)
		{
			low2high_capture_read_count_value = PAC5XXX_TIMERB->CTR0 ;  //store low2high edge base time counts of timerB
		}
		else
		{
			high2low_capture_read_count_value = PAC5XXX_TIMERB->CTR0 ;  //store high2low edge base time counts of timerB
		}

		PAC5XXX_TIMERB->CTL.CLR = 1;  //clear timerB and stop timerB
		PAC5XXX_TIMERB->CTL.CLR = 0;  //restart timerB ,base time counts start from 0


		PAC5XXX_TIMERB->CCTRL0.CCINT = 1;    //clear capture interrupt flag
	}
#endif
	// Clear interrupt flag before exit
	pac5xxx_timer_b_base_int_clear();
}
