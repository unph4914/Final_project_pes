/*
 *  main.c
 *
 *	Application point of entry
 *
 *  Created on: 13-Dec-2023
 *      Author: Unmesh
 *
 * Description: This program is designed to control an embedded system with various peripherals.
 * It includes initialization for RGB LEDs, an IR sensor, a buzzer, and I2C functions.
 * Additionally, it features a loop that continuously processes sensor data and reads I2C data based on a conditional compilation directive.
 */

#include "definitions.h"
#include "buzzer_ir_sensor.h"
#include "pwm_red.h"
#include "i2c_functions.h"
#include "zx_gesture.h"

int main(void) {
	uint8_t brightness = 0;
	uint8_t increasing = 1;

	// Initialize board-specific configurations
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	BOARD_InitDebugConsole();

	// Initialize peripherals
	init_RGB_LED();
	init_IR_Sensor();
	init_Buzzer();
	i2c_init();

	while (1) {
		// Process sensor data and adjust brightness
		processSensor(&brightness, &increasing);
#ifdef I2C
		// Read I2C data if I2C is defined
		readI2CData();
#endif
	}
}
