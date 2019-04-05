
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


#define  SYSTICK_TICKS   500000



//==================================================================================================
/// @brief  This function initialize systick configuration, set the Systick-ISR frequency to 100Hz;
/// @param  None
/// @return None
//==================================================================================================
void init_SysTick_time_base(void)
{
    SysTick_Config(SYSTICK_TICKS);
    NVIC_SetPriority(SysTick_IRQn, 3);
    SysTick->VAL = SYSTICK_TICKS;
}

//==================================================================================================
/// @brief  The Systick-ISR frequency is 100Hz(10ms), in this interrupt, process some protecting event detect,
/// @param  None
/// @return None
//==================================================================================================
void SysTick_Handler(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	calculate_vbus_voltage();
#ifdef  VBUS_MAX_MIN_CHECK_ENABLE
	vbus_voltage_Max_Min_protect();
#endif

#ifdef LOSE_ANGLE_RESTART
	lose_angle_no_commutate_check();
#endif

#ifdef SPEED_CTR_ADC_CMD_ENABLE
	get_speed_ctr_adc_cmd();
#endif

#ifdef SPEED_CTR_PPM_CMD_ENABLE
	get_speed_ctr_PPM_cmd();
#endif

#ifdef ENABLE_POWER_ON_START_MOTOR
	if(motor_ptr->vbus_voltage_value < AUTO_STOP_VBUS)
	{
		motor_ptr->motor_enable_cmd = DISABLE;
	}
	else if(motor_ptr->vbus_voltage_value > AUTO_START_VBUS)
	{
		motor_ptr->motor_enable_cmd = ENABLE;
	}
#endif


	main_state_machine();

	/* Clear pending interrupt */
    NVIC_ClearPendingIRQ(SysTick_IRQn);
}




