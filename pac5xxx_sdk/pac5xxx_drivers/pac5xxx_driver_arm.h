/**************************************************************************//**
 * @file     pac5xxx_driver_arm.h
 * @brief    Firmware driver for the PAC5XXX ARM functions
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

#ifndef PAC5XXX_DRIVER_ARM_H
#define PAC5XXX_DRIVER_ARM_H

#include "pac52XX.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_ARM_RAM
#define RAMFUNC_ARM	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_ARM
#endif

// Function Prototypes for support functions

/**
 * @brief  This function sets the ARM up to enter deep sleep mode, when sleep mode
 *         is entered
 *
 * @return none
 */
RAMFUNC_ARM static  void pac5xxx_arm_sleep_deep_enable(void) { SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; }

/**
 * @brief  This function sets the ARM up to enter normal sleep mode, when sleep mode
 *         is entered (not deep sleep mode)
 *
 * @return none
 */
RAMFUNC_ARM static  void pac5xxx_arm_sleep_deep_disable(void) { SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk; }

/**
 * @brief  This function sets the ARM up to enter sleep mode upon returning from handler mode
 *         to thread mode. When the WFI or WFE instructions are executed, either sleep or deep sleep
 *         modes will be entered after exiting handler mode.
 *
 * @return none
 */
RAMFUNC_ARM static  void pac5xxx_arm_sleep_on_exit_enable(void) { SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk; }

/**
 * @brief  This function sets the ARM up to enter either sleep mode or deep sleep mode when the WFI or WFE 
 * instructions are executed.
 *
 * @return none
 */
RAMFUNC_ARM static  void pac5xxx_arm_sleep_on_exit_disable(void) { SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk; }

/**
 * @brief  This function enters the sleep mode on the ARM using the WFI 
 *         (wait for interrupt) instruction and performs clock management
 *         before entering sleep mode
 *
 * @return none
 *
 */
RAMFUNC_ARM void pac5xxx_arm_sleep_wfi(void);

/**
 * @brief  This function enters the sleep mode on the ARM using the WFE 
 *         (wait for event) instruction and performs clock management
 *         before entering sleep mode
 *
 * @return none
 *
 */
RAMFUNC_ARM void pac5xxx_arm_sleep_wfe(void);

#endif // PAC5XXX_DRIVER_ARM_H
