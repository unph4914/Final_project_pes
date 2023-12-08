#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#define SENSOR_PIN PORTC_PCR6   // Assuming you're using pin 6 of PORTC for the sensor
#define SENSOR_PORT PTC
#define SENSOR_PIN_NO 6

void init_IR_Sensor() {
	// Enable clock for PORTC
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;

	// Configure the pin control register for GPIO
	PORTC->PCR[SENSOR_PIN_NO] = PORT_PCR_MUX(1);

	// Set the data direction for SENSOR_PIN as input
	SENSOR_PORT->PDDR &= ~(1U << SENSOR_PIN_NO);
}

int main() {
	// Initialize the board hardware and debug console
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	BOARD_InitDebugConsole();

	// Initialize the IR sensor
	init_IR_Sensor();

	while (1) {
		// Read the sensor value
		int sensorValue = (SENSOR_PORT->PDIR & (1U << SENSOR_PIN_NO)) ? 1 : 0;

		if (sensorValue == 0) {
			// Obstacle detected
			PRINTF("Obstacle detected\r\n");
		} else {
			// No obstacle
			PRINTF("No obstacle detected\r\n");
		}
	}
}
