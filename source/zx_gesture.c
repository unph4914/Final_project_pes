/*
 * zx_gesture.c
 *
 * Created on: 13-Dec-2023
 *      Author: Unmesh
 *
 * Description: This file contains functions to interact with a ZX Gesture Sensor using I2C communication.
 * It includes functions for reading from and writing to the registers of the ZX Gesture Sensor.
 * The 'zx_read_register' function is used to read data from a specific register of the sensor,
 * while the 'zx_write_register' function is used to write data to a specific register. These functions
 * encapsulate the necessary I2C start, send, and stop sequences for proper communication with the sensor.
 */

#include "zx_gesture.h"

// Read a byte from a specific register of the ZX Gesture Sensor
uint8_t zx_read_register(uint8_t reg) {
	uint8_t dummy_data = 0;
	i2c_start_stop(); 			// Start I2C communication
	dummy_data = I2C0->D; 		// Dummy read to clear the data register
	uint8_t data = i2c_read_byte(); // Read byte from the sensor
	i2c_stop(); 				// Stop I2C communication
	return data; 				// Return the read data
}

// Write a byte to a specific register of the ZX Gesture Sensor
void zx_write_register(uint8_t reg, uint8_t value) {
	i2c_start(); 				// Start I2C communication
	for (int i = 0; i < 100; i++)
		; 						// Short delay
	i2c_send_byte(reg); 		// Send the register address
	i2c_send_byte(value); 		// Send the data to write
	i2c_stop(); 				// Stop I2C communication
	for (int i = 0; i < 100; i++)
		; 						// Short delay
}
