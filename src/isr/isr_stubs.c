
/**************************************************************************//**
 * Copyright (C) 2016, Active-Semi International
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
 
#include "include.h"

void NMI_Handler(void)
{
//  set_fault_mask(FAULT_ARM_NMI);

	set_fault(48828);
}

void HardFault_Handler(void)
{
//  set_fault_mask(FAULT_ARM_HARD_FAULT);

	set_fault(48828);
}

void MemCtl_IRQHandler(void)
{
//  set_fault_mask(FAULT_ARM_MEM_CTL);

	set_fault(48828);
}

void Default_Handler(void)
{
//  set_fault_mask(FAULT_ARM_DEF_HDLR);

    // Go into an infinite loop.
	set_fault(48828);
}

