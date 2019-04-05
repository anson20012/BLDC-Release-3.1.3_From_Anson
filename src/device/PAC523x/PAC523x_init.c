
//=============================================================================
// Copyright (C) 2017, Active-Semi International
//
// THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
// AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
// APPLICATION TO PAC PROCESSORS SUPPLIED BY ACTIVE-SEMI INTERNATIONAL;
// (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
// ACTIVE-SEMICONDUCTOR IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
// DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
// ONLY BY CERTAIN AUTHORIZED PERSONS.
//
//=============================================================================

#include "include.h"


#ifdef PAC523x

//=============================================================================
/// @brief  This function configures the PAC peripherals for this application
/// @param  None
/// @return None
//=============================================================================
void peripheral_init(void)
{
    // Configure SOC Bridge for talking to CAFE
    pac5xxx_tile_socbridge_config(1, 0);                                            // enable, int_enable

    // Disable driver manager and verify active - need to enable even in PAC5210 to get ENHS pin to work
    pac5xxx_tile_register_write(ADDR_ENDRV, 0);
    while ((pac5xxx_tile_register_read(ADDR_ENDRV) & 0x01) != 0)
    {
		set_fault(48828);
    }

    // PLL 50MHZ, FCLK: 50MHz, PLLCLK: 50MHz, ACLK: 50MHz (/1), HCLK: 50MHz (/1)
	pac5xxx_sys_pll_config(50);
	pac5xxx_sys_ccs_config(CCSCTL_CLKIN_CLKREF, CCSCTL_ACLKDIV_DIV1, CCSCTL_HCLKDIV_DIV1);
	pac5xxx_memctl_wait_state(FLASH_WSTATE_25MHZ_LT_HCLK_LTE_50MHZ);

	// Configure timerA for PWM driver and Sampling
	pac5xxx_timer_clock_config(TimerA, TxCTL_CS_ACLK, TxCTL_PS_DIV1);  
	   // Configure TIMERA_TICKS_32KHZ  (updown timer, HALK@50Mhz, /781)
	pac5xxx_timer_base_config(TimerA, TIMERA_PERIOD_TICKS, 0, TxCTL_MODE_UPDOWN, 0); 
	pac5xxx_timer_cctrl_config(TimerA, 1, (TIMERA_PERIOD_TICKS-20), 1); // timerA compare interrupt
	NVIC_SetPriority(TimerA_IRQn, 1);
	NVIC_EnableIRQ(TimerA_IRQn);														// Enable NVIC for Timer A

	// Configure timerA for PWM output (6 phase)
	pac5xxx_dtg_config(DTGA0, DT_LED_TICKS, DT_TED_TICKS, 0, 0, 0, 0);					// Configure DTGA0
	pac5xxx_dtg_config(DTGA1, DT_LED_TICKS, DT_TED_TICKS, 0, 0, 0, 0);					// Configure DTGA1
	pac5xxx_dtg_config(DTGA2, DT_LED_TICKS, DT_TED_TICKS, 0, 0, 0, 0);					// Configure DTGA2
	pac5xxx_timer_cctrl_config(TimerA, 4, (TIMERA_PERIOD_TICKS>>1), 0);					// Set 0 duty
	pac5xxx_timer_cctrl_config(TimerA, 5, (TIMERA_PERIOD_TICKS>>1), 0);					// Set 0 duty
	pac5xxx_timer_cctrl_config(TimerA, 6, (TIMERA_PERIOD_TICKS>>1), 0);					// Set 0 duty

	// Select PA0/1/2/3/4/5 pin to PWM output (6 phase)
//	pac5xxx_timer_io_select_pwma4_pa3();	// UH
//	pac5xxx_timer_io_select_pwma5_pa4();	// VH
//	pac5xxx_timer_io_select_pwma6_pa5();	// WH
	pac5xxx_timer_io_select_pwma0_pa0();	// UL
	pac5xxx_timer_io_select_pwma1_pa1();	// VL
	pac5xxx_timer_io_select_pwma2_pa2();	// WL

	// Enable PORTA-0,1,2,3,4,5 outputs
	pac5xxx_gpio_out_enable_a(0x3F);


	//Configure timerC for getting zero cross point or hall state
	pac5xxx_timer_clock_config(TimerC, TxCTL_CS_HCLK, TxCTL_PS_DIV1);
	pac5xxx_timer_base_config(TimerC, TIMERC_PERIOD_TICKS, 0, TxCTL_MODE_UP, 0);	// TIMERC_TICKS_100KHZ
	pac5xxx_timer_base_int_enable(TimerC, 1);										// Enable base interrupts (timer)
	NVIC_SetPriority(TimerC_IRQn, 0);												// Set priority to 0
	NVIC_DisableIRQ(TimerC_IRQn);													// Disable TimerC interrupt


	// Configure timerD for 30-degree delay and set highest priority
	pac5xxx_timer_clock_config(TimerD, TxCTL_CS_HCLK, TxCTL_PS_DIV128);
	pac5xxx_timer_base_config(TimerD, TIMERD_TICKS_30DEG_PLL, 0, TxCTL_MODE_UP, 0);	// Configure TimerD slowest
	pac5xxx_timer_cctrl_config(TimerD, 0, 2000, 1);
	NVIC_SetPriority(TimerD_IRQn, 0);
	NVIC_DisableIRQ(TimerD_IRQn);


	// Configure nIRQ1 interrupt input signals and enable interrupts
	pac5xxx_gpio_int_mask_b(NIRQ1_PIN_MASK);									// Set interrupt mask at startup (interrupt startup workaround)
	pac5xxx_gpio_int_polarity_b(0);												// Set interrupt polarity (high-to-low)
	pac5xxx_gpio_int_enable_b(NIRQ1_PIN_MASK);									// Enable interrupts in IO controller
	NVIC_SetPriority(GpioB_IRQn, 3);											// Set priority to 0
	NVIC_EnableIRQ(GpioB_IRQn);													// Enable interrupts in NVIC
	pac5xxx_gpio_int_flag_clear_b(NIRQ1_PIN_MASK);								// Clear any active interrupt flags
	pac5xxx_gpio_int_mask_b(0);													// Clear interrupt mask and interrupts are enabled


	// Configure UART IO
	pac5xxx_uart_io_config();
	pac5xxx_gpio_out_pull_up_e(0x06);
	// Configure UART peripheral
	pac5xxx_uart_config_LCR(UART_BPC_8,                    // Bits per character
							UART_STOP_BITS_1,              // Stop Bits
							0,                             // Parity Enabled
							0,				               // Parity Type
							0,                             // Stick Parity
							UART_BRKCTL_NORMAL,            // Break Control
							1);     					   // Divisor Latch Access
	// Configure UART clock for baud rate
	pac5xxx_uart_config_divisor_latch(0x1B);			   // 25MHz clock: divisor: 0x0D, fractional: 0x90
	pac5xxx_uart_config_fractional_divisor(0x20);

	// Configure UART peripheral for access to FIFO from this point on
	pac5xxx_uart_fifo_access();
	// Enable FIFOs, so that the interrupts will work properly
	pac5xxx_uart_fifo_enable(1);
	// Enable receive data available interrupt and NVIC for UART interrupts
	pac5xxx_uart_int_enable_RDAI(1);
	NVIC_SetPriority(UART_IRQn, 3);			// Set lowest priority
	NVIC_EnableIRQ(UART_IRQn);


	// Configure ADC sampling engine:
	// EMUX configuration
    pac5xxx_adc_enable(0);
	pac5xxx_adc_emux_config(ADCEMUXCTL_EMUXC_SEQ, ADCEMUXCTL_EMUXDIV_DIV2);	 		// Configure EMUX to do conversions from ADC sequencer, /2 EMUX divider (HCLK=50MHz/2 = 25MHz)
	pac5xxx_adc_config_emux_io();													// Configure device IO for EMUX

	// ADC configuration
    pac5xxx_adc_config(ADCCTL_ADSTART_AUTO_01_IND_TRIG, ADCCTL_ADCDIV_DIV4, 1);		// Configure ADC for AS0 chained triggers, /6 divider (PLLCLK=100MHz/3=16.66MHz), repeat mode

    // Select PC pin to ADC mode
	pac5xxx_adc_config_io(ADC_CHANNEL_MASK);										// Configure device IO for ADC conversions (as Analog inputs)

	// AS0 configuration
	pac5xxx_timer_a_ccctr0_value_set(5);                   							// Set value for AS0 trigger at triangle peak (PWM center)

	// ADC sequence configuration
#ifdef R_3_SHUNT
	pac5xxx_adc_as0_config_pwm(ADCCTLX_AS1D_DEPTH7, ADCCTLX_TRIGEDGE_LOWTOHI, ADCCTLX_TRIGPWM_PWMA0);
	pac5xxx_adc_as0_sequence_config(0, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_VU_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(1, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_VV_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(2, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_VW_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(3, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_VIN_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(4, VBUS_ADC_SAMPLE_CHANEL, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_IV_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(5, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_IW_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(6, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_IU_EDATA, ASSEQ_DELAY_0);
#else
	pac5xxx_adc_as0_config_pwm(ADCCTLX_AS1D_DEPTH6, ADCCTLX_TRIGEDGE_LOWTOHI, ADCCTLX_TRIGPWM_PWMA0);
	pac5xxx_adc_as0_sequence_config(0, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_VU_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(1, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_VV_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(2, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_VW_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(3, ADCCTL_ADMUX_AD0, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_VIN_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(4, VBUS_ADC_SAMPLE_CHANEL, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_VR_EDATA, ASSEQ_DELAY_0);
	pac5xxx_adc_as0_sequence_config(5, ADCCTL_ADMUX_AD2, ASSEQ_MSPI_AFTER_SH, ADC_SEQ_M1_IBUS_EDATA, ASSEQ_DELAY_0);
#endif

	// Enable ADC interrupts on AS0 for control loop
	pac5xxx_adc_int_enable_as0(1);									// Enable interrupts for AS0 complete
	NVIC_EnableIRQ(ADC_IRQn);										// Enable ADC interrupts in the NVIC
	NVIC_SetPriority(ADC_IRQn,2);

	// Enable ADC
	pac5xxx_adc_enable(1);											// Enable ADC. Automated sequences will begin after issuing ADC start in main()
}


//=============================================================================
/// @brief  This function configures PAC analog peripheral
/// @param  None
/// @return None
//=============================================================================
void cafe_init(void)
{
    // Configure SOC Bridge for talking to CAFE
    pac5xxx_tile_socbridge_config(1, 0);                                    // enable, int_enable

    // Write all CAFE registers
    // If any power manager error bits set on startup, clear them
    if (pac5xxx_tile_register_read(ADDR_STATUS))
        pac5xxx_tile_register_write(ADDR_STATUS, 0xFF);

    pac5xxx_tile_register_write(ADDR_PWRCTL, 0x04);                         // Wake Up Timer == 1sec
    pac5xxx_tile_register_write(ADDR_MISC, MODULE_MISC_BITS_DEFAULT);       // Set MCU Alive, Enable Signal Manager

    // Reset AFE registers to default state
//    pac5xxx_tile_register_write(ADDR_FAULTMASK, 0x00);
//    pac5xxx_tile_register_write(ADDR_SPECCFG0, 0x00);
//    pac5xxx_tile_register_write(ADDR_SPECCFG1, 0x00);
//    pac5xxx_tile_register_write(ADDR_SYSCONF, 0x0C);
    pac5xxx_tile_register_write(ADDR_PROTINTM, 0x00);
    pac5xxx_tile_register_write(ADDR_CFGDRV0, 0x00);
    pac5xxx_tile_register_write(ADDR_CFGDRV1, 0x00);
    pac5xxx_tile_register_write(ADDR_CFGDRV2, 0x00);
    pac5xxx_tile_register_write(ADDR_CFGDRV3, 0x00);
    pac5xxx_tile_register_write(ADDR_SIGSET, 0x00);
    pac5xxx_tile_register_write(ADDR_SHCFG1, 0x00);                         // Disable ADC Scan (EMUX), Disable ADC Buffer

    app_amplifier_gain_init(0x01);

	//Configure Sensorless Comparators
	pac5xxx_tile_register_write(ADDR_CFGAIO7, 0xD0);		   		// MODE7[1:0] = 11b (special mode), OPT7[1:0] = 01b (AB1 as COMP-), POL7 = 0 (act high), MUX[2:0] = n/a
	pac5xxx_tile_register_write(ADDR_CFGAIO8, 0xD0);		   		// MODE8[1:0] = 11b (special mode), OPT8[1:0] = 01b (bypass FF, select MUX out for nIRQ2/POS), POL8 = 0 (act high), MUX[2:0] = n/a
	pac5xxx_tile_register_write(ADDR_CFGAIO9, SLCOMP7 | 0xC0); 		// MODE9[1:0] = 01b (CT Vfilt), OPT9[1:0] = 0bxx (AIO7), POL9 = 0 (act high), MUX[2:0] = n/a

	
	
	
	//Configure Blanking Time Feature
	pac5xxx_tile_register_write(ADDR_BLANKING, 0x13);


	// HYSMODE[7] = 1b (0/20/40/80), HYSAIO7[3:0] = 1010b (40/40)
	pac5xxx_tile_register_write(ADDR_SPECCFG0, (0x80|0x05));
	// HYSAIO8[7:4] = 1010b (40/40), HYSAIO9[3:0] = 1010b (40/40)
	pac5xxx_tile_register_write(ADDR_SPECCFG1, (0x50|0x05));

	// SMUXAIO7[3:0] = 01b (AB1 as COMP-), SMUXAIO8[3:0] = 01b (AB1 as COMP-)
	pac5xxx_tile_register_write(ADDR_SPECCFG2, 0x11);
	// SMUXAIO9[3:0] = 01b (AB1 as COMP-)
	pac5xxx_tile_register_write(ADDR_SPECCFG3, 0x10);
	
	
	
    init_over_current_limit(0x3FF);

    // Clear any error bits
    pac5xxx_tile_register_write(ADDR_PROTSTAT, 0xFF);                       // clear any set bits

    // Enable protection interrupt mask
    pac5xxx_tile_register_write(ADDR_PROTINTM, 0x07);

    // Configure PR event driver settings
	pac5xxx_tile_register_write(ADDR_CFGDRV0, 0x00);						// Diff Amp AIO10/32 Prop Delay 0 ns
	pac5xxx_tile_register_write(ADDR_CFGDRV1, (0x00 | 0x08 | 0x04 | 0x01));	// Diff Amp AIO54 Prop Delay 0 ns (0x00), Disable HS drivers on H/L-PROT (0x08), Disable LS drivers on H/L-PROT (0x04), Enable Break-Before-Make (0x01)
	pac5xxx_tile_register_write(ADDR_CFGDRV2, 0x00);
	pac5xxx_tile_register_write(ADDR_CFGDRV3, 0x00);

    // Enable hysteresis on comparators
    pac5xxx_tile_register_write(ADDR_SIGSET, (0x08 | 0x04));              	// Enable comparator hysteresis on HPROT (0x08) and LPROT (0x04)

    // EMUX configuration
	pac5xxx_tile_register_write(ADDR_SHCFG1, (0x10 | 0x08 | 0x07));			// Enable EMUX (0x10), Enable ADC Buffer (0x08), Enable S/H for Diff Amp 10/32/54 (0x07)

	// Enable driver and verify active
//	pac5xxx_tile_register_write(ADDR_ENDRV, 1);
//	if ((pac5xxx_tile_register_read(ADDR_ENDRV) & 0x01) != 1)
//	{
//		set_fault(48828);
//		while (1);
//	}
}
#endif
