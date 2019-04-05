
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

#include "pid.h"
#include "uart.h"


//==============================================================================================
//  @brief Initializes the PID controller data
//
//  @param pid_data Pointer to the PID controller data
//  @returns none
//
//  @note Note that the user must make sure that the pointer is valid and that the user-defined
//        fields in the data structure are initialized properly (see the definition for the
//        \a PID_Data_Type data structure).
//==============================================================================================
RAMFUNC_PID void pid_reset(PID_Data_Type* pid_data)
{
	pid_data->aw_prev = 0;
	pid_data->I_prev = 0;
	pid_data->PI = 0;
	pid_data->PI_sat = 0;
}


//==============================================================================================
//  @brief Runs the PID controller
//
//  @param pid_data Pointer to the PID controller data
//  @param error Error from last controller
//==============================================================================================

//==============================================================================================
//  Positional PID:
//                   n
//  U(n) = Kp*e(n) + ¡Æ{{e(m) - Ks*[U(m-1) - U*(m-1)]}*Ki*Td}
//                   m=1
//  or
//
//  f_P(n) = Kp*e(n)
//  f_I(n) = {e(n) - Ks*[U(n-1) - U*(n-1)]}*Ki*Td
//  Sum_I(n) = f_I(n) + Sum_I(n-1)
//  Sum_I(n-1) = Sum_I(n)
//  U(n) = f_P(n) + Sum_I(n)
//  U(n-1) = U(n)
//  U*(n-1) = Limited[U(n-1)]
//
//==============================================================================================


RAMFUNC_PID void pid_run(PID_Data_Type* f_pid_data, fix16_t f_error)
{
	fix16_t f_P = 0;
	fix16_t f_I = 0;

	// P = Kp * error
	f_P = fix16_mul_new_16_16(f_pid_data->Kp, f_error);

	// I = ((error - aw_prev) * Ki * TD + I_prev)
	f_I = fix16_sub(f_error, f_pid_data->aw_prev);
	f_I = fix16_mul_new_16_16(f_I, f_pid_data->Ki);
	f_I = fix16_mul_new_16_16(f_I, f_pid_data->Td);		// Note: Td is scaled by 2^10
	f_I >>= 10;											/// De-scale because of Td
	f_I = fix16_add(f_I, f_pid_data->I_prev);

	f_pid_data->I_prev = f_I;

	// Saturate output
	f_pid_data->PI = fix16_add(f_P, f_I);
	f_pid_data->PI_sat = f_pid_data->PI;

	if (f_pid_data->PI > f_pid_data->max_value)
		f_pid_data->PI_sat = f_pid_data->max_value;
	else if (f_pid_data->PI < f_pid_data->min_value)
		f_pid_data->PI_sat = f_pid_data->min_value;
	else
	{
		f_pid_data->PI_sat = f_pid_data->PI;
	}
	// Anti-windup: aw_prev = (PI - PI_sat) * Ks

	f_pid_data->aw_prev = fix16_sub(f_pid_data->PI, f_pid_data->PI_sat);
	f_pid_data->aw_prev = fix16_mul_new_16_16(f_pid_data->aw_prev, f_pid_data->Ks);
}


RAMFUNC_PID void pid_sync(PID_Data_Type* to_data, PID_Data_Type* from_data)
{
	to_data->I_prev = from_data->I_prev;
	to_data->PI = from_data->PI;
	to_data->PI_sat = from_data->PI_sat;
	to_data->aw_prev = from_data->aw_prev;
}


