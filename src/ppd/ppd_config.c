
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

// main PPD struct
volatile PPD_Variables motor_control_ppd ;



// const group of PPD
const uint16_t ppd_phase_test[7] = {0,1,4,2,5,3,6};
const uint16_t ppd_phase_forhead[7] = {0,2,3,4,5,6,1};
const uint16_t ppd_phase_backward[7] = {0,6,1,2,3,4,5};

//==============================================
/// Define the IO_State
//==============================================
#ifdef PAC522x

													//    U/V----U/W---V/W---V/U---W/U---W/V
const uint8_t ppd_pwm_io_state_one_phase[7] = { 0, 0x02, 0x04, 0x04, 0x01, 0x01, 0x02 };
const uint16_t ppd_psel_mask_port_a_one_phase[7] = { 0, 0x0081, 0x0081, 0x0104, 0x0104, 0x0410, 0x0410 };						// DRLx=PWM mode
//static const uint16_t ppd_psel_mask_port_a_one_phase[7] = { 0, 0x0080, 0x0080, 0x0100,  0x0100 ,0x0400, 0x0400 };						// DRLx=GPIO mode


                                                    //        U/VW-----UV/W----V/UW----VW/U----W/UV-----UW/V
const uint8_t ppd_pwm_io_state_two_phase[7] = { 0, 0x02|0x04, 0x04, 0x01|0x04, 0x01, 0x01|0x02, 0x02 };
const uint16_t ppd_psel_mask_port_a_two_phase[7] = { 0, 0x0081, 0x0081|0x0104, 0x0104, 0x0104|0x0410, 0x0410, 0x0081|0x0410 };	// DRLx=PWM mode
//static const uint16_t ppd_psel_mask_port_a_two_phase[7] = { 0, 0x0080, 0x0080|0x0100, 0x0100, 0x0100|0x0400 ,0x0400, 0x0080|0x0400 };	// DRLx=GPIO mode

#endif



#ifdef PAC523x

//    U/V----U/W---V/W---V/U---W/U---W/V
const uint8_t ppd_pwm_io_state_one_phase[7] = { 0, 0x02, 0x04, 0x04, 0x01, 0x01, 0x02 };
const uint16_t ppd_psel_mask_port_a_one_phase[7] = { 0, 0x0081, 0x0081, 0x0104, 0x0104, 0x0410, 0x0410 };						// DRLx=PWM mode
//static const uint16_t ppd_psel_mask_port_a_one_phase[7] = { 0, 0x0080, 0x0080, 0x0100,  0x0100 ,0x0400, 0x0400 };						// DRLx=GPIO mode


//        U/VW-----UV/W----V/UW----VW/U----W/UV-----UW/V
const uint8_t ppd_pwm_io_state_two_phase[7] = { 0, 0x02|0x04, 0x04, 0x01|0x04, 0x01, 0x01|0x02, 0x02 };
const uint16_t ppd_psel_mask_port_a_two_phase[7] = { 0, 0x0081, 0x0081|0x0104, 0x0104, 0x0104|0x0410, 0x0410, 0x0081|0x0410 };	// DRLx=PWM mode
//static const uint16_t ppd_psel_mask_port_a_two_phase[7] = { 0, 0x0080, 0x0080|0x0100, 0x0100, 0x0100|0x0400 ,0x0400, 0x0080|0x0400 };	// DRLx=GPIO mode


#endif



#ifdef PAC525x

                                                   //      U/V---U/W---V/W---V/U---W/U---W/V
const uint8_t ppd_pwm_io_state_one_phase[7] = { 0, 0x02, 0x04, 0x04, 0x01, 0x01, 0x02 };
const uint16_t ppd_psel_mask_port_a_one_phase[7] = { 0, 0x1001, 0x1001, 0x4004, 0x4004, 0x0010, 0x0010};	//H-bridge driver use PWM with death-time mode
//static const uint16_t ppd_psel_mask_port_a_one_phase[7] = { 0, 0x1000, 0x1000, 0x4000, 0x4000, 0x0000, 0x0000,};	//H-bridge driver just high-side(PA6¡¢PA7) use PWM mode
const uint16_t ppd_psel_mask_port_d_one_phase[7] = { 0, 0x0005, 0x0005, 0x0005, 0x0005, 0x4005, 0x4005};	//H-bridge driver just high-side(PD7) select to PAMA6,PD0\PD1 select to SWD mode


                                                  //           U/VW---UV/W----V/UW-----VW/U----W/UV-----UW/V
const uint8_t ppd_pwm_io_state_two_phase[7] = { 0, 0x02|0x04, 0x04, 0x01|0x04, 0x01, 0x01|0x02, 0x02 };
const uint16_t ppd_psel_mask_port_a_two_phase[7] = { 0, 0x1001, 0x1001|0x4004, 0x4004, 0x4004|0x0010, 0x0010, 0x0010|0x1001};	//H-bridge driver use PWM with death-time mode
//static const uint16_t ppd_psel_mask_port_a_two_phase[7] = { 0, 0x1000, 0x1000|0x4000, 0x4000, 0x4000|0x0000, 0x0000, 0x0000|0x1000};	//H-bridge driver just high-side(PA6¡¢PA7) use PWM mode
const uint16_t ppd_psel_mask_port_d_two_phase[7] = { 0, 0x0005, 0x0005|0x0005, 0x0005, 0x0005|0x4005, 0x4005, 0x4005|0x0005};	//H-bridge driver just high-side(PD7) select to PAMA6,PD0\PD1 select to SWD mode

#endif



//==============================================
///	Functions
//==============================================

//=====================================================================
/// @brief  Fill the PPD settings with default values
/// @param  None
/// @return None
//=====================================================================
PPD_RAMFUNC void ppd_settings_init(void)
{
	motor_control_ppd.ppd_detect_rising_tick = DF_PPD_DETECT_RISING_TICK ;
	motor_control_ppd.ppd_detect_falling_tick = DF_PPD_DETECT_FALLING_TICK ;
	motor_control_ppd.ppd_detect_count = DF_PPD_DETECT_COUNT ;
	motor_control_ppd.ppd_detect_blank_count = DF_PPD_BLANK_COUNT ;

	motor_control_ppd.ppd_smooth_count_target = DF_PPD_SMOOTH_COUNT ;
	motor_control_ppd.ppd_tune_duty_ramp = DF_PPD_DUTY_RAMP ;
	motor_control_ppd.ppd_tuning_last_count = DF_PPD_TUNING_LAST_COUNT ;
}

//=====================================================================
/// @brief  init the values which will be used in the PPD process
/// @param  None
/// @return None
//=====================================================================
PPD_RAMFUNC void ppd_values_init(void)
{
	//PPD_Value_Init
	motor_control_ppd.ppd_tune_duty = 0 ;
	motor_control_ppd.ppd_smooth_count = 0 ;

#ifdef IPD_IN_PPD_ENABLE
	motor_control_ppd.ipd_mode = 1 ;
	motor_control_ppd.ppd_smooth_count_target = 0 ;
	motor_control_ppd.ipd_tune_duty = motor_control_ppd.ppd_tune_duty_ramp ;
#else
	motor_control_ppd.ipd_mode = 0 ;
#endif
}



//=====================================================================
/// @brief  init the steps
/// @param  None
/// @return None
//=====================================================================
PPD_RAMFUNC void ppd_steps_init(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	motor_ptr->app_status &= ~status_closed_loop;
	motor_ptr->app_status &= ~status_motor_stall;
	motor_ptr->app_status &= ~status_lose_angle;
	motor_ptr->app_status &= ~status_open_phase;


	pid_reset(&motor_ptr->speed_pid);

	motor_ptr->wait_30degree_enable = 0;
	motor_ptr->samplecounter = 0;
	motor_ptr->motorspeed_sum = 0;
	for (motor_ptr->speed_sample_index = 0; motor_ptr->speed_sample_index < NUM_SPEED_SAMPLES; motor_ptr->speed_sample_index++)
		motor_ptr->motorspeed_buffer[motor_ptr->speed_sample_index] = 0;
	motor_ptr->speed_sample_index = 0;
	bldc_align_go.current_speed_hz = 0;

	// Initialize current control PI
	pid_reset(&motor_ptr->Iq_pid);
	motor_ptr->Iq_ref = 0;
	motor_ptr->Iq_pid.PI_sat = 0xa0000;
	motor_ptr->Iq_pid.I_prev = 0xa0000;

	ppd_values_init();
}







//=====================================================================
/// @brief  Set the PWM Duty which need to fit the main process
/// @param  the duty value we set
/// @return None
//=====================================================================
PPD_RAMFUNC void ppd_set_duty(uint16_t duty_value)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	// these two value is used in the main process
	motor_ptr->temp_pwm_duty = duty_value ;
}

//=====================================================================
/// @brief  Commutate the phase of PPD output which is
/// 			U/V--U/W--V/W--V/U--W/U--W/V
/// @param  High Side Phase
/// @return None
//=====================================================================
PPD_RAMFUNC void ppd_commutate_one_phase(int hs)
{
	// Make sure commutation states are with in array index range
	if (hs <= 6)
	{
#ifdef PAC522x
		pac5xxx_gpio_out_a(ppd_pwm_io_state_one_phase[hs]);				// Set output state for GPIO pins
		PAC5XXX_GPIOA->PSEL.s = ppd_psel_mask_port_a_one_phase[hs];		// Set peripheral select state
#endif

#ifdef PAC523x
		pac5xxx_gpio_out_a(ppd_pwm_io_state_one_phase[hs]);				// Set output state for GPIO pins
		PAC5XXX_GPIOA->PSEL.s = ppd_psel_mask_port_a_one_phase[hs];		// Set peripheral select state
#endif

#ifdef PAC525x
		pac5xxx_gpio_out_a(ppd_pwm_io_state_one_phase[hs]);				// Set output state for GPIO pins
		PAC5XXX_GPIOA->PSEL.s = ppd_psel_mask_port_a_one_phase[hs];		// Set peripheral select state
		PAC5XXX_GPIOD->PSEL.s = ppd_psel_mask_port_d_one_phase[hs];     // Set peripheral select state
#endif
	}
}



//=====================================================================
/// @brief  Commutate the phase of PPD output which is
/// 			U/VW--UV/W--V/UW--VW/U--W/UV--UW/V
/// @param  High Side Phase
/// @return None
//=====================================================================
PPD_RAMFUNC void ppd_commutate_two_phase(int hs)
{
	// Make sure commutation states are with in array index range
	if (hs <= 6)
	{
#ifdef PAC522x
		pac5xxx_gpio_out_a(ppd_pwm_io_state_two_phase[hs]);				// Set output state for GPIO pins
		PAC5XXX_GPIOA->PSEL.s = ppd_psel_mask_port_a_two_phase[hs];		// Set peripheral select state
#endif

#ifdef PAC523x
		pac5xxx_gpio_out_a(ppd_pwm_io_state_two_phase[hs]);				// Set output state for GPIO pins
		PAC5XXX_GPIOA->PSEL.s = ppd_psel_mask_port_a_two_phase[hs];		// Set peripheral select state
#endif

#ifdef PAC525x
		pac5xxx_gpio_out_a(ppd_pwm_io_state_two_phase[hs]);				// Set output state for GPIO pins
		PAC5XXX_GPIOA->PSEL.s = ppd_psel_mask_port_a_two_phase[hs];		// Set peripheral select state
		PAC5XXX_GPIOD->PSEL.s = ppd_psel_mask_port_d_two_phase[hs];     // Set peripheral select state
#endif
	}
}





//=====================================================================
/// @brief  enable the driver (depends on the device)
/// @param  None
/// @return None
//=====================================================================
PPD_RAMFUNC void ppd_enable_driver()
{
	pac5xxx_tile_register_write(ADDR_ENDRV, 1);
}




//=====================================================================
/// @brief  enable the AIO9 (depends on the device)
/// @param  None
/// @return None
//=====================================================================
PPD_RAMFUNC void ppd_enable_AIO9()
{
#ifndef USE_ADC_GET_BEMF_MODE_ENABLE
	pac5xxx_tile_register_write(ADDR_CFGAIO9, slcomp_mux[motor_control_ppd.ppd_result_phase]);
#endif
}








