/*
 * PUSHBUTTON_prog.c
 *
 *  Created on: Aug 17, 2026
 *      Author: zowil
 */
#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "PUSHBUTTON_init.h"
#include "PUSHBUTTON_config.h"
#include <util/delay.h>


void PUSH_BUTTON_vid_init(){
	//internal pull up resistance
	DIO_VidSetPinDir(button1_pin,Input_DDR_Pin);
	DIO_VidSetPinVal(button1_pin,High_Pin_Val);

	DIO_VidSetPinDir(button2_pin,Input_DDR_Pin);
	DIO_VidSetPinVal(button2_pin,High_Pin_Val);

	DIO_VidSetPinDir(button3_pin,Input_DDR_Pin);
	DIO_VidSetPinVal(button3_pin,High_Pin_Val);

}
u8 PUSH_BUTTON_u8_Getstate(u8 u8copyButton){
	//u8 data;
	//switch(u8copyButton){
	//case button1:data=button1_pin;break;
	//case button2:data=button2_pin;break;
	//case button3:data=button3_pin;break;
	//}
    //
	//if (DIO_u8GetPinVal(data) == Low_Pin_Val){
	//while (DIO_u8GetPinVal(Button_arr[u8copyButton]) == Low_Pin_Val);
	//	return PRESSED;
	//}
	//else {
	//	return NOT_PRESSED;
	//}
	if (DIO_u8GetPinVal(Button_arr[u8copyButton]) == Low_Pin_Val){
		while (DIO_u8GetPinVal(Button_arr[u8copyButton]) == Low_Pin_Val);
		return PRESSED;

	}
	else {
		return NOT_PRESSED;
	}

}
