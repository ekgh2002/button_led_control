/*
 * led.c
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */

#include "led.h"

XGpio GPIO_LED;
int led = 0x00;
int led_state = 0;

void Led_Init()
{
    XGpio_Initialize(&GPIO_LED, XPAR_AXI_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&GPIO_LED, CHANNEL_1, OUTPUT);
}

void Led_All_On()
{
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0xff);
}

void Led_All_Off()
{
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0x00);
}

void Led_Right_Shift()
{

	for (int i = 0; i<8; i++)
	{
		led = 0x80 >> i;
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, led);
		usleep(300000);
	}

}

void Led_Left_Shift()
{
	for (int i = 0; i<8; i++)
	{
		led = 0x01 << i;
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, led);
		usleep(300000);
	}
}
