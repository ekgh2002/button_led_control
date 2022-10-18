/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */


#include "main.h"

XGpio GPIO_LED;
XGpio GPIO_BTN;

extern int led_state;



int main()
{
    init_platform();

    XGpio_Initialize(&GPIO_LED, XPAR_AXI_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&GPIO_LED, CHANNEL_1, OUTPUT);

    buttonInst modeButton;
	buttonInst upButton;
	buttonInst downButton;
    Button_Init();
    Button_MakeInst(&modeButton, BUTTON_0);
    Button_MakeInst(&upButton, BUTTON_1);
	Button_MakeInst(&downButton, BUTTON_2);

    print("Hello World\n\r");
    print("Successfully ran Hello World application\n\r");

    int state = 0;

    while(1)
    {
    	if (button_GetState(&modeButton))
    	{
    		state = state + 1;
    	}
    	if (state % 2 == 1)
    	{
    		Led_All_On();
    	}
    	else if (state % 2 == 0)
    	{
    		Led_All_Off();
    	}

    	if (button_GetState(&upButton))
    	{
    		Led_Right_Shift();

    	}
    	if (button_GetState(&downButton))
    	{
    		Led_Left_Shift();
    		//0.3초 간격으로 led left shift
    	}
//    	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0x00);
//    	usleep(100000);
//    	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0xff);
//    	usleep(100000);
    }
    cleanup_platform();
    return 0;
}
