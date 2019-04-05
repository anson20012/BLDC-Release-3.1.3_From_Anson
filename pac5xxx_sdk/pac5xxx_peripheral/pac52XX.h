/****************************************************************************************************//**
 * @file     pac52XX.h
 *
 * @brief    CMSIS Cortex-M0 Peripheral Access Layer Header File for
 *           PAC52XX from Active-Semi.
 *
 * @note     Portions of this file generated with Keil SVDConv V2.85b 
 *           from CMSIS SVD File 'PAC52XX.svd' Version 1.0,
 * @note
 * Copyright (C) 2015-2017, Active-Semi International
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
#ifndef PAC52XX_H
#define PAC52XX_H

/** @addtogroup Active-Semi
  * @{
  */

/** @addtogroup PAC52XX
  * @{
  */

#ifdef __cplusplus
extern "C" {
#endif

// Compiler Specific Definitions
#ifdef __ICCARM__           // IAR C Compiler
#define PAC5XXX_RAMFUNC             __ramfunc
#define PAC5XXX_OPTIMIZE_SPEED_ON   _Pragma("optimize=high speed") 
#define PAC5XXX_OPTIMIZE_SPEED_OFF  // IAR doesn't need optimize off; it's only on for one function
#define UNUSED_PARAM
#elif defined __GNUC__      // GNU C Compiler
#define PAC5XXX_RAMFUNC             __attribute__((section(".data")))
#define PAC5XXX_OPTIMIZE_SPEED_ON   __attribute__((optimize("O3")))
#define PAC5XXX_OPTIMIZE_SPEED_OFF  // GCC doesn't need optimize off; it's only on for one function
#define UNUSED_PARAM				__attribute__((unused))
#elif defined __CC_ARM      // Keil RealView C Compiler
#define PAC5XXX_RAMFUNC             __attribute__((section("ramfunc")))
#define PAC5XXX_OPTIMIZE_SPEED_ON   _Pragma("push") _Pragma("Otime")   
#define PAC5XXX_OPTIMIZE_SPEED_OFF  _Pragma("pop") 
#define UNUSED_PARAM
#else
#define PAC5XXX_RAMFUNC
#define PAC5XXX_OPTIMIZE_SPEED_ON
#define PAC5XXX_OPTIMIZE_SPEED_OFF    
#define UNUSED_PARAM
#endif



/** @addtogroup PAC52XX_Definitions PAC52XX Definitions
  This file defines all structures and symbols for PAC52XX:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - Peripheral definitions
  @{
*/


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup PAC5XXX_CMSIS Device CMSIS Definitions
  Configuration of the Cortex-M0 Processor and Core Peripherals
  @{
*/

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

typedef enum IRQn
{
/* -------------------  Cortex-M0 Processor Exceptions Numbers  --------------------------------- */
  Reset_IRQn                    = -15,      /*!<  1 Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = -14,      /*!<  2 Non Maskable Interrupt                        */
  HardFault_IRQn                = -13,      /*!<  3 Hard Fault Interrupt                          */
  SVCall_IRQn                   = -5,       /*!< 11 SV Call Interrupt                             */
  PendSV_IRQn                   = -2,       /*!< 14 Pend SV Interrupt                             */
  SysTick_IRQn                  = -1,       /*!< 15 System Tick Interrupt                         */

/* ---------------------  PAC52XX Specific Interrupt Numbers  ----------------------------------- */
  MemCtl_IRQn                   = 0,        /*!< Memory Controller Interrupt                      */
  SysClk_IRQn                   = 1,        /*!< Clock/System Controller Interrupt                */
  Wdt_IRQn                      = 2,        /*!< Watchdog Timer Interrupt                         */
  GpioA_IRQn                    = 3,        /*!< GPIO Port A Interrupt                            */
  GpioB_IRQn                    = 4,        /*!< GPIO Port B Interrupt                            */
  GpioC_IRQn                    = 5,        /*!< GPIO Port C Interrupt                            */
  GpioD_IRQn                    = 6,        /*!< GPIO Port D Interrupt                            */
  GpioE_IRQn                    = 7,        /*!< GPIO Port E Interrupt                            */
  TimerA_IRQn                   = 8,        /*!< Timer A Interrupt (Base, CC0-5)                  */
  TimerAExt_IRQn                = 9,        /*!< Timer A Extended Interrupt (CC6-7)               */
  TimerB_IRQn                   = 10,       /*!< Timer B Interrupt                               */
  TimerC_IRQn                   = 11,       /*!< Timer C Interrupt                                */
  TimerD_IRQn                   = 12,       /*!< Timer D Interrupt                                */
  ADC_IRQn                      = 13,       /*!< ADC Interrupt                                    */
  SocBridge_IRQn                = 14,       /*!< SocBridge Interrupt                              */
  SPI_IRQn                      = 15,       /*!< SPI_B Interrupt                                  */
  UART_IRQn                     = 16,       /*!< UART Interrupt                                   */
  I2C_IRQn                      = 17,       /*!< I2C Interrupt                                    */
  EMUX_IRQn                     = 18,       /*!< EMUX Interrupt                                   */
  RTC_IRQn                      = 19        /*!< RTC Interrupt                                    */
} IRQn_Type;


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M0 Processor and Core Peripherals---------------- */
#define __CM0_REV                 0x0201    /*!< Core Revision r2p1                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT             0         /*!< MPU present or not                               */

/*@}*/ /* end of group PAC5XXX_CMSIS */

#include <core_cm0.h>                       /* Cortex-M# processor and core peripherals           */
#include "system_pac5xxx.h"                 /* PAC5XXX System  include file                         */

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/
/** @addtogroup PAC5XXX_Peripherals PAC5XXX Peripherals
  PAC5XXX Device Specific Peripheral registers structures
  @{
*/

/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif

#include "pac5xxx_ADC.h"                      	/* PAC5XXX ADC include file                             */
#include "pac5xxx_GPIO.h"                     	/* PAC5XXX GPIO include file                            */
#include "pac5xxx_I2C.h"                      	/* PAC5XXX I2C include file                             */
#include "pac5xxx_Memory.h"                   	/* PAC5XXX Memory Controller include file               */
#include "pac5xxx_SPI.h"                     	/* PAC5XXX SPI include file                             */
#include "pac5xxx_SocBridge.h"					/* PAC5XXX SOC Bridge include file                      */
#include "pac5xxx_SYS.h"                      	/* PAC5XXX System/Clock System include file             */
#include "pac5xxx_Timers.h"                   	/* PAC5XXX Timers include file                          */
#include "pac5xxx_UART.h"                     	/* PAC5XXX UART include file                            */
#include "pac5xxx_WDT.h"                      	/* PAC5XXX Watchdog Timer include file                  */
#include "pac5xxx_RTC.h"                      	/* PAC5XXX Real-Time Clock include file                 */

// version release state
#define  PAC52XX_RELEASED       0
#define  PAC52XX_RC             1
#define  PAC52XX_BETA           2
#define  PAC52XX_ALPHA          3
#define  PAC52XX_IN_DEVELOPMENT 4

/* ================================================================================ */
/* ================                     SYSCLK                     ================ */
/* ================================================================================ */

/**
  * @brief System and Clock Control (SYSCLK)
  */

typedef struct {                                    /*!< SYSCLK Structure                                                      */
  __IO uint32_t  SCCTL;                             /*!< System Clock Control Register                                         */
  __IO uint32_t  PLLCTL;                            /*!< PLL Control Register                                                  */
  __IO uint32_t  ROSCCTL;                           /*!< Ring Oscillator Control Register                                      */
  __IO uint32_t  XTALCTL;                           /*!< Crystal Driver Control Register                                       */
} SYSCLK_Type;


/* ================================================================================ */
/* ================                     MEMCTL                     ================ */
/* ================================================================================ */


/**
  * @brief FLASH Memory Controller (MEMCTL)
  */

typedef struct {                                    /*!< MEMCTL Structure                                                      */
  __IO uint32_t  FLASHLOCK;                         /*!< FLASH Lock Register                                                   */
  __IO uint32_t  FLASHSTATUS;                       /*!< FLASH Status Register                                                 */
  __IO uint32_t  FLASHPAGE;                         /*!< FLASH page select register                                            */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  FLASHPERASE;                       /*!< FLASH page erase register                                             */
  __I  uint32_t  RESERVED1[3];
  __IO uint32_t  SWDACCESS;                         /*!< SWD access status                                                     */
  __IO uint32_t  FLASHWSTATE;                       /*!< FLASH Wait State Register                                             */
  __IO uint32_t  FLASHBWRITE;                       /*!< FLASH Buffered Write Data                                             */
} MEMCTL_Type;


/* ================================================================================ */
/* ================                       WDT                      ================ */
/* ================================================================================ */


/**
  * @brief Watchdog Timer (WDT)
  */

typedef struct {                                    /*!< WDT Structure                                                         */
  __I  uint32_t  WDTCTL;                            /*!< Watchdog Timer Control Register                                       */
  __IO uint32_t  WDTCDV;                            /*!< Watchdog Timer Count-down Value Register                              */
  __I  uint32_t  WDTCTR;                            /*!< Watchdog Timer Counter Register                                       */
} WDT_Type;


/* ================================================================================ */
/* ================                       RTC                      ================ */
/* ================================================================================ */


/**
  * @brief Real-Time Clock (RTC)
  */

typedef struct {                                    /*!< RTC Structure                                                         */
  __I  uint32_t  RTCCTL;                            /*!< Real-Time Clock Control Register                                      */
  __IO uint32_t  RTCCDV;                            /*!< Real-Time Clock Count-down Value Register                             */
  __I  uint32_t  RTCCTR;                            /*!< Real-Time Clock Counter Register                                      */
} RTC_Type;


/* ================================================================================ */
/* ================                      GPIOA                     ================ */
/* ================================================================================ */


/**
  * @brief General-Purpose Input-Output Port A (GPIOA)
  */

typedef struct {                                    /*!< GPIOA Structure                                                       */
  __IO uint32_t  GPIOnO;                            /*!< GPIO Port Output                                                      */
  __IO uint32_t  GPIOnOE;                           /*!< GPIO Port Output Enable                                               */
  __IO uint32_t  GPIOnDS;                           /*!< GPIO Port Output Drive Strength Select                                */
  __IO uint32_t  GPIOnRUP;                          /*!< GPIO Port Weak Pull Up                                                */
  __IO uint32_t  GPIOnRDN;                          /*!< GPIO Port Weak Pull Down                                              */
  __I  uint32_t  GPIOnI;                            /*!< GPIO Port Input                                                       */
  __I  uint32_t  RESERVED;
  __IO uint32_t  GPIOnPSEL;                         /*!< GPIO Peripheral Select                                                */
  __IO uint32_t  GPIOnINTP;                         /*!< GPIO Port Interrupt Polarity                                          */
  __IO uint32_t  GPIOnINTEN;                        /*!< GPIO Port Interrupt Enable                                            */
  __I  uint32_t  GPIOnINT;                          /*!< GPIO Port Interrupt Flag                                              */
  __IO uint32_t  GPIOnINTM;                         /*!< GPIO Port Interrupt Mask                                              */
} GPIOA_Type;


/* ================================================================================ */
/* ================                      GPIOC                     ================ */
/* ================================================================================ */


/**
  * @brief General-Purpose Input-Output Port C (GPIOC)
  */

typedef struct {                                    /*!< GPIOC Structure                                                       */
  __IO uint32_t  GPIOnO;                            /*!< GPIO Port Output                                                      */
  __IO uint32_t  GPIOnOE;                           /*!< GPIO Port Output Enable                                               */
  __I  uint32_t  RESERVED[3];
  __I  uint32_t  GPIOnI;                            /*!< GPIO Port Input                                                       */
  __IO uint32_t  GPIOnIE;                           /*!< GPIO Port Input Enable                                                */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  GPIOnINTP;                         /*!< GPIO Port Interrupt Polarity                                          */
  __IO uint32_t  GPIOnINTEN;                        /*!< GPIO Port Interrupt Enable                                            */
  __I  uint32_t  GPIOnINT;                          /*!< GPIO Port Interrupt Flag                                              */
  __IO uint32_t  GPIOnINTM;                         /*!< GPIO Port Interrupt Mask                                              */
} GPIOC_Type;


/* ================================================================================ */
/* ================                     TIMERA                     ================ */
/* ================================================================================ */


/**
  * @brief Timer A Peripheral (TIMERA)
  */

typedef struct {                                    /*!< TIMERA Structure                                                      */
  __IO uint32_t  TxCTL;                             /*!< Timer Control Register                                                */
  __IO uint32_t  TxPRD;                             /*!< timer period                                                          */
  __I  uint32_t  TxCTR;                             /*!< timer counter                                                         */
  __I  uint32_t  RESERVED[13];
  __IO uint32_t  TxCC0CTL;                          /*!< timer capture and compare control unit 0                              */
  __IO uint32_t  TxCC0CTR;                          /*!< capture and compare counter unit 0                                    */
  __IO uint32_t  TxCC1CTL;                          /*!< timer capture and compare control unit 0                              */
  __IO uint32_t  TxCC1CTR;                          /*!< capture and compare counter unit 1                                    */
  __IO uint32_t  TxCC2CTL;                          /*!< timer capture and compare control unit 2                              */
  __IO uint32_t  TxCC2CTR;                          /*!< capture and compare counter unit 2                                    */
  __IO uint32_t  TxCC3CTL;                          /*!< timer capture and compare control unit 3                              */
  __IO uint32_t  TxCC3CTR;                          /*!< capture and compare counter unit 3                                    */
  __IO uint32_t  TxCC4CTL;                          /*!< timer capture and compare control unit 4                              */
  __IO uint32_t  TxCC4CTR;                          /*!< capture and compare counter unit 4                                    */
  __IO uint32_t  TxCC5CTL;                          /*!< timer capture and compare control unit 5                              */
  __IO uint32_t  TxCC5CTR;                          /*!< capture and compare counter unit 5                                    */
  __IO uint32_t  TxCC6CTL;                          /*!< timer capture and compare control unit 6                              */
  __IO uint32_t  TxCC6CTR;                          /*!< capture and compare counter unit 6                                    */
  __IO uint32_t  TxCC7CTL;                          /*!< timer capture and compare control unit 7                              */
  __IO uint32_t  TxCC7CTR;                          /*!< capture and compare counter unit 7                                    */
  __I  uint32_t  RESERVED1[8];
  __IO uint32_t  DTGA0CTL;                          /*!< Timer A dead-time generator control unit 0                            */
  __IO uint32_t  DTGA0LED;                          /*!< Timer A dead-time generator leading-edge delay counter unit
                                                         0                                                                     */
  __IO uint32_t  DTGA0TED;                          /*!< Timer A dead-time generator trailing-edge delay counter unit
                                                         0                                                                     */
  __I  uint32_t  RESERVED2;
  __IO uint32_t  DTGA1CTL;                          /*!< Timer A dead-time generator control unit 1                            */
  __IO uint32_t  DTGA1LED;                          /*!< Timer A dead-time generator leading-edge delay counter unit
                                                         1                                                                     */
  __IO uint32_t  DTGA1TED;                          /*!< Timer A dead-time generator trailing-edge delay counter unit
                                                         1                                                                     */
  __I  uint32_t  RESERVED3;
  __IO uint32_t  DTGA2CTL;                          /*!< Timer A dead-time generator control unit 2                            */
  __IO uint32_t  DTGA2LED;                          /*!< Timer A dead-time generator leading-edge delay counter unit
                                                         2                                                                     */
  __IO uint32_t  DTGA2TED;                          /*!< Timer A dead-time generator trailing-edge delay counter unit
                                                         2                                                                     */
  __I  uint32_t  RESERVED4;
  __IO uint32_t  DTGA3CTL;                          /*!< Timer A dead-time generator control unit 3                            */
  __IO uint32_t  DTGA3LED;                          /*!< Timer A dead-time generator leading-edge delay counter unit
                                                         3                                                                     */
  __IO uint32_t  DTGA3TED;                          /*!< Timer A dead-time generator trailing-edge delay counter unit
                                                         0                                                                     */
} TIMERA_Type;


/* ================================================================================ */
/* ================                     TIMERB                     ================ */
/* ================================================================================ */


/**
  * @brief Timer B Peripheral (TIMERB)
  */

typedef struct {                                    /*!< TIMERB Structure                                                      */
  __IO uint32_t  TxCTL;                             /*!< Timer Control Register                                                */
  __IO uint32_t  TxPRD;                             /*!< timer period                                                          */
  __I  uint32_t  TxCTR;                             /*!< timer counter                                                         */
  __I  uint32_t  RESERVED[13];
  __IO uint32_t  TxCC0CTL;                          /*!< timer capture and compare control unit 0                              */
  __IO uint32_t  TxCC0CTR;                          /*!< capture and compare counter unit 0                                    */
  __IO uint32_t  TxCC1CTL;                          /*!< timer capture and compare control unit 1                              */
  __IO uint32_t  TxCC1CTR;                          /*!< capture and compare counter unit 1                                    */
  __IO uint32_t  TxCC2CTL;                          /*!< timer capture and compare control unit 2                              */
  __IO uint32_t  TxCC2CTR;                          /*!< capture and compare counter unit 2                                    */
  __IO uint32_t  TxCC3CTL;                          /*!< timer capture and compare control unit 3                              */
  __IO uint32_t  TxCC3CTR;                          /*!< capture and compare counter unit 3                                    */
  __I  uint32_t  RESERVED1[16];
  __IO uint32_t  DTGB0CTL;                          /*!< Timer B dead-time generator control unit 0                            */
  __IO uint32_t  DTGB0LED;                          /*!< Timer B dead-time generator leading-edge delay counter unit
                                                         0                                                                     */
  __IO uint32_t  DTGB0TED;                          /*!< Timer B dead-time generator trailing-edge delay counter unit
                                                         0                                                                     */
} TIMERB_Type;


/* ================================================================================ */
/* ================                     TIMERC                     ================ */
/* ================================================================================ */


/**
  * @brief Timer C Peripheral (TIMERC)
  */

typedef struct {                                    /*!< TIMERC Structure                                                      */
  __IO uint32_t  TxCTL;                             /*!< Timer Control Register                                                */
  __IO uint32_t  TxPRD;                             /*!< timer period                                                          */
  __I  uint32_t  TxCTR;                             /*!< timer counter                                                         */
  __I  uint32_t  RESERVED[13];
  __IO uint32_t  TxCC0CTL;                          /*!< timer capture and compare control unit 0                              */
  __IO uint32_t  TxCC0CTR;                          /*!< capture and compare counter unit 0                                    */
  __IO uint32_t  TxCC1CTL;                          /*!< timer capture and compare control unit 1                              */
  __IO uint32_t  TxCC1CTR;                          /*!< capture and compare counter unit 1                                    */
  __I  uint32_t  RESERVED1[20];
  __IO uint32_t  DTGC0CTL;                          /*!< Timer C dead-time generator control unit 0                            */
  __IO uint32_t  DTGC0LED;                          /*!< Timer C dead-time generator leading-edge delay counter unit
                                                         0                                                                     */
  __IO uint32_t  DTGC0TED;                          /*!< Timer C dead-time generator trailing-edge delay counter unit
                                                         0                                                                     */
} TIMERC_Type;


/* ================================================================================ */
/* ================                     TIMERD                     ================ */
/* ================================================================================ */


/**
  * @brief Timer D Peripheral (TIMERD)
  */

typedef struct {                                    /*!< TIMERD Structure                                                      */
  __IO uint32_t  TxCTL;                             /*!< Timer Control Register                                                */
  __IO uint32_t  TxPRD;                             /*!< timer period                                                          */
  __I  uint32_t  TxCTR;                             /*!< timer counter                                                         */
  __I  uint32_t  RESERVED[13];
  __IO uint32_t  TxCC0CTL;                          /*!< timer capture and compare control unit 0                              */
  __IO uint32_t  TxCC0CTR;                          /*!< capture and compare counter unit 0                                    */
  __IO uint32_t  TxCC1CTL;                          /*!< timer capture and compare control unit 1                              */
  __IO uint32_t  TxCC1CTR;                          /*!< capture and compare counter unit 1                                    */
  __I  uint32_t  RESERVED1[20];
  __IO uint32_t  DTGD0CTL;                          /*!< Timer A dead-time generator control unit 0                            */
  __IO uint32_t  DTGD0LED;                          /*!< Timer A dead-time generator leading-edge delay counter unit
                                                         0                                                                     */
  __IO uint32_t  DTGD0TED;                          /*!< Timer A dead-time generator trailing-edge delay counter unit
                                                         0                                                                     */
} TIMERD_Type;


/* ================================================================================ */
/* ================                       ADC                      ================ */
/* ================================================================================ */


/**
  * @brief Analog to Digital Converter (ADC)
  */

typedef struct {                                    /*!< ADC Structure                                                         */
  __IO uint32_t  EMUXCTL;                           /*!< ADC External MUX control register                                     */
  __IO uint32_t  EMUXDATA;                          /*!< ADC External MUX data register                                        */
  __I  uint32_t  ADCCTL;                            /*!< ADC control register                                                  */
  __I  uint32_t  ADCCR;                             /*!< ADC conversion result register                                        */
  __IO uint32_t  ADCINT;                            /*!< ADC interrupt register                                                */
  __I  uint32_t  RESERVED[11];
  __IO uint32_t  AS0CTL;                            /*!< Auto sequencer 0 control register                                     */
  __IO uint32_t  AS0S0;                             /*!< Auto sequencer 0 sample 0 control register                            */
  __IO uint32_t  AS0R0;                             /*!< Auto sequencer 0 sample 0 result register                             */
  __IO uint32_t  AS0S1;                             /*!< Auto sequencer 0 sample 1 control register                            */
  __IO uint32_t  AS0R1;                             /*!< Auto sequencer 0 sample 1 result register                             */
  __IO uint32_t  AS0S2;                             /*!< Auto sequencer 0 sample 2 control register                            */
  __IO uint32_t  AS0R2;                             /*!< Auto sequencer 0 sample 2 result register                             */
  __IO uint32_t  AS0S3;                             /*!< Auto sequencer 0 sample 3 control register                            */
  __IO uint32_t  AS0R3;                             /*!< Auto sequencer 0 sample 3 result register                             */
  __IO uint32_t  AS0S4;                             /*!< Auto sequencer 0 sample 4 control register                            */
  __IO uint32_t  AS0R4;                             /*!< Auto sequencer 0 sample 4 result register                             */
  __IO uint32_t  AS0S5;                             /*!< Auto sequencer 0 sample 5 control register                            */
  __IO uint32_t  AS0R5;                             /*!< Auto sequencer 0 sample 5 result register                             */
  __IO uint32_t  AS0S6;                             /*!< Auto sequencer 0 sample 6 control register                            */
  __IO uint32_t  AS0R6;                             /*!< Auto sequencer 0 sample 6 result register                             */
  __IO uint32_t  AS0S7;                             /*!< Auto sequencer 0 sample 7 control register                            */
  __IO uint32_t  AS0R7;                             /*!< Auto sequencer 0 sample 7 result register                             */
  __I  uint32_t  RESERVED1[31];
  __IO uint32_t  AS1CTL;                            /*!< Auto sequencer 1 control register                                     */
  __IO uint32_t  AS1S0;                             /*!< Auto sequencer 1 sample 0 control register                            */
  __IO uint32_t  AS1R0;                             /*!< Auto sequencer 1 sample 0 result register                             */
  __IO uint32_t  AS1S1;                             /*!< Auto sequencer 1 sample 1 control register                            */
  __IO uint32_t  AS1R1;                             /*!< Auto sequencer 1 sample 1 result register                             */
  __IO uint32_t  AS1S2;                             /*!< Auto sequencer 1 sample 2 control register                            */
  __IO uint32_t  AS1R2;                             /*!< Auto sequencer 1 sample 2 result register                             */
  __IO uint32_t  AS1S3;                             /*!< Auto sequencer 1 sample 3 control register                            */
  __IO uint32_t  AS1R3;                             /*!< Auto sequencer 1 sample 3 result register                             */
  __IO uint32_t  AS1S4;                             /*!< Auto sequencer 1 sample 4 control register                            */
  __IO uint32_t  AS1R4;                             /*!< Auto sequencer 1 sample 4 result register                             */
  __IO uint32_t  AS1S5;                             /*!< Auto sequencer 1 sample 5 control register                            */
  __IO uint32_t  AS1R5;                             /*!< Auto sequencer 1 sample 5 result register                             */
  __IO uint32_t  AS1S6;                             /*!< Auto sequencer 1 sample 6 control register                            */
  __IO uint32_t  AS1R6;                             /*!< Auto sequencer 1 sample 6 result register                             */
  __IO uint32_t  AS1S7;                             /*!< Auto sequencer 1 sample 7 control register                            */
  __IO uint32_t  AS1R7;                             /*!< Auto sequencer 1 sample 7 result register                             */
} ADC_Type;


/* ================================================================================ */
/* ================                       I2C                      ================ */
/* ================================================================================ */


/**
  * @brief I2C (I2C)
  */

typedef struct {                                    /*!< I2C Structure                                                         */
  __IO uint32_t  I2CCFG;                            /*!< I2C Configuration Register                                            */
  __I  uint32_t  I2CINT;                            /*!< I2C Interrupt                                                         */
  __IO uint32_t  I2CINTEN;                          /*!< I2C Interrupt Enable                                                  */
  __I  uint32_t  RESERVED[9];
  __IO uint32_t  I2CMACTL;                          /*!< I2C master access control                                             */
  __I  uint32_t  I2CMARXDATA;                       /*!< I2C master receive data                                               */
  __I  uint32_t  I2CMATXDATA;                       /*!< I2C master transmit data                                              */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  I2CBAUD;                           /*!< I2C baud rate                                                         */
  __I  uint32_t  RESERVED2[11];
  __I  uint32_t  I2CSLRXDATA;                       /*!< I2C slave receive data                                                */
  __I  uint32_t  I2CSLTXDATA;                       /*!< I2C slave receive data                                                */
  __IO uint32_t  I2CSLADDR;                         /*!< I2C slave address                                                     */
} I2C_Type;


/* ================================================================================ */
/* ================                      UART                      ================ */
/* ================================================================================ */


/**
  * @brief UART (UART)
  */

typedef struct {                                    /*!< UART Structure                                                        */
  __IO uint32_t  UARTRXTX;                          /*!< UART receive/transmit FIFO                                            */
  __IO uint32_t  UARTIEN;                           /*!< UART interrupt enable                                                 */
  __IO uint32_t  UARTII;                            /*!< UART interrupt identification                                         */
  __IO uint32_t  UARTLC;                            /*!< UART Line Control                                                     */
  __I  uint32_t  RESERVED;
  __IO uint32_t  UARTLS;                            /*!< UART Line Status                                                      */
  __I  uint32_t  RESERVED1[2];
  __IO uint32_t  UARTFCTL;                          /*!< FIFO control                                                          */
  __IO uint32_t  UARTIE_R;                          /*!< UART interrupt enable remapped                                        */
  __IO uint32_t  UARTDL_L;                          /*!< UART divisor latch low byte                                           */
  __IO uint32_t  UARTDL_H;                          /*!< UART divisor latch high byte                                          */
  __I  uint32_t  RESERVED2[2];
  __IO uint32_t  UARTFD_F;                          /*!< UART fractional divisor value                                         */
  __I  uint32_t  RESERVED3;
  __IO uint32_t  UARTFSTAT;                         /*!< UART FIFO status                                                      */
} UART_Type;


/* ================================================================================ */
/* ================                      SOCB                      ================ */
/* ================================================================================ */


/**
  * @brief SOC Bus Bridge (SOCB)
  */

typedef struct {                                    /*!< SOCB Structure                                                        */
  __O  uint32_t  SOCBCTL;                           /*!< SOC Bus Bridge Control                                                */
  __IO uint32_t  SOCBCFG;                           /*!< SOC Bus Bridge Configuration                                          */
  __I  uint32_t  RESERVED[3];
  __IO uint32_t  SOCBSTAT;                          /*!< SOC Bus Bridge Status                                                 */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  SOCBD;                             /*!< SOC Bus Bridge Data. On READ, retrieve received data word from
                                                         the incoming holding buffer. On WRITE, write address or data
                                                          word to the outgoing holding buffer                                  */
  __IO uint32_t  SOCBINT_EN;                        /*!< SOC Bus Bridge Interrupt Enable                                       */
} SOCB_Type;


/* ================================================================================ */
/* ================                       SPI                      ================ */
/* ================================================================================ */


/**
  * @brief SPI (SPI)
  */

typedef struct {                                    /*!< SPI Structure                                                         */
  __O  uint32_t  SPICTL;                            /*!< SPI Control                                                           */
  __IO uint32_t  SPICFG;                            /*!< SPI Configuration                                                     */
  __IO uint32_t  SPICLKDIV;                         /*!< SPI Clock Divider                                                     */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  SPISTAT;                           /*!< SPI Status                                                            */
  __IO uint32_t  SPICSSTR;                          /*!< SPI Chip Select Steering Register                                     */
  __IO uint32_t  SPID;                              /*!< SPI Data. On READ, retrieve received data word from the incoming
                                                         holding buffer. On WRITE, write address or data word to the
                                                          outgoing holding buffer                                              */
  __IO uint32_t  SPIINT_EN;                         /*!< SPI Interrupt Enable                                                  */
} SPI_Type;


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif


/* ================================================================================ */
/* ================         struct 'SYSCLK' Position & Mask        ================ */
/* ================================================================================ */


/* --------------------------------  SYSCLK_SCCTL  -------------------------------- */
#define SYSCLK_SCCTL_CLKIN_Pos                0                                                       /*!< SYSCLK SCCTL: CLKIN Position            */
#define SYSCLK_SCCTL_CLKIN_Msk                (0x03UL << SYSCLK_SCCTL_CLKIN_Pos)                      /*!< SYSCLK SCCTL: CLKIN Mask                */
#define SYSCLK_SCCTL_ACLKDIV_Pos              2                                                       /*!< SYSCLK SCCTL: ACLKDIV Position          */
#define SYSCLK_SCCTL_ACLKDIV_Msk              (0x07UL << SYSCLK_SCCTL_ACLKDIV_Pos)                    /*!< SYSCLK SCCTL: ACLKDIV Mask              */
#define SYSCLK_SCCTL_HCLKDIV_Pos              5                                                       /*!< SYSCLK SCCTL: HCLKDIV Position          */
#define SYSCLK_SCCTL_HCLKDIV_Msk              (0x03UL << SYSCLK_SCCTL_HCLKDIV_Pos)                    /*!< SYSCLK SCCTL: HCLKDIV Mask              */
#define SYSCLK_SCCTL_FCLK_Pos                 7                                                       /*!< SYSCLK SCCTL: FCLK Position             */
#define SYSCLK_SCCTL_FCLK_Msk                 (0x01UL << SYSCLK_SCCTL_FCLK_Pos)                       /*!< SYSCLK SCCTL: FCLK Mask                 */

/* --------------------------------  SYSCLK_PLLCTL  ------------------------------- */
#define SYSCLK_PLLCTL_PLLEN_Pos               0                                                       /*!< SYSCLK PLLCTL: PLLEN Position           */
#define SYSCLK_PLLCTL_PLLEN_Msk               (0x01UL << SYSCLK_PLLCTL_PLLEN_Pos)                     /*!< SYSCLK PLLCTL: PLLEN Mask               */
#define SYSCLK_PLLCTL_PLLINDIV_Pos            2                                                       /*!< SYSCLK PLLCTL: PLLINDIV Position        */
#define SYSCLK_PLLCTL_PLLINDIV_Msk            (0x1fUL << SYSCLK_PLLCTL_PLLINDIV_Pos)                  /*!< SYSCLK PLLCTL: PLLINDIV Mask            */
#define SYSCLK_PLLCTL_PLLFBDIV_Pos            7                                                       /*!< SYSCLK PLLCTL: PLLFBDIV Position        */
#define SYSCLK_PLLCTL_PLLFBDIV_Msk            (0x000001ffUL << SYSCLK_PLLCTL_PLLFBDIV_Pos)            /*!< SYSCLK PLLCTL: PLLFBDIV Mask            */
#define SYSCLK_PLLCTL_PLLOUTDIV_Pos           16                                                      /*!< SYSCLK PLLCTL: PLLOUTDIV Position       */
#define SYSCLK_PLLCTL_PLLOUTDIV_Msk           (0x0fUL << SYSCLK_PLLCTL_PLLOUTDIV_Pos)                 /*!< SYSCLK PLLCTL: PLLOUTDIV Mask           */

/* -------------------------------  SYSCLK_ROSCCTL  ------------------------------- */
#define SYSCLK_ROSCCTL_ROSCEN_Pos             0                                                       /*!< SYSCLK ROSCCTL: ROSCEN Position         */
#define SYSCLK_ROSCCTL_ROSCEN_Msk             (0x01UL << SYSCLK_ROSCCTL_ROSCEN_Pos)                   /*!< SYSCLK ROSCCTL: ROSCEN Mask             */
#define SYSCLK_ROSCCTL_ROSCP_Pos              1                                                       /*!< SYSCLK ROSCCTL: ROSCP Position          */
#define SYSCLK_ROSCCTL_ROSCP_Msk              (0x03UL << SYSCLK_ROSCCTL_ROSCP_Pos)                    /*!< SYSCLK ROSCCTL: ROSCP Mask              */

/* -------------------------------  SYSCLK_XTALCTL  ------------------------------- */
#define SYSCLK_XTALCTL_XTALEN_Pos             0                                                       /*!< SYSCLK XTALCTL: XTALEN Position         */
#define SYSCLK_XTALCTL_XTALEN_Msk             (0x01UL << SYSCLK_XTALCTL_XTALEN_Pos)                   /*!< SYSCLK XTALCTL: XTALEN Mask             */


/* ================================================================================ */
/* ================         struct 'MEMCTL' Position & Mask        ================ */
/* ================================================================================ */


/* -----------------------------  MEMCTL_FLASHSTATUS  ----------------------------- */
#define MEMCTL_FLASHSTATUS_WRITE_Pos          0                                                       /*!< MEMCTL FLASHSTATUS: WRITE Position      */
#define MEMCTL_FLASHSTATUS_WRITE_Msk          (0x01UL << MEMCTL_FLASHSTATUS_WRITE_Pos)                /*!< MEMCTL FLASHSTATUS: WRITE Mask          */
#define MEMCTL_FLASHSTATUS_PERASE_Pos         1                                                       /*!< MEMCTL FLASHSTATUS: PERASE Position     */
#define MEMCTL_FLASHSTATUS_PERASE_Msk         (0x01UL << MEMCTL_FLASHSTATUS_PERASE_Pos)               /*!< MEMCTL FLASHSTATUS: PERASE Mask         */

/* -----------------------------  MEMCTL_FLASHWSTATE  ----------------------------- */
#define MEMCTL_FLASHWSTATE_WSTATE_Pos         0                                                       /*!< MEMCTL FLASHWSTATE: WSTATE Position     */
#define MEMCTL_FLASHWSTATE_WSTATE_Msk         (0x03UL << MEMCTL_FLASHWSTATE_WSTATE_Pos)               /*!< MEMCTL FLASHWSTATE: WSTATE Mask         */


/* ================================================================================ */
/* ================          struct 'WDT' Position & Mask          ================ */
/* ================================================================================ */


/* ---------------------------------  WDT_WDTCTL  --------------------------------- */
#define WDT_WDTCTL_WDTCTRRST_Pos              0                                                       /*!< WDT WDTCTL: WDTCTRRST Position          */
#define WDT_WDTCTL_WDTCTRRST_Msk              (0x07UL << WDT_WDTCTL_WDTCTRRST_Pos)                    /*!< WDT WDTCTL: WDTCTRRST Mask              */
#define WDT_WDTCTL_WDTINTEN_Pos               3                                                       /*!< WDT WDTCTL: WDTINTEN Position           */
#define WDT_WDTCTL_WDTINTEN_Msk               (0x01UL << WDT_WDTCTL_WDTINTEN_Pos)                     /*!< WDT WDTCTL: WDTINTEN Mask               */
#define WDT_WDTCTL_WDTINT_Pos                 4                                                       /*!< WDT WDTCTL: WDTINT Position             */
#define WDT_WDTCTL_WDTINT_Msk                 (0x01UL << WDT_WDTCTL_WDTINT_Pos)                       /*!< WDT WDTCTL: WDTINT Mask                 */
#define WDT_WDTCTL_WDTRESETEN_Pos             5                                                       /*!< WDT WDTCTL: WDTRESETEN Position         */
#define WDT_WDTCTL_WDTRESETEN_Msk             (0x01UL << WDT_WDTCTL_WDTRESETEN_Pos)                   /*!< WDT WDTCTL: WDTRESETEN Mask             */
#define WDT_WDTCTL_WDTCLKDIV_Pos              6                                                       /*!< WDT WDTCTL: WDTCLKDIV Position          */
#define WDT_WDTCTL_WDTCLKDIV_Msk              (0x0fUL << WDT_WDTCTL_WDTCLKDIV_Pos)                    /*!< WDT WDTCTL: WDTCLKDIV Mask              */
#define WDT_WDTCTL_WDTCLKSEL_Pos              10                                                      /*!< WDT WDTCTL: WDTCLKSEL Position          */
#define WDT_WDTCTL_WDTCLKSEL_Msk              (0x01UL << WDT_WDTCTL_WDTCLKSEL_Pos)                    /*!< WDT WDTCTL: WDTCLKSEL Mask              */
#define WDT_WDTCTL_WRBUSY_Pos                 11                                                      /*!< WDT WDTCTL: WRBUSY Position             */
#define WDT_WDTCTL_WRBUSY_Msk                 (0x01UL << WDT_WDTCTL_WRBUSY_Pos)                       /*!< WDT WDTCTL: WRBUSY Mask                 */
#define WDT_WDTCTL_KEY_Pos                    24                                                      /*!< WDT WDTCTL: KEY Position                */
#define WDT_WDTCTL_KEY_Msk                    (0x000000ffUL << WDT_WDTCTL_KEY_Pos)                    /*!< WDT WDTCTL: KEY Mask                    */

/* ---------------------------------  WDT_WDTCDV  --------------------------------- */
#define WDT_WDTCDV_RSTVALUE_Pos               0                                                       /*!< WDT WDTCDV: RSTVALUE Position           */
#define WDT_WDTCDV_RSTVALUE_Msk               (0x00ffffffUL << WDT_WDTCDV_RSTVALUE_Pos)               /*!< WDT WDTCDV: RSTVALUE Mask               */
#define WDT_WDTCDV_KEY_Pos                    24                                                      /*!< WDT WDTCDV: KEY Position                */
#define WDT_WDTCDV_KEY_Msk                    (0x000000ffUL << WDT_WDTCDV_KEY_Pos)                    /*!< WDT WDTCDV: KEY Mask                    */


/* ================================================================================ */
/* ================          struct 'RTC' Position & Mask          ================ */
/* ================================================================================ */


/* ---------------------------------  RTC_RTCCTL  --------------------------------- */
#define RTC_RTCCTL_RTCCTRRST_Pos              0                                                       /*!< RTC RTCCTL: RTCCTRRST Position          */
#define RTC_RTCCTL_RTCCTRRST_Msk              (0x07UL << RTC_RTCCTL_RTCCTRRST_Pos)                    /*!< RTC RTCCTL: RTCCTRRST Mask              */
#define RTC_RTCCTL_RTCINTEN_Pos               3                                                       /*!< RTC RTCCTL: RTCINTEN Position           */
#define RTC_RTCCTL_RTCINTEN_Msk               (0x01UL << RTC_RTCCTL_RTCINTEN_Pos)                     /*!< RTC RTCCTL: RTCINTEN Mask               */
#define RTC_RTCCTL_RTCINT_Pos                 4                                                       /*!< RTC RTCCTL: RTCINT Position             */
#define RTC_RTCCTL_RTCINT_Msk                 (0x01UL << RTC_RTCCTL_RTCINT_Pos)                       /*!< RTC RTCCTL: RTCINT Mask                 */
#define RTC_RTCCTL_RTCCLKDIV_Pos              6                                                       /*!< RTC RTCCTL: RTCCLKDIV Position          */
#define RTC_RTCCTL_RTCCLKDIV_Msk              (0x0fUL << RTC_RTCCTL_RTCCLKDIV_Pos)                    /*!< RTC RTCCTL: RTCCLKDIV Mask              */
#define RTC_RTCCTL_WRBUSY_Pos                 11                                                      /*!< RTC RTCCTL: WRBUSY Position             */
#define RTC_RTCCTL_WRBUSY_Msk                 (0x01UL << RTC_RTCCTL_WRBUSY_Pos)                       /*!< RTC RTCCTL: WRBUSY Mask                 */
#define RTC_RTCCTL_KEY_Pos                    24                                                      /*!< RTC RTCCTL: KEY Position                */
#define RTC_RTCCTL_KEY_Msk                    (0x000000ffUL << RTC_RTCCTL_KEY_Pos)                    /*!< RTC RTCCTL: KEY Mask                    */

/* ---------------------------------  RTC_RTCCDV  --------------------------------- */
#define RTC_RTCCDV_RSTVALUE_Pos               0                                                       /*!< RTC RTCCDV: RSTVALUE Position           */
#define RTC_RTCCDV_RSTVALUE_Msk               (0x00ffffffUL << RTC_RTCCDV_RSTVALUE_Pos)               /*!< RTC RTCCDV: RSTVALUE Mask               */
#define RTC_RTCCDV_KEY_Pos                    24                                                      /*!< RTC RTCCDV: KEY Position                */
#define RTC_RTCCDV_KEY_Msk                    (0x000000ffUL << RTC_RTCCDV_KEY_Pos)                    /*!< RTC RTCCDV: KEY Mask                    */


/* ================================================================================ */
/* ================         struct 'GPIOA' Position & Mask         ================ */
/* ================================================================================ */


/* --------------------------------  GPIOA_GPIOnO  -------------------------------- */
#define GPIOA_GPIOnO_Pn0O_Pos                 0                                                       /*!< GPIOA GPIOnO: Pn0O Position             */
#define GPIOA_GPIOnO_Pn0O_Msk                 (0x01UL << GPIOA_GPIOnO_Pn0O_Pos)                       /*!< GPIOA GPIOnO: Pn0O Mask                 */
#define GPIOA_GPIOnO_Pn1O_Pos                 1                                                       /*!< GPIOA GPIOnO: Pn1O Position             */
#define GPIOA_GPIOnO_Pn1O_Msk                 (0x01UL << GPIOA_GPIOnO_Pn1O_Pos)                       /*!< GPIOA GPIOnO: Pn1O Mask                 */
#define GPIOA_GPIOnO_Pn2O_Pos                 2                                                       /*!< GPIOA GPIOnO: Pn2O Position             */
#define GPIOA_GPIOnO_Pn2O_Msk                 (0x01UL << GPIOA_GPIOnO_Pn2O_Pos)                       /*!< GPIOA GPIOnO: Pn2O Mask                 */
#define GPIOA_GPIOnO_Pn3O_Pos                 3                                                       /*!< GPIOA GPIOnO: Pn3O Position             */
#define GPIOA_GPIOnO_Pn3O_Msk                 (0x01UL << GPIOA_GPIOnO_Pn3O_Pos)                       /*!< GPIOA GPIOnO: Pn3O Mask                 */
#define GPIOA_GPIOnO_Pn4O_Pos                 4                                                       /*!< GPIOA GPIOnO: Pn4O Position             */
#define GPIOA_GPIOnO_Pn4O_Msk                 (0x01UL << GPIOA_GPIOnO_Pn4O_Pos)                       /*!< GPIOA GPIOnO: Pn4O Mask                 */
#define GPIOA_GPIOnO_Pn5O_Pos                 5                                                       /*!< GPIOA GPIOnO: Pn5O Position             */
#define GPIOA_GPIOnO_Pn5O_Msk                 (0x01UL << GPIOA_GPIOnO_Pn5O_Pos)                       /*!< GPIOA GPIOnO: Pn5O Mask                 */
#define GPIOA_GPIOnO_Pn6O_Pos                 6                                                       /*!< GPIOA GPIOnO: Pn6O Position             */
#define GPIOA_GPIOnO_Pn6O_Msk                 (0x01UL << GPIOA_GPIOnO_Pn6O_Pos)                       /*!< GPIOA GPIOnO: Pn6O Mask                 */
#define GPIOA_GPIOnO_Pn7O_Pos                 7                                                       /*!< GPIOA GPIOnO: Pn7O Position             */
#define GPIOA_GPIOnO_Pn7O_Msk                 (0x01UL << GPIOA_GPIOnO_Pn7O_Pos)                       /*!< GPIOA GPIOnO: Pn7O Mask                 */

/* --------------------------------  GPIOA_GPIOnOE  ------------------------------- */
#define GPIOA_GPIOnOE_Pn0OE_Pos               0                                                       /*!< GPIOA GPIOnOE: Pn0OE Position           */
#define GPIOA_GPIOnOE_Pn0OE_Msk               (0x01UL << GPIOA_GPIOnOE_Pn0OE_Pos)                     /*!< GPIOA GPIOnOE: Pn0OE Mask               */
#define GPIOA_GPIOnOE_Pn1OE_Pos               1                                                       /*!< GPIOA GPIOnOE: Pn1OE Position           */
#define GPIOA_GPIOnOE_Pn1OE_Msk               (0x01UL << GPIOA_GPIOnOE_Pn1OE_Pos)                     /*!< GPIOA GPIOnOE: Pn1OE Mask               */
#define GPIOA_GPIOnOE_Pn2OE_Pos               2                                                       /*!< GPIOA GPIOnOE: Pn2OE Position           */
#define GPIOA_GPIOnOE_Pn2OE_Msk               (0x01UL << GPIOA_GPIOnOE_Pn2OE_Pos)                     /*!< GPIOA GPIOnOE: Pn2OE Mask               */
#define GPIOA_GPIOnOE_Pn3OE_Pos               3                                                       /*!< GPIOA GPIOnOE: Pn3OE Position           */
#define GPIOA_GPIOnOE_Pn3OE_Msk               (0x01UL << GPIOA_GPIOnOE_Pn3OE_Pos)                     /*!< GPIOA GPIOnOE: Pn3OE Mask               */
#define GPIOA_GPIOnOE_Pn4OE_Pos               4                                                       /*!< GPIOA GPIOnOE: Pn4OE Position           */
#define GPIOA_GPIOnOE_Pn4OE_Msk               (0x01UL << GPIOA_GPIOnOE_Pn4OE_Pos)                     /*!< GPIOA GPIOnOE: Pn4OE Mask               */
#define GPIOA_GPIOnOE_Pn5OE_Pos               5                                                       /*!< GPIOA GPIOnOE: Pn5OE Position           */
#define GPIOA_GPIOnOE_Pn5OE_Msk               (0x01UL << GPIOA_GPIOnOE_Pn5OE_Pos)                     /*!< GPIOA GPIOnOE: Pn5OE Mask               */
#define GPIOA_GPIOnOE_Pn6OE_Pos               6                                                       /*!< GPIOA GPIOnOE: Pn6OE Position           */
#define GPIOA_GPIOnOE_Pn6OE_Msk               (0x01UL << GPIOA_GPIOnOE_Pn6OE_Pos)                     /*!< GPIOA GPIOnOE: Pn6OE Mask               */
#define GPIOA_GPIOnOE_Pn7OE_Pos               7                                                       /*!< GPIOA GPIOnOE: Pn7OE Position           */
#define GPIOA_GPIOnOE_Pn7OE_Msk               (0x01UL << GPIOA_GPIOnOE_Pn7OE_Pos)                     /*!< GPIOA GPIOnOE: Pn7OE Mask               */

/* --------------------------------  GPIOA_GPIOnDS  ------------------------------- */
#define GPIOA_GPIOnDS_Pn0DS_Pos               0                                                       /*!< GPIOA GPIOnDS: Pn0DS Position           */
#define GPIOA_GPIOnDS_Pn0DS_Msk               (0x01UL << GPIOA_GPIOnDS_Pn0DS_Pos)                     /*!< GPIOA GPIOnDS: Pn0DS Mask               */
#define GPIOA_GPIOnDS_Pn1DS_Pos               1                                                       /*!< GPIOA GPIOnDS: Pn1DS Position           */
#define GPIOA_GPIOnDS_Pn1DS_Msk               (0x01UL << GPIOA_GPIOnDS_Pn1DS_Pos)                     /*!< GPIOA GPIOnDS: Pn1DS Mask               */
#define GPIOA_GPIOnDS_Pn2DS_Pos               2                                                       /*!< GPIOA GPIOnDS: Pn2DS Position           */
#define GPIOA_GPIOnDS_Pn2DS_Msk               (0x01UL << GPIOA_GPIOnDS_Pn2DS_Pos)                     /*!< GPIOA GPIOnDS: Pn2DS Mask               */
#define GPIOA_GPIOnDS_Pn3DS_Pos               3                                                       /*!< GPIOA GPIOnDS: Pn3DS Position           */
#define GPIOA_GPIOnDS_Pn3DS_Msk               (0x01UL << GPIOA_GPIOnDS_Pn3DS_Pos)                     /*!< GPIOA GPIOnDS: Pn3DS Mask               */
#define GPIOA_GPIOnDS_Pn4DS_Pos               4                                                       /*!< GPIOA GPIOnDS: Pn4DS Position           */
#define GPIOA_GPIOnDS_Pn4DS_Msk               (0x01UL << GPIOA_GPIOnDS_Pn4DS_Pos)                     /*!< GPIOA GPIOnDS: Pn4DS Mask               */
#define GPIOA_GPIOnDS_Pn5DS_Pos               5                                                       /*!< GPIOA GPIOnDS: Pn5DS Position           */
#define GPIOA_GPIOnDS_Pn5DS_Msk               (0x01UL << GPIOA_GPIOnDS_Pn5DS_Pos)                     /*!< GPIOA GPIOnDS: Pn5DS Mask               */
#define GPIOA_GPIOnDS_Pn6DS_Pos               6                                                       /*!< GPIOA GPIOnDS: Pn6DS Position           */
#define GPIOA_GPIOnDS_Pn6DS_Msk               (0x01UL << GPIOA_GPIOnDS_Pn6DS_Pos)                     /*!< GPIOA GPIOnDS: Pn6DS Mask               */
#define GPIOA_GPIOnDS_Pn7DS_Pos               7                                                       /*!< GPIOA GPIOnDS: Pn7DS Position           */
#define GPIOA_GPIOnDS_Pn7DS_Msk               (0x01UL << GPIOA_GPIOnDS_Pn7DS_Pos)                     /*!< GPIOA GPIOnDS: Pn7DS Mask               */

/* -------------------------------  GPIOA_GPIOnRUP  ------------------------------- */
#define GPIOA_GPIOnRUP_Pn0RUP_Pos             0                                                       /*!< GPIOA GPIOnRUP: Pn0RUP Position         */
#define GPIOA_GPIOnRUP_Pn0RUP_Msk             (0x01UL << GPIOA_GPIOnRUP_Pn0RUP_Pos)                   /*!< GPIOA GPIOnRUP: Pn0RUP Mask             */
#define GPIOA_GPIOnRUP_Pn1RUP_Pos             1                                                       /*!< GPIOA GPIOnRUP: Pn1RUP Position         */
#define GPIOA_GPIOnRUP_Pn1RUP_Msk             (0x01UL << GPIOA_GPIOnRUP_Pn1RUP_Pos)                   /*!< GPIOA GPIOnRUP: Pn1RUP Mask             */
#define GPIOA_GPIOnRUP_Pn2RUP_Pos             2                                                       /*!< GPIOA GPIOnRUP: Pn2RUP Position         */
#define GPIOA_GPIOnRUP_Pn2RUP_Msk             (0x01UL << GPIOA_GPIOnRUP_Pn2RUP_Pos)                   /*!< GPIOA GPIOnRUP: Pn2RUP Mask             */
#define GPIOA_GPIOnRUP_Pn3RUP_Pos             3                                                       /*!< GPIOA GPIOnRUP: Pn3RUP Position         */
#define GPIOA_GPIOnRUP_Pn3RUP_Msk             (0x01UL << GPIOA_GPIOnRUP_Pn3RUP_Pos)                   /*!< GPIOA GPIOnRUP: Pn3RUP Mask             */
#define GPIOA_GPIOnRUP_Pn4RUP_Pos             4                                                       /*!< GPIOA GPIOnRUP: Pn4RUP Position         */
#define GPIOA_GPIOnRUP_Pn4RUP_Msk             (0x01UL << GPIOA_GPIOnRUP_Pn4RUP_Pos)                   /*!< GPIOA GPIOnRUP: Pn4RUP Mask             */
#define GPIOA_GPIOnRUP_Pn5RUP_Pos             5                                                       /*!< GPIOA GPIOnRUP: Pn5RUP Position         */
#define GPIOA_GPIOnRUP_Pn5RUP_Msk             (0x01UL << GPIOA_GPIOnRUP_Pn5RUP_Pos)                   /*!< GPIOA GPIOnRUP: Pn5RUP Mask             */
#define GPIOA_GPIOnRUP_Pn6RUP_Pos             6                                                       /*!< GPIOA GPIOnRUP: Pn6RUP Position         */
#define GPIOA_GPIOnRUP_Pn6RUP_Msk             (0x01UL << GPIOA_GPIOnRUP_Pn6RUP_Pos)                   /*!< GPIOA GPIOnRUP: Pn6RUP Mask             */
#define GPIOA_GPIOnRUP_Pn7RUP_Pos             7                                                       /*!< GPIOA GPIOnRUP: Pn7RUP Position         */
#define GPIOA_GPIOnRUP_Pn7RUP_Msk             (0x01UL << GPIOA_GPIOnRUP_Pn7RUP_Pos)                   /*!< GPIOA GPIOnRUP: Pn7RUP Mask             */

/* -------------------------------  GPIOA_GPIOnRDN  ------------------------------- */
#define GPIOA_GPIOnRDN_Pn0RDN_Pos             0                                                       /*!< GPIOA GPIOnRDN: Pn0RDN Position         */
#define GPIOA_GPIOnRDN_Pn0RDN_Msk             (0x01UL << GPIOA_GPIOnRDN_Pn0RDN_Pos)                   /*!< GPIOA GPIOnRDN: Pn0RDN Mask             */
#define GPIOA_GPIOnRDN_Pn1RDN_Pos             1                                                       /*!< GPIOA GPIOnRDN: Pn1RDN Position         */
#define GPIOA_GPIOnRDN_Pn1RDN_Msk             (0x01UL << GPIOA_GPIOnRDN_Pn1RDN_Pos)                   /*!< GPIOA GPIOnRDN: Pn1RDN Mask             */
#define GPIOA_GPIOnRDN_Pn2RDN_Pos             2                                                       /*!< GPIOA GPIOnRDN: Pn2RDN Position         */
#define GPIOA_GPIOnRDN_Pn2RDN_Msk             (0x01UL << GPIOA_GPIOnRDN_Pn2RDN_Pos)                   /*!< GPIOA GPIOnRDN: Pn2RDN Mask             */
#define GPIOA_GPIOnRDN_Pn3RDN_Pos             3                                                       /*!< GPIOA GPIOnRDN: Pn3RDN Position         */
#define GPIOA_GPIOnRDN_Pn3RDN_Msk             (0x01UL << GPIOA_GPIOnRDN_Pn3RDN_Pos)                   /*!< GPIOA GPIOnRDN: Pn3RDN Mask             */
#define GPIOA_GPIOnRDN_Pn4RDN_Pos             4                                                       /*!< GPIOA GPIOnRDN: Pn4RDN Position         */
#define GPIOA_GPIOnRDN_Pn4RDN_Msk             (0x01UL << GPIOA_GPIOnRDN_Pn4RDN_Pos)                   /*!< GPIOA GPIOnRDN: Pn4RDN Mask             */
#define GPIOA_GPIOnRDN_Pn5RDN_Pos             5                                                       /*!< GPIOA GPIOnRDN: Pn5RDN Position         */
#define GPIOA_GPIOnRDN_Pn5RDN_Msk             (0x01UL << GPIOA_GPIOnRDN_Pn5RDN_Pos)                   /*!< GPIOA GPIOnRDN: Pn5RDN Mask             */
#define GPIOA_GPIOnRDN_Pn6RDN_Pos             6                                                       /*!< GPIOA GPIOnRDN: Pn6RDN Position         */
#define GPIOA_GPIOnRDN_Pn6RDN_Msk             (0x01UL << GPIOA_GPIOnRDN_Pn6RDN_Pos)                   /*!< GPIOA GPIOnRDN: Pn6RDN Mask             */
#define GPIOA_GPIOnRDN_Pn7RDN_Pos             7                                                       /*!< GPIOA GPIOnRDN: Pn7RDN Position         */
#define GPIOA_GPIOnRDN_Pn7RDN_Msk             (0x01UL << GPIOA_GPIOnRDN_Pn7RDN_Pos)                   /*!< GPIOA GPIOnRDN: Pn7RDN Mask             */

/* --------------------------------  GPIOA_GPIOnI  -------------------------------- */
#define GPIOA_GPIOnI_Pn0I_Pos                 0                                                       /*!< GPIOA GPIOnI: Pn0I Position             */
#define GPIOA_GPIOnI_Pn0I_Msk                 (0x01UL << GPIOA_GPIOnI_Pn0I_Pos)                       /*!< GPIOA GPIOnI: Pn0I Mask                 */
#define GPIOA_GPIOnI_Pn1I_Pos                 1                                                       /*!< GPIOA GPIOnI: Pn1I Position             */
#define GPIOA_GPIOnI_Pn1I_Msk                 (0x01UL << GPIOA_GPIOnI_Pn1I_Pos)                       /*!< GPIOA GPIOnI: Pn1I Mask                 */
#define GPIOA_GPIOnI_Pn2I_Pos                 2                                                       /*!< GPIOA GPIOnI: Pn2I Position             */
#define GPIOA_GPIOnI_Pn2I_Msk                 (0x01UL << GPIOA_GPIOnI_Pn2I_Pos)                       /*!< GPIOA GPIOnI: Pn2I Mask                 */
#define GPIOA_GPIOnI_Pn3I_Pos                 3                                                       /*!< GPIOA GPIOnI: Pn3I Position             */
#define GPIOA_GPIOnI_Pn3I_Msk                 (0x01UL << GPIOA_GPIOnI_Pn3I_Pos)                       /*!< GPIOA GPIOnI: Pn3I Mask                 */
#define GPIOA_GPIOnI_Pn4I_Pos                 4                                                       /*!< GPIOA GPIOnI: Pn4I Position             */
#define GPIOA_GPIOnI_Pn4I_Msk                 (0x01UL << GPIOA_GPIOnI_Pn4I_Pos)                       /*!< GPIOA GPIOnI: Pn4I Mask                 */
#define GPIOA_GPIOnI_Pn5I_Pos                 5                                                       /*!< GPIOA GPIOnI: Pn5I Position             */
#define GPIOA_GPIOnI_Pn5I_Msk                 (0x01UL << GPIOA_GPIOnI_Pn5I_Pos)                       /*!< GPIOA GPIOnI: Pn5I Mask                 */
#define GPIOA_GPIOnI_Pn6I_Pos                 6                                                       /*!< GPIOA GPIOnI: Pn6I Position             */
#define GPIOA_GPIOnI_Pn6I_Msk                 (0x01UL << GPIOA_GPIOnI_Pn6I_Pos)                       /*!< GPIOA GPIOnI: Pn6I Mask                 */
#define GPIOA_GPIOnI_Pn7I_Pos                 7                                                       /*!< GPIOA GPIOnI: Pn7I Position             */
#define GPIOA_GPIOnI_Pn7I_Msk                 (0x01UL << GPIOA_GPIOnI_Pn7I_Pos)                       /*!< GPIOA GPIOnI: Pn7I Mask                 */

/* -------------------------------  GPIOA_GPIOnPSEL  ------------------------------ */
#define GPIOA_GPIOnPSEL_Pn0PSEL_Pos           0                                                       /*!< GPIOA GPIOnPSEL: Pn0PSEL Position       */
#define GPIOA_GPIOnPSEL_Pn0PSEL_Msk           (0x03UL << GPIOA_GPIOnPSEL_Pn0PSEL_Pos)                 /*!< GPIOA GPIOnPSEL: Pn0PSEL Mask           */
#define GPIOA_GPIOnPSEL_Pn1PSEL_Pos           2                                                       /*!< GPIOA GPIOnPSEL: Pn1PSEL Position       */
#define GPIOA_GPIOnPSEL_Pn1PSEL_Msk           (0x03UL << GPIOA_GPIOnPSEL_Pn1PSEL_Pos)                 /*!< GPIOA GPIOnPSEL: Pn1PSEL Mask           */
#define GPIOA_GPIOnPSEL_Pn2PSEL_Pos           4                                                       /*!< GPIOA GPIOnPSEL: Pn2PSEL Position       */
#define GPIOA_GPIOnPSEL_Pn2PSEL_Msk           (0x03UL << GPIOA_GPIOnPSEL_Pn2PSEL_Pos)                 /*!< GPIOA GPIOnPSEL: Pn2PSEL Mask           */
#define GPIOA_GPIOnPSEL_Pn3PSEL_Pos           6                                                       /*!< GPIOA GPIOnPSEL: Pn3PSEL Position       */
#define GPIOA_GPIOnPSEL_Pn3PSEL_Msk           (0x03UL << GPIOA_GPIOnPSEL_Pn3PSEL_Pos)                 /*!< GPIOA GPIOnPSEL: Pn3PSEL Mask           */
#define GPIOA_GPIOnPSEL_Pn4PSEL_Pos           8                                                       /*!< GPIOA GPIOnPSEL: Pn4PSEL Position       */
#define GPIOA_GPIOnPSEL_Pn4PSEL_Msk           (0x03UL << GPIOA_GPIOnPSEL_Pn4PSEL_Pos)                 /*!< GPIOA GPIOnPSEL: Pn4PSEL Mask           */
#define GPIOA_GPIOnPSEL_Pn5PSEL_Pos           10                                                      /*!< GPIOA GPIOnPSEL: Pn5PSEL Position       */
#define GPIOA_GPIOnPSEL_Pn5PSEL_Msk           (0x03UL << GPIOA_GPIOnPSEL_Pn5PSEL_Pos)                 /*!< GPIOA GPIOnPSEL: Pn5PSEL Mask           */
#define GPIOA_GPIOnPSEL_Pn6PSEL_Pos           12                                                      /*!< GPIOA GPIOnPSEL: Pn6PSEL Position       */
#define GPIOA_GPIOnPSEL_Pn6PSEL_Msk           (0x03UL << GPIOA_GPIOnPSEL_Pn6PSEL_Pos)                 /*!< GPIOA GPIOnPSEL: Pn6PSEL Mask           */
#define GPIOA_GPIOnPSEL_Pn7PSEL_Pos           14                                                      /*!< GPIOA GPIOnPSEL: Pn7PSEL Position       */
#define GPIOA_GPIOnPSEL_Pn7PSEL_Msk           (0x03UL << GPIOA_GPIOnPSEL_Pn7PSEL_Pos)                 /*!< GPIOA GPIOnPSEL: Pn7PSEL Mask           */

/* -------------------------------  GPIOA_GPIOnINTP  ------------------------------ */
#define GPIOA_GPIOnINTP_Pn0INTP_Pos           0                                                       /*!< GPIOA GPIOnINTP: Pn0INTP Position       */
#define GPIOA_GPIOnINTP_Pn0INTP_Msk           (0x01UL << GPIOA_GPIOnINTP_Pn0INTP_Pos)                 /*!< GPIOA GPIOnINTP: Pn0INTP Mask           */
#define GPIOA_GPIOnINTP_Pn1INTP_Pos           1                                                       /*!< GPIOA GPIOnINTP: Pn1INTP Position       */
#define GPIOA_GPIOnINTP_Pn1INTP_Msk           (0x01UL << GPIOA_GPIOnINTP_Pn1INTP_Pos)                 /*!< GPIOA GPIOnINTP: Pn1INTP Mask           */
#define GPIOA_GPIOnINTP_Pn2INTP_Pos           2                                                       /*!< GPIOA GPIOnINTP: Pn2INTP Position       */
#define GPIOA_GPIOnINTP_Pn2INTP_Msk           (0x01UL << GPIOA_GPIOnINTP_Pn2INTP_Pos)                 /*!< GPIOA GPIOnINTP: Pn2INTP Mask           */
#define GPIOA_GPIOnINTP_Pn3INTP_Pos           3                                                       /*!< GPIOA GPIOnINTP: Pn3INTP Position       */
#define GPIOA_GPIOnINTP_Pn3INTP_Msk           (0x01UL << GPIOA_GPIOnINTP_Pn3INTP_Pos)                 /*!< GPIOA GPIOnINTP: Pn3INTP Mask           */
#define GPIOA_GPIOnINTP_Pn4INTP_Pos           4                                                       /*!< GPIOA GPIOnINTP: Pn4INTP Position       */
#define GPIOA_GPIOnINTP_Pn4INTP_Msk           (0x01UL << GPIOA_GPIOnINTP_Pn4INTP_Pos)                 /*!< GPIOA GPIOnINTP: Pn4INTP Mask           */
#define GPIOA_GPIOnINTP_Pn5INTP_Pos           5                                                       /*!< GPIOA GPIOnINTP: Pn5INTP Position       */
#define GPIOA_GPIOnINTP_Pn5INTP_Msk           (0x01UL << GPIOA_GPIOnINTP_Pn5INTP_Pos)                 /*!< GPIOA GPIOnINTP: Pn5INTP Mask           */
#define GPIOA_GPIOnINTP_Pn6INTP_Pos           6                                                       /*!< GPIOA GPIOnINTP: Pn6INTP Position       */
#define GPIOA_GPIOnINTP_Pn6INTP_Msk           (0x01UL << GPIOA_GPIOnINTP_Pn6INTP_Pos)                 /*!< GPIOA GPIOnINTP: Pn6INTP Mask           */
#define GPIOA_GPIOnINTP_Pn7INTP_Pos           7                                                       /*!< GPIOA GPIOnINTP: Pn7INTP Position       */
#define GPIOA_GPIOnINTP_Pn7INTP_Msk           (0x01UL << GPIOA_GPIOnINTP_Pn7INTP_Pos)                 /*!< GPIOA GPIOnINTP: Pn7INTP Mask           */

/* ------------------------------  GPIOA_GPIOnINTEN  ------------------------------ */
#define GPIOA_GPIOnINTEN_Pn0INTEN_Pos         0                                                       /*!< GPIOA GPIOnINTEN: Pn0INTEN Position     */
#define GPIOA_GPIOnINTEN_Pn0INTEN_Msk         (0x01UL << GPIOA_GPIOnINTEN_Pn0INTEN_Pos)               /*!< GPIOA GPIOnINTEN: Pn0INTEN Mask         */
#define GPIOA_GPIOnINTEN_Pn1INTEN_Pos         1                                                       /*!< GPIOA GPIOnINTEN: Pn1INTEN Position     */
#define GPIOA_GPIOnINTEN_Pn1INTEN_Msk         (0x01UL << GPIOA_GPIOnINTEN_Pn1INTEN_Pos)               /*!< GPIOA GPIOnINTEN: Pn1INTEN Mask         */
#define GPIOA_GPIOnINTEN_Pn2INTEN_Pos         2                                                       /*!< GPIOA GPIOnINTEN: Pn2INTEN Position     */
#define GPIOA_GPIOnINTEN_Pn2INTEN_Msk         (0x01UL << GPIOA_GPIOnINTEN_Pn2INTEN_Pos)               /*!< GPIOA GPIOnINTEN: Pn2INTEN Mask         */
#define GPIOA_GPIOnINTEN_Pn3INTEN_Pos         3                                                       /*!< GPIOA GPIOnINTEN: Pn3INTEN Position     */
#define GPIOA_GPIOnINTEN_Pn3INTEN_Msk         (0x01UL << GPIOA_GPIOnINTEN_Pn3INTEN_Pos)               /*!< GPIOA GPIOnINTEN: Pn3INTEN Mask         */
#define GPIOA_GPIOnINTEN_Pn4INTEN_Pos         4                                                       /*!< GPIOA GPIOnINTEN: Pn4INTEN Position     */
#define GPIOA_GPIOnINTEN_Pn4INTEN_Msk         (0x01UL << GPIOA_GPIOnINTEN_Pn4INTEN_Pos)               /*!< GPIOA GPIOnINTEN: Pn4INTEN Mask         */
#define GPIOA_GPIOnINTEN_Pn5INTEN_Pos         5                                                       /*!< GPIOA GPIOnINTEN: Pn5INTEN Position     */
#define GPIOA_GPIOnINTEN_Pn5INTEN_Msk         (0x01UL << GPIOA_GPIOnINTEN_Pn5INTEN_Pos)               /*!< GPIOA GPIOnINTEN: Pn5INTEN Mask         */
#define GPIOA_GPIOnINTEN_Pn6INTEN_Pos         6                                                       /*!< GPIOA GPIOnINTEN: Pn6INTEN Position     */
#define GPIOA_GPIOnINTEN_Pn6INTEN_Msk         (0x01UL << GPIOA_GPIOnINTEN_Pn6INTEN_Pos)               /*!< GPIOA GPIOnINTEN: Pn6INTEN Mask         */
#define GPIOA_GPIOnINTEN_Pn7INTEN_Pos         7                                                       /*!< GPIOA GPIOnINTEN: Pn7INTEN Position     */
#define GPIOA_GPIOnINTEN_Pn7INTEN_Msk         (0x01UL << GPIOA_GPIOnINTEN_Pn7INTEN_Pos)               /*!< GPIOA GPIOnINTEN: Pn7INTEN Mask         */

/* -------------------------------  GPIOA_GPIOnINT  ------------------------------- */
#define GPIOA_GPIOnINT_Pn0INT_Pos             0                                                       /*!< GPIOA GPIOnINT: Pn0INT Position         */
#define GPIOA_GPIOnINT_Pn0INT_Msk             (0x01UL << GPIOA_GPIOnINT_Pn0INT_Pos)                   /*!< GPIOA GPIOnINT: Pn0INT Mask             */
#define GPIOA_GPIOnINT_Pn1INT_Pos             1                                                       /*!< GPIOA GPIOnINT: Pn1INT Position         */
#define GPIOA_GPIOnINT_Pn1INT_Msk             (0x01UL << GPIOA_GPIOnINT_Pn1INT_Pos)                   /*!< GPIOA GPIOnINT: Pn1INT Mask             */
#define GPIOA_GPIOnINT_Pn2INT_Pos             2                                                       /*!< GPIOA GPIOnINT: Pn2INT Position         */
#define GPIOA_GPIOnINT_Pn2INT_Msk             (0x01UL << GPIOA_GPIOnINT_Pn2INT_Pos)                   /*!< GPIOA GPIOnINT: Pn2INT Mask             */
#define GPIOA_GPIOnINT_Pn3INT_Pos             3                                                       /*!< GPIOA GPIOnINT: Pn3INT Position         */
#define GPIOA_GPIOnINT_Pn3INT_Msk             (0x01UL << GPIOA_GPIOnINT_Pn3INT_Pos)                   /*!< GPIOA GPIOnINT: Pn3INT Mask             */
#define GPIOA_GPIOnINT_Pn4INT_Pos             4                                                       /*!< GPIOA GPIOnINT: Pn4INT Position         */
#define GPIOA_GPIOnINT_Pn4INT_Msk             (0x01UL << GPIOA_GPIOnINT_Pn4INT_Pos)                   /*!< GPIOA GPIOnINT: Pn4INT Mask             */
#define GPIOA_GPIOnINT_Pn5INT_Pos             5                                                       /*!< GPIOA GPIOnINT: Pn5INT Position         */
#define GPIOA_GPIOnINT_Pn5INT_Msk             (0x01UL << GPIOA_GPIOnINT_Pn5INT_Pos)                   /*!< GPIOA GPIOnINT: Pn5INT Mask             */
#define GPIOA_GPIOnINT_Pn6INT_Pos             6                                                       /*!< GPIOA GPIOnINT: Pn6INT Position         */
#define GPIOA_GPIOnINT_Pn6INT_Msk             (0x01UL << GPIOA_GPIOnINT_Pn6INT_Pos)                   /*!< GPIOA GPIOnINT: Pn6INT Mask             */
#define GPIOA_GPIOnINT_Pn7INT_Pos             7                                                       /*!< GPIOA GPIOnINT: Pn7INT Position         */
#define GPIOA_GPIOnINT_Pn7INT_Msk             (0x01UL << GPIOA_GPIOnINT_Pn7INT_Pos)                   /*!< GPIOA GPIOnINT: Pn7INT Mask             */

/* -------------------------------  GPIOA_GPIOnINTM  ------------------------------ */
#define GPIOA_GPIOnINTM_Pn0INTM_Pos           0                                                       /*!< GPIOA GPIOnINTM: Pn0INTM Position       */
#define GPIOA_GPIOnINTM_Pn0INTM_Msk           (0x01UL << GPIOA_GPIOnINTM_Pn0INTM_Pos)                 /*!< GPIOA GPIOnINTM: Pn0INTM Mask           */
#define GPIOA_GPIOnINTM_Pn1INTM_Pos           1                                                       /*!< GPIOA GPIOnINTM: Pn1INTM Position       */
#define GPIOA_GPIOnINTM_Pn1INTM_Msk           (0x01UL << GPIOA_GPIOnINTM_Pn1INTM_Pos)                 /*!< GPIOA GPIOnINTM: Pn1INTM Mask           */
#define GPIOA_GPIOnINTM_Pn2INTM_Pos           2                                                       /*!< GPIOA GPIOnINTM: Pn2INTM Position       */
#define GPIOA_GPIOnINTM_Pn2INTM_Msk           (0x01UL << GPIOA_GPIOnINTM_Pn2INTM_Pos)                 /*!< GPIOA GPIOnINTM: Pn2INTM Mask           */
#define GPIOA_GPIOnINTM_Pn3INTM_Pos           3                                                       /*!< GPIOA GPIOnINTM: Pn3INTM Position       */
#define GPIOA_GPIOnINTM_Pn3INTM_Msk           (0x01UL << GPIOA_GPIOnINTM_Pn3INTM_Pos)                 /*!< GPIOA GPIOnINTM: Pn3INTM Mask           */
#define GPIOA_GPIOnINTM_Pn4INTM_Pos           4                                                       /*!< GPIOA GPIOnINTM: Pn4INTM Position       */
#define GPIOA_GPIOnINTM_Pn4INTM_Msk           (0x01UL << GPIOA_GPIOnINTM_Pn4INTM_Pos)                 /*!< GPIOA GPIOnINTM: Pn4INTM Mask           */
#define GPIOA_GPIOnINTM_Pn5INTM_Pos           5                                                       /*!< GPIOA GPIOnINTM: Pn5INTM Position       */
#define GPIOA_GPIOnINTM_Pn5INTM_Msk           (0x01UL << GPIOA_GPIOnINTM_Pn5INTM_Pos)                 /*!< GPIOA GPIOnINTM: Pn5INTM Mask           */
#define GPIOA_GPIOnINTM_Pn6INTM_Pos           6                                                       /*!< GPIOA GPIOnINTM: Pn6INTM Position       */
#define GPIOA_GPIOnINTM_Pn6INTM_Msk           (0x01UL << GPIOA_GPIOnINTM_Pn6INTM_Pos)                 /*!< GPIOA GPIOnINTM: Pn6INTM Mask           */
#define GPIOA_GPIOnINTM_Pn7INTM_Pos           7                                                       /*!< GPIOA GPIOnINTM: Pn7INTM Position       */
#define GPIOA_GPIOnINTM_Pn7INTM_Msk           (0x01UL << GPIOA_GPIOnINTM_Pn7INTM_Pos)                 /*!< GPIOA GPIOnINTM: Pn7INTM Mask           */


/* ================================================================================ */
/* ================         struct 'GPIOB' Position & Mask         ================ */
/* ================================================================================ */


/* --------------------------------  GPIOB_GPIOnO  -------------------------------- */
#define GPIOB_GPIOnO_Pn0O_Pos                 0                                                       /*!< GPIOB GPIOnO: Pn0O Position             */
#define GPIOB_GPIOnO_Pn0O_Msk                 (0x01UL << GPIOB_GPIOnO_Pn0O_Pos)                       /*!< GPIOB GPIOnO: Pn0O Mask                 */
#define GPIOB_GPIOnO_Pn1O_Pos                 1                                                       /*!< GPIOB GPIOnO: Pn1O Position             */
#define GPIOB_GPIOnO_Pn1O_Msk                 (0x01UL << GPIOB_GPIOnO_Pn1O_Pos)                       /*!< GPIOB GPIOnO: Pn1O Mask                 */
#define GPIOB_GPIOnO_Pn2O_Pos                 2                                                       /*!< GPIOB GPIOnO: Pn2O Position             */
#define GPIOB_GPIOnO_Pn2O_Msk                 (0x01UL << GPIOB_GPIOnO_Pn2O_Pos)                       /*!< GPIOB GPIOnO: Pn2O Mask                 */
#define GPIOB_GPIOnO_Pn3O_Pos                 3                                                       /*!< GPIOB GPIOnO: Pn3O Position             */
#define GPIOB_GPIOnO_Pn3O_Msk                 (0x01UL << GPIOB_GPIOnO_Pn3O_Pos)                       /*!< GPIOB GPIOnO: Pn3O Mask                 */
#define GPIOB_GPIOnO_Pn4O_Pos                 4                                                       /*!< GPIOB GPIOnO: Pn4O Position             */
#define GPIOB_GPIOnO_Pn4O_Msk                 (0x01UL << GPIOB_GPIOnO_Pn4O_Pos)                       /*!< GPIOB GPIOnO: Pn4O Mask                 */
#define GPIOB_GPIOnO_Pn5O_Pos                 5                                                       /*!< GPIOB GPIOnO: Pn5O Position             */
#define GPIOB_GPIOnO_Pn5O_Msk                 (0x01UL << GPIOB_GPIOnO_Pn5O_Pos)                       /*!< GPIOB GPIOnO: Pn5O Mask                 */
#define GPIOB_GPIOnO_Pn6O_Pos                 6                                                       /*!< GPIOB GPIOnO: Pn6O Position             */
#define GPIOB_GPIOnO_Pn6O_Msk                 (0x01UL << GPIOB_GPIOnO_Pn6O_Pos)                       /*!< GPIOB GPIOnO: Pn6O Mask                 */
#define GPIOB_GPIOnO_Pn7O_Pos                 7                                                       /*!< GPIOB GPIOnO: Pn7O Position             */
#define GPIOB_GPIOnO_Pn7O_Msk                 (0x01UL << GPIOB_GPIOnO_Pn7O_Pos)                       /*!< GPIOB GPIOnO: Pn7O Mask                 */

/* --------------------------------  GPIOB_GPIOnOE  ------------------------------- */
#define GPIOB_GPIOnOE_Pn0OE_Pos               0                                                       /*!< GPIOB GPIOnOE: Pn0OE Position           */
#define GPIOB_GPIOnOE_Pn0OE_Msk               (0x01UL << GPIOB_GPIOnOE_Pn0OE_Pos)                     /*!< GPIOB GPIOnOE: Pn0OE Mask               */
#define GPIOB_GPIOnOE_Pn1OE_Pos               1                                                       /*!< GPIOB GPIOnOE: Pn1OE Position           */
#define GPIOB_GPIOnOE_Pn1OE_Msk               (0x01UL << GPIOB_GPIOnOE_Pn1OE_Pos)                     /*!< GPIOB GPIOnOE: Pn1OE Mask               */
#define GPIOB_GPIOnOE_Pn2OE_Pos               2                                                       /*!< GPIOB GPIOnOE: Pn2OE Position           */
#define GPIOB_GPIOnOE_Pn2OE_Msk               (0x01UL << GPIOB_GPIOnOE_Pn2OE_Pos)                     /*!< GPIOB GPIOnOE: Pn2OE Mask               */
#define GPIOB_GPIOnOE_Pn3OE_Pos               3                                                       /*!< GPIOB GPIOnOE: Pn3OE Position           */
#define GPIOB_GPIOnOE_Pn3OE_Msk               (0x01UL << GPIOB_GPIOnOE_Pn3OE_Pos)                     /*!< GPIOB GPIOnOE: Pn3OE Mask               */
#define GPIOB_GPIOnOE_Pn4OE_Pos               4                                                       /*!< GPIOB GPIOnOE: Pn4OE Position           */
#define GPIOB_GPIOnOE_Pn4OE_Msk               (0x01UL << GPIOB_GPIOnOE_Pn4OE_Pos)                     /*!< GPIOB GPIOnOE: Pn4OE Mask               */
#define GPIOB_GPIOnOE_Pn5OE_Pos               5                                                       /*!< GPIOB GPIOnOE: Pn5OE Position           */
#define GPIOB_GPIOnOE_Pn5OE_Msk               (0x01UL << GPIOB_GPIOnOE_Pn5OE_Pos)                     /*!< GPIOB GPIOnOE: Pn5OE Mask               */
#define GPIOB_GPIOnOE_Pn6OE_Pos               6                                                       /*!< GPIOB GPIOnOE: Pn6OE Position           */
#define GPIOB_GPIOnOE_Pn6OE_Msk               (0x01UL << GPIOB_GPIOnOE_Pn6OE_Pos)                     /*!< GPIOB GPIOnOE: Pn6OE Mask               */
#define GPIOB_GPIOnOE_Pn7OE_Pos               7                                                       /*!< GPIOB GPIOnOE: Pn7OE Position           */
#define GPIOB_GPIOnOE_Pn7OE_Msk               (0x01UL << GPIOB_GPIOnOE_Pn7OE_Pos)                     /*!< GPIOB GPIOnOE: Pn7OE Mask               */

/* --------------------------------  GPIOB_GPIOnDS  ------------------------------- */
#define GPIOB_GPIOnDS_Pn0DS_Pos               0                                                       /*!< GPIOB GPIOnDS: Pn0DS Position           */
#define GPIOB_GPIOnDS_Pn0DS_Msk               (0x01UL << GPIOB_GPIOnDS_Pn0DS_Pos)                     /*!< GPIOB GPIOnDS: Pn0DS Mask               */
#define GPIOB_GPIOnDS_Pn1DS_Pos               1                                                       /*!< GPIOB GPIOnDS: Pn1DS Position           */
#define GPIOB_GPIOnDS_Pn1DS_Msk               (0x01UL << GPIOB_GPIOnDS_Pn1DS_Pos)                     /*!< GPIOB GPIOnDS: Pn1DS Mask               */
#define GPIOB_GPIOnDS_Pn2DS_Pos               2                                                       /*!< GPIOB GPIOnDS: Pn2DS Position           */
#define GPIOB_GPIOnDS_Pn2DS_Msk               (0x01UL << GPIOB_GPIOnDS_Pn2DS_Pos)                     /*!< GPIOB GPIOnDS: Pn2DS Mask               */
#define GPIOB_GPIOnDS_Pn3DS_Pos               3                                                       /*!< GPIOB GPIOnDS: Pn3DS Position           */
#define GPIOB_GPIOnDS_Pn3DS_Msk               (0x01UL << GPIOB_GPIOnDS_Pn3DS_Pos)                     /*!< GPIOB GPIOnDS: Pn3DS Mask               */
#define GPIOB_GPIOnDS_Pn4DS_Pos               4                                                       /*!< GPIOB GPIOnDS: Pn4DS Position           */
#define GPIOB_GPIOnDS_Pn4DS_Msk               (0x01UL << GPIOB_GPIOnDS_Pn4DS_Pos)                     /*!< GPIOB GPIOnDS: Pn4DS Mask               */
#define GPIOB_GPIOnDS_Pn5DS_Pos               5                                                       /*!< GPIOB GPIOnDS: Pn5DS Position           */
#define GPIOB_GPIOnDS_Pn5DS_Msk               (0x01UL << GPIOB_GPIOnDS_Pn5DS_Pos)                     /*!< GPIOB GPIOnDS: Pn5DS Mask               */
#define GPIOB_GPIOnDS_Pn6DS_Pos               6                                                       /*!< GPIOB GPIOnDS: Pn6DS Position           */
#define GPIOB_GPIOnDS_Pn6DS_Msk               (0x01UL << GPIOB_GPIOnDS_Pn6DS_Pos)                     /*!< GPIOB GPIOnDS: Pn6DS Mask               */
#define GPIOB_GPIOnDS_Pn7DS_Pos               7                                                       /*!< GPIOB GPIOnDS: Pn7DS Position           */
#define GPIOB_GPIOnDS_Pn7DS_Msk               (0x01UL << GPIOB_GPIOnDS_Pn7DS_Pos)                     /*!< GPIOB GPIOnDS: Pn7DS Mask               */

/* -------------------------------  GPIOB_GPIOnRUP  ------------------------------- */
#define GPIOB_GPIOnRUP_Pn0RUP_Pos             0                                                       /*!< GPIOB GPIOnRUP: Pn0RUP Position         */
#define GPIOB_GPIOnRUP_Pn0RUP_Msk             (0x01UL << GPIOB_GPIOnRUP_Pn0RUP_Pos)                   /*!< GPIOB GPIOnRUP: Pn0RUP Mask             */
#define GPIOB_GPIOnRUP_Pn1RUP_Pos             1                                                       /*!< GPIOB GPIOnRUP: Pn1RUP Position         */
#define GPIOB_GPIOnRUP_Pn1RUP_Msk             (0x01UL << GPIOB_GPIOnRUP_Pn1RUP_Pos)                   /*!< GPIOB GPIOnRUP: Pn1RUP Mask             */
#define GPIOB_GPIOnRUP_Pn2RUP_Pos             2                                                       /*!< GPIOB GPIOnRUP: Pn2RUP Position         */
#define GPIOB_GPIOnRUP_Pn2RUP_Msk             (0x01UL << GPIOB_GPIOnRUP_Pn2RUP_Pos)                   /*!< GPIOB GPIOnRUP: Pn2RUP Mask             */
#define GPIOB_GPIOnRUP_Pn3RUP_Pos             3                                                       /*!< GPIOB GPIOnRUP: Pn3RUP Position         */
#define GPIOB_GPIOnRUP_Pn3RUP_Msk             (0x01UL << GPIOB_GPIOnRUP_Pn3RUP_Pos)                   /*!< GPIOB GPIOnRUP: Pn3RUP Mask             */
#define GPIOB_GPIOnRUP_Pn4RUP_Pos             4                                                       /*!< GPIOB GPIOnRUP: Pn4RUP Position         */
#define GPIOB_GPIOnRUP_Pn4RUP_Msk             (0x01UL << GPIOB_GPIOnRUP_Pn4RUP_Pos)                   /*!< GPIOB GPIOnRUP: Pn4RUP Mask             */
#define GPIOB_GPIOnRUP_Pn5RUP_Pos             5                                                       /*!< GPIOB GPIOnRUP: Pn5RUP Position         */
#define GPIOB_GPIOnRUP_Pn5RUP_Msk             (0x01UL << GPIOB_GPIOnRUP_Pn5RUP_Pos)                   /*!< GPIOB GPIOnRUP: Pn5RUP Mask             */
#define GPIOB_GPIOnRUP_Pn6RUP_Pos             6                                                       /*!< GPIOB GPIOnRUP: Pn6RUP Position         */
#define GPIOB_GPIOnRUP_Pn6RUP_Msk             (0x01UL << GPIOB_GPIOnRUP_Pn6RUP_Pos)                   /*!< GPIOB GPIOnRUP: Pn6RUP Mask             */
#define GPIOB_GPIOnRUP_Pn7RUP_Pos             7                                                       /*!< GPIOB GPIOnRUP: Pn7RUP Position         */
#define GPIOB_GPIOnRUP_Pn7RUP_Msk             (0x01UL << GPIOB_GPIOnRUP_Pn7RUP_Pos)                   /*!< GPIOB GPIOnRUP: Pn7RUP Mask             */

/* -------------------------------  GPIOB_GPIOnRDN  ------------------------------- */
#define GPIOB_GPIOnRDN_Pn0RDN_Pos             0                                                       /*!< GPIOB GPIOnRDN: Pn0RDN Position         */
#define GPIOB_GPIOnRDN_Pn0RDN_Msk             (0x01UL << GPIOB_GPIOnRDN_Pn0RDN_Pos)                   /*!< GPIOB GPIOnRDN: Pn0RDN Mask             */
#define GPIOB_GPIOnRDN_Pn1RDN_Pos             1                                                       /*!< GPIOB GPIOnRDN: Pn1RDN Position         */
#define GPIOB_GPIOnRDN_Pn1RDN_Msk             (0x01UL << GPIOB_GPIOnRDN_Pn1RDN_Pos)                   /*!< GPIOB GPIOnRDN: Pn1RDN Mask             */
#define GPIOB_GPIOnRDN_Pn2RDN_Pos             2                                                       /*!< GPIOB GPIOnRDN: Pn2RDN Position         */
#define GPIOB_GPIOnRDN_Pn2RDN_Msk             (0x01UL << GPIOB_GPIOnRDN_Pn2RDN_Pos)                   /*!< GPIOB GPIOnRDN: Pn2RDN Mask             */
#define GPIOB_GPIOnRDN_Pn3RDN_Pos             3                                                       /*!< GPIOB GPIOnRDN: Pn3RDN Position         */
#define GPIOB_GPIOnRDN_Pn3RDN_Msk             (0x01UL << GPIOB_GPIOnRDN_Pn3RDN_Pos)                   /*!< GPIOB GPIOnRDN: Pn3RDN Mask             */
#define GPIOB_GPIOnRDN_Pn4RDN_Pos             4                                                       /*!< GPIOB GPIOnRDN: Pn4RDN Position         */
#define GPIOB_GPIOnRDN_Pn4RDN_Msk             (0x01UL << GPIOB_GPIOnRDN_Pn4RDN_Pos)                   /*!< GPIOB GPIOnRDN: Pn4RDN Mask             */
#define GPIOB_GPIOnRDN_Pn5RDN_Pos             5                                                       /*!< GPIOB GPIOnRDN: Pn5RDN Position         */
#define GPIOB_GPIOnRDN_Pn5RDN_Msk             (0x01UL << GPIOB_GPIOnRDN_Pn5RDN_Pos)                   /*!< GPIOB GPIOnRDN: Pn5RDN Mask             */
#define GPIOB_GPIOnRDN_Pn6RDN_Pos             6                                                       /*!< GPIOB GPIOnRDN: Pn6RDN Position         */
#define GPIOB_GPIOnRDN_Pn6RDN_Msk             (0x01UL << GPIOB_GPIOnRDN_Pn6RDN_Pos)                   /*!< GPIOB GPIOnRDN: Pn6RDN Mask             */
#define GPIOB_GPIOnRDN_Pn7RDN_Pos             7                                                       /*!< GPIOB GPIOnRDN: Pn7RDN Position         */
#define GPIOB_GPIOnRDN_Pn7RDN_Msk             (0x01UL << GPIOB_GPIOnRDN_Pn7RDN_Pos)                   /*!< GPIOB GPIOnRDN: Pn7RDN Mask             */

/* --------------------------------  GPIOB_GPIOnI  -------------------------------- */
#define GPIOB_GPIOnI_Pn0I_Pos                 0                                                       /*!< GPIOB GPIOnI: Pn0I Position             */
#define GPIOB_GPIOnI_Pn0I_Msk                 (0x01UL << GPIOB_GPIOnI_Pn0I_Pos)                       /*!< GPIOB GPIOnI: Pn0I Mask                 */
#define GPIOB_GPIOnI_Pn1I_Pos                 1                                                       /*!< GPIOB GPIOnI: Pn1I Position             */
#define GPIOB_GPIOnI_Pn1I_Msk                 (0x01UL << GPIOB_GPIOnI_Pn1I_Pos)                       /*!< GPIOB GPIOnI: Pn1I Mask                 */
#define GPIOB_GPIOnI_Pn2I_Pos                 2                                                       /*!< GPIOB GPIOnI: Pn2I Position             */
#define GPIOB_GPIOnI_Pn2I_Msk                 (0x01UL << GPIOB_GPIOnI_Pn2I_Pos)                       /*!< GPIOB GPIOnI: Pn2I Mask                 */
#define GPIOB_GPIOnI_Pn3I_Pos                 3                                                       /*!< GPIOB GPIOnI: Pn3I Position             */
#define GPIOB_GPIOnI_Pn3I_Msk                 (0x01UL << GPIOB_GPIOnI_Pn3I_Pos)                       /*!< GPIOB GPIOnI: Pn3I Mask                 */
#define GPIOB_GPIOnI_Pn4I_Pos                 4                                                       /*!< GPIOB GPIOnI: Pn4I Position             */
#define GPIOB_GPIOnI_Pn4I_Msk                 (0x01UL << GPIOB_GPIOnI_Pn4I_Pos)                       /*!< GPIOB GPIOnI: Pn4I Mask                 */
#define GPIOB_GPIOnI_Pn5I_Pos                 5                                                       /*!< GPIOB GPIOnI: Pn5I Position             */
#define GPIOB_GPIOnI_Pn5I_Msk                 (0x01UL << GPIOB_GPIOnI_Pn5I_Pos)                       /*!< GPIOB GPIOnI: Pn5I Mask                 */
#define GPIOB_GPIOnI_Pn6I_Pos                 6                                                       /*!< GPIOB GPIOnI: Pn6I Position             */
#define GPIOB_GPIOnI_Pn6I_Msk                 (0x01UL << GPIOB_GPIOnI_Pn6I_Pos)                       /*!< GPIOB GPIOnI: Pn6I Mask                 */
#define GPIOB_GPIOnI_Pn7I_Pos                 7                                                       /*!< GPIOB GPIOnI: Pn7I Position             */
#define GPIOB_GPIOnI_Pn7I_Msk                 (0x01UL << GPIOB_GPIOnI_Pn7I_Pos)                       /*!< GPIOB GPIOnI: Pn7I Mask                 */

/* -------------------------------  GPIOB_GPIOnPSEL  ------------------------------ */
#define GPIOB_GPIOnPSEL_Pn0PSEL_Pos           0                                                       /*!< GPIOB GPIOnPSEL: Pn0PSEL Position       */
#define GPIOB_GPIOnPSEL_Pn0PSEL_Msk           (0x03UL << GPIOB_GPIOnPSEL_Pn0PSEL_Pos)                 /*!< GPIOB GPIOnPSEL: Pn0PSEL Mask           */
#define GPIOB_GPIOnPSEL_Pn1PSEL_Pos           2                                                       /*!< GPIOB GPIOnPSEL: Pn1PSEL Position       */
#define GPIOB_GPIOnPSEL_Pn1PSEL_Msk           (0x03UL << GPIOB_GPIOnPSEL_Pn1PSEL_Pos)                 /*!< GPIOB GPIOnPSEL: Pn1PSEL Mask           */
#define GPIOB_GPIOnPSEL_Pn2PSEL_Pos           4                                                       /*!< GPIOB GPIOnPSEL: Pn2PSEL Position       */
#define GPIOB_GPIOnPSEL_Pn2PSEL_Msk           (0x03UL << GPIOB_GPIOnPSEL_Pn2PSEL_Pos)                 /*!< GPIOB GPIOnPSEL: Pn2PSEL Mask           */
#define GPIOB_GPIOnPSEL_Pn3PSEL_Pos           6                                                       /*!< GPIOB GPIOnPSEL: Pn3PSEL Position       */
#define GPIOB_GPIOnPSEL_Pn3PSEL_Msk           (0x03UL << GPIOB_GPIOnPSEL_Pn3PSEL_Pos)                 /*!< GPIOB GPIOnPSEL: Pn3PSEL Mask           */
#define GPIOB_GPIOnPSEL_Pn4PSEL_Pos           8                                                       /*!< GPIOB GPIOnPSEL: Pn4PSEL Position       */
#define GPIOB_GPIOnPSEL_Pn4PSEL_Msk           (0x03UL << GPIOB_GPIOnPSEL_Pn4PSEL_Pos)                 /*!< GPIOB GPIOnPSEL: Pn4PSEL Mask           */
#define GPIOB_GPIOnPSEL_Pn5PSEL_Pos           10                                                      /*!< GPIOB GPIOnPSEL: Pn5PSEL Position       */
#define GPIOB_GPIOnPSEL_Pn5PSEL_Msk           (0x03UL << GPIOB_GPIOnPSEL_Pn5PSEL_Pos)                 /*!< GPIOB GPIOnPSEL: Pn5PSEL Mask           */
#define GPIOB_GPIOnPSEL_Pn6PSEL_Pos           12                                                      /*!< GPIOB GPIOnPSEL: Pn6PSEL Position       */
#define GPIOB_GPIOnPSEL_Pn6PSEL_Msk           (0x03UL << GPIOB_GPIOnPSEL_Pn6PSEL_Pos)                 /*!< GPIOB GPIOnPSEL: Pn6PSEL Mask           */
#define GPIOB_GPIOnPSEL_Pn7PSEL_Pos           14                                                      /*!< GPIOB GPIOnPSEL: Pn7PSEL Position       */
#define GPIOB_GPIOnPSEL_Pn7PSEL_Msk           (0x03UL << GPIOB_GPIOnPSEL_Pn7PSEL_Pos)                 /*!< GPIOB GPIOnPSEL: Pn7PSEL Mask           */

/* -------------------------------  GPIOB_GPIOnINTP  ------------------------------ */
#define GPIOB_GPIOnINTP_Pn0INTP_Pos           0                                                       /*!< GPIOB GPIOnINTP: Pn0INTP Position       */
#define GPIOB_GPIOnINTP_Pn0INTP_Msk           (0x01UL << GPIOB_GPIOnINTP_Pn0INTP_Pos)                 /*!< GPIOB GPIOnINTP: Pn0INTP Mask           */
#define GPIOB_GPIOnINTP_Pn1INTP_Pos           1                                                       /*!< GPIOB GPIOnINTP: Pn1INTP Position       */
#define GPIOB_GPIOnINTP_Pn1INTP_Msk           (0x01UL << GPIOB_GPIOnINTP_Pn1INTP_Pos)                 /*!< GPIOB GPIOnINTP: Pn1INTP Mask           */
#define GPIOB_GPIOnINTP_Pn2INTP_Pos           2                                                       /*!< GPIOB GPIOnINTP: Pn2INTP Position       */
#define GPIOB_GPIOnINTP_Pn2INTP_Msk           (0x01UL << GPIOB_GPIOnINTP_Pn2INTP_Pos)                 /*!< GPIOB GPIOnINTP: Pn2INTP Mask           */
#define GPIOB_GPIOnINTP_Pn3INTP_Pos           3                                                       /*!< GPIOB GPIOnINTP: Pn3INTP Position       */
#define GPIOB_GPIOnINTP_Pn3INTP_Msk           (0x01UL << GPIOB_GPIOnINTP_Pn3INTP_Pos)                 /*!< GPIOB GPIOnINTP: Pn3INTP Mask           */
#define GPIOB_GPIOnINTP_Pn4INTP_Pos           4                                                       /*!< GPIOB GPIOnINTP: Pn4INTP Position       */
#define GPIOB_GPIOnINTP_Pn4INTP_Msk           (0x01UL << GPIOB_GPIOnINTP_Pn4INTP_Pos)                 /*!< GPIOB GPIOnINTP: Pn4INTP Mask           */
#define GPIOB_GPIOnINTP_Pn5INTP_Pos           5                                                       /*!< GPIOB GPIOnINTP: Pn5INTP Position       */
#define GPIOB_GPIOnINTP_Pn5INTP_Msk           (0x01UL << GPIOB_GPIOnINTP_Pn5INTP_Pos)                 /*!< GPIOB GPIOnINTP: Pn5INTP Mask           */
#define GPIOB_GPIOnINTP_Pn6INTP_Pos           6                                                       /*!< GPIOB GPIOnINTP: Pn6INTP Position       */
#define GPIOB_GPIOnINTP_Pn6INTP_Msk           (0x01UL << GPIOB_GPIOnINTP_Pn6INTP_Pos)                 /*!< GPIOB GPIOnINTP: Pn6INTP Mask           */
#define GPIOB_GPIOnINTP_Pn7INTP_Pos           7                                                       /*!< GPIOB GPIOnINTP: Pn7INTP Position       */
#define GPIOB_GPIOnINTP_Pn7INTP_Msk           (0x01UL << GPIOB_GPIOnINTP_Pn7INTP_Pos)                 /*!< GPIOB GPIOnINTP: Pn7INTP Mask           */

/* ------------------------------  GPIOB_GPIOnINTEN  ------------------------------ */
#define GPIOB_GPIOnINTEN_Pn0INTEN_Pos         0                                                       /*!< GPIOB GPIOnINTEN: Pn0INTEN Position     */
#define GPIOB_GPIOnINTEN_Pn0INTEN_Msk         (0x01UL << GPIOB_GPIOnINTEN_Pn0INTEN_Pos)               /*!< GPIOB GPIOnINTEN: Pn0INTEN Mask         */
#define GPIOB_GPIOnINTEN_Pn1INTEN_Pos         1                                                       /*!< GPIOB GPIOnINTEN: Pn1INTEN Position     */
#define GPIOB_GPIOnINTEN_Pn1INTEN_Msk         (0x01UL << GPIOB_GPIOnINTEN_Pn1INTEN_Pos)               /*!< GPIOB GPIOnINTEN: Pn1INTEN Mask         */
#define GPIOB_GPIOnINTEN_Pn2INTEN_Pos         2                                                       /*!< GPIOB GPIOnINTEN: Pn2INTEN Position     */
#define GPIOB_GPIOnINTEN_Pn2INTEN_Msk         (0x01UL << GPIOB_GPIOnINTEN_Pn2INTEN_Pos)               /*!< GPIOB GPIOnINTEN: Pn2INTEN Mask         */
#define GPIOB_GPIOnINTEN_Pn3INTEN_Pos         3                                                       /*!< GPIOB GPIOnINTEN: Pn3INTEN Position     */
#define GPIOB_GPIOnINTEN_Pn3INTEN_Msk         (0x01UL << GPIOB_GPIOnINTEN_Pn3INTEN_Pos)               /*!< GPIOB GPIOnINTEN: Pn3INTEN Mask         */
#define GPIOB_GPIOnINTEN_Pn4INTEN_Pos         4                                                       /*!< GPIOB GPIOnINTEN: Pn4INTEN Position     */
#define GPIOB_GPIOnINTEN_Pn4INTEN_Msk         (0x01UL << GPIOB_GPIOnINTEN_Pn4INTEN_Pos)               /*!< GPIOB GPIOnINTEN: Pn4INTEN Mask         */
#define GPIOB_GPIOnINTEN_Pn5INTEN_Pos         5                                                       /*!< GPIOB GPIOnINTEN: Pn5INTEN Position     */
#define GPIOB_GPIOnINTEN_Pn5INTEN_Msk         (0x01UL << GPIOB_GPIOnINTEN_Pn5INTEN_Pos)               /*!< GPIOB GPIOnINTEN: Pn5INTEN Mask         */
#define GPIOB_GPIOnINTEN_Pn6INTEN_Pos         6                                                       /*!< GPIOB GPIOnINTEN: Pn6INTEN Position     */
#define GPIOB_GPIOnINTEN_Pn6INTEN_Msk         (0x01UL << GPIOB_GPIOnINTEN_Pn6INTEN_Pos)               /*!< GPIOB GPIOnINTEN: Pn6INTEN Mask         */
#define GPIOB_GPIOnINTEN_Pn7INTEN_Pos         7                                                       /*!< GPIOB GPIOnINTEN: Pn7INTEN Position     */
#define GPIOB_GPIOnINTEN_Pn7INTEN_Msk         (0x01UL << GPIOB_GPIOnINTEN_Pn7INTEN_Pos)               /*!< GPIOB GPIOnINTEN: Pn7INTEN Mask         */

/* -------------------------------  GPIOB_GPIOnINT  ------------------------------- */
#define GPIOB_GPIOnINT_Pn0INT_Pos             0                                                       /*!< GPIOB GPIOnINT: Pn0INT Position         */
#define GPIOB_GPIOnINT_Pn0INT_Msk             (0x01UL << GPIOB_GPIOnINT_Pn0INT_Pos)                   /*!< GPIOB GPIOnINT: Pn0INT Mask             */
#define GPIOB_GPIOnINT_Pn1INT_Pos             1                                                       /*!< GPIOB GPIOnINT: Pn1INT Position         */
#define GPIOB_GPIOnINT_Pn1INT_Msk             (0x01UL << GPIOB_GPIOnINT_Pn1INT_Pos)                   /*!< GPIOB GPIOnINT: Pn1INT Mask             */
#define GPIOB_GPIOnINT_Pn2INT_Pos             2                                                       /*!< GPIOB GPIOnINT: Pn2INT Position         */
#define GPIOB_GPIOnINT_Pn2INT_Msk             (0x01UL << GPIOB_GPIOnINT_Pn2INT_Pos)                   /*!< GPIOB GPIOnINT: Pn2INT Mask             */
#define GPIOB_GPIOnINT_Pn3INT_Pos             3                                                       /*!< GPIOB GPIOnINT: Pn3INT Position         */
#define GPIOB_GPIOnINT_Pn3INT_Msk             (0x01UL << GPIOB_GPIOnINT_Pn3INT_Pos)                   /*!< GPIOB GPIOnINT: Pn3INT Mask             */
#define GPIOB_GPIOnINT_Pn4INT_Pos             4                                                       /*!< GPIOB GPIOnINT: Pn4INT Position         */
#define GPIOB_GPIOnINT_Pn4INT_Msk             (0x01UL << GPIOB_GPIOnINT_Pn4INT_Pos)                   /*!< GPIOB GPIOnINT: Pn4INT Mask             */
#define GPIOB_GPIOnINT_Pn5INT_Pos             5                                                       /*!< GPIOB GPIOnINT: Pn5INT Position         */
#define GPIOB_GPIOnINT_Pn5INT_Msk             (0x01UL << GPIOB_GPIOnINT_Pn5INT_Pos)                   /*!< GPIOB GPIOnINT: Pn5INT Mask             */
#define GPIOB_GPIOnINT_Pn6INT_Pos             6                                                       /*!< GPIOB GPIOnINT: Pn6INT Position         */
#define GPIOB_GPIOnINT_Pn6INT_Msk             (0x01UL << GPIOB_GPIOnINT_Pn6INT_Pos)                   /*!< GPIOB GPIOnINT: Pn6INT Mask             */
#define GPIOB_GPIOnINT_Pn7INT_Pos             7                                                       /*!< GPIOB GPIOnINT: Pn7INT Position         */
#define GPIOB_GPIOnINT_Pn7INT_Msk             (0x01UL << GPIOB_GPIOnINT_Pn7INT_Pos)                   /*!< GPIOB GPIOnINT: Pn7INT Mask             */

/* -------------------------------  GPIOB_GPIOnINTM  ------------------------------ */
#define GPIOB_GPIOnINTM_Pn0INTM_Pos           0                                                       /*!< GPIOB GPIOnINTM: Pn0INTM Position       */
#define GPIOB_GPIOnINTM_Pn0INTM_Msk           (0x01UL << GPIOB_GPIOnINTM_Pn0INTM_Pos)                 /*!< GPIOB GPIOnINTM: Pn0INTM Mask           */
#define GPIOB_GPIOnINTM_Pn1INTM_Pos           1                                                       /*!< GPIOB GPIOnINTM: Pn1INTM Position       */
#define GPIOB_GPIOnINTM_Pn1INTM_Msk           (0x01UL << GPIOB_GPIOnINTM_Pn1INTM_Pos)                 /*!< GPIOB GPIOnINTM: Pn1INTM Mask           */
#define GPIOB_GPIOnINTM_Pn2INTM_Pos           2                                                       /*!< GPIOB GPIOnINTM: Pn2INTM Position       */
#define GPIOB_GPIOnINTM_Pn2INTM_Msk           (0x01UL << GPIOB_GPIOnINTM_Pn2INTM_Pos)                 /*!< GPIOB GPIOnINTM: Pn2INTM Mask           */
#define GPIOB_GPIOnINTM_Pn3INTM_Pos           3                                                       /*!< GPIOB GPIOnINTM: Pn3INTM Position       */
#define GPIOB_GPIOnINTM_Pn3INTM_Msk           (0x01UL << GPIOB_GPIOnINTM_Pn3INTM_Pos)                 /*!< GPIOB GPIOnINTM: Pn3INTM Mask           */
#define GPIOB_GPIOnINTM_Pn4INTM_Pos           4                                                       /*!< GPIOB GPIOnINTM: Pn4INTM Position       */
#define GPIOB_GPIOnINTM_Pn4INTM_Msk           (0x01UL << GPIOB_GPIOnINTM_Pn4INTM_Pos)                 /*!< GPIOB GPIOnINTM: Pn4INTM Mask           */
#define GPIOB_GPIOnINTM_Pn5INTM_Pos           5                                                       /*!< GPIOB GPIOnINTM: Pn5INTM Position       */
#define GPIOB_GPIOnINTM_Pn5INTM_Msk           (0x01UL << GPIOB_GPIOnINTM_Pn5INTM_Pos)                 /*!< GPIOB GPIOnINTM: Pn5INTM Mask           */
#define GPIOB_GPIOnINTM_Pn6INTM_Pos           6                                                       /*!< GPIOB GPIOnINTM: Pn6INTM Position       */
#define GPIOB_GPIOnINTM_Pn6INTM_Msk           (0x01UL << GPIOB_GPIOnINTM_Pn6INTM_Pos)                 /*!< GPIOB GPIOnINTM: Pn6INTM Mask           */
#define GPIOB_GPIOnINTM_Pn7INTM_Pos           7                                                       /*!< GPIOB GPIOnINTM: Pn7INTM Position       */
#define GPIOB_GPIOnINTM_Pn7INTM_Msk           (0x01UL << GPIOB_GPIOnINTM_Pn7INTM_Pos)                 /*!< GPIOB GPIOnINTM: Pn7INTM Mask           */


/* ================================================================================ */
/* ================         struct 'GPIOC' Position & Mask         ================ */
/* ================================================================================ */


/* --------------------------------  GPIOC_GPIOnO  -------------------------------- */
#define GPIOC_GPIOnO_Pn0O_Pos                 0                                                       /*!< GPIOC GPIOnO: Pn0O Position             */
#define GPIOC_GPIOnO_Pn0O_Msk                 (0x01UL << GPIOC_GPIOnO_Pn0O_Pos)                       /*!< GPIOC GPIOnO: Pn0O Mask                 */
#define GPIOC_GPIOnO_Pn1O_Pos                 1                                                       /*!< GPIOC GPIOnO: Pn1O Position             */
#define GPIOC_GPIOnO_Pn1O_Msk                 (0x01UL << GPIOC_GPIOnO_Pn1O_Pos)                       /*!< GPIOC GPIOnO: Pn1O Mask                 */
#define GPIOC_GPIOnO_Pn2O_Pos                 2                                                       /*!< GPIOC GPIOnO: Pn2O Position             */
#define GPIOC_GPIOnO_Pn2O_Msk                 (0x01UL << GPIOC_GPIOnO_Pn2O_Pos)                       /*!< GPIOC GPIOnO: Pn2O Mask                 */
#define GPIOC_GPIOnO_Pn3O_Pos                 3                                                       /*!< GPIOC GPIOnO: Pn3O Position             */
#define GPIOC_GPIOnO_Pn3O_Msk                 (0x01UL << GPIOC_GPIOnO_Pn3O_Pos)                       /*!< GPIOC GPIOnO: Pn3O Mask                 */
#define GPIOC_GPIOnO_Pn4O_Pos                 4                                                       /*!< GPIOC GPIOnO: Pn4O Position             */
#define GPIOC_GPIOnO_Pn4O_Msk                 (0x01UL << GPIOC_GPIOnO_Pn4O_Pos)                       /*!< GPIOC GPIOnO: Pn4O Mask                 */
#define GPIOC_GPIOnO_Pn5O_Pos                 5                                                       /*!< GPIOC GPIOnO: Pn5O Position             */
#define GPIOC_GPIOnO_Pn5O_Msk                 (0x01UL << GPIOC_GPIOnO_Pn5O_Pos)                       /*!< GPIOC GPIOnO: Pn5O Mask                 */
#define GPIOC_GPIOnO_Pn6O_Pos                 6                                                       /*!< GPIOC GPIOnO: Pn6O Position             */
#define GPIOC_GPIOnO_Pn6O_Msk                 (0x01UL << GPIOC_GPIOnO_Pn6O_Pos)                       /*!< GPIOC GPIOnO: Pn6O Mask                 */
#define GPIOC_GPIOnO_Pn7O_Pos                 7                                                       /*!< GPIOC GPIOnO: Pn7O Position             */
#define GPIOC_GPIOnO_Pn7O_Msk                 (0x01UL << GPIOC_GPIOnO_Pn7O_Pos)                       /*!< GPIOC GPIOnO: Pn7O Mask                 */

/* --------------------------------  GPIOC_GPIOnOE  ------------------------------- */
#define GPIOC_GPIOnOE_Pn0OE_Pos               0                                                       /*!< GPIOC GPIOnOE: Pn0OE Position           */
#define GPIOC_GPIOnOE_Pn0OE_Msk               (0x01UL << GPIOC_GPIOnOE_Pn0OE_Pos)                     /*!< GPIOC GPIOnOE: Pn0OE Mask               */
#define GPIOC_GPIOnOE_Pn1OE_Pos               1                                                       /*!< GPIOC GPIOnOE: Pn1OE Position           */
#define GPIOC_GPIOnOE_Pn1OE_Msk               (0x01UL << GPIOC_GPIOnOE_Pn1OE_Pos)                     /*!< GPIOC GPIOnOE: Pn1OE Mask               */
#define GPIOC_GPIOnOE_Pn2OE_Pos               2                                                       /*!< GPIOC GPIOnOE: Pn2OE Position           */
#define GPIOC_GPIOnOE_Pn2OE_Msk               (0x01UL << GPIOC_GPIOnOE_Pn2OE_Pos)                     /*!< GPIOC GPIOnOE: Pn2OE Mask               */
#define GPIOC_GPIOnOE_Pn3OE_Pos               3                                                       /*!< GPIOC GPIOnOE: Pn3OE Position           */
#define GPIOC_GPIOnOE_Pn3OE_Msk               (0x01UL << GPIOC_GPIOnOE_Pn3OE_Pos)                     /*!< GPIOC GPIOnOE: Pn3OE Mask               */
#define GPIOC_GPIOnOE_Pn4OE_Pos               4                                                       /*!< GPIOC GPIOnOE: Pn4OE Position           */
#define GPIOC_GPIOnOE_Pn4OE_Msk               (0x01UL << GPIOC_GPIOnOE_Pn4OE_Pos)                     /*!< GPIOC GPIOnOE: Pn4OE Mask               */
#define GPIOC_GPIOnOE_Pn5OE_Pos               5                                                       /*!< GPIOC GPIOnOE: Pn5OE Position           */
#define GPIOC_GPIOnOE_Pn5OE_Msk               (0x01UL << GPIOC_GPIOnOE_Pn5OE_Pos)                     /*!< GPIOC GPIOnOE: Pn5OE Mask               */
#define GPIOC_GPIOnOE_Pn6OE_Pos               6                                                       /*!< GPIOC GPIOnOE: Pn6OE Position           */
#define GPIOC_GPIOnOE_Pn6OE_Msk               (0x01UL << GPIOC_GPIOnOE_Pn6OE_Pos)                     /*!< GPIOC GPIOnOE: Pn6OE Mask               */
#define GPIOC_GPIOnOE_Pn7OE_Pos               7                                                       /*!< GPIOC GPIOnOE: Pn7OE Position           */
#define GPIOC_GPIOnOE_Pn7OE_Msk               (0x01UL << GPIOC_GPIOnOE_Pn7OE_Pos)                     /*!< GPIOC GPIOnOE: Pn7OE Mask               */

/* --------------------------------  GPIOC_GPIOnI  -------------------------------- */
#define GPIOC_GPIOnI_Pn0I_Pos                 0                                                       /*!< GPIOC GPIOnI: Pn0I Position             */
#define GPIOC_GPIOnI_Pn0I_Msk                 (0x01UL << GPIOC_GPIOnI_Pn0I_Pos)                       /*!< GPIOC GPIOnI: Pn0I Mask                 */
#define GPIOC_GPIOnI_Pn1I_Pos                 1                                                       /*!< GPIOC GPIOnI: Pn1I Position             */
#define GPIOC_GPIOnI_Pn1I_Msk                 (0x01UL << GPIOC_GPIOnI_Pn1I_Pos)                       /*!< GPIOC GPIOnI: Pn1I Mask                 */
#define GPIOC_GPIOnI_Pn2I_Pos                 2                                                       /*!< GPIOC GPIOnI: Pn2I Position             */
#define GPIOC_GPIOnI_Pn2I_Msk                 (0x01UL << GPIOC_GPIOnI_Pn2I_Pos)                       /*!< GPIOC GPIOnI: Pn2I Mask                 */
#define GPIOC_GPIOnI_Pn3I_Pos                 3                                                       /*!< GPIOC GPIOnI: Pn3I Position             */
#define GPIOC_GPIOnI_Pn3I_Msk                 (0x01UL << GPIOC_GPIOnI_Pn3I_Pos)                       /*!< GPIOC GPIOnI: Pn3I Mask                 */
#define GPIOC_GPIOnI_Pn4I_Pos                 4                                                       /*!< GPIOC GPIOnI: Pn4I Position             */
#define GPIOC_GPIOnI_Pn4I_Msk                 (0x01UL << GPIOC_GPIOnI_Pn4I_Pos)                       /*!< GPIOC GPIOnI: Pn4I Mask                 */
#define GPIOC_GPIOnI_Pn5I_Pos                 5                                                       /*!< GPIOC GPIOnI: Pn5I Position             */
#define GPIOC_GPIOnI_Pn5I_Msk                 (0x01UL << GPIOC_GPIOnI_Pn5I_Pos)                       /*!< GPIOC GPIOnI: Pn5I Mask                 */
#define GPIOC_GPIOnI_Pn6I_Pos                 6                                                       /*!< GPIOC GPIOnI: Pn6I Position             */
#define GPIOC_GPIOnI_Pn6I_Msk                 (0x01UL << GPIOC_GPIOnI_Pn6I_Pos)                       /*!< GPIOC GPIOnI: Pn6I Mask                 */
#define GPIOC_GPIOnI_Pn7I_Pos                 7                                                       /*!< GPIOC GPIOnI: Pn7I Position             */
#define GPIOC_GPIOnI_Pn7I_Msk                 (0x01UL << GPIOC_GPIOnI_Pn7I_Pos)                       /*!< GPIOC GPIOnI: Pn7I Mask                 */

/* --------------------------------  GPIOC_GPIOnIE  ------------------------------- */
#define GPIOC_GPIOnIE_Pn0IE_Pos               0                                                       /*!< GPIOC GPIOnIE: Pn0IE Position           */
#define GPIOC_GPIOnIE_Pn0IE_Msk               (0x01UL << GPIOC_GPIOnIE_Pn0IE_Pos)                     /*!< GPIOC GPIOnIE: Pn0IE Mask               */
#define GPIOC_GPIOnIE_Pn1IE_Pos               1                                                       /*!< GPIOC GPIOnIE: Pn1IE Position           */
#define GPIOC_GPIOnIE_Pn1IE_Msk               (0x01UL << GPIOC_GPIOnIE_Pn1IE_Pos)                     /*!< GPIOC GPIOnIE: Pn1IE Mask               */
#define GPIOC_GPIOnIE_Pn2IE_Pos               2                                                       /*!< GPIOC GPIOnIE: Pn2IE Position           */
#define GPIOC_GPIOnIE_Pn2IE_Msk               (0x01UL << GPIOC_GPIOnIE_Pn2IE_Pos)                     /*!< GPIOC GPIOnIE: Pn2IE Mask               */
#define GPIOC_GPIOnIE_Pn3IE_Pos               3                                                       /*!< GPIOC GPIOnIE: Pn3IE Position           */
#define GPIOC_GPIOnIE_Pn3IE_Msk               (0x01UL << GPIOC_GPIOnIE_Pn3IE_Pos)                     /*!< GPIOC GPIOnIE: Pn3IE Mask               */
#define GPIOC_GPIOnIE_Pn4IE_Pos               4                                                       /*!< GPIOC GPIOnIE: Pn4IE Position           */
#define GPIOC_GPIOnIE_Pn4IE_Msk               (0x01UL << GPIOC_GPIOnIE_Pn4IE_Pos)                     /*!< GPIOC GPIOnIE: Pn4IE Mask               */
#define GPIOC_GPIOnIE_Pn5IE_Pos               5                                                       /*!< GPIOC GPIOnIE: Pn5IE Position           */
#define GPIOC_GPIOnIE_Pn5IE_Msk               (0x01UL << GPIOC_GPIOnIE_Pn5IE_Pos)                     /*!< GPIOC GPIOnIE: Pn5IE Mask               */
#define GPIOC_GPIOnIE_Pn6IE_Pos               6                                                       /*!< GPIOC GPIOnIE: Pn6IE Position           */
#define GPIOC_GPIOnIE_Pn6IE_Msk               (0x01UL << GPIOC_GPIOnIE_Pn6IE_Pos)                     /*!< GPIOC GPIOnIE: Pn6IE Mask               */
#define GPIOC_GPIOnIE_Pn7IE_Pos               7                                                       /*!< GPIOC GPIOnIE: Pn7IE Position           */
#define GPIOC_GPIOnIE_Pn7IE_Msk               (0x01UL << GPIOC_GPIOnIE_Pn7IE_Pos)                     /*!< GPIOC GPIOnIE: Pn7IE Mask               */

/* -------------------------------  GPIOC_GPIOnINTP  ------------------------------ */
#define GPIOC_GPIOnINTP_Pn0INTP_Pos           0                                                       /*!< GPIOC GPIOnINTP: Pn0INTP Position       */
#define GPIOC_GPIOnINTP_Pn0INTP_Msk           (0x01UL << GPIOC_GPIOnINTP_Pn0INTP_Pos)                 /*!< GPIOC GPIOnINTP: Pn0INTP Mask           */
#define GPIOC_GPIOnINTP_Pn1INTP_Pos           1                                                       /*!< GPIOC GPIOnINTP: Pn1INTP Position       */
#define GPIOC_GPIOnINTP_Pn1INTP_Msk           (0x01UL << GPIOC_GPIOnINTP_Pn1INTP_Pos)                 /*!< GPIOC GPIOnINTP: Pn1INTP Mask           */
#define GPIOC_GPIOnINTP_Pn2INTP_Pos           2                                                       /*!< GPIOC GPIOnINTP: Pn2INTP Position       */
#define GPIOC_GPIOnINTP_Pn2INTP_Msk           (0x01UL << GPIOC_GPIOnINTP_Pn2INTP_Pos)                 /*!< GPIOC GPIOnINTP: Pn2INTP Mask           */
#define GPIOC_GPIOnINTP_Pn3INTP_Pos           3                                                       /*!< GPIOC GPIOnINTP: Pn3INTP Position       */
#define GPIOC_GPIOnINTP_Pn3INTP_Msk           (0x01UL << GPIOC_GPIOnINTP_Pn3INTP_Pos)                 /*!< GPIOC GPIOnINTP: Pn3INTP Mask           */
#define GPIOC_GPIOnINTP_Pn4INTP_Pos           4                                                       /*!< GPIOC GPIOnINTP: Pn4INTP Position       */
#define GPIOC_GPIOnINTP_Pn4INTP_Msk           (0x01UL << GPIOC_GPIOnINTP_Pn4INTP_Pos)                 /*!< GPIOC GPIOnINTP: Pn4INTP Mask           */
#define GPIOC_GPIOnINTP_Pn5INTP_Pos           5                                                       /*!< GPIOC GPIOnINTP: Pn5INTP Position       */
#define GPIOC_GPIOnINTP_Pn5INTP_Msk           (0x01UL << GPIOC_GPIOnINTP_Pn5INTP_Pos)                 /*!< GPIOC GPIOnINTP: Pn5INTP Mask           */
#define GPIOC_GPIOnINTP_Pn6INTP_Pos           6                                                       /*!< GPIOC GPIOnINTP: Pn6INTP Position       */
#define GPIOC_GPIOnINTP_Pn6INTP_Msk           (0x01UL << GPIOC_GPIOnINTP_Pn6INTP_Pos)                 /*!< GPIOC GPIOnINTP: Pn6INTP Mask           */
#define GPIOC_GPIOnINTP_Pn7INTP_Pos           7                                                       /*!< GPIOC GPIOnINTP: Pn7INTP Position       */
#define GPIOC_GPIOnINTP_Pn7INTP_Msk           (0x01UL << GPIOC_GPIOnINTP_Pn7INTP_Pos)                 /*!< GPIOC GPIOnINTP: Pn7INTP Mask           */

/* ------------------------------  GPIOC_GPIOnINTEN  ------------------------------ */
#define GPIOC_GPIOnINTEN_Pn0INTEN_Pos         0                                                       /*!< GPIOC GPIOnINTEN: Pn0INTEN Position     */
#define GPIOC_GPIOnINTEN_Pn0INTEN_Msk         (0x01UL << GPIOC_GPIOnINTEN_Pn0INTEN_Pos)               /*!< GPIOC GPIOnINTEN: Pn0INTEN Mask         */
#define GPIOC_GPIOnINTEN_Pn1INTEN_Pos         1                                                       /*!< GPIOC GPIOnINTEN: Pn1INTEN Position     */
#define GPIOC_GPIOnINTEN_Pn1INTEN_Msk         (0x01UL << GPIOC_GPIOnINTEN_Pn1INTEN_Pos)               /*!< GPIOC GPIOnINTEN: Pn1INTEN Mask         */
#define GPIOC_GPIOnINTEN_Pn2INTEN_Pos         2                                                       /*!< GPIOC GPIOnINTEN: Pn2INTEN Position     */
#define GPIOC_GPIOnINTEN_Pn2INTEN_Msk         (0x01UL << GPIOC_GPIOnINTEN_Pn2INTEN_Pos)               /*!< GPIOC GPIOnINTEN: Pn2INTEN Mask         */
#define GPIOC_GPIOnINTEN_Pn3INTEN_Pos         3                                                       /*!< GPIOC GPIOnINTEN: Pn3INTEN Position     */
#define GPIOC_GPIOnINTEN_Pn3INTEN_Msk         (0x01UL << GPIOC_GPIOnINTEN_Pn3INTEN_Pos)               /*!< GPIOC GPIOnINTEN: Pn3INTEN Mask         */
#define GPIOC_GPIOnINTEN_Pn4INTEN_Pos         4                                                       /*!< GPIOC GPIOnINTEN: Pn4INTEN Position     */
#define GPIOC_GPIOnINTEN_Pn4INTEN_Msk         (0x01UL << GPIOC_GPIOnINTEN_Pn4INTEN_Pos)               /*!< GPIOC GPIOnINTEN: Pn4INTEN Mask         */
#define GPIOC_GPIOnINTEN_Pn5INTEN_Pos         5                                                       /*!< GPIOC GPIOnINTEN: Pn5INTEN Position     */
#define GPIOC_GPIOnINTEN_Pn5INTEN_Msk         (0x01UL << GPIOC_GPIOnINTEN_Pn5INTEN_Pos)               /*!< GPIOC GPIOnINTEN: Pn5INTEN Mask         */
#define GPIOC_GPIOnINTEN_Pn6INTEN_Pos         6                                                       /*!< GPIOC GPIOnINTEN: Pn6INTEN Position     */
#define GPIOC_GPIOnINTEN_Pn6INTEN_Msk         (0x01UL << GPIOC_GPIOnINTEN_Pn6INTEN_Pos)               /*!< GPIOC GPIOnINTEN: Pn6INTEN Mask         */
#define GPIOC_GPIOnINTEN_Pn7INTEN_Pos         7                                                       /*!< GPIOC GPIOnINTEN: Pn7INTEN Position     */
#define GPIOC_GPIOnINTEN_Pn7INTEN_Msk         (0x01UL << GPIOC_GPIOnINTEN_Pn7INTEN_Pos)               /*!< GPIOC GPIOnINTEN: Pn7INTEN Mask         */

/* -------------------------------  GPIOC_GPIOnINT  ------------------------------- */
#define GPIOC_GPIOnINT_Pn0INT_Pos             0                                                       /*!< GPIOC GPIOnINT: Pn0INT Position         */
#define GPIOC_GPIOnINT_Pn0INT_Msk             (0x01UL << GPIOC_GPIOnINT_Pn0INT_Pos)                   /*!< GPIOC GPIOnINT: Pn0INT Mask             */
#define GPIOC_GPIOnINT_Pn1INT_Pos             1                                                       /*!< GPIOC GPIOnINT: Pn1INT Position         */
#define GPIOC_GPIOnINT_Pn1INT_Msk             (0x01UL << GPIOC_GPIOnINT_Pn1INT_Pos)                   /*!< GPIOC GPIOnINT: Pn1INT Mask             */
#define GPIOC_GPIOnINT_Pn2INT_Pos             2                                                       /*!< GPIOC GPIOnINT: Pn2INT Position         */
#define GPIOC_GPIOnINT_Pn2INT_Msk             (0x01UL << GPIOC_GPIOnINT_Pn2INT_Pos)                   /*!< GPIOC GPIOnINT: Pn2INT Mask             */
#define GPIOC_GPIOnINT_Pn3INT_Pos             3                                                       /*!< GPIOC GPIOnINT: Pn3INT Position         */
#define GPIOC_GPIOnINT_Pn3INT_Msk             (0x01UL << GPIOC_GPIOnINT_Pn3INT_Pos)                   /*!< GPIOC GPIOnINT: Pn3INT Mask             */
#define GPIOC_GPIOnINT_Pn4INT_Pos             4                                                       /*!< GPIOC GPIOnINT: Pn4INT Position         */
#define GPIOC_GPIOnINT_Pn4INT_Msk             (0x01UL << GPIOC_GPIOnINT_Pn4INT_Pos)                   /*!< GPIOC GPIOnINT: Pn4INT Mask             */
#define GPIOC_GPIOnINT_Pn5INT_Pos             5                                                       /*!< GPIOC GPIOnINT: Pn5INT Position         */
#define GPIOC_GPIOnINT_Pn5INT_Msk             (0x01UL << GPIOC_GPIOnINT_Pn5INT_Pos)                   /*!< GPIOC GPIOnINT: Pn5INT Mask             */
#define GPIOC_GPIOnINT_Pn6INT_Pos             6                                                       /*!< GPIOC GPIOnINT: Pn6INT Position         */
#define GPIOC_GPIOnINT_Pn6INT_Msk             (0x01UL << GPIOC_GPIOnINT_Pn6INT_Pos)                   /*!< GPIOC GPIOnINT: Pn6INT Mask             */
#define GPIOC_GPIOnINT_Pn7INT_Pos             7                                                       /*!< GPIOC GPIOnINT: Pn7INT Position         */
#define GPIOC_GPIOnINT_Pn7INT_Msk             (0x01UL << GPIOC_GPIOnINT_Pn7INT_Pos)                   /*!< GPIOC GPIOnINT: Pn7INT Mask             */

/* -------------------------------  GPIOC_GPIOnINTM  ------------------------------ */
#define GPIOC_GPIOnINTM_Pn0INTM_Pos           0                                                       /*!< GPIOC GPIOnINTM: Pn0INTM Position       */
#define GPIOC_GPIOnINTM_Pn0INTM_Msk           (0x01UL << GPIOC_GPIOnINTM_Pn0INTM_Pos)                 /*!< GPIOC GPIOnINTM: Pn0INTM Mask           */
#define GPIOC_GPIOnINTM_Pn1INTM_Pos           1                                                       /*!< GPIOC GPIOnINTM: Pn1INTM Position       */
#define GPIOC_GPIOnINTM_Pn1INTM_Msk           (0x01UL << GPIOC_GPIOnINTM_Pn1INTM_Pos)                 /*!< GPIOC GPIOnINTM: Pn1INTM Mask           */
#define GPIOC_GPIOnINTM_Pn2INTM_Pos           2                                                       /*!< GPIOC GPIOnINTM: Pn2INTM Position       */
#define GPIOC_GPIOnINTM_Pn2INTM_Msk           (0x01UL << GPIOC_GPIOnINTM_Pn2INTM_Pos)                 /*!< GPIOC GPIOnINTM: Pn2INTM Mask           */
#define GPIOC_GPIOnINTM_Pn3INTM_Pos           3                                                       /*!< GPIOC GPIOnINTM: Pn3INTM Position       */
#define GPIOC_GPIOnINTM_Pn3INTM_Msk           (0x01UL << GPIOC_GPIOnINTM_Pn3INTM_Pos)                 /*!< GPIOC GPIOnINTM: Pn3INTM Mask           */
#define GPIOC_GPIOnINTM_Pn4INTM_Pos           4                                                       /*!< GPIOC GPIOnINTM: Pn4INTM Position       */
#define GPIOC_GPIOnINTM_Pn4INTM_Msk           (0x01UL << GPIOC_GPIOnINTM_Pn4INTM_Pos)                 /*!< GPIOC GPIOnINTM: Pn4INTM Mask           */
#define GPIOC_GPIOnINTM_Pn5INTM_Pos           5                                                       /*!< GPIOC GPIOnINTM: Pn5INTM Position       */
#define GPIOC_GPIOnINTM_Pn5INTM_Msk           (0x01UL << GPIOC_GPIOnINTM_Pn5INTM_Pos)                 /*!< GPIOC GPIOnINTM: Pn5INTM Mask           */
#define GPIOC_GPIOnINTM_Pn6INTM_Pos           6                                                       /*!< GPIOC GPIOnINTM: Pn6INTM Position       */
#define GPIOC_GPIOnINTM_Pn6INTM_Msk           (0x01UL << GPIOC_GPIOnINTM_Pn6INTM_Pos)                 /*!< GPIOC GPIOnINTM: Pn6INTM Mask           */
#define GPIOC_GPIOnINTM_Pn7INTM_Pos           7                                                       /*!< GPIOC GPIOnINTM: Pn7INTM Position       */
#define GPIOC_GPIOnINTM_Pn7INTM_Msk           (0x01UL << GPIOC_GPIOnINTM_Pn7INTM_Pos)                 /*!< GPIOC GPIOnINTM: Pn7INTM Mask           */


/* ================================================================================ */
/* ================         struct 'GPIOD' Position & Mask         ================ */
/* ================================================================================ */


/* --------------------------------  GPIOD_GPIOnO  -------------------------------- */
#define GPIOD_GPIOnO_Pn0O_Pos                 0                                                       /*!< GPIOD GPIOnO: Pn0O Position             */
#define GPIOD_GPIOnO_Pn0O_Msk                 (0x01UL << GPIOD_GPIOnO_Pn0O_Pos)                       /*!< GPIOD GPIOnO: Pn0O Mask                 */
#define GPIOD_GPIOnO_Pn1O_Pos                 1                                                       /*!< GPIOD GPIOnO: Pn1O Position             */
#define GPIOD_GPIOnO_Pn1O_Msk                 (0x01UL << GPIOD_GPIOnO_Pn1O_Pos)                       /*!< GPIOD GPIOnO: Pn1O Mask                 */
#define GPIOD_GPIOnO_Pn2O_Pos                 2                                                       /*!< GPIOD GPIOnO: Pn2O Position             */
#define GPIOD_GPIOnO_Pn2O_Msk                 (0x01UL << GPIOD_GPIOnO_Pn2O_Pos)                       /*!< GPIOD GPIOnO: Pn2O Mask                 */
#define GPIOD_GPIOnO_Pn3O_Pos                 3                                                       /*!< GPIOD GPIOnO: Pn3O Position             */
#define GPIOD_GPIOnO_Pn3O_Msk                 (0x01UL << GPIOD_GPIOnO_Pn3O_Pos)                       /*!< GPIOD GPIOnO: Pn3O Mask                 */
#define GPIOD_GPIOnO_Pn4O_Pos                 4                                                       /*!< GPIOD GPIOnO: Pn4O Position             */
#define GPIOD_GPIOnO_Pn4O_Msk                 (0x01UL << GPIOD_GPIOnO_Pn4O_Pos)                       /*!< GPIOD GPIOnO: Pn4O Mask                 */
#define GPIOD_GPIOnO_Pn5O_Pos                 5                                                       /*!< GPIOD GPIOnO: Pn5O Position             */
#define GPIOD_GPIOnO_Pn5O_Msk                 (0x01UL << GPIOD_GPIOnO_Pn5O_Pos)                       /*!< GPIOD GPIOnO: Pn5O Mask                 */
#define GPIOD_GPIOnO_Pn6O_Pos                 6                                                       /*!< GPIOD GPIOnO: Pn6O Position             */
#define GPIOD_GPIOnO_Pn6O_Msk                 (0x01UL << GPIOD_GPIOnO_Pn6O_Pos)                       /*!< GPIOD GPIOnO: Pn6O Mask                 */
#define GPIOD_GPIOnO_Pn7O_Pos                 7                                                       /*!< GPIOD GPIOnO: Pn7O Position             */
#define GPIOD_GPIOnO_Pn7O_Msk                 (0x01UL << GPIOD_GPIOnO_Pn7O_Pos)                       /*!< GPIOD GPIOnO: Pn7O Mask                 */

/* --------------------------------  GPIOD_GPIOnOE  ------------------------------- */
#define GPIOD_GPIOnOE_Pn0OE_Pos               0                                                       /*!< GPIOD GPIOnOE: Pn0OE Position           */
#define GPIOD_GPIOnOE_Pn0OE_Msk               (0x01UL << GPIOD_GPIOnOE_Pn0OE_Pos)                     /*!< GPIOD GPIOnOE: Pn0OE Mask               */
#define GPIOD_GPIOnOE_Pn1OE_Pos               1                                                       /*!< GPIOD GPIOnOE: Pn1OE Position           */
#define GPIOD_GPIOnOE_Pn1OE_Msk               (0x01UL << GPIOD_GPIOnOE_Pn1OE_Pos)                     /*!< GPIOD GPIOnOE: Pn1OE Mask               */
#define GPIOD_GPIOnOE_Pn2OE_Pos               2                                                       /*!< GPIOD GPIOnOE: Pn2OE Position           */
#define GPIOD_GPIOnOE_Pn2OE_Msk               (0x01UL << GPIOD_GPIOnOE_Pn2OE_Pos)                     /*!< GPIOD GPIOnOE: Pn2OE Mask               */
#define GPIOD_GPIOnOE_Pn3OE_Pos               3                                                       /*!< GPIOD GPIOnOE: Pn3OE Position           */
#define GPIOD_GPIOnOE_Pn3OE_Msk               (0x01UL << GPIOD_GPIOnOE_Pn3OE_Pos)                     /*!< GPIOD GPIOnOE: Pn3OE Mask               */
#define GPIOD_GPIOnOE_Pn4OE_Pos               4                                                       /*!< GPIOD GPIOnOE: Pn4OE Position           */
#define GPIOD_GPIOnOE_Pn4OE_Msk               (0x01UL << GPIOD_GPIOnOE_Pn4OE_Pos)                     /*!< GPIOD GPIOnOE: Pn4OE Mask               */
#define GPIOD_GPIOnOE_Pn5OE_Pos               5                                                       /*!< GPIOD GPIOnOE: Pn5OE Position           */
#define GPIOD_GPIOnOE_Pn5OE_Msk               (0x01UL << GPIOD_GPIOnOE_Pn5OE_Pos)                     /*!< GPIOD GPIOnOE: Pn5OE Mask               */
#define GPIOD_GPIOnOE_Pn6OE_Pos               6                                                       /*!< GPIOD GPIOnOE: Pn6OE Position           */
#define GPIOD_GPIOnOE_Pn6OE_Msk               (0x01UL << GPIOD_GPIOnOE_Pn6OE_Pos)                     /*!< GPIOD GPIOnOE: Pn6OE Mask               */
#define GPIOD_GPIOnOE_Pn7OE_Pos               7                                                       /*!< GPIOD GPIOnOE: Pn7OE Position           */
#define GPIOD_GPIOnOE_Pn7OE_Msk               (0x01UL << GPIOD_GPIOnOE_Pn7OE_Pos)                     /*!< GPIOD GPIOnOE: Pn7OE Mask               */

/* --------------------------------  GPIOD_GPIOnDS  ------------------------------- */
#define GPIOD_GPIOnDS_Pn0DS_Pos               0                                                       /*!< GPIOD GPIOnDS: Pn0DS Position           */
#define GPIOD_GPIOnDS_Pn0DS_Msk               (0x01UL << GPIOD_GPIOnDS_Pn0DS_Pos)                     /*!< GPIOD GPIOnDS: Pn0DS Mask               */
#define GPIOD_GPIOnDS_Pn1DS_Pos               1                                                       /*!< GPIOD GPIOnDS: Pn1DS Position           */
#define GPIOD_GPIOnDS_Pn1DS_Msk               (0x01UL << GPIOD_GPIOnDS_Pn1DS_Pos)                     /*!< GPIOD GPIOnDS: Pn1DS Mask               */
#define GPIOD_GPIOnDS_Pn2DS_Pos               2                                                       /*!< GPIOD GPIOnDS: Pn2DS Position           */
#define GPIOD_GPIOnDS_Pn2DS_Msk               (0x01UL << GPIOD_GPIOnDS_Pn2DS_Pos)                     /*!< GPIOD GPIOnDS: Pn2DS Mask               */
#define GPIOD_GPIOnDS_Pn3DS_Pos               3                                                       /*!< GPIOD GPIOnDS: Pn3DS Position           */
#define GPIOD_GPIOnDS_Pn3DS_Msk               (0x01UL << GPIOD_GPIOnDS_Pn3DS_Pos)                     /*!< GPIOD GPIOnDS: Pn3DS Mask               */
#define GPIOD_GPIOnDS_Pn4DS_Pos               4                                                       /*!< GPIOD GPIOnDS: Pn4DS Position           */
#define GPIOD_GPIOnDS_Pn4DS_Msk               (0x01UL << GPIOD_GPIOnDS_Pn4DS_Pos)                     /*!< GPIOD GPIOnDS: Pn4DS Mask               */
#define GPIOD_GPIOnDS_Pn5DS_Pos               5                                                       /*!< GPIOD GPIOnDS: Pn5DS Position           */
#define GPIOD_GPIOnDS_Pn5DS_Msk               (0x01UL << GPIOD_GPIOnDS_Pn5DS_Pos)                     /*!< GPIOD GPIOnDS: Pn5DS Mask               */
#define GPIOD_GPIOnDS_Pn6DS_Pos               6                                                       /*!< GPIOD GPIOnDS: Pn6DS Position           */
#define GPIOD_GPIOnDS_Pn6DS_Msk               (0x01UL << GPIOD_GPIOnDS_Pn6DS_Pos)                     /*!< GPIOD GPIOnDS: Pn6DS Mask               */
#define GPIOD_GPIOnDS_Pn7DS_Pos               7                                                       /*!< GPIOD GPIOnDS: Pn7DS Position           */
#define GPIOD_GPIOnDS_Pn7DS_Msk               (0x01UL << GPIOD_GPIOnDS_Pn7DS_Pos)                     /*!< GPIOD GPIOnDS: Pn7DS Mask               */

/* -------------------------------  GPIOD_GPIOnRUP  ------------------------------- */
#define GPIOD_GPIOnRUP_Pn0RUP_Pos             0                                                       /*!< GPIOD GPIOnRUP: Pn0RUP Position         */
#define GPIOD_GPIOnRUP_Pn0RUP_Msk             (0x01UL << GPIOD_GPIOnRUP_Pn0RUP_Pos)                   /*!< GPIOD GPIOnRUP: Pn0RUP Mask             */
#define GPIOD_GPIOnRUP_Pn1RUP_Pos             1                                                       /*!< GPIOD GPIOnRUP: Pn1RUP Position         */
#define GPIOD_GPIOnRUP_Pn1RUP_Msk             (0x01UL << GPIOD_GPIOnRUP_Pn1RUP_Pos)                   /*!< GPIOD GPIOnRUP: Pn1RUP Mask             */
#define GPIOD_GPIOnRUP_Pn2RUP_Pos             2                                                       /*!< GPIOD GPIOnRUP: Pn2RUP Position         */
#define GPIOD_GPIOnRUP_Pn2RUP_Msk             (0x01UL << GPIOD_GPIOnRUP_Pn2RUP_Pos)                   /*!< GPIOD GPIOnRUP: Pn2RUP Mask             */
#define GPIOD_GPIOnRUP_Pn3RUP_Pos             3                                                       /*!< GPIOD GPIOnRUP: Pn3RUP Position         */
#define GPIOD_GPIOnRUP_Pn3RUP_Msk             (0x01UL << GPIOD_GPIOnRUP_Pn3RUP_Pos)                   /*!< GPIOD GPIOnRUP: Pn3RUP Mask             */
#define GPIOD_GPIOnRUP_Pn4RUP_Pos             4                                                       /*!< GPIOD GPIOnRUP: Pn4RUP Position         */
#define GPIOD_GPIOnRUP_Pn4RUP_Msk             (0x01UL << GPIOD_GPIOnRUP_Pn4RUP_Pos)                   /*!< GPIOD GPIOnRUP: Pn4RUP Mask             */
#define GPIOD_GPIOnRUP_Pn5RUP_Pos             5                                                       /*!< GPIOD GPIOnRUP: Pn5RUP Position         */
#define GPIOD_GPIOnRUP_Pn5RUP_Msk             (0x01UL << GPIOD_GPIOnRUP_Pn5RUP_Pos)                   /*!< GPIOD GPIOnRUP: Pn5RUP Mask             */
#define GPIOD_GPIOnRUP_Pn6RUP_Pos             6                                                       /*!< GPIOD GPIOnRUP: Pn6RUP Position         */
#define GPIOD_GPIOnRUP_Pn6RUP_Msk             (0x01UL << GPIOD_GPIOnRUP_Pn6RUP_Pos)                   /*!< GPIOD GPIOnRUP: Pn6RUP Mask             */
#define GPIOD_GPIOnRUP_Pn7RUP_Pos             7                                                       /*!< GPIOD GPIOnRUP: Pn7RUP Position         */
#define GPIOD_GPIOnRUP_Pn7RUP_Msk             (0x01UL << GPIOD_GPIOnRUP_Pn7RUP_Pos)                   /*!< GPIOD GPIOnRUP: Pn7RUP Mask             */

/* -------------------------------  GPIOD_GPIOnRDN  ------------------------------- */
#define GPIOD_GPIOnRDN_Pn0RDN_Pos             0                                                       /*!< GPIOD GPIOnRDN: Pn0RDN Position         */
#define GPIOD_GPIOnRDN_Pn0RDN_Msk             (0x01UL << GPIOD_GPIOnRDN_Pn0RDN_Pos)                   /*!< GPIOD GPIOnRDN: Pn0RDN Mask             */
#define GPIOD_GPIOnRDN_Pn1RDN_Pos             1                                                       /*!< GPIOD GPIOnRDN: Pn1RDN Position         */
#define GPIOD_GPIOnRDN_Pn1RDN_Msk             (0x01UL << GPIOD_GPIOnRDN_Pn1RDN_Pos)                   /*!< GPIOD GPIOnRDN: Pn1RDN Mask             */
#define GPIOD_GPIOnRDN_Pn2RDN_Pos             2                                                       /*!< GPIOD GPIOnRDN: Pn2RDN Position         */
#define GPIOD_GPIOnRDN_Pn2RDN_Msk             (0x01UL << GPIOD_GPIOnRDN_Pn2RDN_Pos)                   /*!< GPIOD GPIOnRDN: Pn2RDN Mask             */
#define GPIOD_GPIOnRDN_Pn3RDN_Pos             3                                                       /*!< GPIOD GPIOnRDN: Pn3RDN Position         */
#define GPIOD_GPIOnRDN_Pn3RDN_Msk             (0x01UL << GPIOD_GPIOnRDN_Pn3RDN_Pos)                   /*!< GPIOD GPIOnRDN: Pn3RDN Mask             */
#define GPIOD_GPIOnRDN_Pn4RDN_Pos             4                                                       /*!< GPIOD GPIOnRDN: Pn4RDN Position         */
#define GPIOD_GPIOnRDN_Pn4RDN_Msk             (0x01UL << GPIOD_GPIOnRDN_Pn4RDN_Pos)                   /*!< GPIOD GPIOnRDN: Pn4RDN Mask             */
#define GPIOD_GPIOnRDN_Pn5RDN_Pos             5                                                       /*!< GPIOD GPIOnRDN: Pn5RDN Position         */
#define GPIOD_GPIOnRDN_Pn5RDN_Msk             (0x01UL << GPIOD_GPIOnRDN_Pn5RDN_Pos)                   /*!< GPIOD GPIOnRDN: Pn5RDN Mask             */
#define GPIOD_GPIOnRDN_Pn6RDN_Pos             6                                                       /*!< GPIOD GPIOnRDN: Pn6RDN Position         */
#define GPIOD_GPIOnRDN_Pn6RDN_Msk             (0x01UL << GPIOD_GPIOnRDN_Pn6RDN_Pos)                   /*!< GPIOD GPIOnRDN: Pn6RDN Mask             */
#define GPIOD_GPIOnRDN_Pn7RDN_Pos             7                                                       /*!< GPIOD GPIOnRDN: Pn7RDN Position         */
#define GPIOD_GPIOnRDN_Pn7RDN_Msk             (0x01UL << GPIOD_GPIOnRDN_Pn7RDN_Pos)                   /*!< GPIOD GPIOnRDN: Pn7RDN Mask             */

/* --------------------------------  GPIOD_GPIOnI  -------------------------------- */
#define GPIOD_GPIOnI_Pn0I_Pos                 0                                                       /*!< GPIOD GPIOnI: Pn0I Position             */
#define GPIOD_GPIOnI_Pn0I_Msk                 (0x01UL << GPIOD_GPIOnI_Pn0I_Pos)                       /*!< GPIOD GPIOnI: Pn0I Mask                 */
#define GPIOD_GPIOnI_Pn1I_Pos                 1                                                       /*!< GPIOD GPIOnI: Pn1I Position             */
#define GPIOD_GPIOnI_Pn1I_Msk                 (0x01UL << GPIOD_GPIOnI_Pn1I_Pos)                       /*!< GPIOD GPIOnI: Pn1I Mask                 */
#define GPIOD_GPIOnI_Pn2I_Pos                 2                                                       /*!< GPIOD GPIOnI: Pn2I Position             */
#define GPIOD_GPIOnI_Pn2I_Msk                 (0x01UL << GPIOD_GPIOnI_Pn2I_Pos)                       /*!< GPIOD GPIOnI: Pn2I Mask                 */
#define GPIOD_GPIOnI_Pn3I_Pos                 3                                                       /*!< GPIOD GPIOnI: Pn3I Position             */
#define GPIOD_GPIOnI_Pn3I_Msk                 (0x01UL << GPIOD_GPIOnI_Pn3I_Pos)                       /*!< GPIOD GPIOnI: Pn3I Mask                 */
#define GPIOD_GPIOnI_Pn4I_Pos                 4                                                       /*!< GPIOD GPIOnI: Pn4I Position             */
#define GPIOD_GPIOnI_Pn4I_Msk                 (0x01UL << GPIOD_GPIOnI_Pn4I_Pos)                       /*!< GPIOD GPIOnI: Pn4I Mask                 */
#define GPIOD_GPIOnI_Pn5I_Pos                 5                                                       /*!< GPIOD GPIOnI: Pn5I Position             */
#define GPIOD_GPIOnI_Pn5I_Msk                 (0x01UL << GPIOD_GPIOnI_Pn5I_Pos)                       /*!< GPIOD GPIOnI: Pn5I Mask                 */
#define GPIOD_GPIOnI_Pn6I_Pos                 6                                                       /*!< GPIOD GPIOnI: Pn6I Position             */
#define GPIOD_GPIOnI_Pn6I_Msk                 (0x01UL << GPIOD_GPIOnI_Pn6I_Pos)                       /*!< GPIOD GPIOnI: Pn6I Mask                 */
#define GPIOD_GPIOnI_Pn7I_Pos                 7                                                       /*!< GPIOD GPIOnI: Pn7I Position             */
#define GPIOD_GPIOnI_Pn7I_Msk                 (0x01UL << GPIOD_GPIOnI_Pn7I_Pos)                       /*!< GPIOD GPIOnI: Pn7I Mask                 */

/* -------------------------------  GPIOD_GPIOnPSEL  ------------------------------ */
#define GPIOD_GPIOnPSEL_Pn0PSEL_Pos           0                                                       /*!< GPIOD GPIOnPSEL: Pn0PSEL Position       */
#define GPIOD_GPIOnPSEL_Pn0PSEL_Msk           (0x03UL << GPIOD_GPIOnPSEL_Pn0PSEL_Pos)                 /*!< GPIOD GPIOnPSEL: Pn0PSEL Mask           */
#define GPIOD_GPIOnPSEL_Pn1PSEL_Pos           2                                                       /*!< GPIOD GPIOnPSEL: Pn1PSEL Position       */
#define GPIOD_GPIOnPSEL_Pn1PSEL_Msk           (0x03UL << GPIOD_GPIOnPSEL_Pn1PSEL_Pos)                 /*!< GPIOD GPIOnPSEL: Pn1PSEL Mask           */
#define GPIOD_GPIOnPSEL_Pn2PSEL_Pos           4                                                       /*!< GPIOD GPIOnPSEL: Pn2PSEL Position       */
#define GPIOD_GPIOnPSEL_Pn2PSEL_Msk           (0x03UL << GPIOD_GPIOnPSEL_Pn2PSEL_Pos)                 /*!< GPIOD GPIOnPSEL: Pn2PSEL Mask           */
#define GPIOD_GPIOnPSEL_Pn3PSEL_Pos           6                                                       /*!< GPIOD GPIOnPSEL: Pn3PSEL Position       */
#define GPIOD_GPIOnPSEL_Pn3PSEL_Msk           (0x03UL << GPIOD_GPIOnPSEL_Pn3PSEL_Pos)                 /*!< GPIOD GPIOnPSEL: Pn3PSEL Mask           */
#define GPIOD_GPIOnPSEL_Pn4PSEL_Pos           8                                                       /*!< GPIOD GPIOnPSEL: Pn4PSEL Position       */
#define GPIOD_GPIOnPSEL_Pn4PSEL_Msk           (0x03UL << GPIOD_GPIOnPSEL_Pn4PSEL_Pos)                 /*!< GPIOD GPIOnPSEL: Pn4PSEL Mask           */
#define GPIOD_GPIOnPSEL_Pn5PSEL_Pos           10                                                      /*!< GPIOD GPIOnPSEL: Pn5PSEL Position       */
#define GPIOD_GPIOnPSEL_Pn5PSEL_Msk           (0x03UL << GPIOD_GPIOnPSEL_Pn5PSEL_Pos)                 /*!< GPIOD GPIOnPSEL: Pn5PSEL Mask           */
#define GPIOD_GPIOnPSEL_Pn6PSEL_Pos           12                                                      /*!< GPIOD GPIOnPSEL: Pn6PSEL Position       */
#define GPIOD_GPIOnPSEL_Pn6PSEL_Msk           (0x03UL << GPIOD_GPIOnPSEL_Pn6PSEL_Pos)                 /*!< GPIOD GPIOnPSEL: Pn6PSEL Mask           */
#define GPIOD_GPIOnPSEL_Pn7PSEL_Pos           14                                                      /*!< GPIOD GPIOnPSEL: Pn7PSEL Position       */
#define GPIOD_GPIOnPSEL_Pn7PSEL_Msk           (0x03UL << GPIOD_GPIOnPSEL_Pn7PSEL_Pos)                 /*!< GPIOD GPIOnPSEL: Pn7PSEL Mask           */

/* -------------------------------  GPIOD_GPIOnINTP  ------------------------------ */
#define GPIOD_GPIOnINTP_Pn0INTP_Pos           0                                                       /*!< GPIOD GPIOnINTP: Pn0INTP Position       */
#define GPIOD_GPIOnINTP_Pn0INTP_Msk           (0x01UL << GPIOD_GPIOnINTP_Pn0INTP_Pos)                 /*!< GPIOD GPIOnINTP: Pn0INTP Mask           */
#define GPIOD_GPIOnINTP_Pn1INTP_Pos           1                                                       /*!< GPIOD GPIOnINTP: Pn1INTP Position       */
#define GPIOD_GPIOnINTP_Pn1INTP_Msk           (0x01UL << GPIOD_GPIOnINTP_Pn1INTP_Pos)                 /*!< GPIOD GPIOnINTP: Pn1INTP Mask           */
#define GPIOD_GPIOnINTP_Pn2INTP_Pos           2                                                       /*!< GPIOD GPIOnINTP: Pn2INTP Position       */
#define GPIOD_GPIOnINTP_Pn2INTP_Msk           (0x01UL << GPIOD_GPIOnINTP_Pn2INTP_Pos)                 /*!< GPIOD GPIOnINTP: Pn2INTP Mask           */
#define GPIOD_GPIOnINTP_Pn3INTP_Pos           3                                                       /*!< GPIOD GPIOnINTP: Pn3INTP Position       */
#define GPIOD_GPIOnINTP_Pn3INTP_Msk           (0x01UL << GPIOD_GPIOnINTP_Pn3INTP_Pos)                 /*!< GPIOD GPIOnINTP: Pn3INTP Mask           */
#define GPIOD_GPIOnINTP_Pn4INTP_Pos           4                                                       /*!< GPIOD GPIOnINTP: Pn4INTP Position       */
#define GPIOD_GPIOnINTP_Pn4INTP_Msk           (0x01UL << GPIOD_GPIOnINTP_Pn4INTP_Pos)                 /*!< GPIOD GPIOnINTP: Pn4INTP Mask           */
#define GPIOD_GPIOnINTP_Pn5INTP_Pos           5                                                       /*!< GPIOD GPIOnINTP: Pn5INTP Position       */
#define GPIOD_GPIOnINTP_Pn5INTP_Msk           (0x01UL << GPIOD_GPIOnINTP_Pn5INTP_Pos)                 /*!< GPIOD GPIOnINTP: Pn5INTP Mask           */
#define GPIOD_GPIOnINTP_Pn6INTP_Pos           6                                                       /*!< GPIOD GPIOnINTP: Pn6INTP Position       */
#define GPIOD_GPIOnINTP_Pn6INTP_Msk           (0x01UL << GPIOD_GPIOnINTP_Pn6INTP_Pos)                 /*!< GPIOD GPIOnINTP: Pn6INTP Mask           */
#define GPIOD_GPIOnINTP_Pn7INTP_Pos           7                                                       /*!< GPIOD GPIOnINTP: Pn7INTP Position       */
#define GPIOD_GPIOnINTP_Pn7INTP_Msk           (0x01UL << GPIOD_GPIOnINTP_Pn7INTP_Pos)                 /*!< GPIOD GPIOnINTP: Pn7INTP Mask           */

/* ------------------------------  GPIOD_GPIOnINTEN  ------------------------------ */
#define GPIOD_GPIOnINTEN_Pn0INTEN_Pos         0                                                       /*!< GPIOD GPIOnINTEN: Pn0INTEN Position     */
#define GPIOD_GPIOnINTEN_Pn0INTEN_Msk         (0x01UL << GPIOD_GPIOnINTEN_Pn0INTEN_Pos)               /*!< GPIOD GPIOnINTEN: Pn0INTEN Mask         */
#define GPIOD_GPIOnINTEN_Pn1INTEN_Pos         1                                                       /*!< GPIOD GPIOnINTEN: Pn1INTEN Position     */
#define GPIOD_GPIOnINTEN_Pn1INTEN_Msk         (0x01UL << GPIOD_GPIOnINTEN_Pn1INTEN_Pos)               /*!< GPIOD GPIOnINTEN: Pn1INTEN Mask         */
#define GPIOD_GPIOnINTEN_Pn2INTEN_Pos         2                                                       /*!< GPIOD GPIOnINTEN: Pn2INTEN Position     */
#define GPIOD_GPIOnINTEN_Pn2INTEN_Msk         (0x01UL << GPIOD_GPIOnINTEN_Pn2INTEN_Pos)               /*!< GPIOD GPIOnINTEN: Pn2INTEN Mask         */
#define GPIOD_GPIOnINTEN_Pn3INTEN_Pos         3                                                       /*!< GPIOD GPIOnINTEN: Pn3INTEN Position     */
#define GPIOD_GPIOnINTEN_Pn3INTEN_Msk         (0x01UL << GPIOD_GPIOnINTEN_Pn3INTEN_Pos)               /*!< GPIOD GPIOnINTEN: Pn3INTEN Mask         */
#define GPIOD_GPIOnINTEN_Pn4INTEN_Pos         4                                                       /*!< GPIOD GPIOnINTEN: Pn4INTEN Position     */
#define GPIOD_GPIOnINTEN_Pn4INTEN_Msk         (0x01UL << GPIOD_GPIOnINTEN_Pn4INTEN_Pos)               /*!< GPIOD GPIOnINTEN: Pn4INTEN Mask         */
#define GPIOD_GPIOnINTEN_Pn5INTEN_Pos         5                                                       /*!< GPIOD GPIOnINTEN: Pn5INTEN Position     */
#define GPIOD_GPIOnINTEN_Pn5INTEN_Msk         (0x01UL << GPIOD_GPIOnINTEN_Pn5INTEN_Pos)               /*!< GPIOD GPIOnINTEN: Pn5INTEN Mask         */
#define GPIOD_GPIOnINTEN_Pn6INTEN_Pos         6                                                       /*!< GPIOD GPIOnINTEN: Pn6INTEN Position     */
#define GPIOD_GPIOnINTEN_Pn6INTEN_Msk         (0x01UL << GPIOD_GPIOnINTEN_Pn6INTEN_Pos)               /*!< GPIOD GPIOnINTEN: Pn6INTEN Mask         */
#define GPIOD_GPIOnINTEN_Pn7INTEN_Pos         7                                                       /*!< GPIOD GPIOnINTEN: Pn7INTEN Position     */
#define GPIOD_GPIOnINTEN_Pn7INTEN_Msk         (0x01UL << GPIOD_GPIOnINTEN_Pn7INTEN_Pos)               /*!< GPIOD GPIOnINTEN: Pn7INTEN Mask         */

/* -------------------------------  GPIOD_GPIOnINT  ------------------------------- */
#define GPIOD_GPIOnINT_Pn0INT_Pos             0                                                       /*!< GPIOD GPIOnINT: Pn0INT Position         */
#define GPIOD_GPIOnINT_Pn0INT_Msk             (0x01UL << GPIOD_GPIOnINT_Pn0INT_Pos)                   /*!< GPIOD GPIOnINT: Pn0INT Mask             */
#define GPIOD_GPIOnINT_Pn1INT_Pos             1                                                       /*!< GPIOD GPIOnINT: Pn1INT Position         */
#define GPIOD_GPIOnINT_Pn1INT_Msk             (0x01UL << GPIOD_GPIOnINT_Pn1INT_Pos)                   /*!< GPIOD GPIOnINT: Pn1INT Mask             */
#define GPIOD_GPIOnINT_Pn2INT_Pos             2                                                       /*!< GPIOD GPIOnINT: Pn2INT Position         */
#define GPIOD_GPIOnINT_Pn2INT_Msk             (0x01UL << GPIOD_GPIOnINT_Pn2INT_Pos)                   /*!< GPIOD GPIOnINT: Pn2INT Mask             */
#define GPIOD_GPIOnINT_Pn3INT_Pos             3                                                       /*!< GPIOD GPIOnINT: Pn3INT Position         */
#define GPIOD_GPIOnINT_Pn3INT_Msk             (0x01UL << GPIOD_GPIOnINT_Pn3INT_Pos)                   /*!< GPIOD GPIOnINT: Pn3INT Mask             */
#define GPIOD_GPIOnINT_Pn4INT_Pos             4                                                       /*!< GPIOD GPIOnINT: Pn4INT Position         */
#define GPIOD_GPIOnINT_Pn4INT_Msk             (0x01UL << GPIOD_GPIOnINT_Pn4INT_Pos)                   /*!< GPIOD GPIOnINT: Pn4INT Mask             */
#define GPIOD_GPIOnINT_Pn5INT_Pos             5                                                       /*!< GPIOD GPIOnINT: Pn5INT Position         */
#define GPIOD_GPIOnINT_Pn5INT_Msk             (0x01UL << GPIOD_GPIOnINT_Pn5INT_Pos)                   /*!< GPIOD GPIOnINT: Pn5INT Mask             */
#define GPIOD_GPIOnINT_Pn6INT_Pos             6                                                       /*!< GPIOD GPIOnINT: Pn6INT Position         */
#define GPIOD_GPIOnINT_Pn6INT_Msk             (0x01UL << GPIOD_GPIOnINT_Pn6INT_Pos)                   /*!< GPIOD GPIOnINT: Pn6INT Mask             */
#define GPIOD_GPIOnINT_Pn7INT_Pos             7                                                       /*!< GPIOD GPIOnINT: Pn7INT Position         */
#define GPIOD_GPIOnINT_Pn7INT_Msk             (0x01UL << GPIOD_GPIOnINT_Pn7INT_Pos)                   /*!< GPIOD GPIOnINT: Pn7INT Mask             */

/* -------------------------------  GPIOD_GPIOnINTM  ------------------------------ */
#define GPIOD_GPIOnINTM_Pn0INTM_Pos           0                                                       /*!< GPIOD GPIOnINTM: Pn0INTM Position       */
#define GPIOD_GPIOnINTM_Pn0INTM_Msk           (0x01UL << GPIOD_GPIOnINTM_Pn0INTM_Pos)                 /*!< GPIOD GPIOnINTM: Pn0INTM Mask           */
#define GPIOD_GPIOnINTM_Pn1INTM_Pos           1                                                       /*!< GPIOD GPIOnINTM: Pn1INTM Position       */
#define GPIOD_GPIOnINTM_Pn1INTM_Msk           (0x01UL << GPIOD_GPIOnINTM_Pn1INTM_Pos)                 /*!< GPIOD GPIOnINTM: Pn1INTM Mask           */
#define GPIOD_GPIOnINTM_Pn2INTM_Pos           2                                                       /*!< GPIOD GPIOnINTM: Pn2INTM Position       */
#define GPIOD_GPIOnINTM_Pn2INTM_Msk           (0x01UL << GPIOD_GPIOnINTM_Pn2INTM_Pos)                 /*!< GPIOD GPIOnINTM: Pn2INTM Mask           */
#define GPIOD_GPIOnINTM_Pn3INTM_Pos           3                                                       /*!< GPIOD GPIOnINTM: Pn3INTM Position       */
#define GPIOD_GPIOnINTM_Pn3INTM_Msk           (0x01UL << GPIOD_GPIOnINTM_Pn3INTM_Pos)                 /*!< GPIOD GPIOnINTM: Pn3INTM Mask           */
#define GPIOD_GPIOnINTM_Pn4INTM_Pos           4                                                       /*!< GPIOD GPIOnINTM: Pn4INTM Position       */
#define GPIOD_GPIOnINTM_Pn4INTM_Msk           (0x01UL << GPIOD_GPIOnINTM_Pn4INTM_Pos)                 /*!< GPIOD GPIOnINTM: Pn4INTM Mask           */
#define GPIOD_GPIOnINTM_Pn5INTM_Pos           5                                                       /*!< GPIOD GPIOnINTM: Pn5INTM Position       */
#define GPIOD_GPIOnINTM_Pn5INTM_Msk           (0x01UL << GPIOD_GPIOnINTM_Pn5INTM_Pos)                 /*!< GPIOD GPIOnINTM: Pn5INTM Mask           */
#define GPIOD_GPIOnINTM_Pn6INTM_Pos           6                                                       /*!< GPIOD GPIOnINTM: Pn6INTM Position       */
#define GPIOD_GPIOnINTM_Pn6INTM_Msk           (0x01UL << GPIOD_GPIOnINTM_Pn6INTM_Pos)                 /*!< GPIOD GPIOnINTM: Pn6INTM Mask           */
#define GPIOD_GPIOnINTM_Pn7INTM_Pos           7                                                       /*!< GPIOD GPIOnINTM: Pn7INTM Position       */
#define GPIOD_GPIOnINTM_Pn7INTM_Msk           (0x01UL << GPIOD_GPIOnINTM_Pn7INTM_Pos)                 /*!< GPIOD GPIOnINTM: Pn7INTM Mask           */


/* ================================================================================ */
/* ================         struct 'GPIOE' Position & Mask         ================ */
/* ================================================================================ */


/* --------------------------------  GPIOE_GPIOnO  -------------------------------- */
#define GPIOE_GPIOnO_Pn0O_Pos                 0                                                       /*!< GPIOE GPIOnO: Pn0O Position             */
#define GPIOE_GPIOnO_Pn0O_Msk                 (0x01UL << GPIOE_GPIOnO_Pn0O_Pos)                       /*!< GPIOE GPIOnO: Pn0O Mask                 */
#define GPIOE_GPIOnO_Pn1O_Pos                 1                                                       /*!< GPIOE GPIOnO: Pn1O Position             */
#define GPIOE_GPIOnO_Pn1O_Msk                 (0x01UL << GPIOE_GPIOnO_Pn1O_Pos)                       /*!< GPIOE GPIOnO: Pn1O Mask                 */
#define GPIOE_GPIOnO_Pn2O_Pos                 2                                                       /*!< GPIOE GPIOnO: Pn2O Position             */
#define GPIOE_GPIOnO_Pn2O_Msk                 (0x01UL << GPIOE_GPIOnO_Pn2O_Pos)                       /*!< GPIOE GPIOnO: Pn2O Mask                 */
#define GPIOE_GPIOnO_Pn3O_Pos                 3                                                       /*!< GPIOE GPIOnO: Pn3O Position             */
#define GPIOE_GPIOnO_Pn3O_Msk                 (0x01UL << GPIOE_GPIOnO_Pn3O_Pos)                       /*!< GPIOE GPIOnO: Pn3O Mask                 */
#define GPIOE_GPIOnO_Pn4O_Pos                 4                                                       /*!< GPIOE GPIOnO: Pn4O Position             */
#define GPIOE_GPIOnO_Pn4O_Msk                 (0x01UL << GPIOE_GPIOnO_Pn4O_Pos)                       /*!< GPIOE GPIOnO: Pn4O Mask                 */
#define GPIOE_GPIOnO_Pn5O_Pos                 5                                                       /*!< GPIOE GPIOnO: Pn5O Position             */
#define GPIOE_GPIOnO_Pn5O_Msk                 (0x01UL << GPIOE_GPIOnO_Pn5O_Pos)                       /*!< GPIOE GPIOnO: Pn5O Mask                 */
#define GPIOE_GPIOnO_Pn6O_Pos                 6                                                       /*!< GPIOE GPIOnO: Pn6O Position             */
#define GPIOE_GPIOnO_Pn6O_Msk                 (0x01UL << GPIOE_GPIOnO_Pn6O_Pos)                       /*!< GPIOE GPIOnO: Pn6O Mask                 */
#define GPIOE_GPIOnO_Pn7O_Pos                 7                                                       /*!< GPIOE GPIOnO: Pn7O Position             */
#define GPIOE_GPIOnO_Pn7O_Msk                 (0x01UL << GPIOE_GPIOnO_Pn7O_Pos)                       /*!< GPIOE GPIOnO: Pn7O Mask                 */

/* --------------------------------  GPIOE_GPIOnOE  ------------------------------- */
#define GPIOE_GPIOnOE_Pn0OE_Pos               0                                                       /*!< GPIOE GPIOnOE: Pn0OE Position           */
#define GPIOE_GPIOnOE_Pn0OE_Msk               (0x01UL << GPIOE_GPIOnOE_Pn0OE_Pos)                     /*!< GPIOE GPIOnOE: Pn0OE Mask               */
#define GPIOE_GPIOnOE_Pn1OE_Pos               1                                                       /*!< GPIOE GPIOnOE: Pn1OE Position           */
#define GPIOE_GPIOnOE_Pn1OE_Msk               (0x01UL << GPIOE_GPIOnOE_Pn1OE_Pos)                     /*!< GPIOE GPIOnOE: Pn1OE Mask               */
#define GPIOE_GPIOnOE_Pn2OE_Pos               2                                                       /*!< GPIOE GPIOnOE: Pn2OE Position           */
#define GPIOE_GPIOnOE_Pn2OE_Msk               (0x01UL << GPIOE_GPIOnOE_Pn2OE_Pos)                     /*!< GPIOE GPIOnOE: Pn2OE Mask               */
#define GPIOE_GPIOnOE_Pn3OE_Pos               3                                                       /*!< GPIOE GPIOnOE: Pn3OE Position           */
#define GPIOE_GPIOnOE_Pn3OE_Msk               (0x01UL << GPIOE_GPIOnOE_Pn3OE_Pos)                     /*!< GPIOE GPIOnOE: Pn3OE Mask               */
#define GPIOE_GPIOnOE_Pn4OE_Pos               4                                                       /*!< GPIOE GPIOnOE: Pn4OE Position           */
#define GPIOE_GPIOnOE_Pn4OE_Msk               (0x01UL << GPIOE_GPIOnOE_Pn4OE_Pos)                     /*!< GPIOE GPIOnOE: Pn4OE Mask               */
#define GPIOE_GPIOnOE_Pn5OE_Pos               5                                                       /*!< GPIOE GPIOnOE: Pn5OE Position           */
#define GPIOE_GPIOnOE_Pn5OE_Msk               (0x01UL << GPIOE_GPIOnOE_Pn5OE_Pos)                     /*!< GPIOE GPIOnOE: Pn5OE Mask               */
#define GPIOE_GPIOnOE_Pn6OE_Pos               6                                                       /*!< GPIOE GPIOnOE: Pn6OE Position           */
#define GPIOE_GPIOnOE_Pn6OE_Msk               (0x01UL << GPIOE_GPIOnOE_Pn6OE_Pos)                     /*!< GPIOE GPIOnOE: Pn6OE Mask               */
#define GPIOE_GPIOnOE_Pn7OE_Pos               7                                                       /*!< GPIOE GPIOnOE: Pn7OE Position           */
#define GPIOE_GPIOnOE_Pn7OE_Msk               (0x01UL << GPIOE_GPIOnOE_Pn7OE_Pos)                     /*!< GPIOE GPIOnOE: Pn7OE Mask               */

/* --------------------------------  GPIOE_GPIOnDS  ------------------------------- */
#define GPIOE_GPIOnDS_Pn0DS_Pos               0                                                       /*!< GPIOE GPIOnDS: Pn0DS Position           */
#define GPIOE_GPIOnDS_Pn0DS_Msk               (0x01UL << GPIOE_GPIOnDS_Pn0DS_Pos)                     /*!< GPIOE GPIOnDS: Pn0DS Mask               */
#define GPIOE_GPIOnDS_Pn1DS_Pos               1                                                       /*!< GPIOE GPIOnDS: Pn1DS Position           */
#define GPIOE_GPIOnDS_Pn1DS_Msk               (0x01UL << GPIOE_GPIOnDS_Pn1DS_Pos)                     /*!< GPIOE GPIOnDS: Pn1DS Mask               */
#define GPIOE_GPIOnDS_Pn2DS_Pos               2                                                       /*!< GPIOE GPIOnDS: Pn2DS Position           */
#define GPIOE_GPIOnDS_Pn2DS_Msk               (0x01UL << GPIOE_GPIOnDS_Pn2DS_Pos)                     /*!< GPIOE GPIOnDS: Pn2DS Mask               */
#define GPIOE_GPIOnDS_Pn3DS_Pos               3                                                       /*!< GPIOE GPIOnDS: Pn3DS Position           */
#define GPIOE_GPIOnDS_Pn3DS_Msk               (0x01UL << GPIOE_GPIOnDS_Pn3DS_Pos)                     /*!< GPIOE GPIOnDS: Pn3DS Mask               */
#define GPIOE_GPIOnDS_Pn4DS_Pos               4                                                       /*!< GPIOE GPIOnDS: Pn4DS Position           */
#define GPIOE_GPIOnDS_Pn4DS_Msk               (0x01UL << GPIOE_GPIOnDS_Pn4DS_Pos)                     /*!< GPIOE GPIOnDS: Pn4DS Mask               */
#define GPIOE_GPIOnDS_Pn5DS_Pos               5                                                       /*!< GPIOE GPIOnDS: Pn5DS Position           */
#define GPIOE_GPIOnDS_Pn5DS_Msk               (0x01UL << GPIOE_GPIOnDS_Pn5DS_Pos)                     /*!< GPIOE GPIOnDS: Pn5DS Mask               */
#define GPIOE_GPIOnDS_Pn6DS_Pos               6                                                       /*!< GPIOE GPIOnDS: Pn6DS Position           */
#define GPIOE_GPIOnDS_Pn6DS_Msk               (0x01UL << GPIOE_GPIOnDS_Pn6DS_Pos)                     /*!< GPIOE GPIOnDS: Pn6DS Mask               */
#define GPIOE_GPIOnDS_Pn7DS_Pos               7                                                       /*!< GPIOE GPIOnDS: Pn7DS Position           */
#define GPIOE_GPIOnDS_Pn7DS_Msk               (0x01UL << GPIOE_GPIOnDS_Pn7DS_Pos)                     /*!< GPIOE GPIOnDS: Pn7DS Mask               */

/* -------------------------------  GPIOE_GPIOnRUP  ------------------------------- */
#define GPIOE_GPIOnRUP_Pn0RUP_Pos             0                                                       /*!< GPIOE GPIOnRUP: Pn0RUP Position         */
#define GPIOE_GPIOnRUP_Pn0RUP_Msk             (0x01UL << GPIOE_GPIOnRUP_Pn0RUP_Pos)                   /*!< GPIOE GPIOnRUP: Pn0RUP Mask             */
#define GPIOE_GPIOnRUP_Pn1RUP_Pos             1                                                       /*!< GPIOE GPIOnRUP: Pn1RUP Position         */
#define GPIOE_GPIOnRUP_Pn1RUP_Msk             (0x01UL << GPIOE_GPIOnRUP_Pn1RUP_Pos)                   /*!< GPIOE GPIOnRUP: Pn1RUP Mask             */
#define GPIOE_GPIOnRUP_Pn2RUP_Pos             2                                                       /*!< GPIOE GPIOnRUP: Pn2RUP Position         */
#define GPIOE_GPIOnRUP_Pn2RUP_Msk             (0x01UL << GPIOE_GPIOnRUP_Pn2RUP_Pos)                   /*!< GPIOE GPIOnRUP: Pn2RUP Mask             */
#define GPIOE_GPIOnRUP_Pn3RUP_Pos             3                                                       /*!< GPIOE GPIOnRUP: Pn3RUP Position         */
#define GPIOE_GPIOnRUP_Pn3RUP_Msk             (0x01UL << GPIOE_GPIOnRUP_Pn3RUP_Pos)                   /*!< GPIOE GPIOnRUP: Pn3RUP Mask             */
#define GPIOE_GPIOnRUP_Pn4RUP_Pos             4                                                       /*!< GPIOE GPIOnRUP: Pn4RUP Position         */
#define GPIOE_GPIOnRUP_Pn4RUP_Msk             (0x01UL << GPIOE_GPIOnRUP_Pn4RUP_Pos)                   /*!< GPIOE GPIOnRUP: Pn4RUP Mask             */
#define GPIOE_GPIOnRUP_Pn5RUP_Pos             5                                                       /*!< GPIOE GPIOnRUP: Pn5RUP Position         */
#define GPIOE_GPIOnRUP_Pn5RUP_Msk             (0x01UL << GPIOE_GPIOnRUP_Pn5RUP_Pos)                   /*!< GPIOE GPIOnRUP: Pn5RUP Mask             */
#define GPIOE_GPIOnRUP_Pn6RUP_Pos             6                                                       /*!< GPIOE GPIOnRUP: Pn6RUP Position         */
#define GPIOE_GPIOnRUP_Pn6RUP_Msk             (0x01UL << GPIOE_GPIOnRUP_Pn6RUP_Pos)                   /*!< GPIOE GPIOnRUP: Pn6RUP Mask             */
#define GPIOE_GPIOnRUP_Pn7RUP_Pos             7                                                       /*!< GPIOE GPIOnRUP: Pn7RUP Position         */
#define GPIOE_GPIOnRUP_Pn7RUP_Msk             (0x01UL << GPIOE_GPIOnRUP_Pn7RUP_Pos)                   /*!< GPIOE GPIOnRUP: Pn7RUP Mask             */

/* -------------------------------  GPIOE_GPIOnRDN  ------------------------------- */
#define GPIOE_GPIOnRDN_Pn0RDN_Pos             0                                                       /*!< GPIOE GPIOnRDN: Pn0RDN Position         */
#define GPIOE_GPIOnRDN_Pn0RDN_Msk             (0x01UL << GPIOE_GPIOnRDN_Pn0RDN_Pos)                   /*!< GPIOE GPIOnRDN: Pn0RDN Mask             */
#define GPIOE_GPIOnRDN_Pn1RDN_Pos             1                                                       /*!< GPIOE GPIOnRDN: Pn1RDN Position         */
#define GPIOE_GPIOnRDN_Pn1RDN_Msk             (0x01UL << GPIOE_GPIOnRDN_Pn1RDN_Pos)                   /*!< GPIOE GPIOnRDN: Pn1RDN Mask             */
#define GPIOE_GPIOnRDN_Pn2RDN_Pos             2                                                       /*!< GPIOE GPIOnRDN: Pn2RDN Position         */
#define GPIOE_GPIOnRDN_Pn2RDN_Msk             (0x01UL << GPIOE_GPIOnRDN_Pn2RDN_Pos)                   /*!< GPIOE GPIOnRDN: Pn2RDN Mask             */
#define GPIOE_GPIOnRDN_Pn3RDN_Pos             3                                                       /*!< GPIOE GPIOnRDN: Pn3RDN Position         */
#define GPIOE_GPIOnRDN_Pn3RDN_Msk             (0x01UL << GPIOE_GPIOnRDN_Pn3RDN_Pos)                   /*!< GPIOE GPIOnRDN: Pn3RDN Mask             */
#define GPIOE_GPIOnRDN_Pn4RDN_Pos             4                                                       /*!< GPIOE GPIOnRDN: Pn4RDN Position         */
#define GPIOE_GPIOnRDN_Pn4RDN_Msk             (0x01UL << GPIOE_GPIOnRDN_Pn4RDN_Pos)                   /*!< GPIOE GPIOnRDN: Pn4RDN Mask             */
#define GPIOE_GPIOnRDN_Pn5RDN_Pos             5                                                       /*!< GPIOE GPIOnRDN: Pn5RDN Position         */
#define GPIOE_GPIOnRDN_Pn5RDN_Msk             (0x01UL << GPIOE_GPIOnRDN_Pn5RDN_Pos)                   /*!< GPIOE GPIOnRDN: Pn5RDN Mask             */
#define GPIOE_GPIOnRDN_Pn6RDN_Pos             6                                                       /*!< GPIOE GPIOnRDN: Pn6RDN Position         */
#define GPIOE_GPIOnRDN_Pn6RDN_Msk             (0x01UL << GPIOE_GPIOnRDN_Pn6RDN_Pos)                   /*!< GPIOE GPIOnRDN: Pn6RDN Mask             */
#define GPIOE_GPIOnRDN_Pn7RDN_Pos             7                                                       /*!< GPIOE GPIOnRDN: Pn7RDN Position         */
#define GPIOE_GPIOnRDN_Pn7RDN_Msk             (0x01UL << GPIOE_GPIOnRDN_Pn7RDN_Pos)                   /*!< GPIOE GPIOnRDN: Pn7RDN Mask             */

/* --------------------------------  GPIOE_GPIOnI  -------------------------------- */
#define GPIOE_GPIOnI_Pn0I_Pos                 0                                                       /*!< GPIOE GPIOnI: Pn0I Position             */
#define GPIOE_GPIOnI_Pn0I_Msk                 (0x01UL << GPIOE_GPIOnI_Pn0I_Pos)                       /*!< GPIOE GPIOnI: Pn0I Mask                 */
#define GPIOE_GPIOnI_Pn1I_Pos                 1                                                       /*!< GPIOE GPIOnI: Pn1I Position             */
#define GPIOE_GPIOnI_Pn1I_Msk                 (0x01UL << GPIOE_GPIOnI_Pn1I_Pos)                       /*!< GPIOE GPIOnI: Pn1I Mask                 */
#define GPIOE_GPIOnI_Pn2I_Pos                 2                                                       /*!< GPIOE GPIOnI: Pn2I Position             */
#define GPIOE_GPIOnI_Pn2I_Msk                 (0x01UL << GPIOE_GPIOnI_Pn2I_Pos)                       /*!< GPIOE GPIOnI: Pn2I Mask                 */
#define GPIOE_GPIOnI_Pn3I_Pos                 3                                                       /*!< GPIOE GPIOnI: Pn3I Position             */
#define GPIOE_GPIOnI_Pn3I_Msk                 (0x01UL << GPIOE_GPIOnI_Pn3I_Pos)                       /*!< GPIOE GPIOnI: Pn3I Mask                 */
#define GPIOE_GPIOnI_Pn4I_Pos                 4                                                       /*!< GPIOE GPIOnI: Pn4I Position             */
#define GPIOE_GPIOnI_Pn4I_Msk                 (0x01UL << GPIOE_GPIOnI_Pn4I_Pos)                       /*!< GPIOE GPIOnI: Pn4I Mask                 */
#define GPIOE_GPIOnI_Pn5I_Pos                 5                                                       /*!< GPIOE GPIOnI: Pn5I Position             */
#define GPIOE_GPIOnI_Pn5I_Msk                 (0x01UL << GPIOE_GPIOnI_Pn5I_Pos)                       /*!< GPIOE GPIOnI: Pn5I Mask                 */
#define GPIOE_GPIOnI_Pn6I_Pos                 6                                                       /*!< GPIOE GPIOnI: Pn6I Position             */
#define GPIOE_GPIOnI_Pn6I_Msk                 (0x01UL << GPIOE_GPIOnI_Pn6I_Pos)                       /*!< GPIOE GPIOnI: Pn6I Mask                 */
#define GPIOE_GPIOnI_Pn7I_Pos                 7                                                       /*!< GPIOE GPIOnI: Pn7I Position             */
#define GPIOE_GPIOnI_Pn7I_Msk                 (0x01UL << GPIOE_GPIOnI_Pn7I_Pos)                       /*!< GPIOE GPIOnI: Pn7I Mask                 */

/* -------------------------------  GPIOE_GPIOnPSEL  ------------------------------ */
#define GPIOE_GPIOnPSEL_Pn0PSEL_Pos           0                                                       /*!< GPIOE GPIOnPSEL: Pn0PSEL Position       */
#define GPIOE_GPIOnPSEL_Pn0PSEL_Msk           (0x03UL << GPIOE_GPIOnPSEL_Pn0PSEL_Pos)                 /*!< GPIOE GPIOnPSEL: Pn0PSEL Mask           */
#define GPIOE_GPIOnPSEL_Pn1PSEL_Pos           2                                                       /*!< GPIOE GPIOnPSEL: Pn1PSEL Position       */
#define GPIOE_GPIOnPSEL_Pn1PSEL_Msk           (0x03UL << GPIOE_GPIOnPSEL_Pn1PSEL_Pos)                 /*!< GPIOE GPIOnPSEL: Pn1PSEL Mask           */
#define GPIOE_GPIOnPSEL_Pn2PSEL_Pos           4                                                       /*!< GPIOE GPIOnPSEL: Pn2PSEL Position       */
#define GPIOE_GPIOnPSEL_Pn2PSEL_Msk           (0x03UL << GPIOE_GPIOnPSEL_Pn2PSEL_Pos)                 /*!< GPIOE GPIOnPSEL: Pn2PSEL Mask           */
#define GPIOE_GPIOnPSEL_Pn3PSEL_Pos           6                                                       /*!< GPIOE GPIOnPSEL: Pn3PSEL Position       */
#define GPIOE_GPIOnPSEL_Pn3PSEL_Msk           (0x03UL << GPIOE_GPIOnPSEL_Pn3PSEL_Pos)                 /*!< GPIOE GPIOnPSEL: Pn3PSEL Mask           */
#define GPIOE_GPIOnPSEL_Pn4PSEL_Pos           8                                                       /*!< GPIOE GPIOnPSEL: Pn4PSEL Position       */
#define GPIOE_GPIOnPSEL_Pn4PSEL_Msk           (0x03UL << GPIOE_GPIOnPSEL_Pn4PSEL_Pos)                 /*!< GPIOE GPIOnPSEL: Pn4PSEL Mask           */
#define GPIOE_GPIOnPSEL_Pn5PSEL_Pos           10                                                      /*!< GPIOE GPIOnPSEL: Pn5PSEL Position       */
#define GPIOE_GPIOnPSEL_Pn5PSEL_Msk           (0x03UL << GPIOE_GPIOnPSEL_Pn5PSEL_Pos)                 /*!< GPIOE GPIOnPSEL: Pn5PSEL Mask           */
#define GPIOE_GPIOnPSEL_Pn6PSEL_Pos           12                                                      /*!< GPIOE GPIOnPSEL: Pn6PSEL Position       */
#define GPIOE_GPIOnPSEL_Pn6PSEL_Msk           (0x03UL << GPIOE_GPIOnPSEL_Pn6PSEL_Pos)                 /*!< GPIOE GPIOnPSEL: Pn6PSEL Mask           */
#define GPIOE_GPIOnPSEL_Pn7PSEL_Pos           14                                                      /*!< GPIOE GPIOnPSEL: Pn7PSEL Position       */
#define GPIOE_GPIOnPSEL_Pn7PSEL_Msk           (0x03UL << GPIOE_GPIOnPSEL_Pn7PSEL_Pos)                 /*!< GPIOE GPIOnPSEL: Pn7PSEL Mask           */

/* -------------------------------  GPIOE_GPIOnINTP  ------------------------------ */
#define GPIOE_GPIOnINTP_Pn0INTP_Pos           0                                                       /*!< GPIOE GPIOnINTP: Pn0INTP Position       */
#define GPIOE_GPIOnINTP_Pn0INTP_Msk           (0x01UL << GPIOE_GPIOnINTP_Pn0INTP_Pos)                 /*!< GPIOE GPIOnINTP: Pn0INTP Mask           */
#define GPIOE_GPIOnINTP_Pn1INTP_Pos           1                                                       /*!< GPIOE GPIOnINTP: Pn1INTP Position       */
#define GPIOE_GPIOnINTP_Pn1INTP_Msk           (0x01UL << GPIOE_GPIOnINTP_Pn1INTP_Pos)                 /*!< GPIOE GPIOnINTP: Pn1INTP Mask           */
#define GPIOE_GPIOnINTP_Pn2INTP_Pos           2                                                       /*!< GPIOE GPIOnINTP: Pn2INTP Position       */
#define GPIOE_GPIOnINTP_Pn2INTP_Msk           (0x01UL << GPIOE_GPIOnINTP_Pn2INTP_Pos)                 /*!< GPIOE GPIOnINTP: Pn2INTP Mask           */
#define GPIOE_GPIOnINTP_Pn3INTP_Pos           3                                                       /*!< GPIOE GPIOnINTP: Pn3INTP Position       */
#define GPIOE_GPIOnINTP_Pn3INTP_Msk           (0x01UL << GPIOE_GPIOnINTP_Pn3INTP_Pos)                 /*!< GPIOE GPIOnINTP: Pn3INTP Mask           */
#define GPIOE_GPIOnINTP_Pn4INTP_Pos           4                                                       /*!< GPIOE GPIOnINTP: Pn4INTP Position       */
#define GPIOE_GPIOnINTP_Pn4INTP_Msk           (0x01UL << GPIOE_GPIOnINTP_Pn4INTP_Pos)                 /*!< GPIOE GPIOnINTP: Pn4INTP Mask           */
#define GPIOE_GPIOnINTP_Pn5INTP_Pos           5                                                       /*!< GPIOE GPIOnINTP: Pn5INTP Position       */
#define GPIOE_GPIOnINTP_Pn5INTP_Msk           (0x01UL << GPIOE_GPIOnINTP_Pn5INTP_Pos)                 /*!< GPIOE GPIOnINTP: Pn5INTP Mask           */
#define GPIOE_GPIOnINTP_Pn6INTP_Pos           6                                                       /*!< GPIOE GPIOnINTP: Pn6INTP Position       */
#define GPIOE_GPIOnINTP_Pn6INTP_Msk           (0x01UL << GPIOE_GPIOnINTP_Pn6INTP_Pos)                 /*!< GPIOE GPIOnINTP: Pn6INTP Mask           */
#define GPIOE_GPIOnINTP_Pn7INTP_Pos           7                                                       /*!< GPIOE GPIOnINTP: Pn7INTP Position       */
#define GPIOE_GPIOnINTP_Pn7INTP_Msk           (0x01UL << GPIOE_GPIOnINTP_Pn7INTP_Pos)                 /*!< GPIOE GPIOnINTP: Pn7INTP Mask           */

/* ------------------------------  GPIOE_GPIOnINTEN  ------------------------------ */
#define GPIOE_GPIOnINTEN_Pn0INTEN_Pos         0                                                       /*!< GPIOE GPIOnINTEN: Pn0INTEN Position     */
#define GPIOE_GPIOnINTEN_Pn0INTEN_Msk         (0x01UL << GPIOE_GPIOnINTEN_Pn0INTEN_Pos)               /*!< GPIOE GPIOnINTEN: Pn0INTEN Mask         */
#define GPIOE_GPIOnINTEN_Pn1INTEN_Pos         1                                                       /*!< GPIOE GPIOnINTEN: Pn1INTEN Position     */
#define GPIOE_GPIOnINTEN_Pn1INTEN_Msk         (0x01UL << GPIOE_GPIOnINTEN_Pn1INTEN_Pos)               /*!< GPIOE GPIOnINTEN: Pn1INTEN Mask         */
#define GPIOE_GPIOnINTEN_Pn2INTEN_Pos         2                                                       /*!< GPIOE GPIOnINTEN: Pn2INTEN Position     */
#define GPIOE_GPIOnINTEN_Pn2INTEN_Msk         (0x01UL << GPIOE_GPIOnINTEN_Pn2INTEN_Pos)               /*!< GPIOE GPIOnINTEN: Pn2INTEN Mask         */
#define GPIOE_GPIOnINTEN_Pn3INTEN_Pos         3                                                       /*!< GPIOE GPIOnINTEN: Pn3INTEN Position     */
#define GPIOE_GPIOnINTEN_Pn3INTEN_Msk         (0x01UL << GPIOE_GPIOnINTEN_Pn3INTEN_Pos)               /*!< GPIOE GPIOnINTEN: Pn3INTEN Mask         */
#define GPIOE_GPIOnINTEN_Pn4INTEN_Pos         4                                                       /*!< GPIOE GPIOnINTEN: Pn4INTEN Position     */
#define GPIOE_GPIOnINTEN_Pn4INTEN_Msk         (0x01UL << GPIOE_GPIOnINTEN_Pn4INTEN_Pos)               /*!< GPIOE GPIOnINTEN: Pn4INTEN Mask         */
#define GPIOE_GPIOnINTEN_Pn5INTEN_Pos         5                                                       /*!< GPIOE GPIOnINTEN: Pn5INTEN Position     */
#define GPIOE_GPIOnINTEN_Pn5INTEN_Msk         (0x01UL << GPIOE_GPIOnINTEN_Pn5INTEN_Pos)               /*!< GPIOE GPIOnINTEN: Pn5INTEN Mask         */
#define GPIOE_GPIOnINTEN_Pn6INTEN_Pos         6                                                       /*!< GPIOE GPIOnINTEN: Pn6INTEN Position     */
#define GPIOE_GPIOnINTEN_Pn6INTEN_Msk         (0x01UL << GPIOE_GPIOnINTEN_Pn6INTEN_Pos)               /*!< GPIOE GPIOnINTEN: Pn6INTEN Mask         */
#define GPIOE_GPIOnINTEN_Pn7INTEN_Pos         7                                                       /*!< GPIOE GPIOnINTEN: Pn7INTEN Position     */
#define GPIOE_GPIOnINTEN_Pn7INTEN_Msk         (0x01UL << GPIOE_GPIOnINTEN_Pn7INTEN_Pos)               /*!< GPIOE GPIOnINTEN: Pn7INTEN Mask         */

/* -------------------------------  GPIOE_GPIOnINT  ------------------------------- */
#define GPIOE_GPIOnINT_Pn0INT_Pos             0                                                       /*!< GPIOE GPIOnINT: Pn0INT Position         */
#define GPIOE_GPIOnINT_Pn0INT_Msk             (0x01UL << GPIOE_GPIOnINT_Pn0INT_Pos)                   /*!< GPIOE GPIOnINT: Pn0INT Mask             */
#define GPIOE_GPIOnINT_Pn1INT_Pos             1                                                       /*!< GPIOE GPIOnINT: Pn1INT Position         */
#define GPIOE_GPIOnINT_Pn1INT_Msk             (0x01UL << GPIOE_GPIOnINT_Pn1INT_Pos)                   /*!< GPIOE GPIOnINT: Pn1INT Mask             */
#define GPIOE_GPIOnINT_Pn2INT_Pos             2                                                       /*!< GPIOE GPIOnINT: Pn2INT Position         */
#define GPIOE_GPIOnINT_Pn2INT_Msk             (0x01UL << GPIOE_GPIOnINT_Pn2INT_Pos)                   /*!< GPIOE GPIOnINT: Pn2INT Mask             */
#define GPIOE_GPIOnINT_Pn3INT_Pos             3                                                       /*!< GPIOE GPIOnINT: Pn3INT Position         */
#define GPIOE_GPIOnINT_Pn3INT_Msk             (0x01UL << GPIOE_GPIOnINT_Pn3INT_Pos)                   /*!< GPIOE GPIOnINT: Pn3INT Mask             */
#define GPIOE_GPIOnINT_Pn4INT_Pos             4                                                       /*!< GPIOE GPIOnINT: Pn4INT Position         */
#define GPIOE_GPIOnINT_Pn4INT_Msk             (0x01UL << GPIOE_GPIOnINT_Pn4INT_Pos)                   /*!< GPIOE GPIOnINT: Pn4INT Mask             */
#define GPIOE_GPIOnINT_Pn5INT_Pos             5                                                       /*!< GPIOE GPIOnINT: Pn5INT Position         */
#define GPIOE_GPIOnINT_Pn5INT_Msk             (0x01UL << GPIOE_GPIOnINT_Pn5INT_Pos)                   /*!< GPIOE GPIOnINT: Pn5INT Mask             */
#define GPIOE_GPIOnINT_Pn6INT_Pos             6                                                       /*!< GPIOE GPIOnINT: Pn6INT Position         */
#define GPIOE_GPIOnINT_Pn6INT_Msk             (0x01UL << GPIOE_GPIOnINT_Pn6INT_Pos)                   /*!< GPIOE GPIOnINT: Pn6INT Mask             */
#define GPIOE_GPIOnINT_Pn7INT_Pos             7                                                       /*!< GPIOE GPIOnINT: Pn7INT Position         */
#define GPIOE_GPIOnINT_Pn7INT_Msk             (0x01UL << GPIOE_GPIOnINT_Pn7INT_Pos)                   /*!< GPIOE GPIOnINT: Pn7INT Mask             */

/* -------------------------------  GPIOE_GPIOnINTM  ------------------------------ */
#define GPIOE_GPIOnINTM_Pn0INTM_Pos           0                                                       /*!< GPIOE GPIOnINTM: Pn0INTM Position       */
#define GPIOE_GPIOnINTM_Pn0INTM_Msk           (0x01UL << GPIOE_GPIOnINTM_Pn0INTM_Pos)                 /*!< GPIOE GPIOnINTM: Pn0INTM Mask           */
#define GPIOE_GPIOnINTM_Pn1INTM_Pos           1                                                       /*!< GPIOE GPIOnINTM: Pn1INTM Position       */
#define GPIOE_GPIOnINTM_Pn1INTM_Msk           (0x01UL << GPIOE_GPIOnINTM_Pn1INTM_Pos)                 /*!< GPIOE GPIOnINTM: Pn1INTM Mask           */
#define GPIOE_GPIOnINTM_Pn2INTM_Pos           2                                                       /*!< GPIOE GPIOnINTM: Pn2INTM Position       */
#define GPIOE_GPIOnINTM_Pn2INTM_Msk           (0x01UL << GPIOE_GPIOnINTM_Pn2INTM_Pos)                 /*!< GPIOE GPIOnINTM: Pn2INTM Mask           */
#define GPIOE_GPIOnINTM_Pn3INTM_Pos           3                                                       /*!< GPIOE GPIOnINTM: Pn3INTM Position       */
#define GPIOE_GPIOnINTM_Pn3INTM_Msk           (0x01UL << GPIOE_GPIOnINTM_Pn3INTM_Pos)                 /*!< GPIOE GPIOnINTM: Pn3INTM Mask           */
#define GPIOE_GPIOnINTM_Pn4INTM_Pos           4                                                       /*!< GPIOE GPIOnINTM: Pn4INTM Position       */
#define GPIOE_GPIOnINTM_Pn4INTM_Msk           (0x01UL << GPIOE_GPIOnINTM_Pn4INTM_Pos)                 /*!< GPIOE GPIOnINTM: Pn4INTM Mask           */
#define GPIOE_GPIOnINTM_Pn5INTM_Pos           5                                                       /*!< GPIOE GPIOnINTM: Pn5INTM Position       */
#define GPIOE_GPIOnINTM_Pn5INTM_Msk           (0x01UL << GPIOE_GPIOnINTM_Pn5INTM_Pos)                 /*!< GPIOE GPIOnINTM: Pn5INTM Mask           */
#define GPIOE_GPIOnINTM_Pn6INTM_Pos           6                                                       /*!< GPIOE GPIOnINTM: Pn6INTM Position       */
#define GPIOE_GPIOnINTM_Pn6INTM_Msk           (0x01UL << GPIOE_GPIOnINTM_Pn6INTM_Pos)                 /*!< GPIOE GPIOnINTM: Pn6INTM Mask           */
#define GPIOE_GPIOnINTM_Pn7INTM_Pos           7                                                       /*!< GPIOE GPIOnINTM: Pn7INTM Position       */
#define GPIOE_GPIOnINTM_Pn7INTM_Msk           (0x01UL << GPIOE_GPIOnINTM_Pn7INTM_Pos)                 /*!< GPIOE GPIOnINTM: Pn7INTM Mask           */


/* ================================================================================ */
/* ================         struct 'TIMERA' Position & Mask        ================ */
/* ================================================================================ */


/* --------------------------------  TIMERA_TxCTL  -------------------------------- */
#define TIMERA_TxCTL_PRDL_Pos                 0                                                       /*!< TIMERA TxCTL: PRDL Position             */
#define TIMERA_TxCTL_PRDL_Msk                 (0x01UL << TIMERA_TxCTL_PRDL_Pos)                       /*!< TIMERA TxCTL: PRDL Mask                 */
#define TIMERA_TxCTL_CLR_Pos                  2                                                       /*!< TIMERA TxCTL: CLR Position              */
#define TIMERA_TxCTL_CLR_Msk                  (0x01UL << TIMERA_TxCTL_CLR_Pos)                        /*!< TIMERA TxCTL: CLR Mask                  */
#define TIMERA_TxCTL_SS_Pos                   3                                                       /*!< TIMERA TxCTL: SS Position               */
#define TIMERA_TxCTL_SS_Msk                   (0x01UL << TIMERA_TxCTL_SS_Pos)                         /*!< TIMERA TxCTL: SS Mask                   */
#define TIMERA_TxCTL_INT_Pos                  4                                                       /*!< TIMERA TxCTL: INT Position              */
#define TIMERA_TxCTL_INT_Msk                  (0x01UL << TIMERA_TxCTL_INT_Pos)                        /*!< TIMERA TxCTL: INT Mask                  */
#define TIMERA_TxCTL_INTEN_Pos                5                                                       /*!< TIMERA TxCTL: INTEN Position            */
#define TIMERA_TxCTL_INTEN_Msk                (0x01UL << TIMERA_TxCTL_INTEN_Pos)                      /*!< TIMERA TxCTL: INTEN Mask                */
#define TIMERA_TxCTL_CLKDIV_Pos               6                                                       /*!< TIMERA TxCTL: CLKDIV Position           */
#define TIMERA_TxCTL_CLKDIV_Msk               (0x07UL << TIMERA_TxCTL_CLKDIV_Pos)                     /*!< TIMERA TxCTL: CLKDIV Mask               */
#define TIMERA_TxCTL_CLK_Pos                  9                                                       /*!< TIMERA TxCTL: CLK Position              */
#define TIMERA_TxCTL_CLK_Msk                  (0x01UL << TIMERA_TxCTL_CLK_Pos)                        /*!< TIMERA TxCTL: CLK Mask                  */
#define TIMERA_TxCTL_MODE_Pos                 10                                                      /*!< TIMERA TxCTL: MODE Position             */
#define TIMERA_TxCTL_MODE_Msk                 (0x03UL << TIMERA_TxCTL_MODE_Pos)                       /*!< TIMERA TxCTL: MODE Mask                 */
#define TIMERA_TxCTL_DTGCLK_Pos               13                                                      /*!< TIMERA TxCTL: DTGCLK Position           */
#define TIMERA_TxCTL_DTGCLK_Msk               (0x01UL << TIMERA_TxCTL_DTGCLK_Pos)                     /*!< TIMERA TxCTL: DTGCLK Mask               */

/* --------------------------------  TIMERA_TxPRD  -------------------------------- */
#define TIMERA_TxPRD_PERIOD_Pos               0                                                       /*!< TIMERA TxPRD: PERIOD Position           */
#define TIMERA_TxPRD_PERIOD_Msk               (0x0000ffffUL << TIMERA_TxPRD_PERIOD_Pos)               /*!< TIMERA TxPRD: PERIOD Mask               */

/* --------------------------------  TIMERA_TxCTR  -------------------------------- */
#define TIMERA_TxCTR_CTR_Pos                  0                                                       /*!< TIMERA TxCTR: CTR Position              */
#define TIMERA_TxCTR_CTR_Msk                  (0x0000ffffUL << TIMERA_TxCTR_CTR_Pos)                  /*!< TIMERA TxCTR: CTR Mask                  */

/* -------------------------------  TIMERA_TxCC0CTL  ------------------------------ */
#define TIMERA_TxCC0CTL_CCEDG_Pos             0                                                       /*!< TIMERA TxCC0CTL: CCEDG Position         */
#define TIMERA_TxCC0CTL_CCEDG_Msk             (0x03UL << TIMERA_TxCC0CTL_CCEDG_Pos)                   /*!< TIMERA TxCC0CTL: CCEDG Mask             */
#define TIMERA_TxCC0CTL_CCINT_Pos             2                                                       /*!< TIMERA TxCC0CTL: CCINT Position         */
#define TIMERA_TxCC0CTL_CCINT_Msk             (0x01UL << TIMERA_TxCC0CTL_CCINT_Pos)                   /*!< TIMERA TxCC0CTL: CCINT Mask             */
#define TIMERA_TxCC0CTL_CCINTEN_Pos           3                                                       /*!< TIMERA TxCC0CTL: CCINTEN Position       */
#define TIMERA_TxCC0CTL_CCINTEN_Msk           (0x01UL << TIMERA_TxCC0CTL_CCINTEN_Pos)                 /*!< TIMERA TxCC0CTL: CCINTEN Mask           */
#define TIMERA_TxCC0CTL_CCMODE_Pos            4                                                       /*!< TIMERA TxCC0CTL: CCMODE Position        */
#define TIMERA_TxCC0CTL_CCMODE_Msk            (0x01UL << TIMERA_TxCC0CTL_CCMODE_Pos)                  /*!< TIMERA TxCC0CTL: CCMODE Mask            */

/* -------------------------------  TIMERA_TxCC0CTR  ------------------------------ */
#define TIMERA_TxCC0CTR_CCCTR_Pos             0                                                       /*!< TIMERA TxCC0CTR: CCCTR Position         */
#define TIMERA_TxCC0CTR_CCCTR_Msk             (0x0000ffffUL << TIMERA_TxCC0CTR_CCCTR_Pos)             /*!< TIMERA TxCC0CTR: CCCTR Mask             */

/* -------------------------------  TIMERA_TxCC1CTL  ------------------------------ */
#define TIMERA_TxCC1CTL_CCEDG_Pos             0                                                       /*!< TIMERA TxCC1CTL: CCEDG Position         */
#define TIMERA_TxCC1CTL_CCEDG_Msk             (0x03UL << TIMERA_TxCC1CTL_CCEDG_Pos)                   /*!< TIMERA TxCC1CTL: CCEDG Mask             */
#define TIMERA_TxCC1CTL_CCINT_Pos             2                                                       /*!< TIMERA TxCC1CTL: CCINT Position         */
#define TIMERA_TxCC1CTL_CCINT_Msk             (0x01UL << TIMERA_TxCC1CTL_CCINT_Pos)                   /*!< TIMERA TxCC1CTL: CCINT Mask             */
#define TIMERA_TxCC1CTL_CCINTEN_Pos           3                                                       /*!< TIMERA TxCC1CTL: CCINTEN Position       */
#define TIMERA_TxCC1CTL_CCINTEN_Msk           (0x01UL << TIMERA_TxCC1CTL_CCINTEN_Pos)                 /*!< TIMERA TxCC1CTL: CCINTEN Mask           */
#define TIMERA_TxCC1CTL_CCMODE_Pos            4                                                       /*!< TIMERA TxCC1CTL: CCMODE Position        */
#define TIMERA_TxCC1CTL_CCMODE_Msk            (0x01UL << TIMERA_TxCC1CTL_CCMODE_Pos)                  /*!< TIMERA TxCC1CTL: CCMODE Mask            */

/* -------------------------------  TIMERA_TxCC1CTR  ------------------------------ */
#define TIMERA_TxCC1CTR_CCCTR_Pos             0                                                       /*!< TIMERA TxCC1CTR: CCCTR Position         */
#define TIMERA_TxCC1CTR_CCCTR_Msk             (0x0000ffffUL << TIMERA_TxCC1CTR_CCCTR_Pos)             /*!< TIMERA TxCC1CTR: CCCTR Mask             */

/* -------------------------------  TIMERA_TxCC2CTL  ------------------------------ */
#define TIMERA_TxCC2CTL_CCEDG_Pos             0                                                       /*!< TIMERA TxCC2CTL: CCEDG Position         */
#define TIMERA_TxCC2CTL_CCEDG_Msk             (0x03UL << TIMERA_TxCC2CTL_CCEDG_Pos)                   /*!< TIMERA TxCC2CTL: CCEDG Mask             */
#define TIMERA_TxCC2CTL_CCINT_Pos             2                                                       /*!< TIMERA TxCC2CTL: CCINT Position         */
#define TIMERA_TxCC2CTL_CCINT_Msk             (0x01UL << TIMERA_TxCC2CTL_CCINT_Pos)                   /*!< TIMERA TxCC2CTL: CCINT Mask             */
#define TIMERA_TxCC2CTL_CCINTEN_Pos           3                                                       /*!< TIMERA TxCC2CTL: CCINTEN Position       */
#define TIMERA_TxCC2CTL_CCINTEN_Msk           (0x01UL << TIMERA_TxCC2CTL_CCINTEN_Pos)                 /*!< TIMERA TxCC2CTL: CCINTEN Mask           */
#define TIMERA_TxCC2CTL_CCMODE_Pos            4                                                       /*!< TIMERA TxCC2CTL: CCMODE Position        */
#define TIMERA_TxCC2CTL_CCMODE_Msk            (0x01UL << TIMERA_TxCC2CTL_CCMODE_Pos)                  /*!< TIMERA TxCC2CTL: CCMODE Mask            */

/* -------------------------------  TIMERA_TxCC2CTR  ------------------------------ */
#define TIMERA_TxCC2CTR_CCCTR_Pos             0                                                       /*!< TIMERA TxCC2CTR: CCCTR Position         */
#define TIMERA_TxCC2CTR_CCCTR_Msk             (0x0000ffffUL << TIMERA_TxCC2CTR_CCCTR_Pos)             /*!< TIMERA TxCC2CTR: CCCTR Mask             */

/* -------------------------------  TIMERA_TxCC3CTL  ------------------------------ */
#define TIMERA_TxCC3CTL_CCEDG_Pos             0                                                       /*!< TIMERA TxCC3CTL: CCEDG Position         */
#define TIMERA_TxCC3CTL_CCEDG_Msk             (0x03UL << TIMERA_TxCC3CTL_CCEDG_Pos)                   /*!< TIMERA TxCC3CTL: CCEDG Mask             */
#define TIMERA_TxCC3CTL_CCINT_Pos             2                                                       /*!< TIMERA TxCC3CTL: CCINT Position         */
#define TIMERA_TxCC3CTL_CCINT_Msk             (0x01UL << TIMERA_TxCC3CTL_CCINT_Pos)                   /*!< TIMERA TxCC3CTL: CCINT Mask             */
#define TIMERA_TxCC3CTL_CCINTEN_Pos           3                                                       /*!< TIMERA TxCC3CTL: CCINTEN Position       */
#define TIMERA_TxCC3CTL_CCINTEN_Msk           (0x01UL << TIMERA_TxCC3CTL_CCINTEN_Pos)                 /*!< TIMERA TxCC3CTL: CCINTEN Mask           */
#define TIMERA_TxCC3CTL_CCMODE_Pos            4                                                       /*!< TIMERA TxCC3CTL: CCMODE Position        */
#define TIMERA_TxCC3CTL_CCMODE_Msk            (0x01UL << TIMERA_TxCC3CTL_CCMODE_Pos)                  /*!< TIMERA TxCC3CTL: CCMODE Mask            */

/* -------------------------------  TIMERA_TxCC3CTR  ------------------------------ */
#define TIMERA_TxCC3CTR_CCCTR_Pos             0                                                       /*!< TIMERA TxCC3CTR: CCCTR Position         */
#define TIMERA_TxCC3CTR_CCCTR_Msk             (0x0000ffffUL << TIMERA_TxCC3CTR_CCCTR_Pos)             /*!< TIMERA TxCC3CTR: CCCTR Mask             */

/* -------------------------------  TIMERA_TxCC4CTL  ------------------------------ */
#define TIMERA_TxCC4CTL_CCEDG_Pos             0                                                       /*!< TIMERA TxCC4CTL: CCEDG Position         */
#define TIMERA_TxCC4CTL_CCEDG_Msk             (0x03UL << TIMERA_TxCC4CTL_CCEDG_Pos)                   /*!< TIMERA TxCC4CTL: CCEDG Mask             */
#define TIMERA_TxCC4CTL_CCINT_Pos             2                                                       /*!< TIMERA TxCC4CTL: CCINT Position         */
#define TIMERA_TxCC4CTL_CCINT_Msk             (0x01UL << TIMERA_TxCC4CTL_CCINT_Pos)                   /*!< TIMERA TxCC4CTL: CCINT Mask             */
#define TIMERA_TxCC4CTL_CCINTEN_Pos           3                                                       /*!< TIMERA TxCC4CTL: CCINTEN Position       */
#define TIMERA_TxCC4CTL_CCINTEN_Msk           (0x01UL << TIMERA_TxCC4CTL_CCINTEN_Pos)                 /*!< TIMERA TxCC4CTL: CCINTEN Mask           */
#define TIMERA_TxCC4CTL_CCMODE_Pos            4                                                       /*!< TIMERA TxCC4CTL: CCMODE Position        */
#define TIMERA_TxCC4CTL_CCMODE_Msk            (0x01UL << TIMERA_TxCC4CTL_CCMODE_Pos)                  /*!< TIMERA TxCC4CTL: CCMODE Mask            */

/* -------------------------------  TIMERA_TxCC4CTR  ------------------------------ */
#define TIMERA_TxCC4CTR_CCCTR_Pos             0                                                       /*!< TIMERA TxCC4CTR: CCCTR Position         */
#define TIMERA_TxCC4CTR_CCCTR_Msk             (0x0000ffffUL << TIMERA_TxCC4CTR_CCCTR_Pos)             /*!< TIMERA TxCC4CTR: CCCTR Mask             */

/* -------------------------------  TIMERA_TxCC5CTL  ------------------------------ */
#define TIMERA_TxCC5CTL_CCEDG_Pos             0                                                       /*!< TIMERA TxCC5CTL: CCEDG Position         */
#define TIMERA_TxCC5CTL_CCEDG_Msk             (0x03UL << TIMERA_TxCC5CTL_CCEDG_Pos)                   /*!< TIMERA TxCC5CTL: CCEDG Mask             */
#define TIMERA_TxCC5CTL_CCINT_Pos             2                                                       /*!< TIMERA TxCC5CTL: CCINT Position         */
#define TIMERA_TxCC5CTL_CCINT_Msk             (0x01UL << TIMERA_TxCC5CTL_CCINT_Pos)                   /*!< TIMERA TxCC5CTL: CCINT Mask             */
#define TIMERA_TxCC5CTL_CCINTEN_Pos           3                                                       /*!< TIMERA TxCC5CTL: CCINTEN Position       */
#define TIMERA_TxCC5CTL_CCINTEN_Msk           (0x01UL << TIMERA_TxCC5CTL_CCINTEN_Pos)                 /*!< TIMERA TxCC5CTL: CCINTEN Mask           */
#define TIMERA_TxCC5CTL_CCMODE_Pos            4                                                       /*!< TIMERA TxCC5CTL: CCMODE Position        */
#define TIMERA_TxCC5CTL_CCMODE_Msk            (0x01UL << TIMERA_TxCC5CTL_CCMODE_Pos)                  /*!< TIMERA TxCC5CTL: CCMODE Mask            */

/* -------------------------------  TIMERA_TxCC5CTR  ------------------------------ */
#define TIMERA_TxCC5CTR_CCCTR_Pos             0                                                       /*!< TIMERA TxCC5CTR: CCCTR Position         */
#define TIMERA_TxCC5CTR_CCCTR_Msk             (0x0000ffffUL << TIMERA_TxCC5CTR_CCCTR_Pos)             /*!< TIMERA TxCC5CTR: CCCTR Mask             */

/* -------------------------------  TIMERA_TxCC6CTL  ------------------------------ */
#define TIMERA_TxCC6CTL_CCEDG_Pos             0                                                       /*!< TIMERA TxCC6CTL: CCEDG Position         */
#define TIMERA_TxCC6CTL_CCEDG_Msk             (0x03UL << TIMERA_TxCC6CTL_CCEDG_Pos)                   /*!< TIMERA TxCC6CTL: CCEDG Mask             */
#define TIMERA_TxCC6CTL_CCINT_Pos             2                                                       /*!< TIMERA TxCC6CTL: CCINT Position         */
#define TIMERA_TxCC6CTL_CCINT_Msk             (0x01UL << TIMERA_TxCC6CTL_CCINT_Pos)                   /*!< TIMERA TxCC6CTL: CCINT Mask             */
#define TIMERA_TxCC6CTL_CCINTEN_Pos           3                                                       /*!< TIMERA TxCC6CTL: CCINTEN Position       */
#define TIMERA_TxCC6CTL_CCINTEN_Msk           (0x01UL << TIMERA_TxCC6CTL_CCINTEN_Pos)                 /*!< TIMERA TxCC6CTL: CCINTEN Mask           */
#define TIMERA_TxCC6CTL_CCMODE_Pos            4                                                       /*!< TIMERA TxCC6CTL: CCMODE Position        */
#define TIMERA_TxCC6CTL_CCMODE_Msk            (0x01UL << TIMERA_TxCC6CTL_CCMODE_Pos)                  /*!< TIMERA TxCC6CTL: CCMODE Mask            */

/* -------------------------------  TIMERA_TxCC6CTR  ------------------------------ */
#define TIMERA_TxCC6CTR_CCCTR_Pos             0                                                       /*!< TIMERA TxCC6CTR: CCCTR Position         */
#define TIMERA_TxCC6CTR_CCCTR_Msk             (0x0000ffffUL << TIMERA_TxCC6CTR_CCCTR_Pos)             /*!< TIMERA TxCC6CTR: CCCTR Mask             */

/* -------------------------------  TIMERA_TxCC7CTL  ------------------------------ */
#define TIMERA_TxCC7CTL_CCEDG_Pos             0                                                       /*!< TIMERA TxCC7CTL: CCEDG Position         */
#define TIMERA_TxCC7CTL_CCEDG_Msk             (0x03UL << TIMERA_TxCC7CTL_CCEDG_Pos)                   /*!< TIMERA TxCC7CTL: CCEDG Mask             */
#define TIMERA_TxCC7CTL_CCINT_Pos             2                                                       /*!< TIMERA TxCC7CTL: CCINT Position         */
#define TIMERA_TxCC7CTL_CCINT_Msk             (0x01UL << TIMERA_TxCC7CTL_CCINT_Pos)                   /*!< TIMERA TxCC7CTL: CCINT Mask             */
#define TIMERA_TxCC7CTL_CCINTEN_Pos           3                                                       /*!< TIMERA TxCC7CTL: CCINTEN Position       */
#define TIMERA_TxCC7CTL_CCINTEN_Msk           (0x01UL << TIMERA_TxCC7CTL_CCINTEN_Pos)                 /*!< TIMERA TxCC7CTL: CCINTEN Mask           */
#define TIMERA_TxCC7CTL_CCMODE_Pos            4                                                       /*!< TIMERA TxCC7CTL: CCMODE Position        */
#define TIMERA_TxCC7CTL_CCMODE_Msk            (0x01UL << TIMERA_TxCC7CTL_CCMODE_Pos)                  /*!< TIMERA TxCC7CTL: CCMODE Mask            */

/* -------------------------------  TIMERA_TxCC7CTR  ------------------------------ */
#define TIMERA_TxCC7CTR_CCCTR_Pos             0                                                       /*!< TIMERA TxCC7CTR: CCCTR Position         */
#define TIMERA_TxCC7CTR_CCCTR_Msk             (0x0000ffffUL << TIMERA_TxCC7CTR_CCCTR_Pos)             /*!< TIMERA TxCC7CTR: CCCTR Mask             */

/* -------------------------------  TIMERA_DTGA0CTL  ------------------------------ */
#define TIMERA_DTGA0CTL_INVLS_Pos             4                                                       /*!< TIMERA DTGA0CTL: INVLS Position         */
#define TIMERA_DTGA0CTL_INVLS_Msk             (0x01UL << TIMERA_DTGA0CTL_INVLS_Pos)                   /*!< TIMERA DTGA0CTL: INVLS Mask             */
#define TIMERA_DTGA0CTL_INVHS_Pos             5                                                       /*!< TIMERA DTGA0CTL: INVHS Position         */
#define TIMERA_DTGA0CTL_INVHS_Msk             (0x01UL << TIMERA_DTGA0CTL_INVHS_Pos)                   /*!< TIMERA DTGA0CTL: INVHS Mask             */
#define TIMERA_DTGA0CTL_OTP_Pos               6                                                       /*!< TIMERA DTGA0CTL: OTP Position           */
#define TIMERA_DTGA0CTL_OTP_Msk               (0x01UL << TIMERA_DTGA0CTL_OTP_Pos)                     /*!< TIMERA DTGA0CTL: OTP Mask               */
#define TIMERA_DTGA0CTL_BYPASS_Pos            7                                                       /*!< TIMERA DTGA0CTL: BYPASS Position        */
#define TIMERA_DTGA0CTL_BYPASS_Msk            (0x01UL << TIMERA_DTGA0CTL_BYPASS_Pos)                  /*!< TIMERA DTGA0CTL: BYPASS Mask            */

/* -------------------------------  TIMERA_DTGA0LED  ------------------------------ */
#define TIMERA_DTGA0LED_LED_Pos               0                                                       /*!< TIMERA DTGA0LED: LED Position           */
#define TIMERA_DTGA0LED_LED_Msk               (0x00000fffUL << TIMERA_DTGA0LED_LED_Pos)               /*!< TIMERA DTGA0LED: LED Mask               */

/* -------------------------------  TIMERA_DTGA0TED  ------------------------------ */
#define TIMERA_DTGA0TED_TED_Pos               0                                                       /*!< TIMERA DTGA0TED: TED Position           */
#define TIMERA_DTGA0TED_TED_Msk               (0x00000fffUL << TIMERA_DTGA0TED_TED_Pos)               /*!< TIMERA DTGA0TED: TED Mask               */

/* -------------------------------  TIMERA_DTGA1CTL  ------------------------------ */
#define TIMERA_DTGA1CTL_INVLS_Pos             4                                                       /*!< TIMERA DTGA1CTL: INVLS Position         */
#define TIMERA_DTGA1CTL_INVLS_Msk             (0x01UL << TIMERA_DTGA1CTL_INVLS_Pos)                   /*!< TIMERA DTGA1CTL: INVLS Mask             */
#define TIMERA_DTGA1CTL_INVHS_Pos             5                                                       /*!< TIMERA DTGA1CTL: INVHS Position         */
#define TIMERA_DTGA1CTL_INVHS_Msk             (0x01UL << TIMERA_DTGA1CTL_INVHS_Pos)                   /*!< TIMERA DTGA1CTL: INVHS Mask             */
#define TIMERA_DTGA1CTL_OTP_Pos               6                                                       /*!< TIMERA DTGA1CTL: OTP Position           */
#define TIMERA_DTGA1CTL_OTP_Msk               (0x01UL << TIMERA_DTGA1CTL_OTP_Pos)                     /*!< TIMERA DTGA1CTL: OTP Mask               */
#define TIMERA_DTGA1CTL_BYPASS_Pos            7                                                       /*!< TIMERA DTGA1CTL: BYPASS Position        */
#define TIMERA_DTGA1CTL_BYPASS_Msk            (0x01UL << TIMERA_DTGA1CTL_BYPASS_Pos)                  /*!< TIMERA DTGA1CTL: BYPASS Mask            */

/* -------------------------------  TIMERA_DTGA1LED  ------------------------------ */
#define TIMERA_DTGA1LED_LED_Pos               0                                                       /*!< TIMERA DTGA1LED: LED Position           */
#define TIMERA_DTGA1LED_LED_Msk               (0x00000fffUL << TIMERA_DTGA1LED_LED_Pos)               /*!< TIMERA DTGA1LED: LED Mask               */

/* -------------------------------  TIMERA_DTGA1TED  ------------------------------ */
#define TIMERA_DTGA1TED_TED_Pos               0                                                       /*!< TIMERA DTGA1TED: TED Position           */
#define TIMERA_DTGA1TED_TED_Msk               (0x00000fffUL << TIMERA_DTGA1TED_TED_Pos)               /*!< TIMERA DTGA1TED: TED Mask               */

/* -------------------------------  TIMERA_DTGA2CTL  ------------------------------ */
#define TIMERA_DTGA2CTL_INVLS_Pos             4                                                       /*!< TIMERA DTGA2CTL: INVLS Position         */
#define TIMERA_DTGA2CTL_INVLS_Msk             (0x01UL << TIMERA_DTGA2CTL_INVLS_Pos)                   /*!< TIMERA DTGA2CTL: INVLS Mask             */
#define TIMERA_DTGA2CTL_INVHS_Pos             5                                                       /*!< TIMERA DTGA2CTL: INVHS Position         */
#define TIMERA_DTGA2CTL_INVHS_Msk             (0x01UL << TIMERA_DTGA2CTL_INVHS_Pos)                   /*!< TIMERA DTGA2CTL: INVHS Mask             */
#define TIMERA_DTGA2CTL_OTP_Pos               6                                                       /*!< TIMERA DTGA2CTL: OTP Position           */
#define TIMERA_DTGA2CTL_OTP_Msk               (0x01UL << TIMERA_DTGA2CTL_OTP_Pos)                     /*!< TIMERA DTGA2CTL: OTP Mask               */
#define TIMERA_DTGA2CTL_BYPASS_Pos            7                                                       /*!< TIMERA DTGA2CTL: BYPASS Position        */
#define TIMERA_DTGA2CTL_BYPASS_Msk            (0x01UL << TIMERA_DTGA2CTL_BYPASS_Pos)                  /*!< TIMERA DTGA2CTL: BYPASS Mask            */

/* -------------------------------  TIMERA_DTGA2LED  ------------------------------ */
#define TIMERA_DTGA2LED_LED_Pos               0                                                       /*!< TIMERA DTGA2LED: LED Position           */
#define TIMERA_DTGA2LED_LED_Msk               (0x00000fffUL << TIMERA_DTGA2LED_LED_Pos)               /*!< TIMERA DTGA2LED: LED Mask               */

/* -------------------------------  TIMERA_DTGA2TED  ------------------------------ */
#define TIMERA_DTGA2TED_TED_Pos               0                                                       /*!< TIMERA DTGA2TED: TED Position           */
#define TIMERA_DTGA2TED_TED_Msk               (0x00000fffUL << TIMERA_DTGA2TED_TED_Pos)               /*!< TIMERA DTGA2TED: TED Mask               */

/* -------------------------------  TIMERA_DTGA3CTL  ------------------------------ */
#define TIMERA_DTGA3CTL_INVLS_Pos             4                                                       /*!< TIMERA DTGA3CTL: INVLS Position         */
#define TIMERA_DTGA3CTL_INVLS_Msk             (0x01UL << TIMERA_DTGA3CTL_INVLS_Pos)                   /*!< TIMERA DTGA3CTL: INVLS Mask             */
#define TIMERA_DTGA3CTL_INVHS_Pos             5                                                       /*!< TIMERA DTGA3CTL: INVHS Position         */
#define TIMERA_DTGA3CTL_INVHS_Msk             (0x01UL << TIMERA_DTGA3CTL_INVHS_Pos)                   /*!< TIMERA DTGA3CTL: INVHS Mask             */
#define TIMERA_DTGA3CTL_OTP_Pos               6                                                       /*!< TIMERA DTGA3CTL: OTP Position           */
#define TIMERA_DTGA3CTL_OTP_Msk               (0x01UL << TIMERA_DTGA3CTL_OTP_Pos)                     /*!< TIMERA DTGA3CTL: OTP Mask               */
#define TIMERA_DTGA3CTL_BYPASS_Pos            7                                                       /*!< TIMERA DTGA3CTL: BYPASS Position        */
#define TIMERA_DTGA3CTL_BYPASS_Msk            (0x01UL << TIMERA_DTGA3CTL_BYPASS_Pos)                  /*!< TIMERA DTGA3CTL: BYPASS Mask            */

/* -------------------------------  TIMERA_DTGA3LED  ------------------------------ */
#define TIMERA_DTGA3LED_LED_Pos               0                                                       /*!< TIMERA DTGA3LED: LED Position           */
#define TIMERA_DTGA3LED_LED_Msk               (0x00000fffUL << TIMERA_DTGA3LED_LED_Pos)               /*!< TIMERA DTGA3LED: LED Mask               */

/* -------------------------------  TIMERA_DTGA3TED  ------------------------------ */
#define TIMERA_DTGA3TED_TED_Pos               0                                                       /*!< TIMERA DTGA3TED: TED Position           */
#define TIMERA_DTGA3TED_TED_Msk               (0x00000fffUL << TIMERA_DTGA3TED_TED_Pos)               /*!< TIMERA DTGA3TED: TED Mask               */


/* ================================================================================ */
/* ================         struct 'TIMERB' Position & Mask        ================ */
/* ================================================================================ */


/* --------------------------------  TIMERB_TxCTL  -------------------------------- */
#define TIMERB_TxCTL_PRDL_Pos                 0                                                       /*!< TIMERB TxCTL: PRDL Position             */
#define TIMERB_TxCTL_PRDL_Msk                 (0x01UL << TIMERB_TxCTL_PRDL_Pos)                       /*!< TIMERB TxCTL: PRDL Mask                 */
#define TIMERB_TxCTL_CLR_Pos                  2                                                       /*!< TIMERB TxCTL: CLR Position              */
#define TIMERB_TxCTL_CLR_Msk                  (0x01UL << TIMERB_TxCTL_CLR_Pos)                        /*!< TIMERB TxCTL: CLR Mask                  */
#define TIMERB_TxCTL_SS_Pos                   3                                                       /*!< TIMERB TxCTL: SS Position               */
#define TIMERB_TxCTL_SS_Msk                   (0x01UL << TIMERB_TxCTL_SS_Pos)                         /*!< TIMERB TxCTL: SS Mask                   */
#define TIMERB_TxCTL_INT_Pos                  4                                                       /*!< TIMERB TxCTL: INT Position              */
#define TIMERB_TxCTL_INT_Msk                  (0x01UL << TIMERB_TxCTL_INT_Pos)                        /*!< TIMERB TxCTL: INT Mask                  */
#define TIMERB_TxCTL_INTEN_Pos                5                                                       /*!< TIMERB TxCTL: INTEN Position            */
#define TIMERB_TxCTL_INTEN_Msk                (0x01UL << TIMERB_TxCTL_INTEN_Pos)                      /*!< TIMERB TxCTL: INTEN Mask                */
#define TIMERB_TxCTL_CLKDIV_Pos               6                                                       /*!< TIMERB TxCTL: CLKDIV Position           */
#define TIMERB_TxCTL_CLKDIV_Msk               (0x07UL << TIMERB_TxCTL_CLKDIV_Pos)                     /*!< TIMERB TxCTL: CLKDIV Mask               */
#define TIMERB_TxCTL_CLK_Pos                  9                                                       /*!< TIMERB TxCTL: CLK Position              */
#define TIMERB_TxCTL_CLK_Msk                  (0x01UL << TIMERB_TxCTL_CLK_Pos)                        /*!< TIMERB TxCTL: CLK Mask                  */
#define TIMERB_TxCTL_MODE_Pos                 10                                                      /*!< TIMERB TxCTL: MODE Position             */
#define TIMERB_TxCTL_MODE_Msk                 (0x03UL << TIMERB_TxCTL_MODE_Pos)                       /*!< TIMERB TxCTL: MODE Mask                 */
#define TIMERB_TxCTL_DTGCLK_Pos               13                                                      /*!< TIMERB TxCTL: DTGCLK Position           */
#define TIMERB_TxCTL_DTGCLK_Msk               (0x01UL << TIMERB_TxCTL_DTGCLK_Pos)                     /*!< TIMERB TxCTL: DTGCLK Mask               */

/* --------------------------------  TIMERB_TxPRD  -------------------------------- */
#define TIMERB_TxPRD_PERIOD_Pos               0                                                       /*!< TIMERB TxPRD: PERIOD Position           */
#define TIMERB_TxPRD_PERIOD_Msk               (0x0000ffffUL << TIMERB_TxPRD_PERIOD_Pos)               /*!< TIMERB TxPRD: PERIOD Mask               */

/* --------------------------------  TIMERB_TxCTR  -------------------------------- */
#define TIMERB_TxCTR_CTR_Pos                  0                                                       /*!< TIMERB TxCTR: CTR Position              */
#define TIMERB_TxCTR_CTR_Msk                  (0x0000ffffUL << TIMERB_TxCTR_CTR_Pos)                  /*!< TIMERB TxCTR: CTR Mask                  */

/* -------------------------------  TIMERB_TxCC0CTL  ------------------------------ */
#define TIMERB_TxCC0CTL_CCEDG_Pos             0                                                       /*!< TIMERB TxCC0CTL: CCEDG Position         */
#define TIMERB_TxCC0CTL_CCEDG_Msk             (0x03UL << TIMERB_TxCC0CTL_CCEDG_Pos)                   /*!< TIMERB TxCC0CTL: CCEDG Mask             */
#define TIMERB_TxCC0CTL_CCINT_Pos             2                                                       /*!< TIMERB TxCC0CTL: CCINT Position         */
#define TIMERB_TxCC0CTL_CCINT_Msk             (0x01UL << TIMERB_TxCC0CTL_CCINT_Pos)                   /*!< TIMERB TxCC0CTL: CCINT Mask             */
#define TIMERB_TxCC0CTL_CCINTEN_Pos           3                                                       /*!< TIMERB TxCC0CTL: CCINTEN Position       */
#define TIMERB_TxCC0CTL_CCINTEN_Msk           (0x01UL << TIMERB_TxCC0CTL_CCINTEN_Pos)                 /*!< TIMERB TxCC0CTL: CCINTEN Mask           */
#define TIMERB_TxCC0CTL_CCMODE_Pos            4                                                       /*!< TIMERB TxCC0CTL: CCMODE Position        */
#define TIMERB_TxCC0CTL_CCMODE_Msk            (0x01UL << TIMERB_TxCC0CTL_CCMODE_Pos)                  /*!< TIMERB TxCC0CTL: CCMODE Mask            */

/* -------------------------------  TIMERB_TxCC0CTR  ------------------------------ */
#define TIMERB_TxCC0CTR_CCCTR_Pos             0                                                       /*!< TIMERB TxCC0CTR: CCCTR Position         */
#define TIMERB_TxCC0CTR_CCCTR_Msk             (0x0000ffffUL << TIMERB_TxCC0CTR_CCCTR_Pos)             /*!< TIMERB TxCC0CTR: CCCTR Mask             */

/* -------------------------------  TIMERB_TxCC1CTL  ------------------------------ */
#define TIMERB_TxCC1CTL_CCEDG_Pos             0                                                       /*!< TIMERB TxCC1CTL: CCEDG Position         */
#define TIMERB_TxCC1CTL_CCEDG_Msk             (0x03UL << TIMERB_TxCC1CTL_CCEDG_Pos)                   /*!< TIMERB TxCC1CTL: CCEDG Mask             */
#define TIMERB_TxCC1CTL_CCINT_Pos             2                                                       /*!< TIMERB TxCC1CTL: CCINT Position         */
#define TIMERB_TxCC1CTL_CCINT_Msk             (0x01UL << TIMERB_TxCC1CTL_CCINT_Pos)                   /*!< TIMERB TxCC1CTL: CCINT Mask             */
#define TIMERB_TxCC1CTL_CCINTEN_Pos           3                                                       /*!< TIMERB TxCC1CTL: CCINTEN Position       */
#define TIMERB_TxCC1CTL_CCINTEN_Msk           (0x01UL << TIMERB_TxCC1CTL_CCINTEN_Pos)                 /*!< TIMERB TxCC1CTL: CCINTEN Mask           */
#define TIMERB_TxCC1CTL_CCMODE_Pos            4                                                       /*!< TIMERB TxCC1CTL: CCMODE Position        */
#define TIMERB_TxCC1CTL_CCMODE_Msk            (0x01UL << TIMERB_TxCC1CTL_CCMODE_Pos)                  /*!< TIMERB TxCC1CTL: CCMODE Mask            */

/* -------------------------------  TIMERB_TxCC1CTR  ------------------------------ */
#define TIMERB_TxCC1CTR_CCCTR_Pos             0                                                       /*!< TIMERB TxCC1CTR: CCCTR Position         */
#define TIMERB_TxCC1CTR_CCCTR_Msk             (0x0000ffffUL << TIMERB_TxCC1CTR_CCCTR_Pos)             /*!< TIMERB TxCC1CTR: CCCTR Mask             */

/* -------------------------------  TIMERB_TxCC2CTL  ------------------------------ */
#define TIMERB_TxCC2CTL_CCEDG_Pos             0                                                       /*!< TIMERB TxCC2CTL: CCEDG Position         */
#define TIMERB_TxCC2CTL_CCEDG_Msk             (0x03UL << TIMERB_TxCC2CTL_CCEDG_Pos)                   /*!< TIMERB TxCC2CTL: CCEDG Mask             */
#define TIMERB_TxCC2CTL_CCINT_Pos             2                                                       /*!< TIMERB TxCC2CTL: CCINT Position         */
#define TIMERB_TxCC2CTL_CCINT_Msk             (0x01UL << TIMERB_TxCC2CTL_CCINT_Pos)                   /*!< TIMERB TxCC2CTL: CCINT Mask             */
#define TIMERB_TxCC2CTL_CCINTEN_Pos           3                                                       /*!< TIMERB TxCC2CTL: CCINTEN Position       */
#define TIMERB_TxCC2CTL_CCINTEN_Msk           (0x01UL << TIMERB_TxCC2CTL_CCINTEN_Pos)                 /*!< TIMERB TxCC2CTL: CCINTEN Mask           */
#define TIMERB_TxCC2CTL_CCMODE_Pos            4                                                       /*!< TIMERB TxCC2CTL: CCMODE Position        */
#define TIMERB_TxCC2CTL_CCMODE_Msk            (0x01UL << TIMERB_TxCC2CTL_CCMODE_Pos)                  /*!< TIMERB TxCC2CTL: CCMODE Mask            */

/* -------------------------------  TIMERB_TxCC2CTR  ------------------------------ */
#define TIMERB_TxCC2CTR_CCCTR_Pos             0                                                       /*!< TIMERB TxCC2CTR: CCCTR Position         */
#define TIMERB_TxCC2CTR_CCCTR_Msk             (0x0000ffffUL << TIMERB_TxCC2CTR_CCCTR_Pos)             /*!< TIMERB TxCC2CTR: CCCTR Mask             */

/* -------------------------------  TIMERB_TxCC3CTL  ------------------------------ */
#define TIMERB_TxCC3CTL_CCEDG_Pos             0                                                       /*!< TIMERB TxCC3CTL: CCEDG Position         */
#define TIMERB_TxCC3CTL_CCEDG_Msk             (0x03UL << TIMERB_TxCC3CTL_CCEDG_Pos)                   /*!< TIMERB TxCC3CTL: CCEDG Mask             */
#define TIMERB_TxCC3CTL_CCINT_Pos             2                                                       /*!< TIMERB TxCC3CTL: CCINT Position         */
#define TIMERB_TxCC3CTL_CCINT_Msk             (0x01UL << TIMERB_TxCC3CTL_CCINT_Pos)                   /*!< TIMERB TxCC3CTL: CCINT Mask             */
#define TIMERB_TxCC3CTL_CCINTEN_Pos           3                                                       /*!< TIMERB TxCC3CTL: CCINTEN Position       */
#define TIMERB_TxCC3CTL_CCINTEN_Msk           (0x01UL << TIMERB_TxCC3CTL_CCINTEN_Pos)                 /*!< TIMERB TxCC3CTL: CCINTEN Mask           */
#define TIMERB_TxCC3CTL_CCMODE_Pos            4                                                       /*!< TIMERB TxCC3CTL: CCMODE Position        */
#define TIMERB_TxCC3CTL_CCMODE_Msk            (0x01UL << TIMERB_TxCC3CTL_CCMODE_Pos)                  /*!< TIMERB TxCC3CTL: CCMODE Mask            */

/* -------------------------------  TIMERB_TxCC3CTR  ------------------------------ */
#define TIMERB_TxCC3CTR_CCCTR_Pos             0                                                       /*!< TIMERB TxCC3CTR: CCCTR Position         */
#define TIMERB_TxCC3CTR_CCCTR_Msk             (0x0000ffffUL << TIMERB_TxCC3CTR_CCCTR_Pos)             /*!< TIMERB TxCC3CTR: CCCTR Mask             */

/* -------------------------------  TIMERB_DTGB0CTL  ------------------------------ */
#define TIMERB_DTGB0CTL_INVLS_Pos             4                                                       /*!< TIMERB DTGB0CTL: INVLS Position         */
#define TIMERB_DTGB0CTL_INVLS_Msk             (0x01UL << TIMERB_DTGB0CTL_INVLS_Pos)                   /*!< TIMERB DTGB0CTL: INVLS Mask             */
#define TIMERB_DTGB0CTL_INVHS_Pos             5                                                       /*!< TIMERB DTGB0CTL: INVHS Position         */
#define TIMERB_DTGB0CTL_INVHS_Msk             (0x01UL << TIMERB_DTGB0CTL_INVHS_Pos)                   /*!< TIMERB DTGB0CTL: INVHS Mask             */
#define TIMERB_DTGB0CTL_OTP_Pos               6                                                       /*!< TIMERB DTGB0CTL: OTP Position           */
#define TIMERB_DTGB0CTL_OTP_Msk               (0x01UL << TIMERB_DTGB0CTL_OTP_Pos)                     /*!< TIMERB DTGB0CTL: OTP Mask               */
#define TIMERB_DTGB0CTL_BYPASS_Pos            7                                                       /*!< TIMERB DTGB0CTL: BYPASS Position        */
#define TIMERB_DTGB0CTL_BYPASS_Msk            (0x01UL << TIMERB_DTGB0CTL_BYPASS_Pos)                  /*!< TIMERB DTGB0CTL: BYPASS Mask            */

/* -------------------------------  TIMERB_DTGB0LED  ------------------------------ */
#define TIMERB_DTGB0LED_LED_Pos               0                                                       /*!< TIMERB DTGB0LED: LED Position           */
#define TIMERB_DTGB0LED_LED_Msk               (0x00000fffUL << TIMERB_DTGB0LED_LED_Pos)               /*!< TIMERB DTGB0LED: LED Mask               */

/* -------------------------------  TIMERB_DTGB0TED  ------------------------------ */
#define TIMERB_DTGB0TED_TED_Pos               0                                                       /*!< TIMERB DTGB0TED: TED Position           */
#define TIMERB_DTGB0TED_TED_Msk               (0x00000fffUL << TIMERB_DTGB0TED_TED_Pos)               /*!< TIMERB DTGB0TED: TED Mask               */


/* ================================================================================ */
/* ================         struct 'TIMERC' Position & Mask        ================ */
/* ================================================================================ */


/* --------------------------------  TIMERC_TxCTL  -------------------------------- */
#define TIMERC_TxCTL_PRDL_Pos                 0                                                       /*!< TIMERC TxCTL: PRDL Position             */
#define TIMERC_TxCTL_PRDL_Msk                 (0x01UL << TIMERC_TxCTL_PRDL_Pos)                       /*!< TIMERC TxCTL: PRDL Mask                 */
#define TIMERC_TxCTL_CLR_Pos                  2                                                       /*!< TIMERC TxCTL: CLR Position              */
#define TIMERC_TxCTL_CLR_Msk                  (0x01UL << TIMERC_TxCTL_CLR_Pos)                        /*!< TIMERC TxCTL: CLR Mask                  */
#define TIMERC_TxCTL_SS_Pos                   3                                                       /*!< TIMERC TxCTL: SS Position               */
#define TIMERC_TxCTL_SS_Msk                   (0x01UL << TIMERC_TxCTL_SS_Pos)                         /*!< TIMERC TxCTL: SS Mask                   */
#define TIMERC_TxCTL_INT_Pos                  4                                                       /*!< TIMERC TxCTL: INT Position              */
#define TIMERC_TxCTL_INT_Msk                  (0x01UL << TIMERC_TxCTL_INT_Pos)                        /*!< TIMERC TxCTL: INT Mask                  */
#define TIMERC_TxCTL_INTEN_Pos                5                                                       /*!< TIMERC TxCTL: INTEN Position            */
#define TIMERC_TxCTL_INTEN_Msk                (0x01UL << TIMERC_TxCTL_INTEN_Pos)                      /*!< TIMERC TxCTL: INTEN Mask                */
#define TIMERC_TxCTL_CLKDIV_Pos               6                                                       /*!< TIMERC TxCTL: CLKDIV Position           */
#define TIMERC_TxCTL_CLKDIV_Msk               (0x07UL << TIMERC_TxCTL_CLKDIV_Pos)                     /*!< TIMERC TxCTL: CLKDIV Mask               */
#define TIMERC_TxCTL_CLK_Pos                  9                                                       /*!< TIMERC TxCTL: CLK Position              */
#define TIMERC_TxCTL_CLK_Msk                  (0x01UL << TIMERC_TxCTL_CLK_Pos)                        /*!< TIMERC TxCTL: CLK Mask                  */
#define TIMERC_TxCTL_MODE_Pos                 10                                                      /*!< TIMERC TxCTL: MODE Position             */
#define TIMERC_TxCTL_MODE_Msk                 (0x03UL << TIMERC_TxCTL_MODE_Pos)                       /*!< TIMERC TxCTL: MODE Mask                 */
#define TIMERC_TxCTL_DTGCLK_Pos               13                                                      /*!< TIMERC TxCTL: DTGCLK Position           */
#define TIMERC_TxCTL_DTGCLK_Msk               (0x01UL << TIMERC_TxCTL_DTGCLK_Pos)                     /*!< TIMERC TxCTL: DTGCLK Mask               */

/* --------------------------------  TIMERC_TxPRD  -------------------------------- */
#define TIMERC_TxPRD_PERIOD_Pos               0                                                       /*!< TIMERC TxPRD: PERIOD Position           */
#define TIMERC_TxPRD_PERIOD_Msk               (0x0000ffffUL << TIMERC_TxPRD_PERIOD_Pos)               /*!< TIMERC TxPRD: PERIOD Mask               */

/* --------------------------------  TIMERC_TxCTR  -------------------------------- */
#define TIMERC_TxCTR_CTR_Pos                  0                                                       /*!< TIMERC TxCTR: CTR Position              */
#define TIMERC_TxCTR_CTR_Msk                  (0x0000ffffUL << TIMERC_TxCTR_CTR_Pos)                  /*!< TIMERC TxCTR: CTR Mask                  */

/* -------------------------------  TIMERC_TxCC0CTL  ------------------------------ */
#define TIMERC_TxCC0CTL_CCEDG_Pos             0                                                       /*!< TIMERC TxCC0CTL: CCEDG Position         */
#define TIMERC_TxCC0CTL_CCEDG_Msk             (0x03UL << TIMERC_TxCC0CTL_CCEDG_Pos)                   /*!< TIMERC TxCC0CTL: CCEDG Mask             */
#define TIMERC_TxCC0CTL_CCINT_Pos             2                                                       /*!< TIMERC TxCC0CTL: CCINT Position         */
#define TIMERC_TxCC0CTL_CCINT_Msk             (0x01UL << TIMERC_TxCC0CTL_CCINT_Pos)                   /*!< TIMERC TxCC0CTL: CCINT Mask             */
#define TIMERC_TxCC0CTL_CCINTEN_Pos           3                                                       /*!< TIMERC TxCC0CTL: CCINTEN Position       */
#define TIMERC_TxCC0CTL_CCINTEN_Msk           (0x01UL << TIMERC_TxCC0CTL_CCINTEN_Pos)                 /*!< TIMERC TxCC0CTL: CCINTEN Mask           */
#define TIMERC_TxCC0CTL_CCMODE_Pos            4                                                       /*!< TIMERC TxCC0CTL: CCMODE Position        */
#define TIMERC_TxCC0CTL_CCMODE_Msk            (0x01UL << TIMERC_TxCC0CTL_CCMODE_Pos)                  /*!< TIMERC TxCC0CTL: CCMODE Mask            */

/* -------------------------------  TIMERC_TxCC0CTR  ------------------------------ */
#define TIMERC_TxCC0CTR_CCCTR_Pos             0                                                       /*!< TIMERC TxCC0CTR: CCCTR Position         */
#define TIMERC_TxCC0CTR_CCCTR_Msk             (0x0000ffffUL << TIMERC_TxCC0CTR_CCCTR_Pos)             /*!< TIMERC TxCC0CTR: CCCTR Mask             */

/* -------------------------------  TIMERC_TxCC1CTL  ------------------------------ */
#define TIMERC_TxCC1CTL_CCEDG_Pos             0                                                       /*!< TIMERC TxCC1CTL: CCEDG Position         */
#define TIMERC_TxCC1CTL_CCEDG_Msk             (0x03UL << TIMERC_TxCC1CTL_CCEDG_Pos)                   /*!< TIMERC TxCC1CTL: CCEDG Mask             */
#define TIMERC_TxCC1CTL_CCINT_Pos             2                                                       /*!< TIMERC TxCC1CTL: CCINT Position         */
#define TIMERC_TxCC1CTL_CCINT_Msk             (0x01UL << TIMERC_TxCC1CTL_CCINT_Pos)                   /*!< TIMERC TxCC1CTL: CCINT Mask             */
#define TIMERC_TxCC1CTL_CCINTEN_Pos           3                                                       /*!< TIMERC TxCC1CTL: CCINTEN Position       */
#define TIMERC_TxCC1CTL_CCINTEN_Msk           (0x01UL << TIMERC_TxCC1CTL_CCINTEN_Pos)                 /*!< TIMERC TxCC1CTL: CCINTEN Mask           */
#define TIMERC_TxCC1CTL_CCMODE_Pos            4                                                       /*!< TIMERC TxCC1CTL: CCMODE Position        */
#define TIMERC_TxCC1CTL_CCMODE_Msk            (0x01UL << TIMERC_TxCC1CTL_CCMODE_Pos)                  /*!< TIMERC TxCC1CTL: CCMODE Mask            */

/* -------------------------------  TIMERC_TxCC1CTR  ------------------------------ */
#define TIMERC_TxCC1CTR_CCCTR_Pos             0                                                       /*!< TIMERC TxCC1CTR: CCCTR Position         */
#define TIMERC_TxCC1CTR_CCCTR_Msk             (0x0000ffffUL << TIMERC_TxCC1CTR_CCCTR_Pos)             /*!< TIMERC TxCC1CTR: CCCTR Mask             */

/* -------------------------------  TIMERC_DTGC0CTL  ------------------------------ */
#define TIMERC_DTGC0CTL_INVLS_Pos             4                                                       /*!< TIMERC DTGC0CTL: INVLS Position         */
#define TIMERC_DTGC0CTL_INVLS_Msk             (0x01UL << TIMERC_DTGC0CTL_INVLS_Pos)                   /*!< TIMERC DTGC0CTL: INVLS Mask             */
#define TIMERC_DTGC0CTL_INVHS_Pos             5                                                       /*!< TIMERC DTGC0CTL: INVHS Position         */
#define TIMERC_DTGC0CTL_INVHS_Msk             (0x01UL << TIMERC_DTGC0CTL_INVHS_Pos)                   /*!< TIMERC DTGC0CTL: INVHS Mask             */
#define TIMERC_DTGC0CTL_OTP_Pos               6                                                       /*!< TIMERC DTGC0CTL: OTP Position           */
#define TIMERC_DTGC0CTL_OTP_Msk               (0x01UL << TIMERC_DTGC0CTL_OTP_Pos)                     /*!< TIMERC DTGC0CTL: OTP Mask               */
#define TIMERC_DTGC0CTL_BYPASS_Pos            7                                                       /*!< TIMERC DTGC0CTL: BYPASS Position        */
#define TIMERC_DTGC0CTL_BYPASS_Msk            (0x01UL << TIMERC_DTGC0CTL_BYPASS_Pos)                  /*!< TIMERC DTGC0CTL: BYPASS Mask            */

/* -------------------------------  TIMERC_DTGC0LED  ------------------------------ */
#define TIMERC_DTGC0LED_LED_Pos               0                                                       /*!< TIMERC DTGC0LED: LED Position           */
#define TIMERC_DTGC0LED_LED_Msk               (0x00000fffUL << TIMERC_DTGC0LED_LED_Pos)               /*!< TIMERC DTGC0LED: LED Mask               */

/* -------------------------------  TIMERC_DTGC0TED  ------------------------------ */
#define TIMERC_DTGC0TED_TED_Pos               0                                                       /*!< TIMERC DTGC0TED: TED Position           */
#define TIMERC_DTGC0TED_TED_Msk               (0x00000fffUL << TIMERC_DTGC0TED_TED_Pos)               /*!< TIMERC DTGC0TED: TED Mask               */


/* ================================================================================ */
/* ================         struct 'TIMERD' Position & Mask        ================ */
/* ================================================================================ */


/* --------------------------------  TIMERD_TxCTL  -------------------------------- */
#define TIMERD_TxCTL_PRDL_Pos                 0                                                       /*!< TIMERD TxCTL: PRDL Position             */
#define TIMERD_TxCTL_PRDL_Msk                 (0x01UL << TIMERD_TxCTL_PRDL_Pos)                       /*!< TIMERD TxCTL: PRDL Mask                 */
#define TIMERD_TxCTL_CLR_Pos                  2                                                       /*!< TIMERD TxCTL: CLR Position              */
#define TIMERD_TxCTL_CLR_Msk                  (0x01UL << TIMERD_TxCTL_CLR_Pos)                        /*!< TIMERD TxCTL: CLR Mask                  */
#define TIMERD_TxCTL_SS_Pos                   3                                                       /*!< TIMERD TxCTL: SS Position               */
#define TIMERD_TxCTL_SS_Msk                   (0x01UL << TIMERD_TxCTL_SS_Pos)                         /*!< TIMERD TxCTL: SS Mask                   */
#define TIMERD_TxCTL_INT_Pos                  4                                                       /*!< TIMERD TxCTL: INT Position              */
#define TIMERD_TxCTL_INT_Msk                  (0x01UL << TIMERD_TxCTL_INT_Pos)                        /*!< TIMERD TxCTL: INT Mask                  */
#define TIMERD_TxCTL_INTEN_Pos                5                                                       /*!< TIMERD TxCTL: INTEN Position            */
#define TIMERD_TxCTL_INTEN_Msk                (0x01UL << TIMERD_TxCTL_INTEN_Pos)                      /*!< TIMERD TxCTL: INTEN Mask                */
#define TIMERD_TxCTL_CLKDIV_Pos               6                                                       /*!< TIMERD TxCTL: CLKDIV Position           */
#define TIMERD_TxCTL_CLKDIV_Msk               (0x07UL << TIMERD_TxCTL_CLKDIV_Pos)                     /*!< TIMERD TxCTL: CLKDIV Mask               */
#define TIMERD_TxCTL_CLK_Pos                  9                                                       /*!< TIMERD TxCTL: CLK Position              */
#define TIMERD_TxCTL_CLK_Msk                  (0x01UL << TIMERD_TxCTL_CLK_Pos)                        /*!< TIMERD TxCTL: CLK Mask                  */
#define TIMERD_TxCTL_MODE_Pos                 10                                                      /*!< TIMERD TxCTL: MODE Position             */
#define TIMERD_TxCTL_MODE_Msk                 (0x03UL << TIMERD_TxCTL_MODE_Pos)                       /*!< TIMERD TxCTL: MODE Mask                 */
#define TIMERD_TxCTL_DTGCLK_Pos               13                                                      /*!< TIMERD TxCTL: DTGCLK Position           */
#define TIMERD_TxCTL_DTGCLK_Msk               (0x01UL << TIMERD_TxCTL_DTGCLK_Pos)                     /*!< TIMERD TxCTL: DTGCLK Mask               */

/* --------------------------------  TIMERD_TxPRD  -------------------------------- */
#define TIMERD_TxPRD_PERIOD_Pos               0                                                       /*!< TIMERD TxPRD: PERIOD Position           */
#define TIMERD_TxPRD_PERIOD_Msk               (0x0000ffffUL << TIMERD_TxPRD_PERIOD_Pos)               /*!< TIMERD TxPRD: PERIOD Mask               */

/* --------------------------------  TIMERD_TxCTR  -------------------------------- */
#define TIMERD_TxCTR_CTR_Pos                  0                                                       /*!< TIMERD TxCTR: CTR Position              */
#define TIMERD_TxCTR_CTR_Msk                  (0x0000ffffUL << TIMERD_TxCTR_CTR_Pos)                  /*!< TIMERD TxCTR: CTR Mask                  */

/* -------------------------------  TIMERD_TxCC0CTL  ------------------------------ */
#define TIMERD_TxCC0CTL_CCEDG_Pos             0                                                       /*!< TIMERD TxCC0CTL: CCEDG Position         */
#define TIMERD_TxCC0CTL_CCEDG_Msk             (0x03UL << TIMERD_TxCC0CTL_CCEDG_Pos)                   /*!< TIMERD TxCC0CTL: CCEDG Mask             */
#define TIMERD_TxCC0CTL_CCINT_Pos             2                                                       /*!< TIMERD TxCC0CTL: CCINT Position         */
#define TIMERD_TxCC0CTL_CCINT_Msk             (0x01UL << TIMERD_TxCC0CTL_CCINT_Pos)                   /*!< TIMERD TxCC0CTL: CCINT Mask             */
#define TIMERD_TxCC0CTL_CCINTEN_Pos           3                                                       /*!< TIMERD TxCC0CTL: CCINTEN Position       */
#define TIMERD_TxCC0CTL_CCINTEN_Msk           (0x01UL << TIMERD_TxCC0CTL_CCINTEN_Pos)                 /*!< TIMERD TxCC0CTL: CCINTEN Mask           */
#define TIMERD_TxCC0CTL_CCMODE_Pos            4                                                       /*!< TIMERD TxCC0CTL: CCMODE Position        */
#define TIMERD_TxCC0CTL_CCMODE_Msk            (0x01UL << TIMERD_TxCC0CTL_CCMODE_Pos)                  /*!< TIMERD TxCC0CTL: CCMODE Mask            */

/* -------------------------------  TIMERD_TxCC0CTR  ------------------------------ */
#define TIMERD_TxCC0CTR_CCCTR_Pos             0                                                       /*!< TIMERD TxCC0CTR: CCCTR Position         */
#define TIMERD_TxCC0CTR_CCCTR_Msk             (0x0000ffffUL << TIMERD_TxCC0CTR_CCCTR_Pos)             /*!< TIMERD TxCC0CTR: CCCTR Mask             */

/* -------------------------------  TIMERD_TxCC1CTL  ------------------------------ */
#define TIMERD_TxCC1CTL_CCEDG_Pos             0                                                       /*!< TIMERD TxCC1CTL: CCEDG Position         */
#define TIMERD_TxCC1CTL_CCEDG_Msk             (0x03UL << TIMERD_TxCC1CTL_CCEDG_Pos)                   /*!< TIMERD TxCC1CTL: CCEDG Mask             */
#define TIMERD_TxCC1CTL_CCINT_Pos             2                                                       /*!< TIMERD TxCC1CTL: CCINT Position         */
#define TIMERD_TxCC1CTL_CCINT_Msk             (0x01UL << TIMERD_TxCC1CTL_CCINT_Pos)                   /*!< TIMERD TxCC1CTL: CCINT Mask             */
#define TIMERD_TxCC1CTL_CCINTEN_Pos           3                                                       /*!< TIMERD TxCC1CTL: CCINTEN Position       */
#define TIMERD_TxCC1CTL_CCINTEN_Msk           (0x01UL << TIMERD_TxCC1CTL_CCINTEN_Pos)                 /*!< TIMERD TxCC1CTL: CCINTEN Mask           */
#define TIMERD_TxCC1CTL_CCMODE_Pos            4                                                       /*!< TIMERD TxCC1CTL: CCMODE Position        */
#define TIMERD_TxCC1CTL_CCMODE_Msk            (0x01UL << TIMERD_TxCC1CTL_CCMODE_Pos)                  /*!< TIMERD TxCC1CTL: CCMODE Mask            */

/* -------------------------------  TIMERD_TxCC1CTR  ------------------------------ */
#define TIMERD_TxCC1CTR_CCCTR_Pos             0                                                       /*!< TIMERD TxCC1CTR: CCCTR Position         */
#define TIMERD_TxCC1CTR_CCCTR_Msk             (0x0000ffffUL << TIMERD_TxCC1CTR_CCCTR_Pos)             /*!< TIMERD TxCC1CTR: CCCTR Mask             */

/* -------------------------------  TIMERD_DTGD0CTL  ------------------------------ */
#define TIMERD_DTGD0CTL_INVLS_Pos             4                                                       /*!< TIMERD DTGD0CTL: INVLS Position         */
#define TIMERD_DTGD0CTL_INVLS_Msk             (0x01UL << TIMERD_DTGD0CTL_INVLS_Pos)                   /*!< TIMERD DTGD0CTL: INVLS Mask             */
#define TIMERD_DTGD0CTL_INVHS_Pos             5                                                       /*!< TIMERD DTGD0CTL: INVHS Position         */
#define TIMERD_DTGD0CTL_INVHS_Msk             (0x01UL << TIMERD_DTGD0CTL_INVHS_Pos)                   /*!< TIMERD DTGD0CTL: INVHS Mask             */
#define TIMERD_DTGD0CTL_OTP_Pos               6                                                       /*!< TIMERD DTGD0CTL: OTP Position           */
#define TIMERD_DTGD0CTL_OTP_Msk               (0x01UL << TIMERD_DTGD0CTL_OTP_Pos)                     /*!< TIMERD DTGD0CTL: OTP Mask               */
#define TIMERD_DTGD0CTL_BYPASS_Pos            7                                                       /*!< TIMERD DTGD0CTL: BYPASS Position        */
#define TIMERD_DTGD0CTL_BYPASS_Msk            (0x01UL << TIMERD_DTGD0CTL_BYPASS_Pos)                  /*!< TIMERD DTGD0CTL: BYPASS Mask            */

/* -------------------------------  TIMERD_DTGD0LED  ------------------------------ */
#define TIMERD_DTGD0LED_LED_Pos               0                                                       /*!< TIMERD DTGD0LED: LED Position           */
#define TIMERD_DTGD0LED_LED_Msk               (0x00000fffUL << TIMERD_DTGD0LED_LED_Pos)               /*!< TIMERD DTGD0LED: LED Mask               */

/* -------------------------------  TIMERD_DTGD0TED  ------------------------------ */
#define TIMERD_DTGD0TED_TED_Pos               0                                                       /*!< TIMERD DTGD0TED: TED Position           */
#define TIMERD_DTGD0TED_TED_Msk               (0x00000fffUL << TIMERD_DTGD0TED_TED_Pos)               /*!< TIMERD DTGD0TED: TED Mask               */


/* ================================================================================ */
/* ================          struct 'ADC' Position & Mask          ================ */
/* ================================================================================ */


/* ---------------------------------  ADC_EMUXCTL  -------------------------------- */
#define ADC_EMUXCTL_EMUXCDIV_Pos              0                                                       /*!< ADC EMUXCTL: EMUXCDIV Position          */
#define ADC_EMUXCTL_EMUXCDIV_Msk              (0x07UL << ADC_EMUXCTL_EMUXCDIV_Pos)                    /*!< ADC EMUXCTL: EMUXCDIV Mask              */
#define ADC_EMUXCTL_EMUXDONE_Pos              3                                                       /*!< ADC EMUXCTL: EMUXDONE Position          */
#define ADC_EMUXCTL_EMUXDONE_Msk              (0x01UL << ADC_EMUXCTL_EMUXDONE_Pos)                    /*!< ADC EMUXCTL: EMUXDONE Mask              */
#define ADC_EMUXCTL_EMUXBUSY_Pos              4                                                       /*!< ADC EMUXCTL: EMUXBUSY Position          */
#define ADC_EMUXCTL_EMUXBUSY_Msk              (0x01UL << ADC_EMUXCTL_EMUXBUSY_Pos)                    /*!< ADC EMUXCTL: EMUXBUSY Mask              */
#define ADC_EMUXCTL_EMUXC_Pos                 5                                                       /*!< ADC EMUXCTL: EMUXC Position             */
#define ADC_EMUXCTL_EMUXC_Msk                 (0x01UL << ADC_EMUXCTL_EMUXC_Pos)                       /*!< ADC EMUXCTL: EMUXC Mask                 */

/* --------------------------------  ADC_EMUXDATA  -------------------------------- */
#define ADC_EMUXDATA_DATA_Pos                 0                                                       /*!< ADC EMUXDATA: DATA Position             */
#define ADC_EMUXDATA_DATA_Msk                 (0x0000ffffUL << ADC_EMUXDATA_DATA_Pos)                 /*!< ADC EMUXDATA: DATA Mask                 */

/* ---------------------------------  ADC_ADCCTL  --------------------------------- */
#define ADC_ADCCTL_ADCCDIV_Pos                0                                                       /*!< ADC ADCCTL: ADCCDIV Position            */
#define ADC_ADCCTL_ADCCDIV_Msk                (0x07UL << ADC_ADCCTL_ADCCDIV_Pos)                      /*!< ADC ADCCTL: ADCCDIV Mask                */
#define ADC_ADCCTL_ADCMUX_Pos                 4                                                       /*!< ADC ADCCTL: ADCMUX Position             */
#define ADC_ADCCTL_ADCMUX_Msk                 (0x07UL << ADC_ADCCTL_ADCMUX_Pos)                       /*!< ADC ADCCTL: ADCMUX Mask                 */
#define ADC_ADCCTL_ADCBUSY_Pos                7                                                       /*!< ADC ADCCTL: ADCBUSY Position            */
#define ADC_ADCCTL_ADCBUSY_Msk                (0x01UL << ADC_ADCCTL_ADCBUSY_Pos)                      /*!< ADC ADCCTL: ADCBUSY Mask                */
#define ADC_ADCCTL_ADCMODE_Pos                10                                                      /*!< ADC ADCCTL: ADCMODE Position            */
#define ADC_ADCCTL_ADCMODE_Msk                (0x07UL << ADC_ADCCTL_ADCMODE_Pos)                      /*!< ADC ADCCTL: ADCMODE Mask                */
#define ADC_ADCCTL_ADCSTART_Pos               14                                                      /*!< ADC ADCCTL: ADCSTART Position           */
#define ADC_ADCCTL_ADCSTART_Msk               (0x01UL << ADC_ADCCTL_ADCSTART_Pos)                     /*!< ADC ADCCTL: ADCSTART Mask               */
#define ADC_ADCCTL_ADCEN_Pos                  15                                                      /*!< ADC ADCCTL: ADCEN Position              */
#define ADC_ADCCTL_ADCEN_Msk                  (0x01UL << ADC_ADCCTL_ADCEN_Pos)                        /*!< ADC ADCCTL: ADCEN Mask                  */

/* ----------------------------------  ADC_ADCCR  --------------------------------- */
#define ADC_ADCCR_ADCRESULT_Pos               0                                                       /*!< ADC ADCCR: ADCRESULT Position           */
#define ADC_ADCCR_ADCRESULT_Msk               (0x0000ffffUL << ADC_ADCCR_ADCRESULT_Pos)               /*!< ADC ADCCR: ADCRESULT Mask               */

/* ---------------------------------  ADC_ADCINT  --------------------------------- */
#define ADC_ADCINT_ADCINT_Pos                 0                                                       /*!< ADC ADCINT: ADCINT Position             */
#define ADC_ADCINT_ADCINT_Msk                 (0x01UL << ADC_ADCINT_ADCINT_Pos)                       /*!< ADC ADCINT: ADCINT Mask                 */
#define ADC_ADCINT_EMUXINT_Pos                1                                                       /*!< ADC ADCINT: EMUXINT Position            */
#define ADC_ADCINT_EMUXINT_Msk                (0x01UL << ADC_ADCINT_EMUXINT_Pos)                      /*!< ADC ADCINT: EMUXINT Mask                */
#define ADC_ADCINT_AS0INT_Pos                 2                                                       /*!< ADC ADCINT: AS0INT Position             */
#define ADC_ADCINT_AS0INT_Msk                 (0x01UL << ADC_ADCINT_AS0INT_Pos)                       /*!< ADC ADCINT: AS0INT Mask                 */
#define ADC_ADCINT_AS1INT_Pos                 3                                                       /*!< ADC ADCINT: AS1INT Position             */
#define ADC_ADCINT_AS1INT_Msk                 (0x01UL << ADC_ADCINT_AS1INT_Pos)                       /*!< ADC ADCINT: AS1INT Mask                 */
#define ADC_ADCINT_ASCINT_Pos                 4                                                       /*!< ADC ADCINT: ASCINT Position             */
#define ADC_ADCINT_ASCINT_Msk                 (0x01UL << ADC_ADCINT_ASCINT_Pos)                       /*!< ADC ADCINT: ASCINT Mask                 */
#define ADC_ADCINT_ADCINT_EN_Pos              8                                                       /*!< ADC ADCINT: ADCINT_EN Position          */
#define ADC_ADCINT_ADCINT_EN_Msk              (0x01UL << ADC_ADCINT_ADCINT_EN_Pos)                    /*!< ADC ADCINT: ADCINT_EN Mask              */
#define ADC_ADCINT_EMUXINT_EN_Pos             9                                                       /*!< ADC ADCINT: EMUXINT_EN Position         */
#define ADC_ADCINT_EMUXINT_EN_Msk             (0x01UL << ADC_ADCINT_EMUXINT_EN_Pos)                   /*!< ADC ADCINT: EMUXINT_EN Mask             */
#define ADC_ADCINT_AS0INT_EN_Pos              10                                                      /*!< ADC ADCINT: AS0INT_EN Position          */
#define ADC_ADCINT_AS0INT_EN_Msk              (0x01UL << ADC_ADCINT_AS0INT_EN_Pos)                    /*!< ADC ADCINT: AS0INT_EN Mask              */
#define ADC_ADCINT_AS1INT_EN_Pos              11                                                      /*!< ADC ADCINT: AS1INT_EN Position          */
#define ADC_ADCINT_AS1INT_EN_Msk              (0x01UL << ADC_ADCINT_AS1INT_EN_Pos)                    /*!< ADC ADCINT: AS1INT_EN Mask              */
#define ADC_ADCINT_ASCINT_EN_Pos              12                                                      /*!< ADC ADCINT: ASCINT_EN Position          */
#define ADC_ADCINT_ASCINT_EN_Msk              (0x01UL << ADC_ADCINT_ASCINT_EN_Pos)                    /*!< ADC ADCINT: ASCINT_EN Mask              */
#define ADC_ADCINT_ASCINTSEQ_Pos              16                                                      /*!< ADC ADCINT: ASCINTSEQ Position          */
#define ADC_ADCINT_ASCINTSEQ_Msk              (0x03UL << ADC_ADCINT_ASCINTSEQ_Pos)                    /*!< ADC ADCINT: ASCINTSEQ Mask              */
#define ADC_ADCINT_ASCINTTR_Pos               18                                                      /*!< ADC ADCINT: ASCINTTR Position           */
#define ADC_ADCINT_ASCINTTR_Msk               (0x03UL << ADC_ADCINT_ASCINTTR_Pos)                     /*!< ADC ADCINT: ASCINTTR Mask               */

/* ---------------------------------  ADC_AS0CTL  --------------------------------- */
#define ADC_AS0CTL_ASAxTRPWM_Pos              0                                                       /*!< ADC AS0CTL: ASAxTRPWM Position          */
#define ADC_AS0CTL_ASAxTRPWM_Msk              (0x0fUL << ADC_AS0CTL_ASAxTRPWM_Pos)                    /*!< ADC AS0CTL: ASAxTRPWM Mask              */
#define ADC_AS0CTL_ASAxTRTMR_Pos              4                                                       /*!< ADC AS0CTL: ASAxTRTMR Position          */
#define ADC_AS0CTL_ASAxTRTMR_Msk              (0x03UL << ADC_AS0CTL_ASAxTRTMR_Pos)                    /*!< ADC AS0CTL: ASAxTRTMR Mask              */
#define ADC_AS0CTL_ASxTRE_Pos                 6                                                       /*!< ADC AS0CTL: ASxTRE Position             */
#define ADC_AS0CTL_ASxTRE_Msk                 (0x01UL << ADC_AS0CTL_ASxTRE_Pos)                       /*!< ADC AS0CTL: ASxTRE Mask                 */
#define ADC_AS0CTL_ASxTR_Pos                  7                                                       /*!< ADC AS0CTL: ASxTR Position              */
#define ADC_AS0CTL_ASxTR_Msk                  (0x01UL << ADC_AS0CTL_ASxTR_Pos)                        /*!< ADC AS0CTL: ASxTR Mask                  */
#define ADC_AS0CTL_ASxD_Pos                   8                                                       /*!< ADC AS0CTL: ASxD Position               */
#define ADC_AS0CTL_ASxD_Msk                   (0x07UL << ADC_AS0CTL_ASxD_Pos)                         /*!< ADC AS0CTL: ASxD Mask                   */
#define ADC_AS0CTL_ASxEN_Pos                  11                                                      /*!< ADC AS0CTL: ASxEN Position              */
#define ADC_AS0CTL_ASxEN_Msk                  (0x01UL << ADC_AS0CTL_ASxEN_Pos)                        /*!< ADC AS0CTL: ASxEN Mask                  */
#define ADC_AS0CTL_ASxBUSY_Pos                12                                                      /*!< ADC AS0CTL: ASxBUSY Position            */
#define ADC_AS0CTL_ASxBUSY_Msk                (0x01UL << ADC_AS0CTL_ASxBUSY_Pos)                      /*!< ADC AS0CTL: ASxBUSY Mask                */

/* ----------------------------------  ADC_AS0S0  --------------------------------- */
#define ADC_AS0S0_EMUXD_Pos                   0                                                       /*!< ADC AS0S0: EMUXD Position               */
#define ADC_AS0S0_EMUXD_Msk                   (0x000000ffUL << ADC_AS0S0_EMUXD_Pos)                   /*!< ADC AS0S0: EMUXD Mask                   */
#define ADC_AS0S0_EMUXS_Pos                   8                                                       /*!< ADC AS0S0: EMUXS Position               */
#define ADC_AS0S0_EMUXS_Msk                   (0x03UL << ADC_AS0S0_EMUXS_Pos)                         /*!< ADC AS0S0: EMUXS Mask                   */
#define ADC_AS0S0_DELAY_Pos                   10                                                      /*!< ADC AS0S0: DELAY Position               */
#define ADC_AS0S0_DELAY_Msk                   (0x03UL << ADC_AS0S0_DELAY_Pos)                         /*!< ADC AS0S0: DELAY Mask                   */
#define ADC_AS0S0_ADCMUX_Pos                  12                                                      /*!< ADC AS0S0: ADCMUX Position              */
#define ADC_AS0S0_ADCMUX_Msk                  (0x07UL << ADC_AS0S0_ADCMUX_Pos)                        /*!< ADC AS0S0: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS0R0  --------------------------------- */
#define ADC_AS0R0_ADCRESULT_Pos               0                                                       /*!< ADC AS0R0: ADCRESULT Position           */
#define ADC_AS0R0_ADCRESULT_Msk               (0x000003ffUL << ADC_AS0R0_ADCRESULT_Pos)               /*!< ADC AS0R0: ADCRESULT Mask               */

/* ----------------------------------  ADC_AS0S1  --------------------------------- */
#define ADC_AS0S1_EMUXD_Pos                   0                                                       /*!< ADC AS0S1: EMUXD Position               */
#define ADC_AS0S1_EMUXD_Msk                   (0x000000ffUL << ADC_AS0S1_EMUXD_Pos)                   /*!< ADC AS0S1: EMUXD Mask                   */
#define ADC_AS0S1_EMUXS_Pos                   8                                                       /*!< ADC AS0S1: EMUXS Position               */
#define ADC_AS0S1_EMUXS_Msk                   (0x03UL << ADC_AS0S1_EMUXS_Pos)                         /*!< ADC AS0S1: EMUXS Mask                   */
#define ADC_AS0S1_DELAY_Pos                   10                                                      /*!< ADC AS0S1: DELAY Position               */
#define ADC_AS0S1_DELAY_Msk                   (0x03UL << ADC_AS0S1_DELAY_Pos)                         /*!< ADC AS0S1: DELAY Mask                   */
#define ADC_AS0S1_ADCMUX_Pos                  12                                                      /*!< ADC AS0S1: ADCMUX Position              */
#define ADC_AS0S1_ADCMUX_Msk                  (0x07UL << ADC_AS0S1_ADCMUX_Pos)                        /*!< ADC AS0S1: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS0S2  --------------------------------- */
#define ADC_AS0S2_EMUXD_Pos                   0                                                       /*!< ADC AS0S2: EMUXD Position               */
#define ADC_AS0S2_EMUXD_Msk                   (0x000000ffUL << ADC_AS0S2_EMUXD_Pos)                   /*!< ADC AS0S2: EMUXD Mask                   */
#define ADC_AS0S2_EMUXS_Pos                   8                                                       /*!< ADC AS0S2: EMUXS Position               */
#define ADC_AS0S2_EMUXS_Msk                   (0x03UL << ADC_AS0S2_EMUXS_Pos)                         /*!< ADC AS0S2: EMUXS Mask                   */
#define ADC_AS0S2_DELAY_Pos                   10                                                      /*!< ADC AS0S2: DELAY Position               */
#define ADC_AS0S2_DELAY_Msk                   (0x03UL << ADC_AS0S2_DELAY_Pos)                         /*!< ADC AS0S2: DELAY Mask                   */
#define ADC_AS0S2_ADCMUX_Pos                  12                                                      /*!< ADC AS0S2: ADCMUX Position              */
#define ADC_AS0S2_ADCMUX_Msk                  (0x07UL << ADC_AS0S2_ADCMUX_Pos)                        /*!< ADC AS0S2: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS0S3  --------------------------------- */
#define ADC_AS0S3_EMUXD_Pos                   0                                                       /*!< ADC AS0S3: EMUXD Position               */
#define ADC_AS0S3_EMUXD_Msk                   (0x000000ffUL << ADC_AS0S3_EMUXD_Pos)                   /*!< ADC AS0S3: EMUXD Mask                   */
#define ADC_AS0S3_EMUXS_Pos                   8                                                       /*!< ADC AS0S3: EMUXS Position               */
#define ADC_AS0S3_EMUXS_Msk                   (0x03UL << ADC_AS0S3_EMUXS_Pos)                         /*!< ADC AS0S3: EMUXS Mask                   */
#define ADC_AS0S3_DELAY_Pos                   10                                                      /*!< ADC AS0S3: DELAY Position               */
#define ADC_AS0S3_DELAY_Msk                   (0x03UL << ADC_AS0S3_DELAY_Pos)                         /*!< ADC AS0S3: DELAY Mask                   */
#define ADC_AS0S3_ADCMUX_Pos                  12                                                      /*!< ADC AS0S3: ADCMUX Position              */
#define ADC_AS0S3_ADCMUX_Msk                  (0x07UL << ADC_AS0S3_ADCMUX_Pos)                        /*!< ADC AS0S3: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS0S4  --------------------------------- */
#define ADC_AS0S4_EMUXD_Pos                   0                                                       /*!< ADC AS0S4: EMUXD Position               */
#define ADC_AS0S4_EMUXD_Msk                   (0x000000ffUL << ADC_AS0S4_EMUXD_Pos)                   /*!< ADC AS0S4: EMUXD Mask                   */
#define ADC_AS0S4_EMUXS_Pos                   8                                                       /*!< ADC AS0S4: EMUXS Position               */
#define ADC_AS0S4_EMUXS_Msk                   (0x03UL << ADC_AS0S4_EMUXS_Pos)                         /*!< ADC AS0S4: EMUXS Mask                   */
#define ADC_AS0S4_DELAY_Pos                   10                                                      /*!< ADC AS0S4: DELAY Position               */
#define ADC_AS0S4_DELAY_Msk                   (0x03UL << ADC_AS0S4_DELAY_Pos)                         /*!< ADC AS0S4: DELAY Mask                   */
#define ADC_AS0S4_ADCMUX_Pos                  12                                                      /*!< ADC AS0S4: ADCMUX Position              */
#define ADC_AS0S4_ADCMUX_Msk                  (0x07UL << ADC_AS0S4_ADCMUX_Pos)                        /*!< ADC AS0S4: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS0S5  --------------------------------- */
#define ADC_AS0S5_EMUXD_Pos                   0                                                       /*!< ADC AS0S5: EMUXD Position               */
#define ADC_AS0S5_EMUXD_Msk                   (0x000000ffUL << ADC_AS0S5_EMUXD_Pos)                   /*!< ADC AS0S5: EMUXD Mask                   */
#define ADC_AS0S5_EMUXS_Pos                   8                                                       /*!< ADC AS0S5: EMUXS Position               */
#define ADC_AS0S5_EMUXS_Msk                   (0x03UL << ADC_AS0S5_EMUXS_Pos)                         /*!< ADC AS0S5: EMUXS Mask                   */
#define ADC_AS0S5_DELAY_Pos                   10                                                      /*!< ADC AS0S5: DELAY Position               */
#define ADC_AS0S5_DELAY_Msk                   (0x03UL << ADC_AS0S5_DELAY_Pos)                         /*!< ADC AS0S5: DELAY Mask                   */
#define ADC_AS0S5_ADCMUX_Pos                  12                                                      /*!< ADC AS0S5: ADCMUX Position              */
#define ADC_AS0S5_ADCMUX_Msk                  (0x07UL << ADC_AS0S5_ADCMUX_Pos)                        /*!< ADC AS0S5: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS0S6  --------------------------------- */
#define ADC_AS0S6_EMUXD_Pos                   0                                                       /*!< ADC AS0S6: EMUXD Position               */
#define ADC_AS0S6_EMUXD_Msk                   (0x000000ffUL << ADC_AS0S6_EMUXD_Pos)                   /*!< ADC AS0S6: EMUXD Mask                   */
#define ADC_AS0S6_EMUXS_Pos                   8                                                       /*!< ADC AS0S6: EMUXS Position               */
#define ADC_AS0S6_EMUXS_Msk                   (0x03UL << ADC_AS0S6_EMUXS_Pos)                         /*!< ADC AS0S6: EMUXS Mask                   */
#define ADC_AS0S6_DELAY_Pos                   10                                                      /*!< ADC AS0S6: DELAY Position               */
#define ADC_AS0S6_DELAY_Msk                   (0x03UL << ADC_AS0S6_DELAY_Pos)                         /*!< ADC AS0S6: DELAY Mask                   */
#define ADC_AS0S6_ADCMUX_Pos                  12                                                      /*!< ADC AS0S6: ADCMUX Position              */
#define ADC_AS0S6_ADCMUX_Msk                  (0x07UL << ADC_AS0S6_ADCMUX_Pos)                        /*!< ADC AS0S6: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS0S7  --------------------------------- */
#define ADC_AS0S7_EMUXD_Pos                   0                                                       /*!< ADC AS0S7: EMUXD Position               */
#define ADC_AS0S7_EMUXD_Msk                   (0x000000ffUL << ADC_AS0S7_EMUXD_Pos)                   /*!< ADC AS0S7: EMUXD Mask                   */
#define ADC_AS0S7_EMUXS_Pos                   8                                                       /*!< ADC AS0S7: EMUXS Position               */
#define ADC_AS0S7_EMUXS_Msk                   (0x03UL << ADC_AS0S7_EMUXS_Pos)                         /*!< ADC AS0S7: EMUXS Mask                   */
#define ADC_AS0S7_DELAY_Pos                   10                                                      /*!< ADC AS0S7: DELAY Position               */
#define ADC_AS0S7_DELAY_Msk                   (0x03UL << ADC_AS0S7_DELAY_Pos)                         /*!< ADC AS0S7: DELAY Mask                   */
#define ADC_AS0S7_ADCMUX_Pos                  12                                                      /*!< ADC AS0S7: ADCMUX Position              */
#define ADC_AS0S7_ADCMUX_Msk                  (0x07UL << ADC_AS0S7_ADCMUX_Pos)                        /*!< ADC AS0S7: ADCMUX Mask                  */

/* ---------------------------------  ADC_AS1CTL  --------------------------------- */
#define ADC_AS1CTL_ASAxTRPWM_Pos              0                                                       /*!< ADC AS1CTL: ASAxTRPWM Position          */
#define ADC_AS1CTL_ASAxTRPWM_Msk              (0x0fUL << ADC_AS1CTL_ASAxTRPWM_Pos)                    /*!< ADC AS1CTL: ASAxTRPWM Mask              */
#define ADC_AS1CTL_ASAxTRTMR_Pos              4                                                       /*!< ADC AS1CTL: ASAxTRTMR Position          */
#define ADC_AS1CTL_ASAxTRTMR_Msk              (0x03UL << ADC_AS1CTL_ASAxTRTMR_Pos)                    /*!< ADC AS1CTL: ASAxTRTMR Mask              */
#define ADC_AS1CTL_ASxTRE_Pos                 6                                                       /*!< ADC AS1CTL: ASxTRE Position             */
#define ADC_AS1CTL_ASxTRE_Msk                 (0x01UL << ADC_AS1CTL_ASxTRE_Pos)                       /*!< ADC AS1CTL: ASxTRE Mask                 */
#define ADC_AS1CTL_ASxTR_Pos                  7                                                       /*!< ADC AS1CTL: ASxTR Position              */
#define ADC_AS1CTL_ASxTR_Msk                  (0x01UL << ADC_AS1CTL_ASxTR_Pos)                        /*!< ADC AS1CTL: ASxTR Mask                  */
#define ADC_AS1CTL_ASxD_Pos                   8                                                       /*!< ADC AS1CTL: ASxD Position               */
#define ADC_AS1CTL_ASxD_Msk                   (0x07UL << ADC_AS1CTL_ASxD_Pos)                         /*!< ADC AS1CTL: ASxD Mask                   */
#define ADC_AS1CTL_ASxEN_Pos                  11                                                      /*!< ADC AS1CTL: ASxEN Position              */
#define ADC_AS1CTL_ASxEN_Msk                  (0x01UL << ADC_AS1CTL_ASxEN_Pos)                        /*!< ADC AS1CTL: ASxEN Mask                  */
#define ADC_AS1CTL_ASxBUSY_Pos                12                                                      /*!< ADC AS1CTL: ASxBUSY Position            */
#define ADC_AS1CTL_ASxBUSY_Msk                (0x01UL << ADC_AS1CTL_ASxBUSY_Pos)                      /*!< ADC AS1CTL: ASxBUSY Mask                */

/* ----------------------------------  ADC_AS1S0  --------------------------------- */
#define ADC_AS1S0_EMUXD_Pos                   0                                                       /*!< ADC AS1S0: EMUXD Position               */
#define ADC_AS1S0_EMUXD_Msk                   (0x000000ffUL << ADC_AS1S0_EMUXD_Pos)                   /*!< ADC AS1S0: EMUXD Mask                   */
#define ADC_AS1S0_EMUXS_Pos                   8                                                       /*!< ADC AS1S0: EMUXS Position               */
#define ADC_AS1S0_EMUXS_Msk                   (0x03UL << ADC_AS1S0_EMUXS_Pos)                         /*!< ADC AS1S0: EMUXS Mask                   */
#define ADC_AS1S0_DELAY_Pos                   10                                                      /*!< ADC AS1S0: DELAY Position               */
#define ADC_AS1S0_DELAY_Msk                   (0x03UL << ADC_AS1S0_DELAY_Pos)                         /*!< ADC AS1S0: DELAY Mask                   */
#define ADC_AS1S0_ADCMUX_Pos                  12                                                      /*!< ADC AS1S0: ADCMUX Position              */
#define ADC_AS1S0_ADCMUX_Msk                  (0x07UL << ADC_AS1S0_ADCMUX_Pos)                        /*!< ADC AS1S0: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS1R0  --------------------------------- */
#define ADC_AS1R0_ADCRESULT_Pos               0                                                       /*!< ADC AS1R0: ADCRESULT Position           */
#define ADC_AS1R0_ADCRESULT_Msk               (0x000003ffUL << ADC_AS1R0_ADCRESULT_Pos)               /*!< ADC AS1R0: ADCRESULT Mask               */

/* ----------------------------------  ADC_AS1S1  --------------------------------- */
#define ADC_AS1S1_EMUXD_Pos                   0                                                       /*!< ADC AS1S1: EMUXD Position               */
#define ADC_AS1S1_EMUXD_Msk                   (0x000000ffUL << ADC_AS1S1_EMUXD_Pos)                   /*!< ADC AS1S1: EMUXD Mask                   */
#define ADC_AS1S1_EMUXS_Pos                   8                                                       /*!< ADC AS1S1: EMUXS Position               */
#define ADC_AS1S1_EMUXS_Msk                   (0x03UL << ADC_AS1S1_EMUXS_Pos)                         /*!< ADC AS1S1: EMUXS Mask                   */
#define ADC_AS1S1_DELAY_Pos                   10                                                      /*!< ADC AS1S1: DELAY Position               */
#define ADC_AS1S1_DELAY_Msk                   (0x03UL << ADC_AS1S1_DELAY_Pos)                         /*!< ADC AS1S1: DELAY Mask                   */
#define ADC_AS1S1_ADCMUX_Pos                  12                                                      /*!< ADC AS1S1: ADCMUX Position              */
#define ADC_AS1S1_ADCMUX_Msk                  (0x07UL << ADC_AS1S1_ADCMUX_Pos)                        /*!< ADC AS1S1: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS1S2  --------------------------------- */
#define ADC_AS1S2_EMUXD_Pos                   0                                                       /*!< ADC AS1S2: EMUXD Position               */
#define ADC_AS1S2_EMUXD_Msk                   (0x000000ffUL << ADC_AS1S2_EMUXD_Pos)                   /*!< ADC AS1S2: EMUXD Mask                   */
#define ADC_AS1S2_EMUXS_Pos                   8                                                       /*!< ADC AS1S2: EMUXS Position               */
#define ADC_AS1S2_EMUXS_Msk                   (0x03UL << ADC_AS1S2_EMUXS_Pos)                         /*!< ADC AS1S2: EMUXS Mask                   */
#define ADC_AS1S2_DELAY_Pos                   10                                                      /*!< ADC AS1S2: DELAY Position               */
#define ADC_AS1S2_DELAY_Msk                   (0x03UL << ADC_AS1S2_DELAY_Pos)                         /*!< ADC AS1S2: DELAY Mask                   */
#define ADC_AS1S2_ADCMUX_Pos                  12                                                      /*!< ADC AS1S2: ADCMUX Position              */
#define ADC_AS1S2_ADCMUX_Msk                  (0x07UL << ADC_AS1S2_ADCMUX_Pos)                        /*!< ADC AS1S2: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS1S3  --------------------------------- */
#define ADC_AS1S3_EMUXD_Pos                   0                                                       /*!< ADC AS1S3: EMUXD Position               */
#define ADC_AS1S3_EMUXD_Msk                   (0x000000ffUL << ADC_AS1S3_EMUXD_Pos)                   /*!< ADC AS1S3: EMUXD Mask                   */
#define ADC_AS1S3_EMUXS_Pos                   8                                                       /*!< ADC AS1S3: EMUXS Position               */
#define ADC_AS1S3_EMUXS_Msk                   (0x03UL << ADC_AS1S3_EMUXS_Pos)                         /*!< ADC AS1S3: EMUXS Mask                   */
#define ADC_AS1S3_DELAY_Pos                   10                                                      /*!< ADC AS1S3: DELAY Position               */
#define ADC_AS1S3_DELAY_Msk                   (0x03UL << ADC_AS1S3_DELAY_Pos)                         /*!< ADC AS1S3: DELAY Mask                   */
#define ADC_AS1S3_ADCMUX_Pos                  12                                                      /*!< ADC AS1S3: ADCMUX Position              */
#define ADC_AS1S3_ADCMUX_Msk                  (0x07UL << ADC_AS1S3_ADCMUX_Pos)                        /*!< ADC AS1S3: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS1S4  --------------------------------- */
#define ADC_AS1S4_EMUXD_Pos                   0                                                       /*!< ADC AS1S4: EMUXD Position               */
#define ADC_AS1S4_EMUXD_Msk                   (0x000000ffUL << ADC_AS1S4_EMUXD_Pos)                   /*!< ADC AS1S4: EMUXD Mask                   */
#define ADC_AS1S4_EMUXS_Pos                   8                                                       /*!< ADC AS1S4: EMUXS Position               */
#define ADC_AS1S4_EMUXS_Msk                   (0x03UL << ADC_AS1S4_EMUXS_Pos)                         /*!< ADC AS1S4: EMUXS Mask                   */
#define ADC_AS1S4_DELAY_Pos                   10                                                      /*!< ADC AS1S4: DELAY Position               */
#define ADC_AS1S4_DELAY_Msk                   (0x03UL << ADC_AS1S4_DELAY_Pos)                         /*!< ADC AS1S4: DELAY Mask                   */
#define ADC_AS1S4_ADCMUX_Pos                  12                                                      /*!< ADC AS1S4: ADCMUX Position              */
#define ADC_AS1S4_ADCMUX_Msk                  (0x07UL << ADC_AS1S4_ADCMUX_Pos)                        /*!< ADC AS1S4: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS1S5  --------------------------------- */
#define ADC_AS1S5_EMUXD_Pos                   0                                                       /*!< ADC AS1S5: EMUXD Position               */
#define ADC_AS1S5_EMUXD_Msk                   (0x000000ffUL << ADC_AS1S5_EMUXD_Pos)                   /*!< ADC AS1S5: EMUXD Mask                   */
#define ADC_AS1S5_EMUXS_Pos                   8                                                       /*!< ADC AS1S5: EMUXS Position               */
#define ADC_AS1S5_EMUXS_Msk                   (0x03UL << ADC_AS1S5_EMUXS_Pos)                         /*!< ADC AS1S5: EMUXS Mask                   */
#define ADC_AS1S5_DELAY_Pos                   10                                                      /*!< ADC AS1S5: DELAY Position               */
#define ADC_AS1S5_DELAY_Msk                   (0x03UL << ADC_AS1S5_DELAY_Pos)                         /*!< ADC AS1S5: DELAY Mask                   */
#define ADC_AS1S5_ADCMUX_Pos                  12                                                      /*!< ADC AS1S5: ADCMUX Position              */
#define ADC_AS1S5_ADCMUX_Msk                  (0x07UL << ADC_AS1S5_ADCMUX_Pos)                        /*!< ADC AS1S5: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS1S6  --------------------------------- */
#define ADC_AS1S6_EMUXD_Pos                   0                                                       /*!< ADC AS1S6: EMUXD Position               */
#define ADC_AS1S6_EMUXD_Msk                   (0x000000ffUL << ADC_AS1S6_EMUXD_Pos)                   /*!< ADC AS1S6: EMUXD Mask                   */
#define ADC_AS1S6_EMUXS_Pos                   8                                                       /*!< ADC AS1S6: EMUXS Position               */
#define ADC_AS1S6_EMUXS_Msk                   (0x03UL << ADC_AS1S6_EMUXS_Pos)                         /*!< ADC AS1S6: EMUXS Mask                   */
#define ADC_AS1S6_DELAY_Pos                   10                                                      /*!< ADC AS1S6: DELAY Position               */
#define ADC_AS1S6_DELAY_Msk                   (0x03UL << ADC_AS1S6_DELAY_Pos)                         /*!< ADC AS1S6: DELAY Mask                   */
#define ADC_AS1S6_ADCMUX_Pos                  12                                                      /*!< ADC AS1S6: ADCMUX Position              */
#define ADC_AS1S6_ADCMUX_Msk                  (0x07UL << ADC_AS1S6_ADCMUX_Pos)                        /*!< ADC AS1S6: ADCMUX Mask                  */

/* ----------------------------------  ADC_AS1S7  --------------------------------- */
#define ADC_AS1S7_EMUXD_Pos                   0                                                       /*!< ADC AS1S7: EMUXD Position               */
#define ADC_AS1S7_EMUXD_Msk                   (0x000000ffUL << ADC_AS1S7_EMUXD_Pos)                   /*!< ADC AS1S7: EMUXD Mask                   */
#define ADC_AS1S7_EMUXS_Pos                   8                                                       /*!< ADC AS1S7: EMUXS Position               */
#define ADC_AS1S7_EMUXS_Msk                   (0x03UL << ADC_AS1S7_EMUXS_Pos)                         /*!< ADC AS1S7: EMUXS Mask                   */
#define ADC_AS1S7_DELAY_Pos                   10                                                      /*!< ADC AS1S7: DELAY Position               */
#define ADC_AS1S7_DELAY_Msk                   (0x03UL << ADC_AS1S7_DELAY_Pos)                         /*!< ADC AS1S7: DELAY Mask                   */
#define ADC_AS1S7_ADCMUX_Pos                  12                                                      /*!< ADC AS1S7: ADCMUX Position              */
#define ADC_AS1S7_ADCMUX_Msk                  (0x07UL << ADC_AS1S7_ADCMUX_Pos)                        /*!< ADC AS1S7: ADCMUX Mask                  */


/* ================================================================================ */
/* ================          struct 'I2C' Position & Mask          ================ */
/* ================================================================================ */


/* ---------------------------------  I2C_I2CCFG  --------------------------------- */
#define I2C_I2CCFG_SLEN_Pos                   0                                                       /*!< I2C I2CCFG: SLEN Position               */
#define I2C_I2CCFG_SLEN_Msk                   (0x01UL << I2C_I2CCFG_SLEN_Pos)                         /*!< I2C I2CCFG: SLEN Mask                   */
#define I2C_I2CCFG_MAEN_Pos                   2                                                       /*!< I2C I2CCFG: MAEN Position               */
#define I2C_I2CCFG_MAEN_Msk                   (0x01UL << I2C_I2CCFG_MAEN_Pos)                         /*!< I2C I2CCFG: MAEN Mask                   */
#define I2C_I2CCFG_ADDRMODE_Pos               4                                                       /*!< I2C I2CCFG: ADDRMODE Position           */
#define I2C_I2CCFG_ADDRMODE_Msk               (0x01UL << I2C_I2CCFG_ADDRMODE_Pos)                     /*!< I2C I2CCFG: ADDRMODE Mask               */

/* ---------------------------------  I2C_I2CINT  --------------------------------- */
#define I2C_I2CINT_MATXE_Pos                  0                                                       /*!< I2C I2CINT: MATXE Position              */
#define I2C_I2CINT_MATXE_Msk                  (0x01UL << I2C_I2CINT_MATXE_Pos)                        /*!< I2C I2CINT: MATXE Mask                  */
#define I2C_I2CINT_MACTLE_Pos                 1                                                       /*!< I2C I2CINT: MACTLE Position             */
#define I2C_I2CINT_MACTLE_Msk                 (0x01UL << I2C_I2CINT_MACTLE_Pos)                       /*!< I2C I2CINT: MACTLE Mask                 */
#define I2C_I2CINT_MARXF_Pos                  2                                                       /*!< I2C I2CINT: MARXF Position              */
#define I2C_I2CINT_MARXF_Msk                  (0x01UL << I2C_I2CINT_MARXF_Pos)                        /*!< I2C I2CINT: MARXF Mask                  */
#define I2C_I2CINT_MAXFERDONEINT_Pos          8                                                       /*!< I2C I2CINT: MAXFERDONEINT Position      */
#define I2C_I2CINT_MAXFERDONEINT_Msk          (0x01UL << I2C_I2CINT_MAXFERDONEINT_Pos)                /*!< I2C I2CINT: MAXFERDONEINT Mask          */
#define I2C_I2CINT_MAADDRACKINT_Pos           9                                                       /*!< I2C I2CINT: MAADDRACKINT Position       */
#define I2C_I2CINT_MAADDRACKINT_Msk           (0x01UL << I2C_I2CINT_MAADDRACKINT_Pos)                 /*!< I2C I2CINT: MAADDRACKINT Mask           */
#define I2C_I2CINT_MAARBLINT_Pos              10                                                      /*!< I2C I2CINT: MAARBLINT Position          */
#define I2C_I2CINT_MAARBLINT_Msk              (0x01UL << I2C_I2CINT_MAARBLINT_Pos)                    /*!< I2C I2CINT: MAARBLINT Mask              */
#define I2C_I2CINT_MADACKINT_Pos              11                                                      /*!< I2C I2CINT: MADACKINT Position          */
#define I2C_I2CINT_MADACKINT_Msk              (0x01UL << I2C_I2CINT_MADACKINT_Pos)                    /*!< I2C I2CINT: MADACKINT Mask              */
#define I2C_I2CINT_SLADDRMINT_Pos             16                                                      /*!< I2C I2CINT: SLADDRMINT Position         */
#define I2C_I2CINT_SLADDRMINT_Msk             (0x01UL << I2C_I2CINT_SLADDRMINT_Pos)                   /*!< I2C I2CINT: SLADDRMINT Mask             */
#define I2C_I2CINT_SLTXEINT_Pos               17                                                      /*!< I2C I2CINT: SLTXEINT Position           */
#define I2C_I2CINT_SLTXEINT_Msk               (0x01UL << I2C_I2CINT_SLTXEINT_Pos)                     /*!< I2C I2CINT: SLTXEINT Mask               */
#define I2C_I2CINT_SLRXFINT_Pos               18                                                      /*!< I2C I2CINT: SLRXFINT Position           */
#define I2C_I2CINT_SLRXFINT_Msk               (0x01UL << I2C_I2CINT_SLRXFINT_Pos)                     /*!< I2C I2CINT: SLRXFINT Mask               */
#define I2C_I2CINT_SLXFERDONEINT_Pos          24                                                      /*!< I2C I2CINT: SLXFERDONEINT Position      */
#define I2C_I2CINT_SLXFERDONEINT_Msk          (0x01UL << I2C_I2CINT_SLXFERDONEINT_Pos)                /*!< I2C I2CINT: SLXFERDONEINT Mask          */

/* --------------------------------  I2C_I2CINTEN  -------------------------------- */
#define I2C_I2CINTEN_MATXE_Pos                0                                                       /*!< I2C I2CINTEN: MATXE Position            */
#define I2C_I2CINTEN_MATXE_Msk                (0x01UL << I2C_I2CINTEN_MATXE_Pos)                      /*!< I2C I2CINTEN: MATXE Mask                */
#define I2C_I2CINTEN_MACTLE_Pos               1                                                       /*!< I2C I2CINTEN: MACTLE Position           */
#define I2C_I2CINTEN_MACTLE_Msk               (0x01UL << I2C_I2CINTEN_MACTLE_Pos)                     /*!< I2C I2CINTEN: MACTLE Mask               */
#define I2C_I2CINTEN_MARXF_Pos                2                                                       /*!< I2C I2CINTEN: MARXF Position            */
#define I2C_I2CINTEN_MARXF_Msk                (0x01UL << I2C_I2CINTEN_MARXF_Pos)                      /*!< I2C I2CINTEN: MARXF Mask                */
#define I2C_I2CINTEN_MAXFERDONE_Pos           8                                                       /*!< I2C I2CINTEN: MAXFERDONE Position       */
#define I2C_I2CINTEN_MAXFERDONE_Msk           (0x01UL << I2C_I2CINTEN_MAXFERDONE_Pos)                 /*!< I2C I2CINTEN: MAXFERDONE Mask           */
#define I2C_I2CINTEN_SLADDRM_Pos              16                                                      /*!< I2C I2CINTEN: SLADDRM Position          */
#define I2C_I2CINTEN_SLADDRM_Msk              (0x01UL << I2C_I2CINTEN_SLADDRM_Pos)                    /*!< I2C I2CINTEN: SLADDRM Mask              */
#define I2C_I2CINTEN_SLTXE_Pos                17                                                      /*!< I2C I2CINTEN: SLTXE Position            */
#define I2C_I2CINTEN_SLTXE_Msk                (0x01UL << I2C_I2CINTEN_SLTXE_Pos)                      /*!< I2C I2CINTEN: SLTXE Mask                */
#define I2C_I2CINTEN_SLRXF_Pos                18                                                      /*!< I2C I2CINTEN: SLRXF Position            */
#define I2C_I2CINTEN_SLRXF_Msk                (0x01UL << I2C_I2CINTEN_SLRXF_Pos)                      /*!< I2C I2CINTEN: SLRXF Mask                */
#define I2C_I2CINTEN_SLXFERDONEINTEN_Pos      24                                                      /*!< I2C I2CINTEN: SLXFERDONEINTEN Position  */
#define I2C_I2CINTEN_SLXFERDONEINTEN_Msk      (0x01UL << I2C_I2CINTEN_SLXFERDONEINTEN_Pos)            /*!< I2C I2CINTEN: SLXFERDONEINTEN Mask      */

/* --------------------------------  I2C_I2CMACTL  -------------------------------- */
#define I2C_I2CMACTL_I2CADDRL_Pos             0                                                       /*!< I2C I2CMACTL: I2CADDRL Position         */
#define I2C_I2CMACTL_I2CADDRL_Msk             (0x7fUL << I2C_I2CMACTL_I2CADDRL_Pos)                   /*!< I2C I2CMACTL: I2CADDRL Mask             */
#define I2C_I2CMACTL_I2CADDRU_Pos             7                                                       /*!< I2C I2CMACTL: I2CADDRU Position         */
#define I2C_I2CMACTL_I2CADDRU_Msk             (0x07UL << I2C_I2CMACTL_I2CADDRU_Pos)                   /*!< I2C I2CMACTL: I2CADDRU Mask             */
#define I2C_I2CMACTL_RSTART_Pos               10                                                      /*!< I2C I2CMACTL: RSTART Position           */
#define I2C_I2CMACTL_RSTART_Msk               (0x01UL << I2C_I2CMACTL_RSTART_Pos)                     /*!< I2C I2CMACTL: RSTART Mask               */
#define I2C_I2CMACTL_XFERTYPE_Pos             11                                                      /*!< I2C I2CMACTL: XFERTYPE Position         */
#define I2C_I2CMACTL_XFERTYPE_Msk             (0x01UL << I2C_I2CMACTL_XFERTYPE_Pos)                   /*!< I2C I2CMACTL: XFERTYPE Mask             */
#define I2C_I2CMACTL_I2CMACTLF_Pos            13                                                      /*!< I2C I2CMACTL: I2CMACTLF Position        */
#define I2C_I2CMACTL_I2CMACTLF_Msk            (0x01UL << I2C_I2CMACTL_I2CMACTLF_Pos)                  /*!< I2C I2CMACTL: I2CMACTLF Mask            */

/* -------------------------------  I2C_I2CMARXDATA  ------------------------------ */
#define I2C_I2CMARXDATA_MARXDATA_Pos          0                                                       /*!< I2C I2CMARXDATA: MARXDATA Position      */
#define I2C_I2CMARXDATA_MARXDATA_Msk          (0x000000ffUL << I2C_I2CMARXDATA_MARXDATA_Pos)          /*!< I2C I2CMARXDATA: MARXDATA Mask          */
#define I2C_I2CMARXDATA_I2CMARXDATAF_Pos      8                                                       /*!< I2C I2CMARXDATA: I2CMARXDATAF Position  */
#define I2C_I2CMARXDATA_I2CMARXDATAF_Msk      (0x01UL << I2C_I2CMARXDATA_I2CMARXDATAF_Pos)            /*!< I2C I2CMARXDATA: I2CMARXDATAF Mask      */

/* -------------------------------  I2C_I2CMATXDATA  ------------------------------ */
#define I2C_I2CMATXDATA_MATXDATA_Pos          0                                                       /*!< I2C I2CMATXDATA: MATXDATA Position      */
#define I2C_I2CMATXDATA_MATXDATA_Msk          (0x000000ffUL << I2C_I2CMATXDATA_MATXDATA_Pos)          /*!< I2C I2CMATXDATA: MATXDATA Mask          */
#define I2C_I2CMATXDATA_I2CMATXDATAF_Pos      8                                                       /*!< I2C I2CMATXDATA: I2CMATXDATAF Position  */
#define I2C_I2CMATXDATA_I2CMATXDATAF_Msk      (0x01UL << I2C_I2CMATXDATA_I2CMATXDATAF_Pos)            /*!< I2C I2CMATXDATA: I2CMATXDATAF Mask      */
#define I2C_I2CMATXDATA_LBYTE_Pos             9                                                       /*!< I2C I2CMATXDATA: LBYTE Position         */
#define I2C_I2CMATXDATA_LBYTE_Msk             (0x01UL << I2C_I2CMATXDATA_LBYTE_Pos)                   /*!< I2C I2CMATXDATA: LBYTE Mask             */

/* ---------------------------------  I2C_I2CBAUD  -------------------------------- */
#define I2C_I2CBAUD_SCLL_Pos                  0                                                       /*!< I2C I2CBAUD: SCLL Position              */
#define I2C_I2CBAUD_SCLL_Msk                  (0x000007ffUL << I2C_I2CBAUD_SCLL_Pos)                  /*!< I2C I2CBAUD: SCLL Mask                  */
#define I2C_I2CBAUD_SCLH_Pos                  16                                                      /*!< I2C I2CBAUD: SCLH Position              */
#define I2C_I2CBAUD_SCLH_Msk                  (0x000007ffUL << I2C_I2CBAUD_SCLH_Pos)                  /*!< I2C I2CBAUD: SCLH Mask                  */

/* -------------------------------  I2C_I2CSLRXDATA  ------------------------------ */
#define I2C_I2CSLRXDATA_SLRXDATA_Pos          0                                                       /*!< I2C I2CSLRXDATA: SLRXDATA Position      */
#define I2C_I2CSLRXDATA_SLRXDATA_Msk          (0x000000ffUL << I2C_I2CSLRXDATA_SLRXDATA_Pos)          /*!< I2C I2CSLRXDATA: SLRXDATA Mask          */
#define I2C_I2CSLRXDATA_I2CSLRXDATAF_Pos      8                                                       /*!< I2C I2CSLRXDATA: I2CSLRXDATAF Position  */
#define I2C_I2CSLRXDATA_I2CSLRXDATAF_Msk      (0x01UL << I2C_I2CSLRXDATA_I2CSLRXDATAF_Pos)            /*!< I2C I2CSLRXDATA: I2CSLRXDATAF Mask      */

/* -------------------------------  I2C_I2CSLTXDATA  ------------------------------ */
#define I2C_I2CSLTXDATA_SLTXDATA_Pos          0                                                       /*!< I2C I2CSLTXDATA: SLTXDATA Position      */
#define I2C_I2CSLTXDATA_SLTXDATA_Msk          (0x000000ffUL << I2C_I2CSLTXDATA_SLTXDATA_Pos)          /*!< I2C I2CSLTXDATA: SLTXDATA Mask          */
#define I2C_I2CSLTXDATA_NACK_Pos              8                                                       /*!< I2C I2CSLTXDATA: NACK Position          */
#define I2C_I2CSLTXDATA_NACK_Msk              (0x01UL << I2C_I2CSLTXDATA_NACK_Pos)                    /*!< I2C I2CSLTXDATA: NACK Mask              */
#define I2C_I2CSLTXDATA_I2CSLTXDATAF_Pos      9                                                       /*!< I2C I2CSLTXDATA: I2CSLTXDATAF Position  */
#define I2C_I2CSLTXDATA_I2CSLTXDATAF_Msk      (0x01UL << I2C_I2CSLTXDATA_I2CSLTXDATAF_Pos)            /*!< I2C I2CSLTXDATA: I2CSLTXDATAF Mask      */

/* --------------------------------  I2C_I2CSLADDR  ------------------------------- */
#define I2C_I2CSLADDR_SLADDRL_Pos             0                                                       /*!< I2C I2CSLADDR: SLADDRL Position         */
#define I2C_I2CSLADDR_SLADDRL_Msk             (0x7fUL << I2C_I2CSLADDR_SLADDRL_Pos)                   /*!< I2C I2CSLADDR: SLADDRL Mask             */
#define I2C_I2CSLADDR_SLADDRH_Pos             7                                                       /*!< I2C I2CSLADDR: SLADDRH Position         */
#define I2C_I2CSLADDR_SLADDRH_Msk             (0x07UL << I2C_I2CSLADDR_SLADDRH_Pos)                   /*!< I2C I2CSLADDR: SLADDRH Mask             */


/* ================================================================================ */
/* ================          struct 'UART' Position & Mask         ================ */
/* ================================================================================ */


/* --------------------------------  UART_UARTRXTX  ------------------------------- */
#define UART_UARTRXTX_RXTX_Pos                0                                                       /*!< UART UARTRXTX: RXTX Position            */
#define UART_UARTRXTX_RXTX_Msk                (0x000000ffUL << UART_UARTRXTX_RXTX_Pos)                /*!< UART UARTRXTX: RXTX Mask                */

/* --------------------------------  UART_UARTIEN  -------------------------------- */
#define UART_UARTIEN_RXINTEN_Pos              0                                                       /*!< UART UARTIEN: RXINTEN Position          */
#define UART_UARTIEN_RXINTEN_Msk              (0x01UL << UART_UARTIEN_RXINTEN_Pos)                    /*!< UART UARTIEN: RXINTEN Mask              */
#define UART_UARTIEN_TXINTEN_Pos              1                                                       /*!< UART UARTIEN: TXINTEN Position          */
#define UART_UARTIEN_TXINTEN_Msk              (0x01UL << UART_UARTIEN_TXINTEN_Pos)                    /*!< UART UARTIEN: TXINTEN Mask              */
#define UART_UARTIEN_RSINTEN_Pos              2                                                       /*!< UART UARTIEN: RSINTEN Position          */
#define UART_UARTIEN_RSINTEN_Msk              (0x01UL << UART_UARTIEN_RSINTEN_Pos)                    /*!< UART UARTIEN: RSINTEN Mask              */
#define UART_UARTIEN_MSINTEN_Pos              3                                                       /*!< UART UARTIEN: MSINTEN Position          */
#define UART_UARTIEN_MSINTEN_Msk              (0x01UL << UART_UARTIEN_MSINTEN_Pos)                    /*!< UART UARTIEN: MSINTEN Mask              */

/* ---------------------------------  UART_UARTII  -------------------------------- */
#define UART_UARTII_UARTINT_Pos               0                                                       /*!< UART UARTII: UARTINT Position           */
#define UART_UARTII_UARTINT_Msk               (0x01UL << UART_UARTII_UARTINT_Pos)                     /*!< UART UARTII: UARTINT Mask               */
#define UART_UARTII_UARTINTID_Pos             1                                                       /*!< UART UARTII: UARTINTID Position         */
#define UART_UARTII_UARTINTID_Msk             (0x07UL << UART_UARTII_UARTINTID_Pos)                   /*!< UART UARTII: UARTINTID Mask             */

/* ---------------------------------  UART_UARTLC  -------------------------------- */
#define UART_UARTLC_BPC_Pos                   0                                                       /*!< UART UARTLC: BPC Position               */
#define UART_UARTLC_BPC_Msk                   (0x03UL << UART_UARTLC_BPC_Pos)                         /*!< UART UARTLC: BPC Mask                   */
#define UART_UARTLC_STB_Pos                   2                                                       /*!< UART UARTLC: STB Position               */
#define UART_UARTLC_STB_Msk                   (0x01UL << UART_UARTLC_STB_Pos)                         /*!< UART UARTLC: STB Mask                   */
#define UART_UARTLC_PEN_Pos                   3                                                       /*!< UART UARTLC: PEN Position               */
#define UART_UARTLC_PEN_Msk                   (0x01UL << UART_UARTLC_PEN_Pos)                         /*!< UART UARTLC: PEN Mask                   */
#define UART_UARTLC_EPS_Pos                   4                                                       /*!< UART UARTLC: EPS Position               */
#define UART_UARTLC_EPS_Msk                   (0x01UL << UART_UARTLC_EPS_Pos)                         /*!< UART UARTLC: EPS Mask                   */
#define UART_UARTLC_SP_Pos                    5                                                       /*!< UART UARTLC: SP Position                */
#define UART_UARTLC_SP_Msk                    (0x01UL << UART_UARTLC_SP_Pos)                          /*!< UART UARTLC: SP Mask                    */
#define UART_UARTLC_SB_Pos                    6                                                       /*!< UART UARTLC: SB Position                */
#define UART_UARTLC_SB_Msk                    (0x01UL << UART_UARTLC_SB_Pos)                          /*!< UART UARTLC: SB Mask                    */

/* ---------------------------------  UART_UARTLS  -------------------------------- */
#define UART_UARTLS_RXDR_Pos                  0                                                       /*!< UART UARTLS: RXDR Position              */
#define UART_UARTLS_RXDR_Msk                  (0x01UL << UART_UARTLS_RXDR_Pos)                        /*!< UART UARTLS: RXDR Mask                  */
#define UART_UARTLS_RXOE_Pos                  1                                                       /*!< UART UARTLS: RXOE Position              */
#define UART_UARTLS_RXOE_Msk                  (0x01UL << UART_UARTLS_RXOE_Pos)                        /*!< UART UARTLS: RXOE Mask                  */
#define UART_UARTLS_RXPE_Pos                  2                                                       /*!< UART UARTLS: RXPE Position              */
#define UART_UARTLS_RXPE_Msk                  (0x01UL << UART_UARTLS_RXPE_Pos)                        /*!< UART UARTLS: RXPE Mask                  */
#define UART_UARTLS_RXFE_Pos                  3                                                       /*!< UART UARTLS: RXFE Position              */
#define UART_UARTLS_RXFE_Msk                  (0x01UL << UART_UARTLS_RXFE_Pos)                        /*!< UART UARTLS: RXFE Mask                  */
#define UART_UARTLS_RXBE_Pos                  4                                                       /*!< UART UARTLS: RXBE Position              */
#define UART_UARTLS_RXBE_Msk                  (0x01UL << UART_UARTLS_RXBE_Pos)                        /*!< UART UARTLS: RXBE Mask                  */
#define UART_UARTLS_TCFE_Pos                  5                                                       /*!< UART UARTLS: TCFE Position              */
#define UART_UARTLS_TCFE_Msk                  (0x01UL << UART_UARTLS_TCFE_Pos)                        /*!< UART UARTLS: TCFE Mask                  */
#define UART_UARTLS_TXE_Pos                   6                                                       /*!< UART UARTLS: TXE Position               */
#define UART_UARTLS_TXE_Msk                   (0x01UL << UART_UARTLS_TXE_Pos)                         /*!< UART UARTLS: TXE Mask                   */
#define UART_UARTLS_RXE_Pos                   7                                                       /*!< UART UARTLS: RXE Position               */
#define UART_UARTLS_RXE_Msk                   (0x01UL << UART_UARTLS_RXE_Pos)                         /*!< UART UARTLS: RXE Mask                   */

/* --------------------------------  UART_UARTFCTL  ------------------------------- */
#define UART_UARTFCTL_FEN_Pos                 0                                                       /*!< UART UARTFCTL: FEN Position             */
#define UART_UARTFCTL_FEN_Msk                 (0x01UL << UART_UARTFCTL_FEN_Pos)                       /*!< UART UARTFCTL: FEN Mask                 */
#define UART_UARTFCTL_RXFRESET_Pos            1                                                       /*!< UART UARTFCTL: RXFRESET Position        */
#define UART_UARTFCTL_RXFRESET_Msk            (0x01UL << UART_UARTFCTL_RXFRESET_Pos)                  /*!< UART UARTFCTL: RXFRESET Mask            */
#define UART_UARTFCTL_TXFRESET_Pos            2                                                       /*!< UART UARTFCTL: TXFRESET Position        */
#define UART_UARTFCTL_TXFRESET_Msk            (0x01UL << UART_UARTFCTL_TXFRESET_Pos)                  /*!< UART UARTFCTL: TXFRESET Mask            */
#define UART_UARTFCTL_RXFT_Pos                6                                                       /*!< UART UARTFCTL: RXFT Position            */
#define UART_UARTFCTL_RXFT_Msk                (0x03UL << UART_UARTFCTL_RXFT_Pos)                      /*!< UART UARTFCTL: RXFT Mask                */

/* --------------------------------  UART_UARTIE_R  ------------------------------- */
#define UART_UARTIE_R_RXINTEN_Pos             0                                                       /*!< UART UARTIE_R: RXINTEN Position         */
#define UART_UARTIE_R_RXINTEN_Msk             (0x01UL << UART_UARTIE_R_RXINTEN_Pos)                   /*!< UART UARTIE_R: RXINTEN Mask             */
#define UART_UARTIE_R_TXINTEN_Pos             1                                                       /*!< UART UARTIE_R: TXINTEN Position         */
#define UART_UARTIE_R_TXINTEN_Msk             (0x01UL << UART_UARTIE_R_TXINTEN_Pos)                   /*!< UART UARTIE_R: TXINTEN Mask             */
#define UART_UARTIE_R_RSINTEN_Pos             2                                                       /*!< UART UARTIE_R: RSINTEN Position         */
#define UART_UARTIE_R_RSINTEN_Msk             (0x01UL << UART_UARTIE_R_RSINTEN_Pos)                   /*!< UART UARTIE_R: RSINTEN Mask             */
#define UART_UARTIE_R_MSINTEN_Pos             3                                                       /*!< UART UARTIE_R: MSINTEN Position         */
#define UART_UARTIE_R_MSINTEN_Msk             (0x01UL << UART_UARTIE_R_MSINTEN_Pos)                   /*!< UART UARTIE_R: MSINTEN Mask             */

/* --------------------------------  UART_UARTDL_L  ------------------------------- */
#define UART_UARTDL_L_DL_L_Pos                0                                                       /*!< UART UARTDL_L: DL_L Position            */
#define UART_UARTDL_L_DL_L_Msk                (0x000000ffUL << UART_UARTDL_L_DL_L_Pos)                /*!< UART UARTDL_L: DL_L Mask                */

/* --------------------------------  UART_UARTDL_H  ------------------------------- */
#define UART_UARTDL_H_DL_H_Pos                0                                                       /*!< UART UARTDL_H: DL_H Position            */
#define UART_UARTDL_H_DL_H_Msk                (0x000000ffUL << UART_UARTDL_H_DL_H_Pos)                /*!< UART UARTDL_H: DL_H Mask                */

/* --------------------------------  UART_UARTFD_F  ------------------------------- */
#define UART_UARTFD_F_FRAC_Pos                0                                                       /*!< UART UARTFD_F: FRAC Position            */
#define UART_UARTFD_F_FRAC_Msk                (0x000000ffUL << UART_UARTFD_F_FRAC_Pos)                /*!< UART UARTFD_F: FRAC Mask                */

/* -------------------------------  UART_UARTFSTAT  ------------------------------- */
#define UART_UARTFSTAT_TXFE_Pos               0                                                       /*!< UART UARTFSTAT: TXFE Position           */
#define UART_UARTFSTAT_TXFE_Msk               (0x01UL << UART_UARTFSTAT_TXFE_Pos)                     /*!< UART UARTFSTAT: TXFE Mask               */
#define UART_UARTFSTAT_TXFF_Pos               1                                                       /*!< UART UARTFSTAT: TXFF Position           */
#define UART_UARTFSTAT_TXFF_Msk               (0x01UL << UART_UARTFSTAT_TXFF_Pos)                     /*!< UART UARTFSTAT: TXFF Mask               */
#define UART_UARTFSTAT_RXFE_Pos               2                                                       /*!< UART UARTFSTAT: RXFE Position           */
#define UART_UARTFSTAT_RXFE_Msk               (0x01UL << UART_UARTFSTAT_RXFE_Pos)                     /*!< UART UARTFSTAT: RXFE Mask               */
#define UART_UARTFSTAT_RXFF_Pos               3                                                       /*!< UART UARTFSTAT: RXFF Position           */
#define UART_UARTFSTAT_RXFF_Msk               (0x01UL << UART_UARTFSTAT_RXFF_Pos)                     /*!< UART UARTFSTAT: RXFF Mask               */


/* ================================================================================ */
/* ================          struct 'SOCB' Position & Mask         ================ */
/* ================================================================================ */


/* --------------------------------  SOCB_SOCBCTL  -------------------------------- */
#define SOCB_SOCBCTL_SSEN_Pos                 0                                                       /*!< SOCB SOCBCTL: SSEN Position             */
#define SOCB_SOCBCTL_SSEN_Msk                 (0x01UL << SOCB_SOCBCTL_SSEN_Pos)                       /*!< SOCB SOCBCTL: SSEN Mask                 */
#define SOCB_SOCBCTL_SIE_Pos                  1                                                       /*!< SOCB SOCBCTL: SIE Position              */
#define SOCB_SOCBCTL_SIE_Msk                  (0x01UL << SOCB_SOCBCTL_SIE_Pos)                        /*!< SOCB SOCBCTL: SIE Mask                  */
#define SOCB_SOCBCTL_MTRARM_Pos               5                                                       /*!< SOCB SOCBCTL: MTRARM Position           */
#define SOCB_SOCBCTL_MTRARM_Msk               (0x01UL << SOCB_SOCBCTL_MTRARM_Pos)                     /*!< SOCB SOCBCTL: MTRARM Mask               */

/* --------------------------------  SOCB_SOCBCFG  -------------------------------- */
#define SOCB_SOCBCFG_MRST_Pos                 2                                                       /*!< SOCB SOCBCFG: MRST Position             */
#define SOCB_SOCBCFG_MRST_Msk                 (0x01UL << SOCB_SOCBCFG_MRST_Pos)                       /*!< SOCB SOCBCFG: MRST Mask                 */

/* --------------------------------  SOCB_SOCBSTAT  ------------------------------- */
#define SOCB_SOCBSTAT_SOCB_INT_Pos            0                                                       /*!< SOCB SOCBSTAT: SOCB_INT Position        */
#define SOCB_SOCBSTAT_SOCB_INT_Msk            (0x01UL << SOCB_SOCBSTAT_SOCB_INT_Pos)                  /*!< SOCB SOCBSTAT: SOCB_INT Mask            */
#define SOCB_SOCBSTAT_RDOFL_Pos               2                                                       /*!< SOCB SOCBSTAT: RDOFL Position           */
#define SOCB_SOCBSTAT_RDOFL_Msk               (0x01UL << SOCB_SOCBSTAT_RDOFL_Pos)                     /*!< SOCB SOCBSTAT: RDOFL Mask               */
#define SOCB_SOCBSTAT_CYC_DONE_Pos            5                                                       /*!< SOCB SOCBSTAT: CYC_DONE Position        */
#define SOCB_SOCBSTAT_CYC_DONE_Msk            (0x01UL << SOCB_SOCBSTAT_CYC_DONE_Pos)                  /*!< SOCB SOCBSTAT: CYC_DONE Mask            */
#define SOCB_SOCBSTAT_WRUFL_Pos               8                                                       /*!< SOCB SOCBSTAT: WRUFL Position           */
#define SOCB_SOCBSTAT_WRUFL_Msk               (0x01UL << SOCB_SOCBSTAT_WRUFL_Pos)                     /*!< SOCB SOCBSTAT: WRUFL Mask               */
#define SOCB_SOCBSTAT_TXFULL_Pos              9                                                       /*!< SOCB SOCBSTAT: TXFULL Position          */
#define SOCB_SOCBSTAT_TXFULL_Msk              (0x01UL << SOCB_SOCBSTAT_TXFULL_Pos)                    /*!< SOCB SOCBSTAT: TXFULL Mask              */
#define SOCB_SOCBSTAT_RXFULL_Pos              10                                                      /*!< SOCB SOCBSTAT: RXFULL Position          */
#define SOCB_SOCBSTAT_RXFULL_Msk              (0x01UL << SOCB_SOCBSTAT_RXFULL_Pos)                    /*!< SOCB SOCBSTAT: RXFULL Mask              */
#define SOCB_SOCBSTAT_CURSTATE_Pos            12                                                      /*!< SOCB SOCBSTAT: CURSTATE Position        */
#define SOCB_SOCBSTAT_CURSTATE_Msk            (0x07UL << SOCB_SOCBSTAT_CURSTATE_Pos)                  /*!< SOCB SOCBSTAT: CURSTATE Mask            */

/* ---------------------------------  SOCB_SOCBD  --------------------------------- */
#define SOCB_SOCBD_DATA_Pos                   0                                                       /*!< SOCB SOCBD: DATA Position               */
#define SOCB_SOCBD_DATA_Msk                   (0x000000ffUL << SOCB_SOCBD_DATA_Pos)                   /*!< SOCB SOCBD: DATA Mask                   */

/* -------------------------------  SOCB_SOCBINT_EN  ------------------------------ */
#define SOCB_SOCBINT_EN_RDOFL_EN_Pos          2                                                       /*!< SOCB SOCBINT_EN: RDOFL_EN Position      */
#define SOCB_SOCBINT_EN_RDOFL_EN_Msk          (0x01UL << SOCB_SOCBINT_EN_RDOFL_EN_Pos)                /*!< SOCB SOCBINT_EN: RDOFL_EN Mask          */
#define SOCB_SOCBINT_EN_WRUFL_EN_Pos          8                                                       /*!< SOCB SOCBINT_EN: WRUFL_EN Position      */
#define SOCB_SOCBINT_EN_WRUFL_EN_Msk          (0x01UL << SOCB_SOCBINT_EN_WRUFL_EN_Pos)                /*!< SOCB SOCBINT_EN: WRUFL_EN Mask          */


/* ================================================================================ */
/* ================          struct 'SPI' Position & Mask          ================ */
/* ================================================================================ */


/* ---------------------------------  SPI_SPICTL  --------------------------------- */
#define SPI_SPICTL_SSEN_Pos                   0                                                       /*!< SPI SPICTL: SSEN Position               */
#define SPI_SPICTL_SSEN_Msk                   (0x01UL << SPI_SPICTL_SSEN_Pos)                         /*!< SPI SPICTL: SSEN Mask                   */
#define SPI_SPICTL_SIE_Pos                    1                                                       /*!< SPI SPICTL: SIE Position                */
#define SPI_SPICTL_SIE_Msk                    (0x01UL << SPI_SPICTL_SIE_Pos)                          /*!< SPI SPICTL: SIE Mask                    */
#define SPI_SPICTL_LPBK_Pos                   2                                                       /*!< SPI SPICTL: LPBK Position               */
#define SPI_SPICTL_LPBK_Msk                   (0x01UL << SPI_SPICTL_LPBK_Pos)                         /*!< SPI SPICTL: LPBK Mask                   */
#define SPI_SPICTL_SE_Pos                     3                                                       /*!< SPI SPICTL: SE Position                 */
#define SPI_SPICTL_SE_Msk                     (0x01UL << SPI_SPICTL_SE_Pos)                           /*!< SPI SPICTL: SE Mask                     */
#define SPI_SPICTL_MTRARM_Pos                 5                                                       /*!< SPI SPICTL: MTRARM Position             */
#define SPI_SPICTL_MTRARM_Msk                 (0x01UL << SPI_SPICTL_MTRARM_Pos)                       /*!< SPI SPICTL: MTRARM Mask                 */
#define SPI_SPICTL_MTRANS_Pos                 6                                                       /*!< SPI SPICTL: MTRANS Position             */
#define SPI_SPICTL_MTRANS_Msk                 (0x01UL << SPI_SPICTL_MTRANS_Pos)                       /*!< SPI SPICTL: MTRANS Mask                 */
#define SPI_SPICTL_MMST_N_Pos                 7                                                       /*!< SPI SPICTL: MMST_N Position             */
#define SPI_SPICTL_MMST_N_Msk                 (0x01UL << SPI_SPICTL_MMST_N_Pos)                       /*!< SPI SPICTL: MMST_N Mask                 */
#define SPI_SPICTL_RTRANS_Pos                 8                                                       /*!< SPI SPICTL: RTRANS Position             */
#define SPI_SPICTL_RTRANS_Msk                 (0x01UL << SPI_SPICTL_RTRANS_Pos)                       /*!< SPI SPICTL: RTRANS Mask                 */

/* ---------------------------------  SPI_SPICFG  --------------------------------- */
#define SPI_SPICFG_WL_Pos                     0                                                       /*!< SPI SPICFG: WL Position                 */
#define SPI_SPICFG_WL_Msk                     (0x03UL << SPI_SPICFG_WL_Pos)                           /*!< SPI SPICFG: WL Mask                     */
#define SPI_SPICFG_MRST_Pos                   2                                                       /*!< SPI SPICFG: MRST Position               */
#define SPI_SPICFG_MRST_Msk                   (0x01UL << SPI_SPICFG_MRST_Pos)                         /*!< SPI SPICFG: MRST Mask                   */
#define SPI_SPICFG_LB1ST_Pos                  3                                                       /*!< SPI SPICFG: LB1ST Position              */
#define SPI_SPICFG_LB1ST_Msk                  (0x01UL << SPI_SPICFG_LB1ST_Pos)                        /*!< SPI SPICFG: LB1ST Mask                  */
#define SPI_SPICFG_CP_Pos                     4                                                       /*!< SPI SPICFG: CP Position                 */
#define SPI_SPICFG_CP_Msk                     (0x01UL << SPI_SPICFG_CP_Pos)                           /*!< SPI SPICFG: CP Mask                     */
#define SPI_SPICFG_CPH_Pos                    5                                                       /*!< SPI SPICFG: CPH Position                */
#define SPI_SPICFG_CPH_Msk                    (0x01UL << SPI_SPICFG_CPH_Pos)                          /*!< SPI SPICFG: CPH Mask                    */
#define SPI_SPICFG_RCVCP_Pos                  6                                                       /*!< SPI SPICFG: RCVCP Position              */
#define SPI_SPICFG_RCVCP_Msk                  (0x01UL << SPI_SPICFG_RCVCP_Pos)                        /*!< SPI SPICFG: RCVCP Mask                  */
#define SPI_SPICFG_RCVCPH_Pos                 7                                                       /*!< SPI SPICFG: RCVCPH Position             */
#define SPI_SPICFG_RCVCPH_Msk                 (0x01UL << SPI_SPICFG_RCVCPH_Pos)                       /*!< SPI SPICFG: RCVCPH Mask                 */
#define SPI_SPICFG_TXDATPH_Pos                9                                                       /*!< SPI SPICFG: TXDATPH Position            */
#define SPI_SPICFG_TXDATPH_Msk                (0x01UL << SPI_SPICFG_TXDATPH_Pos)                      /*!< SPI SPICFG: TXDATPH Mask                */
#define SPI_SPICFG_TDBUF_Pos                  10                                                      /*!< SPI SPICFG: TDBUF Position              */
#define SPI_SPICFG_TDBUF_Msk                  (0x01UL << SPI_SPICFG_TDBUF_Pos)                        /*!< SPI SPICFG: TDBUF Mask                  */
#define SPI_SPICFG_MTURBO_Pos                 11                                                      /*!< SPI SPICFG: MTURBO Position             */
#define SPI_SPICFG_MTURBO_Msk                 (0x01UL << SPI_SPICFG_MTURBO_Pos)                       /*!< SPI SPICFG: MTURBO Mask                 */

/* --------------------------------  SPI_SPICLKDIV  ------------------------------- */
#define SPI_SPICLKDIV_CLKDIV_Pos              0                                                       /*!< SPI SPICLKDIV: CLKDIV Position          */
#define SPI_SPICLKDIV_CLKDIV_Msk              (0x0000ffffUL << SPI_SPICLKDIV_CLKDIV_Pos)              /*!< SPI SPICLKDIV: CLKDIV Mask              */

/* ---------------------------------  SPI_SPISTAT  -------------------------------- */
#define SPI_SPISTAT_SPI_INT_Pos               0                                                       /*!< SPI SPISTAT: SPI_INT Position           */
#define SPI_SPISTAT_SPI_INT_Msk               (0x01UL << SPI_SPISTAT_SPI_INT_Pos)                     /*!< SPI SPISTAT: SPI_INT Mask               */
#define SPI_SPISTAT_RDOFL_Pos                 2                                                       /*!< SPI SPISTAT: RDOFL Position             */
#define SPI_SPISTAT_RDOFL_Msk                 (0x01UL << SPI_SPISTAT_RDOFL_Pos)                       /*!< SPI SPISTAT: RDOFL Mask                 */
#define SPI_SPISTAT_LE_Pos                    3                                                       /*!< SPI SPISTAT: LE Position                */
#define SPI_SPISTAT_LE_Msk                    (0x01UL << SPI_SPISTAT_LE_Pos)                          /*!< SPI SPISTAT: LE Mask                    */
#define SPI_SPISTAT_UCLK_Pos                  4                                                       /*!< SPI SPISTAT: UCLK Position              */
#define SPI_SPISTAT_UCLK_Msk                  (0x01UL << SPI_SPISTAT_UCLK_Pos)                        /*!< SPI SPISTAT: UCLK Mask                  */
#define SPI_SPISTAT_CYC_DONE_Pos              5                                                       /*!< SPI SPISTAT: CYC_DONE Position          */
#define SPI_SPISTAT_CYC_DONE_Msk              (0x01UL << SPI_SPISTAT_CYC_DONE_Pos)                    /*!< SPI SPISTAT: CYC_DONE Mask              */
#define SPI_SPISTAT_TE_Pos                    6                                                       /*!< SPI SPISTAT: TE Position                */
#define SPI_SPISTAT_TE_Msk                    (0x01UL << SPI_SPISTAT_TE_Pos)                          /*!< SPI SPISTAT: TE Mask                    */
#define SPI_SPISTAT_WRUFL_Pos                 8                                                       /*!< SPI SPISTAT: WRUFL Position             */
#define SPI_SPISTAT_WRUFL_Msk                 (0x01UL << SPI_SPISTAT_WRUFL_Pos)                       /*!< SPI SPISTAT: WRUFL Mask                 */
#define SPI_SPISTAT_TXFULL_Pos                9                                                       /*!< SPI SPISTAT: TXFULL Position            */
#define SPI_SPISTAT_TXFULL_Msk                (0x01UL << SPI_SPISTAT_TXFULL_Pos)                      /*!< SPI SPISTAT: TXFULL Mask                */
#define SPI_SPISTAT_RXFULL_Pos                10                                                      /*!< SPI SPISTAT: RXFULL Position            */
#define SPI_SPISTAT_RXFULL_Msk                (0x01UL << SPI_SPISTAT_RXFULL_Pos)                      /*!< SPI SPISTAT: RXFULL Mask                */
#define SPI_SPISTAT_CURSTATE_Pos              12                                                      /*!< SPI SPISTAT: CURSTATE Position          */
#define SPI_SPISTAT_CURSTATE_Msk              (0x07UL << SPI_SPISTAT_CURSTATE_Pos)                    /*!< SPI SPISTAT: CURSTATE Mask              */

/* --------------------------------  SPI_SPICSSTR  -------------------------------- */
#define SPI_SPICSSTR_CSNUM_Pos                0                                                       /*!< SPI SPICSSTR: CSNUM Position            */
#define SPI_SPICSSTR_CSNUM_Msk                (0x03UL << SPI_SPICSSTR_CSNUM_Pos)                      /*!< SPI SPICSSTR: CSNUM Mask                */
#define SPI_SPICSSTR_CSL_Pos                  2                                                       /*!< SPI SPICSSTR: CSL Position              */
#define SPI_SPICSSTR_CSL_Msk                  (0x01UL << SPI_SPICSSTR_CSL_Pos)                        /*!< SPI SPICSSTR: CSL Mask                  */
#define SPI_SPICSSTR_CSSETUP_Pos              8                                                       /*!< SPI SPICSSTR: CSSETUP Position          */
#define SPI_SPICSSTR_CSSETUP_Msk              (0x0fUL << SPI_SPICSSTR_CSSETUP_Pos)                    /*!< SPI SPICSSTR: CSSETUP Mask              */
#define SPI_SPICSSTR_CSHOLD_Pos               12                                                      /*!< SPI SPICSSTR: CSHOLD Position           */
#define SPI_SPICSSTR_CSHOLD_Msk               (0x0fUL << SPI_SPICSSTR_CSHOLD_Pos)                     /*!< SPI SPICSSTR: CSHOLD Mask               */
#define SPI_SPICSSTR_CSWAIT_Pos               16                                                      /*!< SPI SPICSSTR: CSWAIT Position           */
#define SPI_SPICSSTR_CSWAIT_Msk               (0x0fUL << SPI_SPICSSTR_CSWAIT_Pos)                     /*!< SPI SPICSSTR: CSWAIT Mask               */
#define SPI_SPICSSTR_CKWAIT_Pos               20                                                      /*!< SPI SPICSSTR: CKWAIT Position           */
#define SPI_SPICSSTR_CKWAIT_Msk               (0x0fUL << SPI_SPICSSTR_CKWAIT_Pos)                     /*!< SPI SPICSSTR: CKWAIT Mask               */

/* ----------------------------------  SPI_SPID  ---------------------------------- */
#define SPI_SPID_DATA_Pos                     0                                                       /*!< SPI SPID: DATA Position                 */
#define SPI_SPID_DATA_Msk                     (0x000000ffUL << SPI_SPID_DATA_Pos)                     /*!< SPI SPID: DATA Mask                     */

/* --------------------------------  SPI_SPIINT_EN  ------------------------------- */
#define SPI_SPIINT_EN_RDOFL_EN_Pos            2                                                       /*!< SPI SPIINT_EN: RDOFL_EN Position        */
#define SPI_SPIINT_EN_RDOFL_EN_Msk            (0x01UL << SPI_SPIINT_EN_RDOFL_EN_Pos)                  /*!< SPI SPIINT_EN: RDOFL_EN Mask            */
#define SPI_SPIINT_EN_LE_EN_Pos               3                                                       /*!< SPI SPIINT_EN: LE_EN Position           */
#define SPI_SPIINT_EN_LE_EN_Msk               (0x01UL << SPI_SPIINT_EN_LE_EN_Pos)                     /*!< SPI SPIINT_EN: LE_EN Mask               */
#define SPI_SPIINT_EN_UCLK_EN_Pos             4                                                       /*!< SPI SPIINT_EN: UCLK_EN Position         */
#define SPI_SPIINT_EN_UCLK_EN_Msk             (0x01UL << SPI_SPIINT_EN_UCLK_EN_Pos)                   /*!< SPI SPIINT_EN: UCLK_EN Mask             */
#define SPI_SPIINT_EN_CYC_DONE_EN_Pos         5                                                       /*!< SPI SPIINT_EN: CYC_DONE_EN Position     */
#define SPI_SPIINT_EN_CYC_DONE_EN_Msk         (0x01UL << SPI_SPIINT_EN_CYC_DONE_EN_Pos)               /*!< SPI SPIINT_EN: CYC_DONE_EN Mask         */
#define SPI_SPIINT_EN_TE_EN_Pos               6                                                       /*!< SPI SPIINT_EN: TE_EN Position           */
#define SPI_SPIINT_EN_TE_EN_Msk               (0x01UL << SPI_SPIINT_EN_TE_EN_Pos)                     /*!< SPI SPIINT_EN: TE_EN Mask               */
#define SPI_SPIINT_EN_BP_DONE_Pos             7                                                       /*!< SPI SPIINT_EN: BP_DONE Position         */
#define SPI_SPIINT_EN_BP_DONE_Msk             (0x01UL << SPI_SPIINT_EN_BP_DONE_Pos)                   /*!< SPI SPIINT_EN: BP_DONE Mask             */
#define SPI_SPIINT_EN_WRUFL_EN_Pos            8                                                       /*!< SPI SPIINT_EN: WRUFL_EN Position        */
#define SPI_SPIINT_EN_WRUFL_EN_Msk            (0x01UL << SPI_SPIINT_EN_WRUFL_EN_Pos)                  /*!< SPI SPIINT_EN: WRUFL_EN Mask            */

/*@}*/ /* end of group PAC5XXX_Peripherals */


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/** @addtogroup PAC5XXX_MemoryMap PAC5XXX Memory Mapping
  @{
*/

/* Peripheral and SRAM base address */
#define PAC5XXX_FLASH_BASE                      (0x00000000UL)                              /*!< FLASH        Base Address            */
#define PAC5XXX_FLASH_SEG0_BASE                 (0x00000000UL)                              /*!< FLASH segment 0 Base Address         */
#define PAC5XXX_FLASH_SEG1_BASE                 (0x00000400UL)                              /*!< FLASH segment 1 Base Address         */
#define PAC5XXX_FLASH_SEG2_BASE                 (0x00000800UL)                              /*!< FLASH segment 2 Base Address         */
#define PAC5XXX_FLASH_SEG3_BASE                 (0x00000C00UL)                              /*!< FLASH segment 3 Base Address         */
#define PAC5XXX_FLASH_SEG4_BASE                 (0x00001000UL)                              /*!< FLASH segment 4 Base Address         */
#define PAC5XXX_FLASH_SEG5_BASE                 (0x00001400UL)                              /*!< FLASH segment 5 Base Address         */
#define PAC5XXX_FLASH_SEG6_BASE                 (0x00001800UL)                              /*!< FLASH segment 6 Base Address         */
#define PAC5XXX_FLASH_SEG7_BASE                 (0x00001C00UL)                              /*!< FLASH segment 7 Base Address         */
#define PAC5XXX_FLASH_SEG8_BASE                 (0x00002000UL)                              /*!< FLASH segment 8 Base Address         */
#define PAC5XXX_FLASH_SEG9_BASE                 (0x00002400UL)                              /*!< FLASH segment 9 Base Address         */
#define PAC5XXX_FLASH_SEG10_BASE                (0x00002800UL)                              /*!< FLASH segment 10 Base Address        */
#define PAC5XXX_FLASH_SEG11_BASE                (0x00002C00UL)                              /*!< FLASH segment 11 Base Address        */
#define PAC5XXX_FLASH_SEG12_BASE                (0x00003000UL)                              /*!< FLASH segment 12 Base Address        */
#define PAC5XXX_FLASH_SEG13_BASE                (0x00003400UL)                              /*!< FLASH segment 13 Base Address        */
#define PAC5XXX_FLASH_SEG14_BASE                (0x00003800UL)                              /*!< FLASH segment 14 Base Address        */
#define PAC5XXX_FLASH_SEG15_BASE                (0x00003C00UL)                              /*!< FLASH segment 15 Base Address        */
#define PAC5XXX_FLASH_SEG16_BASE                (0x00004000UL)                              /*!< FLASH segment 0 Base Address         */
#define PAC5XXX_FLASH_SEG17_BASE                (0x00004400UL)                              /*!< FLASH segment 1 Base Address         */
#define PAC5XXX_FLASH_SEG18_BASE                (0x00004800UL)                              /*!< FLASH segment 2 Base Address         */
#define PAC5XXX_FLASH_SEG19_BASE                (0x00004C00UL)                              /*!< FLASH segment 3 Base Address         */
#define PAC5XXX_FLASH_SEG20_BASE                (0x00005000UL)                              /*!< FLASH segment 4 Base Address         */
#define PAC5XXX_FLASH_SEG21_BASE                (0x00005400UL)                              /*!< FLASH segment 5 Base Address         */
#define PAC5XXX_FLASH_SEG22_BASE                (0x00005800UL)                              /*!< FLASH segment 6 Base Address         */
#define PAC5XXX_FLASH_SEG23_BASE                (0x00005C00UL)                              /*!< FLASH segment 7 Base Address         */
#define PAC5XXX_FLASH_SEG24_BASE                (0x00006000UL)                              /*!< FLASH segment 8 Base Address         */
#define PAC5XXX_FLASH_SEG25_BASE                (0x00006400UL)                              /*!< FLASH segment 9 Base Address         */
#define PAC5XXX_FLASH_SEG26_BASE                (0x00006800UL)                              /*!< FLASH segment 10 Base Address        */
#define PAC5XXX_FLASH_SEG27_BASE                (0x00006C00UL)                              /*!< FLASH segment 11 Base Address        */
#define PAC5XXX_FLASH_SEG28_BASE                (0x00007000UL)                              /*!< FLASH segment 12 Base Address        */
#define PAC5XXX_FLASH_SEG29_BASE                (0x00007400UL)                              /*!< FLASH segment 13 Base Address        */
#define PAC5XXX_FLASH_SEG30_BASE                (0x00007800UL)                              /*!< FLASH segment 14 Base Address        */
#define PAC5XXX_FLASH_SEG31_BASE                (0x00007C00UL)                              /*!< FLASH segment 15 Base Address        */

#define PAC5XXX_SRAM_BASE                       (0x20000000UL)                              /*!< SRAM         Base Address            */
#define PAC5XXX_PERIPH_BASE                     (0x40000000UL)                              /*!< Peripheral   Base Address            */

/* Peripheral memory map */
#define PAC5XXX_SYSCTL_BASE                     (PAC5XXX_PERIPH_BASE)                         /*!< System/Clock Control    Base Address */
#define PAC5XXX_MEMCTL_BASE                     (PAC5XXX_PERIPH_BASE + 0x20000)               /*!< FLASH Memory Controller Base Address */
#define PAC5XXX_WDT_BASE                        (PAC5XXX_PERIPH_BASE + 0x30000)               /*!< Watchdog Timer          Base Address */
#define PAC5XXX_RTC_BASE                        (PAC5XXX_PERIPH_BASE + 0x40000)               /*!< RTC                     Base Address */
#define PAC5XXX_GPIOA_BASE                      (PAC5XXX_PERIPH_BASE + 0x70000)               /*!< GPIO A                  Base Address */
#define PAC5XXX_GPIOB_BASE                      (PAC5XXX_PERIPH_BASE + 0x70040)               /*!< GPIO B                  Base Address */
#define PAC5XXX_GPIOAB_BASE                     (PAC5XXX_PERIPH_BASE + 0x70080)               /*!< GPIO A/B                Base Address */
#define PAC5XXX_GPIOC_BASE                      (PAC5XXX_PERIPH_BASE + 0x80000)               /*!< GPIO C                  Base Address */
#define PAC5XXX_GPIOD_BASE                      (PAC5XXX_PERIPH_BASE + 0x80040)               /*!< GPIO D                  Base Address */
#define PAC5XXX_GPIOCD_BASE                     (PAC5XXX_PERIPH_BASE + 0x80080)               /*!< GPIO C/D                Base Address */
#define PAC5XXX_GPIOE_BASE                      (PAC5XXX_PERIPH_BASE + 0x90000)               /*!< GPIO E                  Base Address */
#define PAC5XXX_TIMERA_BASE                     (PAC5XXX_PERIPH_BASE + 0xD0000)               /*!< Timer A/DTGA[0:3]       Base Address */
#define PAC5XXX_TIMERB_BASE                     (PAC5XXX_PERIPH_BASE + 0xE0000)               /*!< Timer B/DTGB            Base Address */
#define PAC5XXX_TIMERC_BASE                     (PAC5XXX_PERIPH_BASE + 0xF0000)               /*!< Timer C/DTGC            Base Address */
#define PAC5XXX_TIMERD_BASE                     (PAC5XXX_PERIPH_BASE + 0x100000)              /*!< Timer D/DTGD            Base Address */
#define PAC5XXX_ADC_BASE                        (PAC5XXX_PERIPH_BASE + 0x150000)              /*!< ADC                     Base Address */
#define PAC5XXX_I2C_BASE                        (PAC5XXX_PERIPH_BASE + 0x1B0000)              /*!< I2C                     Base Address */
#define PAC5XXX_UART_BASE                       (PAC5XXX_PERIPH_BASE + 0x1D0000)              /*!< UART                    Base Address */
#define PAC5XXX_SOCBRIDGE_BASE                  (PAC5XXX_PERIPH_BASE + 0x200000)              /*!< SOC Bridge              Base Address */
#define PAC5XXX_SPI_BASE                       (PAC5XXX_PERIPH_BASE + 0x210000)               /*!< SPI                    Base Address */
/*@}*/ /* end of group PAC5XXX_MemoryMap */


/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/

/** @addtogroup PAC5XXX_PeripheralDecl PAC5XXX Peripheral Declaration
  @{
*/

#define PAC5XXX_SYSCTL                           ((PAC5XXX_SYSCLKCTL_TypeDef *) PAC5XXX_SYSCTL_BASE)
#define PAC5XXX_MEMCTL                           ((PAC5XXX_MEMCTL_TypeDef *) PAC5XXX_MEMCTL_BASE)
#define PAC5XXX_WDT                              ((PAC5XXX_WDT_TypeDef *) PAC5XXX_WDT_BASE)
#define PAC5XXX_RTC                              ((PAC5XXX_RTC_TypeDef *) PAC5XXX_RTC_BASE)
#define PAC5XXX_GPIOA                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOA_BASE)
#define PAC5XXX_GPIOB                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOB_BASE)
#define PAC5XXX_GPIOAB                           ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOAB_BASE)
#define PAC5XXX_GPIOC                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOC_BASE)
#define PAC5XXX_GPIOD                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOD_BASE)
#define PAC5XXX_GPIOCD                           ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOCD_BASE)
#define PAC5XXX_GPIOE                            ((PAC5XXX_GPIO_TypeDef *) PAC5XXX_GPIOE_BASE)
#define PAC5XXX_TIMERA                           ((PAC5XXX_Timer8CC_TypeDef *) PAC5XXX_TIMERA_BASE)
#define PAC5XXX_TIMERB                           ((PAC5XXX_Timer4CC_TypeDef *) PAC5XXX_TIMERB_BASE)
#define PAC5XXX_TIMERC                           ((PAC5XXX_Timer2CC_TypeDef *) PAC5XXX_TIMERC_BASE)
#define PAC5XXX_TIMERD                           ((PAC5XXX_Timer2CC_TypeDef *) PAC5XXX_TIMERD_BASE)
#define PAC5XXX_ADC                              ((PAC5XXX_ADC_TypeDef *) PAC5XXX_ADC_BASE)
#define PAC5XXX_I2C                              ((PAC5XXX_I2C_TypeDef *) PAC5XXX_I2C_BASE)
#define PAC5XXX_UART                             ((PAC5XXX_UART_TypeDef *) PAC5XXX_UART_BASE)
#define PAC5XXX_SPI                              ((PAC5XXX_SPI_TypeDef *) PAC5XXX_SPI_BASE)
#define PAC5XXX_SOCBRIDGE                        ((PAC5XXX_SocBridge_TypeDef *) PAC5XXX_SOCBRIDGE_BASE)

/*@}*/ /* end of group PAC5XXX_PeripheralDecl */


/*@}*/ /* end of group PAC52XX_Definitions */ 
/** @} */ /* End of group PAC52XX */
/** @} */ /* End of group Active-Semi */

#ifdef __cplusplus
}
#endif

#endif  // PAC52XX_H
