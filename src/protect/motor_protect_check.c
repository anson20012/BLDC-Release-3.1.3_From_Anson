
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


uint8_t  stall_detect_keep_counts_1,stall_detect_keep_counts_2;
uint32_t over_load_keep_counts;

//==================================================================================================
/// @brief  This function over/under voltage,then protect
/// @param  None
/// @return None
//==================================================================================================
#ifdef VBUS_MAX_MIN_CHECK_ENABLE
void vbus_voltage_Max_Min_protect(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	if(motor_ptr->vbus_voltage_value >= MAX_VBUS)
	{
		pwm_disable();

		motor_ptr->motor_enable_cmd = DISABLE;
		main_machine_state = STATE_MAIN_STOP_STANDBY;
		motor_ptr->app_status |= status_Vbus_overvoltage;
	}
	if(motor_ptr->vbus_voltage_value <= MIN_VBUS)
	{
		pwm_disable();

		motor_ptr->motor_enable_cmd = DISABLE;
		main_machine_state = STATE_MAIN_STOP_STANDBY;
		motor_ptr->app_status |= status_Vbus_undervoltage;
	}
	if(motor_ptr->motor_enable_cmd)
	{
		if((motor_ptr->vbus_voltage_value < MAX_VBUS)&&(motor_ptr->vbus_voltage_value > MIN_VBUS))
		{
			motor_ptr->app_status &= ~status_Vbus_overvoltage;
			motor_ptr->app_status &= ~status_Vbus_undervoltage;
		}
	}
}
#endif





//==================================================================================================
/// @brief  This function no commutate,then protect
/// @param  None
/// @return None
//==================================================================================================
#ifdef	LOSE_ANGLE_RESTART
void lose_angle_no_commutate_check(void)
{	
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	if(bldc_align_go.align_and_go_state == STATE_STARTUP_DONE)
	{
		motor_ptr->motor_lose_angle_count++;
		if(motor_ptr->motor_lose_angle_count >= LOSE_ANGLE_TIME_COUNTS)
		{
			/*!< Set motor status to disable */
			motor_ptr->app_status &= ~status_motor_enabled;

			/*!< Disable PWM output */
			pwm_disable();

			/* Set motor align and go state machine to 1st state which is STATE_STARTUP_INIT */
			//bldc_align_go.align_and_go_state = STATE_STARTUP_ALIGN;
			bldc_align_go.align_and_go_state = STATE_STARTUP_INIT;
			main_machine_state = STATE_MAIN_STOP_STANDBY;
			motor_ptr->motor_lose_angle_count = 0;

			motor_ptr->app_status |= status_lose_angle;
		}
	}
}
#endif


