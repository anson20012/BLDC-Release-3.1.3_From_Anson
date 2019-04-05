
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


//================================================================================================================
/// @brief  This is the interrupt handler for GPIOB, which is where the IRQ1 pin resides. If IRQ1 pin goes low.
///         If OC event happen, it will trigger gpioB0 interrupt£¬in GpioB-ISR£¬set some status£»
/// @param  None
/// @return None
//================================================================================================================
void GpioB_IRQHandler(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	if (pac5xxx_gpio_int_flag_set_b() & NIRQ1_PIN_MASK)
	{
		// In case of over current interrupt, disable PWM clear motor enable flag
		pwm_disable();
		motor_ptr->app_status |= status_over_current;
		main_machine_state = STATE_MAIN_STOP_STANDBY;

		// Set motor status to disable
		motor_ptr->app_status &= ~status_open_loop;
		motor_ptr->app_status &= ~status_closed_loop;
		motor_ptr->app_status &= ~status_motor_enabled;
		motor_ptr->app_status &= ~status_pwm_duty_loop;

		// Set motor align and go state machine to 1st state which is STATE_STARTUP_INIT
		bldc_align_go.align_and_go_state =  STATE_STARTUP_INIT;
		// Clear interrupt flag before exit
		pac5xxx_gpio_int_flag_clear_b(NIRQ1_PIN_MASK);
	}
	pac5xxx_gpio_int_flag_clear_b(0xFF);
}
