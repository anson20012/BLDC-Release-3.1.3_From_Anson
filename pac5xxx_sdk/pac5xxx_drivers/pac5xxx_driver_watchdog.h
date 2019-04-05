/**************************************************************************//**
 * @file     pac5xxx_driver_watchdog.h
 * @brief    Firmware driver for the PAC5XXX watchdog timer
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

#ifndef PAC5XXX_DRIVER_WATCHDOG_H
#define PAC5XXX_DRIVER_WATCHDOG_H

/** @addtogroup PAC5XXX_Driver_Watchdog PAC5XXX Watchdog Timer
  @{
*/

#include "pac52XX.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_WATCHDOG_RAM
#define RAMFUNC_WATCHDOG	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_WATCHDOG
#endif

// Function Prototypes for support functions

/**
 * @brief  This function configures watchdog timer
 *
 * @param  ie_en Set to non-zero to enable Watchdog Timer interval interrupt
 * @param  por_en Set to non-zero to enable Watchdog Timer Power-on Reset
 * @param  cdv The Watchdog timer count-down value in clock ticks
 * @return none
 *
 */
RAMFUNC_WATCHDOG void pac5xxx_watchdog_config(int ie_en, int por_en, uint32_t cdv);

/**
 * @brief  This function configures watchdog timer clock input and pre-scaler
 *
 * @param  clock_select Clock input selection from PAC5XXX_WDT peripheral file
 * @param  prescale Input clock pre-scaler from PAC5XXX_WDT peripheral file
 * @return none
 *
 */
RAMFUNC_WATCHDOG void pac5xxx_watchdog_config_clock(WDTCTL_CLKSEL_Type clock_select, WDTCTL_PS_Type prescale);

/**
 * @brief  This function resets the watchdog timer
 *
 * @return none
 *
 */
RAMFUNC_WATCHDOG void pac5xxx_watchdog_reset(void);

/**
 * @brief  This function clears the watchdog timer interrupt flag (for the interval timer)
 *
 * @return none
 *
 */
RAMFUNC_WATCHDOG void pac5xxx_watchdog_clear_if(void);

/**
 * @brief  This function indicates whether or not the WDT has completed its last register write
 *
 * @returns 0: Not busy, non-zero: busy
 */
RAMFUNC_WATCHDOG static int pac5xxx_watchdog_write_busy(void) { return ((PAC5XXX_WDT->WDTCTL & WDTCTL_WRBUSY_MASK) != 0); }



/*@}*/ /* end of group PAC5XXX_Driver_Watchdog */

#endif // PAC5XXX_DRIVER_WATCHDOG_H

