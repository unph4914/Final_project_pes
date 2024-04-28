/*
 * i2c_functions.c
 *
 *  Created on: 13-Dec-2023
 *      Author: Unmesh
 *
 *  Description: This file contains functions for initializing and controlling I2C communication.
 *  It includes functions for initializing I2C, generating start and stop conditions, sending and
 *  receiving bytes, and reading data from a specific I2C device. The functions are designed to
 *  facilitate communication with an I2C device, specifically a ZX Sensor, for reading gesture
 *  and axis data. Conditional compilation is used to include the readI2CData function when I2C
 *  is defined, demonstrating the ability to customize the inclusion of functionalities.
 */

#include "i2c_functions.h"

void i2c_init() {
	// Enable clock for I2C0 and Port B
	SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;

	// Set I2C pins to I2C function on Port B
	PORTB->PCR[I2C0_SCL_PIN] = PORT_PCR_MUX(2); // Set PTB0 to I2C SCL
	PORTB->PCR[I2C0_SDA_PIN] = PORT_PCR_MUX(2); // Set PTB1 to I2C SDA

	// Set I2C to master mode, set baud rate, enable I2C
	I2C0->F = 0x0E; // Set baud rate
	I2C0->C1 = I2C_C1_IICEN_MASK;
}

void i2c_start() {
	I2C0->C1 |= I2C_C1_MST_MASK | I2C_C1_TX_MASK; // Enter master mode and transmit mode
	I2C0->D = (ZX_SENSOR_ADDRESS << 1) | I2C_TRANSMIT; // Send slave address with W/R bit
	while ((I2C0->S & I2C_S_IICIF_MASK) == 0) {
	} // Wait for transfer complete
	I2C0->S |= I2C_S_IICIF_MASK; // Clear interrupt flag
}

void i2c_repeated_start() {
	I2C0->C1 |= I2C_C1_RSTA_MASK;		// Condition for repeated start
}

void i2c_start_stop() {
	I2C0->C1 |= I2C_C1_MST_MASK; // Enter master mode and transmit mode
	I2C0->C1 |= I2C_C1_TX_MASK;
	I2C0->D = (ZX_SENSOR_ADDRESS << 1) | I2C_RECEIVE; // Send slave address with W/R bit
	while ((I2C0->S & I2C_S_IICIF_MASK) == 0) {
	} 							 // Wait for transfer complete
	I2C0->S |= I2C_S_IICIF_MASK; // Clear interrupt flag
	for (int i = 0; i < 100; i++)
		;
}

void i2c_send_byte(uint8_t data) {
	I2C0->D = data;
	while ((I2C0->S & I2C_S_IICIF_MASK) == 0) {
	} 							 // Wait for transfer complete
	I2C0->S |= I2C_S_IICIF_MASK; // Clear interrupt flag
	for (int i = 0; i < 200; i++)
		;
}

uint8_t i2c_read_byte(void) {
	uint8_t data;
	I2C0->C1 &= ~I2C_C1_TX_MASK; // Set to receive mode
	data = I2C0->D;
	while ((I2C0->S & I2C_S_IICIF_MASK) == 0) {
	} 							 // Wait for transfer complete
	I2C0->S |= I2C_S_IICIF_MASK; // Clear interrupt flag
	return data;
}

void i2c_stop() {
	I2C0->C1 &= ~I2C_C1_MST_MASK; // Exit master mode
	I2C0->C1 &= ~I2C_C1_TX_MASK;
	for (int i = 0; i < 100; i++)
		;
}

#ifdef I2C
void readI2CData() {
	uint8_t dataX = zx_read_register(0x08);				// To read X direction Data
	uint8_t dataZ = zx_read_register(0x0a);				// To read Z direction Data
	uint8_t dataGesture = zx_read_register(0x04);		// To read Gesture Data
	i2c_stop();

	PRINTF("X Axis Value = %d, Z Axis Value = %d Gesture %d Detected\r\n",
			dataX, dataZ, dataGesture);
}
#endif
