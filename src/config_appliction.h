
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

#ifndef BLDC_APPLICATION_H
#define BLDC_APPLICATION_H

#include "include.h"

#define NUM_SPEED_SAMPLES       			6				// How many samples needed to accumulate for speed calculation
#define NUM_SPEED_SAMPLES_BLANKING         2           	// Array length to hold motor speed used for automatic delay calculation

typedef enum
{
	status_motor_enabled = 1,
	status_over_current = 2,
	status_closed_loop = 4,
	status_lose_angle = 8,
	status_motor_stall = 16,
	status_Vbus_overvoltage = 32,
	status_Vbus_undervoltage = 64,
	status_open_phase = 128,
	status_hall_error = 256,
	status_open_loop = 512,
	status_pwm_duty_loop = 1024,
} StatusStateBits;


typedef enum
{
	STATE_MAIN_STOP_STANDBY = 0,
	STATE_MAIN_OL,
	STATE_MAIN_OL_SWITCH_CL_WAIT,
	STATE_MAIN_CL_SPEED,
	STATE_MAIN_CL_CURRENT,
	STATE_MAIN_CL_PWM_DUTY,
	STATE_MAIN_SIM_DETECT,
	STATE_MAIN_STOP_BRAKING,
	STATE_MAIN_COASTING
}eBLDC_Main_Machine_State;

typedef enum
{
	STATE_CONTROL_IDLE = 0,
	STATE_CONTROL_OL,
	STATE_CONTROL_OL_SWITCH_CL_WAIT,
	STATE_CONTROL_CL_SPEED,
	STATE_CONTROL_CL_CURRENT,
	STATE_CONTROL_CL_PWM_DUTY,
	STATE_CONTROL_SIM_DETECT,
	STATE_CONTROL_BRAKING_PWM_CONTROL,
	STATE_CONTROL_COASTING
}eSub_Control_Machine_State;

typedef enum
{
	STATE_TIMERC_FIRST_SAMPLE = 0,
	STATE_TIMERC_GOOD_SAMPLES,
	STATE_TIMERC_ZERO_CROSS_POINT,
	STATE_TIMERC_WAIT_COMMUTATE,
	STATE_TIMERC_BLANKING_CYCLE_TIME
}eGet_Zero_Cross_Point_State;

typedef enum
{
	STATE_HALL_STARTUP = 0,
	STATE_HALL_SWITCH_TO_BEMF
}eHall_Bemf_Switch_State;

typedef enum
{
	STATE_STARTUP_INIT = 0,
	STATE_STARTUP_ALIGN,
	STATE_STARTUP_ALIGN_DELAY,
	STATE_STARTUP_GO,
	STATE_STARTUP_SWITCH_TO_BEMF,
	STATE_STARTUP_DONE,
}eMotor_Align_Go_State;

typedef enum
{
	STATE_SIM_INIT = 0,
	STATE_SIM_DETECT,
	STATE_SIM_STOP,
	STATE_SIM_MOVE,
	STATE_SIM_SAME_DIRECTION,
	STATE_SIM_DIFF_DIRECTION,
	STATE_SIM_BRAKING,
}eSIM_State;








typedef struct
{
	eMotor_Align_Go_State align_and_go_state;
	uint16_t align_ticks;				    		// Number of PWM ticks to keep in align mode
	uint16_t align_ticks_store;
	uint16_t align_ticks_temp;						// Temp variable to hold Number of PWM ticks in align mode
	uint16_t start_speed_ticks_period;				// Variable to hold Number of PWM ticks in go mode
	uint16_t start_speed_ticks_temp;	    		// Temp variable to hold number of PWM ticks to keep in go mode
	uint16_t align_go_duty_cycle;					// Align and go duty cycle
	uint16_t align_go_duty_cycle_store;				// Align and go duty cycle
	uint16_t go_step;			  		    		// Valid current go state for motor
	fix16_t  accel_rate_time_base;					// Number of 1 ms ticks in between speed changes
	fix16_t  start_speed_hz;
	fix16_t  current_speed_hz;
	fix16_t  switch_speed_hz;
	uint16_t switch_speed_ticks;
	uint16_t AccelRateTimeBaseTemp;
	fix16_t  accel_rate_factor;
	uint8_t  auto_acceleration_mode;

	uint16_t sine_wave_index;
	fix16_t  wave_pwm_duty_u;
	fix16_t  wave_pwm_duty_v;
	fix16_t  wave_pwm_duty_w;
}Motor_Align_Go;

typedef struct
{
	fix16_t Iq_ref;									// Iq_ref
	fix16_t Iq_ref_sp;								// Iq_ref setpoint
	fix16_t Iq_ref_cl;								// Iq_ref for close loop
	fix16_t Iq_fb;									// Iq_fb
	fix16_t Iq_previous;                            // Iq previous value use for digital filtering
	fix16_t Iq_prev_non_filtered;                   // Iq previous value use for backup as good last non filtered value
	fix16_t Iq_filter_gain;
	PID_Data_Type Iq_pid;							// PID controller for Iq
	PID_Data_Type speed_pid;
	fix16_t duty_percent_fix16;

	int16_t Ibus_ADC;								// Stored Iu ADC value
	fix16_t Iq_ramp_rate;							// Iq ref Ramp Rate
	uint8_t speed_pid_skips;						// Number of times speed PID has been skipped
	uint8_t enable_current_control;					// Current control enable disable flag
	uint8_t num_of_good_zc_samples;                 // Number of good zero cross samples, need to validate good zero crossing
	uint16_t blanking_sample_counts;                // Number of PWM cycles we blank out zero cross sensing after commutation
    fix16_t motor_close_loop_speed;                 // Motor close loop speed in int format, 1HZ - 1 count
    fix16_t motor_close_loop_current;
    fix16_t motor_close_loop_speed_temp;            // Motor close loop speed temp variable use for speed ramp
    fix16_t motor_close_loop_speed_ramp;            // Motor close loop speed ramp rate variable
    fix16_t adc_zero_cross_offset_percentage;       // Used in ADC zero cross detection as an offset to move center tap point
    uint8_t auto_open_to_close_loop_sw_count;       // Use to check open loop speed number if cycles before switch over                                                   /*!< Value comes from GUI as an percentage */
    fix16_t motor_auto_blank_percent;               // Blanking time comes in percentage from GUI
    fix16_t ratio_bw_pwmFreq_timerDFreq;
    fix16_t vbus_voltage_value;

    uint8_t motor_enabled;
    uint8_t debug_buffer_command;

    uint8_t control_mode_select_number;
    fix16_t closed_loop_current_command;

    uint32_t coasting_timeout_counts;
    uint32_t coasting_timeout;





    // configuration
    uint32_t app_status;
    uint32_t app_measured_speed;
    uint32_t app_speed_ref;
    uint32_t app_pwm_freq_khz;
    fix16_t  app_control_freq_khz;
    fix16_t  app_speed_command;
    uint32_t app_over_current_limit;
    uint32_t app_over_current_resistor;
    uint32_t app_amplifier_gain;
    uint32_t app_amplifier_gain_register;


    // Global Variables
    uint8_t  motor_enable_cmd;
    fix16_t  I_total_factor;
    uint8_t  oc_reset_flag;
    uint8_t  reverse_tune_flag;
    fix16_t  main_machine_control_counts;
    uint16_t motor_lose_angle_count;


    // PWM duty cycle
    fix16_t  align_pwm_duty_max;
    fix16_t  pwm_control_duty_cycle;
    uint16_t pwm_control_duty_change_delay_counts;
    uint16_t final_pwm_duty;
    uint16_t pwm_duty_Fall_buf;
    uint16_t temp_pwm_duty;
    uint16_t temp_pwm_duty_u;
    uint16_t temp_pwm_duty_v;
    uint16_t temp_pwm_duty_w;
    uint16_t pwm_timer_ticks;									// Number of timer A ticks for PWM period
    fix16_t  one_div_pwm_timer_ticks_fix16;


    uint8_t  sample;
    uint8_t  samplecounter;
    uint8_t  target_sample;									// Last good commutation state sample store
    uint16_t speed_sample_index;
    uint16_t speed_sample_index_blanking;
    uint8_t  wait_30degree_enable;					      		// Force to invalid value to force commutation on startup
    uint8_t  sl_current_state;			  						// Force to invalid value to force commutation on startup
    uint8_t  sl_next_state;										// Force to invalid value to force commutation on startup
    int32_t  commutation_advanced_rise;
    int32_t  commutation_advanced_fall;

    // Array to store speed for one electrical cycle
    uint16_t call_speed_loop_delay_count;
    uint16_t motorspeed;
    uint32_t motorspeed_sum;
    fix16_t  motor_speed_sum_fix16;
    fix16_t  motorspeed_sum_blanking_fix16;
    uint32_t motorspeed_sum_blanking;
    uint16_t motorspeed_buffer[NUM_SPEED_SAMPLES];
    uint16_t motorspeed_buffer_blanking[NUM_SPEED_SAMPLES_BLANKING];
    uint16_t timer_d_base_timer_first;
    uint16_t timer_d_base_timer_second;
    uint16_t timer_d_base_timer_offset;
    uint16_t average_speed;
    volatile uint16_t commutation_blanking_time;
    int32_t  comm_advanced_delay_temp;
    uint16_t comm_advanced_delay;

    uint8_t timerA_isr_counts;

    uint16_t charge_delay_count;
    uint16_t charge_done_flag;

} BLDC_Controller;


typedef struct
{
	eSIM_State sim_process_state;

	fix16_t bemf_u ;
	fix16_t bemf_v ;
	fix16_t bemf_w ;

	fix16_t bemf_u_init;
	fix16_t bemf_v_init;
	fix16_t bemf_w_init;
	fix16_t bemf_uvw_init_center_tap_voltage;

	fix16_t delta_uv_bemf;
	fix16_t delta_uw_bemf;
	fix16_t delta_vw_bemf;
	fix16_t uvw_center_tap_voltage ;
	uint8_t step_state;
	uint8_t step_state_p;
	uint8_t bemf_state;
	uint8_t bemf_state_p;
	uint8_t direction_flag;
	uint8_t direction_flag_P;

	fix16_t bemf_voltage;
	uint16_t input_pwm_duty_count;
	uint8_t motor_stop_bemf_flag;
	uint16_t detect_diff_position_counts;

	uint16_t braking_vbus_voltage_ref;
	uint16_t braking_vbus_voltage_fdb;
	uint16_t braking_depth_pwm_duty_counts;
	uint16_t braking_bemf_u;
	uint16_t braking_bemf_v;
	uint16_t braking_bemf_w;
	uint16_t braking_bemf_uvw_center_tap_voltage;
	uint8_t  braking_detect_motor_stop_flag;
	uint8_t  braking_stop_counts;
	uint8_t  braking_restart_disable_driver_counts;
	uint8_t  motor_in_motion_flag;
	uint32_t in_braking_state_counts;

	fix16_t  bemf_ratio;
	fix16_t  bemf_adc_scal_fator;
	uint16_t each_phs_bemf_delta_threshold;
	uint8_t  keep_detect_step_times;
	fix16_t  ratio_timerc_timerd_freq;
} Sim_Detect;


typedef struct
{
	uint8_t  hall_value;
	uint8_t  sensored_current_state;
	uint8_t  sensored_current_state_pre;
	uint16_t hall_bemf_switch_speed;
	uint32_t hall_to_mos_state_detect;
	uint8_t  commutate_flag;
} Hall_Sensor;

typedef struct
{
	fix16_t app_measured_speed_fix16;
	fix16_t app_speed_ref_fix16;
	fix16_t ibus_adc_fix16;

	fix16_t sl_current_hall_fix16;
	fix16_t sl_current_state_fix16;
	uint8_t sl_current_step_position;
	uint8_t sl_current_step_position_pre;

	fix16_t aio7_adc_value_fix16;
	fix16_t aio8_adc_value_fix16;
	fix16_t aio9_adc_value_fix16;
	fix16_t centre_adc_value_fix16;
	uint8_t phase_comparator_output;
	
} Pwm_Dac_Debug;


// structural and enumerate body
extern Motor_Align_Go          		bldc_align_go;
extern BLDC_Controller           	bldc_m1;
extern eBLDC_Main_Machine_State    	main_machine_state;
extern eSub_Control_Machine_State  control_machine_state;
extern eGet_Zero_Cross_Point_State get_zero_cross_point_state;
extern eHall_Bemf_Switch_State     	hall_bemf_switch_state;


//three phase sine wave table for motor start-up
extern const fix16_t sine_wave_3phase[60][3];
// Commutation state table with Analog MAUX setting
extern const uint8_t slcomp_mux[7] ;
extern const uint8_t slcomp_next_state[7] ;
extern const uint8_t slcomp_last_state[7];
extern const uint8_t slcomp_cross_polarity[7] ;					//POLx = 0,active High
extern const uint8_t slcomp_next_state_rev[7] ;					//reverse
extern const uint8_t slcomp_last_state_rev[7];      				//reverse
extern const uint8_t slcomp_cross_polarity_rev[7] ;				//reverse









#define ENABLE     						(1)
#define DISABLE    						(0)

#define DELAY_CHARGE_COUNTS                5
#define DELAY_SWITCH_TO_SPEED_LOOP_COUNTS  12
#define OVER_CURRENT_FLAG                  0x02

//  PWM DAC
#define PWMDAC_PWM_PIN_PORT_A_DEBUG    	0x38            // Pin mask for LS gate drive PWM for Port A


// Definitions
#define TIMERA_PERIOD_TICKS				781				// Number of timer a ticks for PWM
#define TIMERB_TICKS_DEBUG_DAC_45KHZ   	1111
#define TIMERB_PERIOD_TICKS_PPM        	65535
#define TIMERC_PERIOD_TICKS	        	500     		// Number of timer c ticks for 100Khz timer (up timer, HCLK@50MHz, /1)
#define TIMERD_TICKS_30DEG_PLL		    	65535			// Number of timer ticks for 30 degree timer (max 335ms per 60 degrees)

#define FIX16_1DOT_024                 	0x10624
#define RATIO_BW_TIMERC_FREQ_TIMERD_FREQ   16777   		// TimerC 100Khz:  0x4189 = 65536*(100Kz/(50M/128))  TimerC 160Khz:  26843 = 65536*(160Kz/(50M/128))
#define TIMER_D_FREQ_F16		            (0x0186A000)			// TMRD Freq = 50MHz / 128 = 195,312.5 Hz (This number is divided by 1000 so it can be represented by a Fix16 type)


#define SPEED_RAMP_COUNTS          		5
#define CURRENT_RAMP_COUNTS        		10

#define LED_PIN_MASK						0x01					// Pin mask for LED output PE0
#define LED_PIN_NUM						0						// Pin number for LED output (active high) PE0
#define LED1_TOGGLE						(pac5xxx_gpio_out_toggle_e(LED_PIN_MASK))		// Toggle LED state
#define LED1_ON							(pac5xxx_gpio_out_pin_set_e(LED_PIN_NUM))		// Set LED to on
#define LED1_OFF							(pac5xxx_gpio_out_pin_clear_e(LED_PIN_NUM))		// Set LED to off


#define NIRQ1_PIN_MASK						0x01
#define NIRQ2_PIN_MASK						0x80
#define SLCOMP7							0x10
#define SLCOMP8							0x20
#define SLCOMP9							0x30


#define AIO7_LOW2HIGH           			0
#define AIO7_HIGH2LOW           			1
#define AIO8_LOW2HIGH           			0
#define AIO8_HIGH2LOW           			1
#define AIO9_LOW2HIGH           			0
#define AIO9_HIGH2LOW           			1


#define HALF_DEGREE_ADV_DLY		        (0x00000222)				// 0.5 degree advance delay factor = 1/2 Comm Adv Delay * 1/2 degree * 1/30 degrees



#define COMMUTATION_BLANKING_COUNT          10

#define IQ_RAMP_RATE                      	 0x65536            	// 0.01 A, convert into fix16
#define IQ_REFERENCE                        0x00008000             // 0.5 A, convert to fix16
#define TD_FOR_IQ_PID                       0x000020C5			    // 8KHZ = 125 usec * 1024 = 0.128* 65536, converted into fix16 = 0x000020CA

#define TRUE   (1)
#define FALSE  (0)

#define DEFAULT_GOOD_ZERO_CROSS_SAMPLES 		   3
#define DEFAULT_CLOSE_LOOP_SPEED           	   50

#define OPEN_TO_CLOSE_LOOP_GOOD_SPEED_COUNT       1
#define SPEED_RAMP_RATE_1HZ_SEC                   0x00001999

#define DEFAULT_AUTO_BLANKING_PERCENT             0x00008000  		// 50% of commutation time

#define MATH_ZERO_DOT_ONE_FIX16       			   0x1999
#define MATH_ONE_DIV_SIX_FIX16       			   0x2AAA
#define MATH_ONE_DIV_THREE_FIX16       		   0x5555

#define SINE_WAVE_ARRAY_INDEX_MAX		     	   59
#define SINE_WAVE_ARRAY_INDEX_MIN                 0

#define COASTING_DUTY_REDUCE_RATE             	   5
#endif
