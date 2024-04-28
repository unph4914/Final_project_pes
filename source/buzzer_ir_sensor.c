/*
 * buzzer_ir_sensor.c
 *
 *  Created on: 13-Dec-2023
 *      Author: Unmesh
 *
 *  Description: This file contains functions for initializing and controlling a buzzer and an IR sensor.
 *  The functions include initializing the IR sensor and buzzer, generating a delay in microseconds,
 *  playing a tone with a specified frequency and duration, and processing sensor data to detect obstacles.
 */

#include "buzzer_ir_sensor.h"
#include "pwm_red.h"

void init_IR_Sensor() {
	// Enable clock for PORTC
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;

	// Configure the pin control register for GPIO
	PORTC->PCR[SENSOR_PIN_NO] = PORT_PCR_MUX(1);

	// Set the data direction for SENSOR_PIN as input
	SENSOR_PORT->PDDR &= ~(1U << SENSOR_PIN_NO);
}

void init_Buzzer() {
	// Configure the pin control register for GPIO
	PORTC->PCR[BUZZER_PIN_NO] = PORT_PCR_MUX(1);

	// Set the data direction for BUZZER_PIN as output
	BUZZER_PORT->PDDR |= (1U << BUZZER_PIN_NO);
}

void delayMicroseconds(long int us) {
	long int delayLoops = (CPU_CLOCK_HZ / 1000000) * us / 6; // Delay as per CPU instructions per loop
	while (delayLoops--) {
	}
}

void playTone(int frequency, int duration) {
	long int i, cycles;
	cycles = frequency * duration / 1000;

	for (i = 0; i < cycles; i++) {
		BUZZER_PORT->PSOR = (1U << BUZZER_PIN_NO); // Turn buzzer on
		delayMicroseconds(1000000 / frequency / 2); // Wait for half the cycle
		BUZZER_PORT->PCOR = (1U << BUZZER_PIN_NO); // Turn buzzer off
		delayMicroseconds(1000000 / frequency / 2); // Wait for half the cycle
	}
}

// Process the sensor data to detect obstacles and control the buzzer
void processSensor(uint8_t *brightness, uint8_t *increasing) {
	int sensorValue = (SENSOR_PORT->PDIR & (1U << SENSOR_PIN_NO)) ? 1 : 0;

	if (sensorValue == 0) {
		PRINTF("Obstacle detected\r\n");			// Detected
		set_Red_LED_Brightness(*brightness);		// Set brightness
		playTone(440, 200);							// Play tune

		// Update brightness
		if (*increasing) {
			*brightness += 30;
			if (*brightness >= 0xFF)
				*increasing = 0;
		} else {
			if (*brightness == 0)
				*increasing = 1;
			else
				*brightness -= 30;
		}
	} else {
		PRINTF("Obstacle Not Detected\r\n");		// Not detected or removed
		BUZZER_PORT->PCOR = (1U << BUZZER_PIN_NO);	// Turn off buzzer
		set_Red_LED_Brightness(0);					// Turn off LED
		*brightness = 0;
		*increasing = 1;
	}
}
