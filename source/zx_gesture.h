/*
 * zx_gesture.h
 *
 *  Created on: 13-Dec-2023
 *      Author: Unmesh
 */

#ifndef ZX_GESTURE_H_
#define ZX_GESTURE_H_

#include "definitions.h"
#include "i2c_functions.h"

uint8_t zx_read_register(uint8_t reg);

void zx_write_register(uint8_t reg, uint8_t value);



#endif /* ZX_GESTURE_H_ */
