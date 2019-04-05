;/*****************************************************************************
; * @file:    startup_pac52xx_keil.s
; * @purpose: CMSIS Cortex-M0 Core Device Startup File for the 
; *           PAC52XX Device Family
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; * Copyright (C) 2017, Active-Semi International
; *
; * THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES, 
; * AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S 
; * APPLICATION TO PAC PROCESSORS SUPPLIED BY ACTIVE-SEMI INTERNATIONAL; 
; * (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT 
; * ACTIVE-SEMICONDUCTOR IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
; * DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
; * ONLY BY CERTAIN AUTHORIZED PERSONS. 
; *
; *****************************************************************************/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000100

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0				          ; Reserved
                DCD     0						  ; Reserved
                DCD     0						  ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     MemCtl_IRQHandler         ; 0: Memory Controller Handler
                DCD 	SysClk_IRQHandler         ; 1: System and Clock Controller Handler
				DCD     Wdt_IRQHandler            ; 2: Watchdog Timer Handler
				DCD     GpioA_IRQHandler          ; 3: GPIO A Handler
				DCD     GpioB_IRQHandler          ; 4: GPIO B Handler
				DCD     GpioC_IRQHandler          ; 5: GPIO C Handler
				DCD     GpioD_IRQHandler          ; 6: GPIO D Handler
				DCD     GpioE_IRQHandler          ; 7: GPIO E Handler
				DCD     TimerA_IRQHandler         ; 8: Timer A Handler (Base, CC 0-5)
				DCD     TimerAExt_IRQHandler      ; 9: Timer A Ext Handler (CC 6, 7)
				DCD     TimerB_IRQHandler         ; 10: Timer B Handler (Base + CC)
				DCD     TimerC_IRQHandler         ; 11: Timer C Handler (Base + CC)
				DCD     TimerD_IRQHandler         ; 12: Timer D Handler (Base + CC)
				DCD     ADC_IRQHandler            ; 13: ADC Handler
				DCD     SocBridge_IRQHandler      ; 14: SocBridge Handler
				DCD     SPIB_IRQHandler           ; 15: SPI-B Handler
				DCD     UART_IRQHandler           ; 16: UART Handler
				DCD     I2C_IRQHandler            ; 17: I2C Handler
				DCD     EMUX_IRQHandler           ; 18: EMUX Handler
				DCD     RTC_IRQHandler            ; 19: RTC Handler
					
                IF      :LNOT::DEF:NO_CRP
                AREA    |.ARM.__at_0x02FC|, CODE, READONLY
CRP_Key         DCD     0xFFFFFFFF
                ENDIF


                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)                

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  MemCtl_IRQHandler         [WEAK]
				EXPORT  MemCtl_IRQHandler         [WEAK]	
				EXPORT  SysClk_IRQHandler         [WEAK]
				EXPORT  Wdt_IRQHandler            [WEAK]
				EXPORT  GpioA_IRQHandler          [WEAK]
				EXPORT  GpioB_IRQHandler          [WEAK]
				EXPORT  GpioC_IRQHandler          [WEAK]
				EXPORT  GpioD_IRQHandler          [WEAK]
				EXPORT  GpioE_IRQHandler          [WEAK]
				EXPORT  TimerA_IRQHandler         [WEAK]
				EXPORT  TimerAExt_IRQHandler      [WEAK]
				EXPORT  TimerB_IRQHandler         [WEAK]
				EXPORT  TimerC_IRQHandler         [WEAK]
				EXPORT  TimerD_IRQHandler         [WEAK]
				EXPORT  ADC_IRQHandler            [WEAK]
				EXPORT  SocBridge_IRQHandler      [WEAK]
				EXPORT  SPIB_IRQHandler           [WEAK]
				EXPORT  UART_IRQHandler           [WEAK]
				EXPORT  I2C_IRQHandler            [WEAK]
				EXPORT  EMUX_IRQHandler           [WEAK]
				EXPORT  RTC_IRQHandler            [WEAK]

MemCtl_IRQHandler
SysClk_IRQHandler
Wdt_IRQHandler
GpioA_IRQHandler
GpioB_IRQHandler
GpioC_IRQHandler
GpioD_IRQHandler
GpioE_IRQHandler
TimerA_IRQHandler
TimerAExt_IRQHandler
TimerB_IRQHandler
TimerC_IRQHandler
TimerD_IRQHandler
ADC_IRQHandler
SocBridge_IRQHandler
SPIB_IRQHandler
UART_IRQHandler
I2C_IRQHandler
EMUX_IRQHandler
RTC_IRQHandler

                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
