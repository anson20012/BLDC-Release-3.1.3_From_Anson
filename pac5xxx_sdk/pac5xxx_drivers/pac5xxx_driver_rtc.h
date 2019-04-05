/**************************************************************************//**
 * @file     pac5xxx_driver_rtc.h
 * @brief    Firmware driver for the PAC5XXX real-time clock
 *
 * @note
 * Copyright (C) 2015, Active-Semi International
 *
 * THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
 * AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
 * APPLICATION TO PAC PROCESSORS SUPPLIED BY ACTIVE-SEMI INTERNATIONAL;
 * (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
 * ACTIVE-SEMICONDUCTOR IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
 * DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
 * ONLY BY CERTAIN AUTHORIZED PERSONS.
 *
 ******************************************************************************/

#ifndef PAC5XXX_DRIVER_RTC_H
#define PAC5XXX_DRIVER_RTC_H

/** @addtogroup PAC5XXX_Driver_Rtc PAC5XXX Real-Time Clock
  @{
*/

#include "pac52XX.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_RTC_RAM
#define RAMFUNC_RTC	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_RTC
#endif

// Function Prototypes for support functions

/**
 * @brief  This function configures Real-time Clock
 *
 * @param  ie_en Set to non-zero to enable Watchdog Timer interval interrupt
 * @param  cdv The Real-time clock count-down value in clock ticks
 * @param  prescale The input clock pre-scaler for the RTC
 * @return none
 *
 */
RAMFUNC_RTC void pac5xxx_rtc_config(int ie_en, uint32_t cdv, RTCCTL_PS_Type prescale);

/**
 * @brief  This function resets the watchdog timer
 *
 * @return none
 *
 */
RAMFUNC_RTC void pac5xxx_rtc_reset(void);

/**
 * @brief  This function clears the Real-Time Clock interrupt flag
 *
 * @return none
 *
 */
RAMFUNC_RTC void pac5xxx_rtc_clear_if(void);

/**
 * @brief  This function indicates whether or not the RTC has completed its last register write
 *
 * @returns 0: Not busy, non-zero: busy
 */
RAMFUNC_RTC static int pac5xxx_rtc_write_busy(void) { return ((PAC5XXX_RTC->RTCCTL & RTCCTL_WRBUSY_MASK) != 0); }


/*@}*/ /* end of group PAC5XXX_Driver_Rtc */


#endif // PAC5XXX_DRIVER_RTC_H

