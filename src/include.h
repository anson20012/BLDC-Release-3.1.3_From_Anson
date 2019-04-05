
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

#ifndef INCLUDE_H
#define INCLUDE_H

#include "pac52XX.h"
#include "pac5xxx_driver_gpio.h"
#include "pac5xxx_driver_adc.h"
#include "pac5xxx_driver_timer.h"
#include "pac5xxx_driver_socbridge.h"
#include "pac5xxx_driver_tile.h"
#include "pac5xxx_driver_system.h"
#include "pac5xxx_driver_rtc.h"
#include "pac5xxx_driver_watchdog.h"
#include "pac5xxx_driver_memory.h"
#include "pac5xxx_driver_uart.h"

#include "config_board.h"
#include "pac5xxx_tile_DriverManager.h"
#include "pac5xxx_tile_PowerManager.h"
#include "pac5xxx_tile_SignalManager.h"
#include "pac5xxx_tile_SystemManager.h"

#include "fix16.h"
#include "pid.h"
#include "config_options.h"
#include "config_appliction.h"
#include "sensorless.h"
#include "PAC522x_app.h"
#include "PAC525x_app.h"
#include "uart.h"
#include "braking_control.h"
#include "debug_dac.h"
#include "user_parameter.h"
#include "hall.h"
#include "sim_config.h"
#include "motor_protect_check.h"
#include "speed_ctr_adc_cmd.h"
#include "speed_ctr_PPM_cmd.h"
#include "ppd_config.h"
#include "version.h"


#endif
