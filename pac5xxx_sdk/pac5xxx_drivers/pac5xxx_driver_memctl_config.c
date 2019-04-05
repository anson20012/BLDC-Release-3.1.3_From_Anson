/**************************************************************************//**
 * @file     pac5xxx_driver_memctl_config.c
 * @brief    Firmware driver for the PAC5XXX Memory Controller
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

#include "pac5xxx_driver_memory.h"

RAMFUNC_MEMORY void pac5xxx_memctl_flash_page_erase(int segment)
{
  PAC5XXX_MEMCTL->FLASHPAGE.PAGE = segment;
  PAC5XXX_MEMCTL->FLASHPERASE = FLASH_LOCK_ALLOW_PERASE_KEY;
}

RAMFUNC_MEMORY void pac5xxx_memctl_flash_swr_enable_por(int enabled)
{
  PAC5XXX_MEMCTL->FLASHLOCK = FLASH_LOCK_ALLOW_FLASHDBG_KEY;
  PAC5XXX_MEMCTL->SWDACCESS.VAL = enabled;
}

RAMFUNC_MEMORY void pac5xxx_memctl_wait_state(MEMCTL_WaitState wait_states)
{
  PAC5XXX_MEMCTL->FLASHLOCK = FLASH_LOCK_ALLOW_FLASHWSTATE_KEY;
  PAC5XXX_MEMCTL->FLASHWSTATE.VAL = wait_states;
}

RAMFUNC_MEMORY void pac5xxx_memctl_buffered_write(int segment, int address_offset, uint16_t data)
{
	PAC5XXX_MEMCTL->FLASHBWRITE = FLASH_LOCK_ALLOW_BWRITE_KEY;
	PAC5XXX_MEMCTL->FLASHBWRITEDATA.PAGE = segment;
	PAC5XXX_MEMCTL->FLASHBWRITEDATA.ADDRESS = address_offset;
	PAC5XXX_MEMCTL->FLASHBWRITEDATA.DATA = data;
}
