/*
 * buzzer_ir_sensor.h
 *
 *  Created on: 13-Dec-2023
 *      Author: Unmesh
 */

#ifndef BUZZER_IR_SENSOR_H_
#define BUZZER_IR_SENSOR_H_

#include "definitions.h"

void init_IR_Sensor();

void init_Buzzer();

void delayMicroseconds(long int us);

void playTone(int frequency, int duration);

void processSensor(uint8_t *brightness, uint8_t *increasing);


#endif /* BUZZER_IR_SENSOR_H_ */
