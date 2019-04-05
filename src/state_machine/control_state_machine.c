
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

//===================================================================================
/// @brief  This function is control  process (32Khz)
/// @param  None
/// @return None
//===================================================================================
void control_state_machine(void)
{
	BLDC_Controller* motor_ptr;
	motor_ptr = &bldc_m1;
#ifdef SIM_ENABLE
	Sim_Detect* sim_ptr;
	sim_ptr = &bldc_sim_m1;
#endif

	switch(control_machine_state)
	{
		case STATE_CONTROL_IDLE :
			break;

		case STATE_CONTROL_OL :
			if(motor_ptr->charge_done_flag != 1)
			{
				if(motor_ptr->charge_delay_count++ >= DELAY_CHARGE_COUNTS)
				{
					motor_ptr->charge_delay_count = 0 ;
					motor_ptr->charge_done_flag = 1 ;
				}
				else if (motor_ptr->charge_delay_count == 0 )
				{
					// this is for SIM
					__disable_irq();
					pac5xxx_tile_register_write(ADDR_ENDRV, 1);
					__enable_irq();
				}
			}
			else
			{

				// give rotor position in align and go mode
				#ifdef PPD_START_UP_ENABLE
					ppd_state_process();
					// Update timer CCR value for required duty cycle
					set_duty(motor_ptr->temp_pwm_duty);
				#else
					// call current control PI to control motor torque is open loop
					pid_run(&(motor_ptr->Iq_pid), fix16_sub(motor_ptr->Iq_ref, motor_ptr->Iq_fb)); //0, 
					if(motor_ptr->Iq_pid.PI_sat > (bldc_align_go.align_go_duty_cycle<<16))
					{
						pid_reset(&motor_ptr->Iq_pid);
						motor_ptr->Iq_pid.aw_prev = bldc_align_go.align_go_duty_cycle<<16;  //156  
						motor_ptr->Iq_pid.I_prev = bldc_align_go.align_go_duty_cycle<<16;   //uint16_t converts to fix16_t need <<16
						motor_ptr->Iq_pid.PI_sat = bldc_align_go.align_go_duty_cycle<<16;
					}

					#ifdef SINE_WAVE_START_UP_ENABLE
					       //fix16_t converts to uint16_t, need >>16
						motor_ptr->temp_pwm_duty_u = fix16_mul_new_16_16(motor_ptr->Iq_pid.PI_sat,bldc_align_go.wave_pwm_duty_u)>>16; 
						motor_ptr->temp_pwm_duty_v = fix16_mul_new_16_16(motor_ptr->Iq_pid.PI_sat,bldc_align_go.wave_pwm_duty_v)>>16;
						motor_ptr->temp_pwm_duty_w = fix16_mul_new_16_16(motor_ptr->Iq_pid.PI_sat,bldc_align_go.wave_pwm_duty_w)>>16;
							// Update timer CCR value for required duty cycle
						sine_start_up_set_duty(motor_ptr->temp_pwm_duty_u,motor_ptr->temp_pwm_duty_v,motor_ptr->temp_pwm_duty_w);
					#else
						motor_ptr->temp_pwm_duty = motor_ptr->Iq_pid.PI_sat>>16;
						// Update timer CCR value for required duty cycle
						set_duty(motor_ptr->temp_pwm_duty);
					#endif
				#endif
			}
			break;

		case STATE_CONTROL_OL_SWITCH_CL_WAIT :
			#ifndef PPD_START_UP_ENABLE
				// Running current close loop
				pid_run(&(motor_ptr->Iq_pid), fix16_sub(motor_ptr->Iq_ref, motor_ptr->Iq_fb));
				if(motor_ptr->Iq_pid.PI_sat > (bldc_align_go.align_go_duty_cycle<<16))
				{
					pid_reset(&motor_ptr->Iq_pid);
					motor_ptr->Iq_pid.aw_prev = bldc_align_go.align_go_duty_cycle<<16;
					motor_ptr->Iq_pid.I_prev = bldc_align_go.align_go_duty_cycle<<16;
					motor_ptr->Iq_pid.PI_sat = bldc_align_go.align_go_duty_cycle<<16;
				}
				motor_ptr->temp_pwm_duty = motor_ptr->Iq_pid.PI_sat>>16;

			#endif
				// Update timer CCR value for required duty cycle
				set_duty(motor_ptr->temp_pwm_duty);
			break;

		case STATE_CONTROL_CL_SPEED :
			pid_run(&motor_ptr->speed_pid, fix16_sub((motor_ptr->app_measured_speed<<15), (motor_ptr->app_speed_ref<<15)));
			// In close loop current control PI uses speed PI output as it's input for Iq Ref
			motor_ptr->Iq_ref = motor_ptr->speed_pid.PI_sat;
			// Running close current loop
			pid_run(&(motor_ptr->Iq_pid), fix16_sub(motor_ptr->Iq_ref, motor_ptr->Iq_fb));
			motor_ptr->temp_pwm_duty = motor_ptr->Iq_pid.PI_sat>>16;
			// Update timer CCR value for required duty cycle
			set_duty(motor_ptr->temp_pwm_duty);
			break;

		case STATE_CONTROL_CL_CURRENT :
			motor_ptr->Iq_ref = motor_ptr->closed_loop_current_command;
			// Running close current loop
			pid_run(&(motor_ptr->Iq_pid), fix16_sub(motor_ptr->Iq_ref, motor_ptr->Iq_fb));
			motor_ptr->temp_pwm_duty = motor_ptr->Iq_pid.PI_sat>>16;
			// Update timer CCR value for required duty cycle
			set_duty(motor_ptr->temp_pwm_duty);
			break;

		case STATE_CONTROL_CL_PWM_DUTY :
			pwm_duty_control();
			// Update timer CCR value for required duty cycle
			set_duty(motor_ptr->temp_pwm_duty);
			break;

		case STATE_CONTROL_SIM_DETECT :
			#ifdef  SIM_ENABLE
			sim_process();
			#endif
			break;

		case STATE_CONTROL_BRAKING_PWM_CONTROL :
			#ifdef 	MOTOR_STOP_BRAKING_ENABLE
			braking_charge_vbus_control();
			braking_detect_motor_state();
			#endif
			break;

		case STATE_CONTROL_COASTING :
			// Update timer CCR value for required duty cycle
			set_duty(motor_ptr->temp_pwm_duty);
			break;

		default :
			control_machine_state = STATE_CONTROL_IDLE;
			break;
	}
}

