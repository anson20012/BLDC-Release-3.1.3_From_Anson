
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

#ifndef VERSION_H
#define VERSION_H

#define VERSION_TYPE				3
#define VERSION_MAJOR				1
#define VERSION_MINOR				2

#endif

//==========================
//BLDC -Release-3.1.2
//==========================
//----- New Features -----
//=======================================================================================================================
//- 2018/01/11  Fix bug: Remove "Stall function" and "over load function"
//- 2018/01/11  Fix bug: Change SIM libary
//- 2018/01/10  Fix bug: Change TimerC&TimerD interrupt enable and disable moment
//- 2018/01/10  Fix bug: Fix align and go speed rate can not more than 100Hz/s issue
//- 2018/01/10  Fix bug: Change GUI commutate advance to 30 max value from 60 max value
//- 2018/01/10  Fix bug: Change GUI open loop Iq_ref max value to 100
//- 2018/01/10  Fix bug: Change "peripheral_init" function about "while ((pac5xxx_tile_register_read(ADDR_ENDRV) & 0x01) != 0)"
//- 2018/01/05  Fix bug: Fix PAC5232 AIO7/8/9 comparator issue
//- 2018/01/03  Add new: Use reading AIO7/8/9 adc value to get zero crossing point

//- 2018/05/31  Add new: add stubs isrs in case of MCU run out
//- 2018/05/31  Add new: add charge
//- 2018/05/31  Fix bug: fix IPD lib for PAC5232

//=======================================================================================================================


//==========================
//BLDC -Release-3.1.1
//==========================
//----- New Features -----
//=======================================================================================================================
//- 2017/11/16  Fix bug: Fix Keil put in ram issue
//- 2017/10/27  Fix bug: Fix PAC5232 Ibus sample and GUI output parameter bug about LP&HP register
//- 2017/10/17  Fix bug: Fix IPD libary promble that the start up is not good,if select reverse
//=======================================================================================================================

//==========================
//BLDC -Release-3.1.0
//==========================
//----- New Features -----
//=======================================================================================================================
//- 2017/09/21  Fix bug: Fix IPD libary promble
//- 2017/09/21  Fix bug: Fix SIM libary define promble
//- 2017/08/17  Add new: Change the SDK version to "v2.4.0"
//- 2017/08/17  Add new: add EP5232MVM1 board config
//- 2017/09/12  Fix bug: autorun ipd function fault fix
//=======================================================================================================================

//==========================
//BLDC -Release-3.0.1
//==========================
//----- New Features -----
//=======================================================================================================================
//- 2017/08/03  Fix bug: Align and go mode switch to BEMF mode have a systick period delay time bug
//- 2017/08/03  Fix bug: if open "#define  MOTOR_STOP_BRAKING_ENABLE" build fail bug
//- 2017/06/28  Remove the int64_t part code
//- 2017/06/20  Fix bug: PWM mode switch to Speed mode occur big current bug
//- 2017/06/20  Fix bug: Hall mode build failed
//- 2017/06/09  Add new function : Coasting TimeOut
//- 2017/06/09  Add new function : Braking TimeOut
//- 2017/06/08  Add new function : Speed mode \ Torque mode \ PWM duty mode select
//- 2017/06/07  Fix bug: Amplifier Gain x4  x8  x16  x32  x48
//- 2017/05/25  Add new function : IPD mode
//- 2017/03/30  change structure : add main state & sub control state
//- 2017/03/01  Add new function : start up sine wave
//- 2017/02/21  Add new function : PPD mode
//=======================================================================================================================

//==========================
//BLDC -Release-3.0.0
//==========================
//----- New Features -----
//=======================================================================================================================
//- 2017/03/30  change structure : add main state & sub control state
//- 2017/03/01  Add new function : start up sine wave
//- 2017/02/21  Add new function : PPD mode
//=======================================================================================================================

//==========================
//BLDC -Release-2.1.2
//==========================
//----- New Features -----
//=======================================================================================================================
//- 2016/12/27  Add new function : start up using hall ,then change to BEMF mode, low speed use hall,high speed use BEMF
//- 2017/02/21  Add new function : PPD mode
//=======================================================================================================================
