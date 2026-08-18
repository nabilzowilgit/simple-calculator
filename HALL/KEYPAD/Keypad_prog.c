/*
 * Keypad_prog.c
 *
 *  Created on: Aug 15, 2026
 *      Author: zowil
 */
#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "Keypad_config.h"
#include "Keypad_init.h"
#include <util/delay.h>

void KEYPAD_vid_init(){
	//internal pull-up resistance //
	DIO_VidSetPinsDir(KeyPad_ROW_PINS,KEY_NO_ROWS,Input_DDR_Pin);
	DIO_VidSetPinsVal(KeyPad_ROW_PINS,KEY_NO_ROWS,High_Pin_Val );

	DIO_VidSetPinsDir(KeyPad_COL_PINS,KEY_NO_COLS,Output_DDR_Pin);
	DIO_VidSetPinsVal(KeyPad_COL_PINS,KEY_NO_COLS,High_Pin_Val );

}


u8 KEYPAD_u8_Getstate(u8 *u8CopyKey){

	for(u8 j =0;j <KEY_NO_COLS ;j++){
		DIO_VidSetPinVal(KeyPad_COL_PINS[j],Low_Pin_Val);
		for(u8 i = 0;i < KEY_NO_ROWS ; i++){
			if(DIO_u8GetPinVal(KeyPad_ROW_PINS[i]) == Low_Pin_Val){
				*u8CopyKey = KeyPad_Pattern[i][j];
				while(DIO_u8GetPinVal(KeyPad_ROW_PINS[i]) == Low_Pin_Val);
				DIO_VidSetPinVal(KeyPad_COL_PINS[j],High_Pin_Val);
				return PRESSED;
			}
		}
		DIO_VidSetPinVal(KeyPad_COL_PINS[j],High_Pin_Val);
	}

	return NOT_PRESSED;
}
