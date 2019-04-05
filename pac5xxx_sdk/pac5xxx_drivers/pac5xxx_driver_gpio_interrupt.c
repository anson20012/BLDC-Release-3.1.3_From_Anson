/**************************************************************************//**
 * @file     pac5xxx_driver_gpio_interrupt.c
 * @brief    Firmware driver for the PAC5XXX GPIO Interrupts
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

#include "pac5xxx_driver_gpio.h"

RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_a(uint8_t port_mask, uint8_t active_high_mask)
{
	pac5xxx_gpio_int_mask_a(port_mask);									// Set interrupt mask at startup (interrupt startup workaround)
	pac5xxx_gpio_int_polarity_a(active_high_mask);						// Set interrupt polarity
	pac5xxx_gpio_int_enable_a(port_mask);								// Enable interrupts in IO controller
	NVIC_EnableIRQ(GpioA_IRQn);											// Enable interrupts in NVIC
	pac5xxx_gpio_int_flag_clear_a(port_mask);							// Clear any active interrupt flags
	pac5xxx_gpio_int_mask_a(0);											// Clear interrupt mask and interrupts are enabled

}

RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_b(uint8_t port_mask, uint8_t active_high_mask)
{
	pac5xxx_gpio_int_mask_b(port_mask);									// Set interrupt mask at startup (interrupt startup workaround)
	pac5xxx_gpio_int_polarity_b(active_high_mask);						// Set interrupt polarity
	pac5xxx_gpio_int_enable_b(port_mask);								// Enable interrupts in IO controller
	NVIC_EnableIRQ(GpioB_IRQn);											// Enable interrupts in NVIC
	pac5xxx_gpio_int_flag_clear_b(port_mask);							// Clear any active interrupt flags
	pac5xxx_gpio_int_mask_b(0);											// Clear interrupt mask and interrupts are enabled

}
RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_c(uint8_t port_mask, uint8_t active_high_mask)
{
	pac5xxx_gpio_int_mask_c(port_mask);									// Set interrupt mask at startup (interrupt startup workaround)
	pac5xxx_gpio_int_polarity_c(active_high_mask);						// Set interrupt polarity
	pac5xxx_gpio_int_enable_c(port_mask);								// Enable interrupts in IO controller
	NVIC_EnableIRQ(GpioC_IRQn);											// Enable interrupts in NVIC
	pac5xxx_gpio_int_flag_clear_c(port_mask);							// Clear any active interrupt flags
	pac5xxx_gpio_int_mask_c(0);											// Clear interrupt mask and interrupts are enabled

}
RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_d(uint8_t port_mask, uint8_t active_high_mask)
{
	pac5xxx_gpio_int_mask_d(port_mask);									// Set interrupt mask at startup (interrupt startup workaround)
	pac5xxx_gpio_int_polarity_d(active_high_mask);						// Set interrupt polarity
	pac5xxx_gpio_int_enable_d(port_mask);								// Enable interrupts in IO controller
	NVIC_EnableIRQ(GpioD_IRQn);											// Enable interrupts in NVIC
	pac5xxx_gpio_int_flag_clear_d(port_mask);							// Clear any active interrupt flags
	pac5xxx_gpio_int_mask_d(0);											// Clear interrupt mask and interrupts are enabled

}
RAMFUNC_GPIO void pac5xxx_gpio_configure_interrupt_e(uint8_t port_mask, uint8_t active_high_mask)
{
	pac5xxx_gpio_int_mask_e(port_mask);									// Set interrupt mask at startup (interrupt startup workaround)
	pac5xxx_gpio_int_polarity_e(active_high_mask);						// Set interrupt polarity
	pac5xxx_gpio_int_enable_e(port_mask);								// Enable interrupts in IO controller
	NVIC_EnableIRQ(GpioE_IRQn);											// Enable interrupts in NVIC
	pac5xxx_gpio_int_flag_clear_e(port_mask);							// Clear any active interrupt flags
	pac5xxx_gpio_int_mask_e(0);											// Clear interrupt mask and interrupts are enabled

}
