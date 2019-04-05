
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


// structural and enum body
Motor_Align_Go 					bldc_align_go;
BLDC_Controller            		bldc_m1;
eBLDC_Main_Machine_State    	main_machine_state;
eSub_Control_Machine_State 		control_machine_state;
eGet_Zero_Cross_Point_State     get_zero_cross_point_state;
eHall_Bemf_Switch_State     	hall_bemf_switch_state;


//================================================================================================
/// @brief  Main program that performs PAC configuration and handles real time task management
/// @param  None
/// @return None
//================================================================================================
int main(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	__disable_irq();

	// Initialize all peripherals
	peripheral_init();

	// Initialize CAFE
	cafe_init();

	// Initialize Systick time
	init_SysTick_time_base();

#if defined(Hall_MODE_ENABLE)||defined(Hall_Detect_IN_BEMF_MODE)
	// Initialize Hall detect IO
	sensored_gpio_init();
#endif

#ifdef  DEBUG_PWM_DAC_ENABLE
	debug_dac_init();
#endif

#ifdef SPEED_CTR_PPM_CMD_ENABLE
	speed_ctr_PPM_init();
#endif

	// Initialize motor object
	bldc_motor_init_parameters(motor_ptr);

	// Start ADC sequencer
	pac5xxx_adc_start();


#ifdef ENABLE_USER_PARAMETER
	user_param_fill();
//	motor_ptr->motor_enable_cmd = ENABLE;
#endif

	main_machine_state = STATE_MAIN_STOP_STANDBY;
	control_machine_state = STATE_CONTROL_IDLE;
	// Enable global interrupts
	__enable_irq();


	while(1)
	{

	}
}
