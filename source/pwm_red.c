/*
 * pwm_red.c
 *
 *  Created on: 13-Dec-2023
 *      Author: Unmesh
 *
 *  Description: This file contains functions to initialize and control the brightness of RGB LEDs using PWM (Pulse Width Modulation).
 * 	It includes the setup for clock sources, port configuration, and TPM (Timer/Pulse-width Modulation) modules. The initialization
 * 	function configures the necessary ports and TPM modules for the red, green, and blue components of an RGB LED. The file also
 * 	contains a function to adjust the brightness of the red component of the RGB LED. This is achieved by changing the duty cycle of
 * 	the PWM signal applied to the red LED.
 */

#include "pwm_red.h"

void init_RGB_LED() {
	// Enable the clock to Port B and Port D
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;

	// Configure the multiplexer for PWM
	PORTB->PCR[RED_LED_PIN] = PORT_PCR_MUX(3);
	PORTB->PCR[GREEN_LED_PIN] = PORT_PCR_MUX(3);
	PORTD->PCR[BLUE_LED_PIN] = PORT_PCR_MUX(4);

	// Enable the clock to TPM0 and TPM2
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK | SIM_SCGC6_TPM2_MASK;

	// Set TPM source clock
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);

	// Initialize TPM modules for PWM
	TPM_RED->MOD = 0xFF;
	TPM_GREEN->MOD = 0xFF;
	TPM_BLUE->MOD = 0xFF;

	// Edge-aligned PWM
	TPM_RED->CONTROLS[TPM_CHANNEL_RED].CnSC = TPM_CnSC_MSB_MASK
			| TPM_CnSC_ELSA_MASK;
	TPM_GREEN->CONTROLS[TPM_CHANNEL_GREEN].CnSC = TPM_CnSC_MSB_MASK
			| TPM_CnSC_ELSA_MASK;
	TPM_BLUE->CONTROLS[TPM_CHANNEL_BLUE].CnSC = TPM_CnSC_MSB_MASK
			| TPM_CnSC_ELSA_MASK;

	// Start the TPM modules
	TPM_RED->SC |= TPM_SC_CMOD(1);
	TPM_GREEN->SC |= TPM_SC_CMOD(1);
	TPM_BLUE->SC |= TPM_SC_CMOD(1);
}

void set_Red_LED_Brightness(uint8_t brightness) {
	TPM_RED->CONTROLS[TPM_CHANNEL_RED].CnV = brightness;		// Set brightness
}
