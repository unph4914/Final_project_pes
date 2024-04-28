/*
 * definitions.h
 *
 *  Created on: 13-Dec-2023
 *      Author: Unmesh
 */

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#define CPU_CLOCK_HZ 48000000 // 48 MHz

#define I2C0_SCL_PIN   		 0  // SCL pin number on Port B PTB0
#define I2C0_SDA_PIN   		 1  // SDA pin number on Port B PTB1
#define I2C_MASTER     		 0x20 // Master mode
#define I2C_TRANSMIT         0x0 // Transmit mode
#define I2C_RECEIVE    		 0x1  // Receive mode
#define ZX_SENSOR_ADDRESS    0x10 // ZX Sensor Slave ID

#define RED_LED_PIN   18
#define GREEN_LED_PIN 19
#define BLUE_LED_PIN  1

// Define the TPM channels
#define TPM_RED   TPM2
#define TPM_GREEN TPM2
#define TPM_BLUE  TPM0

// Define the respective channels
#define TPM_CHANNEL_RED   0
#define TPM_CHANNEL_GREEN 1
#define TPM_CHANNEL_BLUE  1

#define SENSOR_PIN PORTC_PCR6    //Using pin 6 of PORTC for the sensor
#define SENSOR_PORT PTC
#define SENSOR_PIN_NO 6

#define BUZZER_PIN PORTC_PCR5    //Using pin 5 of PORTC for the buzzer
#define BUZZER_PORT PTC
#define BUZZER_PIN_NO 5

#endif /* DEFINITIONS_H_ */
