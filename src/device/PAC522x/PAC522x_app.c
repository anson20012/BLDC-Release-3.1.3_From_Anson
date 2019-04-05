
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


#ifdef PAC522x
 	 	 	 	 	 	 	 	 	   //      V     W     W     U     U     V
static const uint8_t pwm_io_state[7] = { 0, 0x02, 0x04, 0x04, 0x01, 0x01, 0x02 };  // H-bridge low-side driver(PA0¡¢PA1¡¢PA2) output high in GPIO mode

											 //      U        U       V       V       W       W
//static const uint16_t psel_mask_port_a[7] = { 0, 0x0081, 0x0081, 0x0104, 0x0104, 0x0410, 0x0410 };   // H-bridge driver use PWM with death-time mode
static const uint16_t psel_mask_port_a[7] = { 0, 0x0080, 0x0080, 0x0100,  0x0100 ,0x0400, 0x0400};  // H-bridge driver just high-side use PWM mode


//=============================================================================
/// @brief  This function get Vbus voltage
/// @param  None
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void calculate_ibus_current(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	// Read current from sequence 0
#ifdef R_3_SHUNT
	get_curent_adc_value(motor_ptr);
#else
	motor_ptr->Ibus_ADC = PAC5XXX_ADC->AS0R0.VAL;
#endif

    // Convert adc value into real current
#ifdef DIGITAL_LOW_PASS_FILTER_ENABLE
	motor_ptr->Iq_fb = fix16_mul_new_16_16(digital_low_pass_filter_for_Iq(fix16_from_int(motor_ptr->Ibus_ADC)), motor_ptr->I_total_factor);
#else
	motor_ptr->Iq_fb = fix16_mul_new_16_16(fix16_from_int(motor_ptr->Ibus_ADC), motor_ptr->I_total_factor);
#endif

//	motor_ptr->duty_percent_fix16 = fix16_mul_new_16_16((PAC5XXX_TIMERA->CTR4<<16),motor_ptr->one_div_pwm_timer_ticks_fix16);
//	motor_ptr->Iq_fb = fix16_mul_new_16_16(motor_ptr->Iq_fb,motor_ptr->duty_percent_fix16);
}

//=============================================================================
/// @brief  This function get Vbus voltage
/// @param  None
/// @return None
//=============================================================================
void calculate_vbus_voltage(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	motor_ptr->vbus_voltage_value = fix16_mul_new_16_16(VDD2P5DIV1023FIX16, (R1_PLUS_R2_BY_R2_RATIO_VBUS));
	motor_ptr->vbus_voltage_value = fix16_mul_new_16_16(fix16_from_int(VBUS_ADC_RESULT_CHANEL), motor_ptr->vbus_voltage_value)>>16;
}

//=============================================================================
/// @brief  This function set pwm duty cycle
/// @param  uint16_t temp_pwm_duty
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void set_duty(uint16_t temp_pwm_duty)
{
	PAC5XXX_TIMERA->CTR4 = temp_pwm_duty;
	PAC5XXX_TIMERA->CTR5 = temp_pwm_duty;
	PAC5XXX_TIMERA->CTR6 = temp_pwm_duty;
}

//=============================================================================
/// @brief  This function set pwm duty cycle for sine wave start up
/// @param  uint16_t temp_pwm_duty
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void sine_start_up_set_duty(uint16_t u_temp_pwm_duty,uint16_t v_temp_pwm_duty,uint16_t w_temp_pwm_duty)
{
	PAC5XXX_TIMERA->CTR4 = u_temp_pwm_duty;
	PAC5XXX_TIMERA->CTR5 = v_temp_pwm_duty;
	PAC5XXX_TIMERA->CTR6 = w_temp_pwm_duty;
}

//=============================================================================
/// @brief  This function commutate , change mosfet state,Use to select
///			port as GPIO or PWM mode ,Make sure commutation states are with
///			in array index range
/// @param  hs (current state)
/// @return None
//=============================================================================
PAC5XXX_RAMFUNC void commutate(int hs)
{
	if (hs <= 6)
	{
		pac5xxx_gpio_out_a(pwm_io_state[hs]);					// Set output state for H-bridge low-side driver in GPIO mode
		PAC5XXX_GPIOA->PSEL.s =  psel_mask_port_a[hs];	        // Set peripheral select state
	}
}

//=============================================================================
/// @brief  This function config amplifier gain value
/// @param  app_amplifier gain
/// @return None
//=============================================================================
void app_amplifier_gain_init(uint32_t app_amplifier_gain)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	switch(app_amplifier_gain)
	{
		case 1:
			motor_ptr->app_amplifier_gain_register = 1;
			break;
		case 2:
			motor_ptr->app_amplifier_gain_register = 2;
			break;
		case 4:
			motor_ptr->app_amplifier_gain_register = 3;
			break;
		case 8:
			motor_ptr->app_amplifier_gain_register = 4;
			break;
		case 16:
			motor_ptr->app_amplifier_gain_register = 5;
			break;
		case 32:
			motor_ptr->app_amplifier_gain_register = 6;
			break;
		case 48:
			motor_ptr->app_amplifier_gain_register = 7;
			break;
	}
#ifdef R_3_SHUNT
	pac5xxx_tile_register_write(ADDR_CFGAIO0, (0x43|(motor_ptr->app_amplifier_gain_register<<3)));	// 0x4A-->X1; 0x52-->X2; 0x5A-->X4; 0x62-->X8
	pac5xxx_tile_register_write(ADDR_CFGAIO1, 0x30);							// LPROT10
	pac5xxx_tile_register_write(ADDR_CFGAIO2, (0x43|(motor_ptr->app_amplifier_gain_register<<3)));	// 0x4A-->X1; 0x52-->X2; 0x5A-->X4; 0x62-->X8
	pac5xxx_tile_register_write(ADDR_CFGAIO3, 0x30);							// LPROT32
	pac5xxx_tile_register_write(ADDR_CFGAIO4, (0x43|(motor_ptr->app_amplifier_gain_register<<3)));	// 0x4A-->X1; 0x52-->X2; 0x5A-->X4; 0x62-->X8
	pac5xxx_tile_register_write(ADDR_CFGAIO5, 0x30);							// LPROT54
	pac5xxx_tile_register_write(ADDR_PROTINTM, 0x07);							// LPROT10&LPROT32&LPROT54-->0x07
#else
	pac5xxx_tile_register_write(ADDR_CFGAIO0, (0x43|(motor_ptr->app_amplifier_gain_register<<3)));	//0x4A-->X1; 0x52-->X2; 0x5A-->X4; 0x62-->X8
	pac5xxx_tile_register_write(ADDR_CFGAIO1, 0x30);							//LPROT10
	pac5xxx_tile_register_write(ADDR_PROTINTM, 0x01);							//LPROT10-->0x01
#endif
}

//=============================================================================
/// @brief  This function config over current value
/// @param  current_limit
/// @return None
//=============================================================================
void init_over_current_limit(uint32_t current_limit)
{
    // Set LPROT protection threshold
    pac5xxx_tile_register_write(ADDR_LPDAC0, (uint8_t)((current_limit >> 2) & 0xFF));   // HB: 8b MSB
    pac5xxx_tile_register_write(ADDR_LPDAC1, (uint8_t)((current_limit & 0x3)));         // LB: 2b LSB
}

//=============================================================================
/// @brief  This function reset oc flag
/// @param  None
/// @return None
//=============================================================================
void oc_reset(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
	uint16_t register_val;

	// Disable global interrupts until OC reset is complete
	__disable_irq();

	PAC5XXX_TIMERA->CTR4 = 0 ;									// Set 0 duty
	PAC5XXX_TIMERA->CTR5 = 0 ;									// Set 0 duty
	PAC5XXX_TIMERA->CTR6 = 0 ;									// Set 0 duty


    // Clear int/fault flags
    pac5xxx_tile_register_write(ADDR_PROTINTM, 0x00);
    while (pac5xxx_tile_register_read(ADDR_PROTSTAT));

#ifdef R_3_SHUNT
	pac5xxx_tile_register_write(ADDR_PROTINTM, 0x07); //LPROT10/32/54
#else
	pac5xxx_tile_register_write(ADDR_PROTINTM, 0x01); //LPROT10
#endif
    // Disable driver
    do {
        pac5xxx_tile_register_write(ADDR_ENDRV, 0);
        register_val = pac5xxx_tile_register_read(ADDR_ENDRV);
    } while ((register_val&0x1) != 0x0);

    // Enable driver
    do {
        pac5xxx_tile_register_write(ADDR_ENDRV, 1);
        register_val = pac5xxx_tile_register_read(ADDR_ENDRV);
    } while ((register_val&0x1) != 0x1);

	// Update status
    motor_ptr->app_status &= ~status_over_current;
	main_machine_state = STATE_MAIN_STOP_STANDBY;

	// Enable global interrupts
	__enable_irq();
}

//=============================================================================
/// @brief  This function enable pwm driver
/// @param  None
/// @return None
//=============================================================================
void pwm_enable(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

	// Set pwm duty variable to zero, disable all PWM outputs and clear close loop status
	PAC5XXX_TIMERA->CTR4 = 0 ;									// Set 0 duty
	PAC5XXX_TIMERA->CTR5 = 0 ;									// Set 0 duty
	PAC5XXX_TIMERA->CTR6 = 0 ;									// Set 0 duty

	// Set IO state of all pins to 0
	PAC5XXX_GPIOA->OUT.b &= (~0x3F);  /* PA[0,1,2,] UL, VL, WL, PA[3,4,5] UH, VH, WH */

	// Select GPIO peripheral for Port A
	PAC5XXX_GPIOA->PSEL.s |= (0x0595);

	// Turn on output enables
	PAC5XXX_GPIOA->OUTEN.b |= (0x38 | 0x07);

    // Enable driver manager and verify active - need to enable even in PAC5210 to get ENHS pin to work
    pac5xxx_tile_register_write(ADDR_ENDRV, 1);

    motor_ptr->app_status &= ~status_closed_loop;
}

//=============================================================================
/// @brief  This function disable pwm driver
/// @param  None
/// @return None
//=============================================================================
void pwm_disable(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;

    // Disable driver manager and verify active - need to enable even in PAC5210 to get ENHS pin to work
    pac5xxx_tile_register_write(ADDR_ENDRV, 0);

	// Set pwm duty variable to zero, disable all PWM outputs and clear close loop status
	PAC5XXX_TIMERA->CTR4 = 0 ;									// Set 0 duty
	PAC5XXX_TIMERA->CTR5 = 0 ;									// Set 0 duty
	PAC5XXX_TIMERA->CTR6 = 0 ;									// Set 0 duty

	// Set IO state of all pins to 0
	PAC5XXX_GPIOA->OUT.b &= (~0x3F);  /* PA[0,1,2,] UL, VL, WL, PA[3,4,5] UH, VH, WH */

	// Select GPIO peripheral for Port A
	PAC5XXX_GPIOA->PSEL.s &= (~0x0595);

	// Turn on output enables
	PAC5XXX_GPIOA->OUTEN.b |= (0x38 | 0x07);

	motor_ptr->app_status &= ~status_closed_loop;
}

//=============================================================================
/// @brief  This function config gpio
/// @param  None
/// @return None
//=============================================================================
void sensored_gpio_init(void)
{
#ifdef  HALL_VALUE_FROM_GPIOE
	PAC5XXX_GPIOE->OUTEN.P3 = 0;		//HALL U
	PAC5XXX_GPIOE->OUTEN.P4 = 0;		//HALL V
	PAC5XXX_GPIOE->OUTEN.P5 = 0;		//HALL W

	PAC5XXX_GPIOE->INE.P3 = 1;			//HALL U
	PAC5XXX_GPIOE->INE.P4 = 1;			//HALL V
	PAC5XXX_GPIOE->INE.P5 = 1;			//HALL W

	PAC5XXX_GPIOE->PU.P3 = 1;			//HALL U
	PAC5XXX_GPIOE->PU.P4 = 1;			//HALL V
	PAC5XXX_GPIOE->PU.P5 = 1;			//HALL W
#endif

#ifdef  HALL_VALUE_FROM_GPIOD
	PAC5XXX_GPIOD->OUTEN.P2 = 0;		//HALL U
	PAC5XXX_GPIOD->OUTEN.P3 = 0;		//HALL V
	PAC5XXX_GPIOD->OUTEN.P7 = 0;		//HALL W

	PAC5XXX_GPIOD->INE.P2 = 1;			//HALL U
	PAC5XXX_GPIOD->INE.P3 = 1;			//HALL V
	PAC5XXX_GPIOD->INE.P7 = 1;			//HALL W

	PAC5XXX_GPIOD->PU.P2 = 1;			//HALL U
	PAC5XXX_GPIOD->PU.P3 = 1;			//HALL V
	PAC5XXX_GPIOD->PU.P7 = 1;			//HALL W
#endif
}

#endif

