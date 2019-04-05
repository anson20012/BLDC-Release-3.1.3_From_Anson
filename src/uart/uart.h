/**************************************************************************//**
 * @file     uart.h
 * @brief    Peripheral and initialization routines for the application.
 * @date     03 March 2017
 *
 * @note
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

#ifndef UART_H
#define UART_H

#include "include.h"

#ifdef ENABLE_UART_COMMUNICATE
typedef enum
{
	success,									/*!< UART message received successfully */
	host_write_error,							/*!< UART error when writing from host to target (receive message) */
	host_read_error,							/*!< UART error when reading from target to host (transmit message) */
	checksum_error,								/*!< UART checksum error */
} Uart_Status;


// Function declarations
static uint8_t uart_checksum(uint8_t* pBuffer);
static void int_to_buffer(uint32_t data);
Uart_Status uart_message_process(void);
#endif

#endif
