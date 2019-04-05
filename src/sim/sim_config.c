
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


Sim_Detect bldc_sim_m1;
const uint8_t sim_to_mos_state[] = {9,2,4,3,6,1,5,9};
const uint8_t sim_to_mos_state_rev[] = {9,1,3,2,5,6,4,9};


#ifdef SIM_ENABLE


//===================================================================================
/// @brief  This function init sim variable
/// @param  None
/// @return None
//===================================================================================
PAC5XXX_RAMFUNC void sim_variable_init(void)
{
	Sim_Detect* sim_ptr;
	sim_ptr = &bldc_sim_m1;

	sim_ptr->each_phs_bemf_delta_threshold = SIM_EACH_PHASE_BEMF_DELTA_THRESHOLD;
	sim_ptr->keep_detect_step_times = SIM_DETECT_PERIOD_COUNTS;
	sim_ptr->ratio_timerc_timerd_freq = RATIO_BW_TIMERC_FREQ_TIMERD_FREQ;
	sim_ptr->bemf_adc_scal_fator = VDD2P5DIV1023MUL5FIX16;
	sim_ptr->bemf_ratio = R1_PLUS_R2_BY_R2_RATIO_BEMF;
}



//===================================================================================
/// @brief  This function read bemf ADC value
/// @param  None
/// @return None
//===================================================================================
PAC5XXX_RAMFUNC void sim_bemf_adc_read(void)
{
	Sim_Detect* sim_ptr;
	sim_ptr = &bldc_sim_m1;

	sim_ptr->bemf_u = BRAKING_BEMF_AIO7_ADC;
	sim_ptr->bemf_v = BRAKING_BEMF_AIO8_ADC;
	sim_ptr->bemf_w = BRAKING_BEMF_AIO9_ADC;
}



#endif
