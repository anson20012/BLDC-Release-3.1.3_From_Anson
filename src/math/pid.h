
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

#ifndef PID_H
#define PID_H

#include "fix16.h"


#define PAC5XXX_PID_RAM							// Uncomment to link FOC functions in RAM
#ifdef PAC5XXX_PID_RAM
	#define RAMFUNC_PID	 PAC5XXX_RAMFUNC
#else
	#define RAMFUNC_PID
#endif


typedef struct
{
	// Operational variables - updated controller

	fix16_t aw_prev;							// Anti-windup from the previous PID calculation
	fix16_t I_prev;								// I term from the previous PID calculation
	fix16_t PI;									// Current value of PID controller output before saturation check
	fix16_t PI_sat;								// Current value of PID controller output after saturation check

	// Configuration variables - specified by user. Controller does not change

	fix16_t Kp;									// Proportional gain term * 2^8 (scaling for integer math)
	fix16_t Ki;									// Integral gain term * 2^8 (scaling for integer math)
	fix16_t Ks;									// Saturation gain term * 2^8 (scaling for integer math)
	fix16_t min_value;							// Saturation filter minimum output value
	fix16_t max_value;							// Saturation filter maximum output value
	fix16_t Td;									// Td for d/dt calculation (scaled by 2^10)

} PID_Data_Type;



RAMFUNC_PID extern void pid_reset(PID_Data_Type* pi_data);							// Reset PID controller data
RAMFUNC_PID extern void pid_run(PID_Data_Type* pid_data, fix16_t input_data);		    // Runs PID controller with the given input data
RAMFUNC_PID extern void pid_sync(PID_Data_Type* to_data, PID_Data_Type* from_data);	// Copies PID state (not gains) from one PID controller to another

#endif



