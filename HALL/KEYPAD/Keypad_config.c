/*
 * Keypad_config.c
 *
 *  Created on: Aug 15, 2026
 *      Author: zowil
 */
#include "../../Service/STD_types.h"
#include "../../MCAL/DIO/dio_init.h"
#include "Keypad_config.h"

u8 KeyPad_ROW_PINS[KEY_NO_ROWS]={PinB2,PinB3,PinB4,PinB5};

u8 KeyPad_COL_PINS[KEY_NO_COLS]={PinC0,PinC1,PinC2,PinC3};

u8 KeyPad_Pattern[KEY_NO_ROWS][KEY_NO_COLS]={{'7','8','9','/'},
											 {'4','5','6','*'},
											 {'1','2','3','-'},
											 {'C','0','=','+'}};
