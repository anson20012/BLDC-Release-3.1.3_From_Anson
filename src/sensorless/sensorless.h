
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

#ifndef SENSORLESS_H
#define SENSORLESS_H

#include "include.h"




// isr_systick.c
void init_SysTick_time_base(void);

// PAC522x_init.c
void peripheral_init(void);
void cafe_init(void);

// main_state_machine.c
void main_state_machine(void);
void control_state_machine(void);

// align_and_go.c
void ready_for_bemf_mode(void);
void square_wave_start_up_process(void);
void sine_wave_start_up_process(void);

// bldc_misc_functions.c
PAC5XXX_RAMFUNC  fix16_t digital_low_pass_filter_for_Iq (fix16_t digital_low_pass_filter_input);
void bldc_motor_iq_ref_ramp(BLDC_Controller* motor_ptr);
void bldc_motor_speed_ref_ramp(BLDC_Controller* motor_ptr);
void bldc_motor_init_current_control_pid (BLDC_Controller* motor_ptr);
void bldc_motor_init_parameters(BLDC_Controller* motor_ptr);
PAC5XXX_RAMFUNC fix16_t HertzToTicks(int Hertz, fix16_t Freq);
PAC5XXX_RAMFUNC void get_curent_adc_value(BLDC_Controller* motor_ptr);
void set_fault(uint16_t blink_tick_count);
void motor_stop_state_reset(void);

// get_pwm_duty_cycle.c
PAC5XXX_RAMFUNC void pwm_duty_control(void);

// get_rotor_position.c
PAC5XXX_RAMFUNC void get_zero_crossing_point(void);

#endif



