/**************************************************************************//**
 * @file     pac5xxx_driver_memory.h
 * @brief    Firmware driver for the PAC5XXX memory controller
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

#ifndef PAC5XXX_DRIVER_MEMORY_H
#define PAC5XXX_DRIVER_MEMORY_H

/** @addtogroup PAC5XXX_Driver_Memory PAC5XXX Memory Controller
  @{
*/

#include "pac52XX.h"
#include "pac5xxx_driver_config.h"

#ifdef PAC5XXX_DRIVER_MEMORY_RAM
#define RAMFUNC_MEMORY	PAC5XXX_RAMFUNC
#else 
#define RAMFUNC_MEMORY
#endif

// Function Prototypes for support functions

/**
 * @brief  This function indicates if a memory controller page erase operation is in progress
 *
 * @return 0: Not in progress; non-zero: in progress
 */
RAMFUNC_MEMORY static  int pac5xxx_memctl_page_erase_active(void) { return PAC5XXX_MEMCTL->FLASHCTL.PERASE; }

/**
 * @brief  This function indicates if a memory controller buffered write operation is in progress
 *
 * @return 0: Not in progress; non-zero: in progress
 */
RAMFUNC_MEMORY static  int pac5xxx_memctl_buffered_write_active(void) { return PAC5XXX_MEMCTL->FLASHCTL.WRITE; }

/**
 * @brief  This function performs an erase of the given FLASH page
 * @param page Flash page to erase (0-31)
 * @return none
 */
RAMFUNC_MEMORY void pac5xxx_memctl_flash_page_erase(int page);

/**
 * @brief  This function prepares the system for writing data to either the INFO or FLASH areas
 *
 * @return none
 */
RAMFUNC_MEMORY static  void pac5xxx_memctl_flash_write_prep(void) { PAC5XXX_MEMCTL->FLASHLOCK = FLASH_LOCK_ALLOW_FLASHWRITE_KEY; }

/**
 * @brief  This function configures SWR access during a power-on reset
 *
 * @param enabled 1: SWR access at reset; 0: No SWR access at POR
 * @return none
 */
RAMFUNC_MEMORY void pac5xxx_memctl_flash_swr_enable_por(int enabled);

/**
 * @brief  This function configures the number of FLASH controller wait states
 * @param   wait_states The number of wait states (0-3)
 *
 * @return none
 */
RAMFUNC_MEMORY void pac5xxx_memctl_wait_state(MEMCTL_WaitState wait_states);

/**
 * @brief  This function starts a buffered write operation with the given data
 * @param  segment FLASH segment that contains the data to write
 * @param  address_offset The address offset of the data
 * @param  data The data to write
 *
 * @return none
 */
RAMFUNC_MEMORY void pac5xxx_memctl_buffered_write(int segment, int address_offset, uint16_t data);


/*@}*/ /* end of group PAC5XXX_Driver_Memory */

#endif 	// PAC5XXX_DRIVER_MEMORY_H

