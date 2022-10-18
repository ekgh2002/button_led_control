/*
 * led.h
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */

#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

#define CHANNEL_1	1
#define OUTPUT		0x00
#define INPUT		0x01

void Led_Init();
void Led_All_On();
void Led_All_Off();
void Led_Right_Shift();
void Led_Left_Shift();


