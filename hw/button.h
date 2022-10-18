/*
 * button.h
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */


#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

//#define FALSE		0
//#define TURE		1

#define CHANNEL_1	1
#define OUTPUT		0x00
#define INPUT		0x01

#define RELEASED	0
#define PUSHED		1

#define BUTTON_0	0
#define BUTTON_1	1
#define BUTTON_2	2
#define BUTTON_3	3

#define CHANNEL_1	1
#define CHANNEL_2	2

typedef struct _buttonInst
{
	int prevState;
	int buttonNum;
} buttonInst;

void Button_Init();
void Button_MakeInst(buttonInst *button, int buttonNum);
int button_GetState(buttonInst *button);


