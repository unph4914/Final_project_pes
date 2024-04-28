/*
 * i2c_functions.h
 *
 *  Created on: 13-Dec-2023
 *      Author: Unmesh
 */

#ifndef I2C_FUNCTIONS_H_
#define I2C_FUNCTIONS_H_

#include "definitions.h"

void i2c_init();

void i2c_start();

void i2c_repeated_start();

void i2c_start_stop();

void i2c_send_byte(uint8_t data);

uint8_t i2c_read_byte(void);

void i2c_stop();

void readI2CData();


#endif /* I2C_FUNCTIONS_H_ */
