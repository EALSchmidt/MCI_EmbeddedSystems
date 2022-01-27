/*
 *  Created on: 2022 Jan 27 13:57:32
 *  Author: meschmidt
 *
 *	XMC4500_BlinkyLED
 *		Example for a basic program for alternating the blinking of both LEDs on the XMC4500 Relax Kit (LED1 and LED2). This example
 *  	is realized without additional libraries or timers.
 */

#define TICKS_TO_WASTE		1000000		// Define the amount of µC Ticks to waste between LEDs blinking

#include "DAVE.h"		// Declarations from DAVE Code Generation (includes SFR declaration)

int main(void)
{
	DAVE_Init();		// Initialization of DAVE APPs

	DIGITAL_IO_SetOutputLow(&LED1);		// Set the Output Level of LED1 to Low
	DIGITAL_IO_SetOutputHigh(&LED2);	// Set the Output Level of LED2 to High

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */
	while(1U)
	{
		for(int i = 0; i < TICKS_TO_WASTE; i++)		// Waste Time to delay the LEDs from blinking
			__NOP();

		DIGITAL_IO_ToggleOutput(&LED1);		// Toggle the Output Level of LED1 (Low -> High | High -> Low)
		DIGITAL_IO_ToggleOutput(&LED2);		// Toggle the Output Level of LED2 (Low -> High | High -> Low)
	}
}
