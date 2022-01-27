/*
 *  Created on: 2022 Jan 27 15:35:30
 *  Author: meschmidt
 *
 *	XMC4500_GPIOwithIRQ
 *		Example for a basic program to read and set GPIOs on the XMC4500 Relax Kit (LED1 and LED2). In this example both Buttons
 *		are used, but BUTTON2 is implemented using a PIN_INTERRUPT while the state of BUTTON1 must be checked manually within
 *		our while-loop. In general, a solution which uses the available hardware resources (Interrupts) should be preferred.
 */

#include "DAVE.h"		// Declarations from DAVE Code Generation (includes SFR declaration)

/*
 *	This IRQ (Interrupt Request, also often called ISR - Interrupt Service Routine) is called, once the predefined Interrupt Settings
 *	in our PIN_INTERRUPT App are fulfilled. In this case, a "Rising Edge" on the selected Pin of BUTTON2. IRQs typically have neither
 *	return values, nor do they require any input parameters.
 */
void IRQ_Button_2_Pressed(void)
{
	DIGITAL_IO_ToggleOutput(&LED2);		// Toggle the Output Level of LED2 (Low -> High | High -> Low)
}

int main(void)
{
	DAVE_Init();		// Initialization of DAVE APPs

	DIGITAL_IO_SetOutputLow(&LED1);		// Set the Output Level of LED1 to Low
	DIGITAL_IO_SetOutputLow(&LED2);		// Set the Output Level of LED2 to Low

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */
	while(1U)
	{
		if(DIGITAL_IO_GetInput(&BUTTON1)) {		// Function "DIGITAL_IO_GetInput" to check the current state of the BUTTON1 pin
			DIGITAL_IO_ToggleOutput(&LED1);		// Toggle the Output Level of LED2 (Low -> High | High -> Low)

			/*	Wait and hold the currently running code until BUTTON1 is released. This is implemented keep
			    the code from performing the DIGITAL_IO_ToggleOutput multiple times on a single button press. */
			while(DIGITAL_IO_GetInput(&BUTTON1)) __NOP();
		}
	}
}
