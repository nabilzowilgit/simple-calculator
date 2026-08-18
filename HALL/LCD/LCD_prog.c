/*
 * LCD_prog.c
 *
 *  Created on: Aug 9, 2026
 *      Author: zowil
 */
#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "LCD_config.h"
#include "LCD_init.h"
#include <util/delay.h>


#if LCD_mode == LCD_8bit_mode

void LCD_vid_8bit_init(){
	DIO_VidSetPortDir(LCD_Port,Output_DDR_Port);
	DIO_VidSetPinDir(RS,Output_DDR_Pin);
	DIO_VidSetPinDir(E,Output_DDR_Pin);
	_delay_ms(30);
	LCD_vid_8bit_writecmd(LCD_CMD_FUNCTION_SET_8BIT);
	_delay_us(39);
	LCD_vid_8bit_writecmd(LCD_CMD_DISPLAY_ON);
	_delay_us(39);
	LCD_vid_8bit_writecmd(LCD_CMD_CLEAR_DIS);
	_delay_ms(1.53);
	LCD_vid_8bit_writecmd(LCD_CMD_ENTRY_MODE_INC);
}
void LCD_vid_8bit_writecmd(u8 u8Copycommand){
	DIO_VidSetPinVal(RS,Low_Pin_Val);
	DIO_VidSetPortVal(LCD_Port,u8Copycommand);
	DIO_VidSetPinVal(E,High_Pin_Val);
	_delay_ms(1);
	DIO_VidSetPinVal(E,Low_Pin_Val);
}
void LCD_vid_8bit_GOTO(u8 u8CopyRow ,u8 u8CopyCol ){
	u8 address = 0;
	switch (u8CopyRow){
	case Row1:address = u8CopyCol + LCD_CMD_SET_DDRAM  ;break;
	case Row2:address = u8CopyCol + LCD_CMD_SET_DDRAM + 0x40  ;break;
	}
	LCD_vid_8bit_writecmd(address);
}
void LCD_vid_8bit_writechar(u8 u8Copychar){
	DIO_VidSetPinVal(RS,High_Pin_Val);
	DIO_VidSetPortVal(LCD_Port,u8Copychar);
	DIO_VidSetPinVal(E,High_Pin_Val);
	_delay_ms(1);
	DIO_VidSetPinVal(E,Low_Pin_Val);
}
void LCD_vid_8bit_writestr(u8 *u8Copystr){
	DIO_VidSetPinVal(RS,High_Pin_Val);
	for (u8 i =0; u8Copystr[i] != '\0' ;i++){
		DIO_VidSetPortVal(LCD_Port,u8Copystr[i]);
		DIO_VidSetPinVal(E,High_Pin_Val);
		_delay_ms(1);
		DIO_VidSetPinVal(E,Low_Pin_Val);
	}
}
void LCD_vid_8bit_writeint(s32 s32Copyint){
	u32 u32Number;

		    if(s32Copyint < 0)
		    {
		        LCD_vid_8bit_writechar('-');

		        u32Number = -(s32Copyint + 1);
		        u32Number++;
		    }
		    else
		    {
		        u32Number = s32Copyint;
		    }

		    if(u32Number >= 10)
		    {
		        LCD_vid_8bit_writeint(u32Number / 10);
		    }

		    LCD_vid_8bit_writechar((u32Number % 10) + '0');

}

void LCD_vid_8bit_writefloat(f64 f64Copyfloat){
	    s32 integer_part;
	    u32 decimal_part;

	    if(f64Copyfloat < 0)
	    {
	        LCD_vid_8bit_writechar('-');

	        f64Copyfloat = -f64Copyfloat;
	    }

	    integer_part = (s32)f64Copyfloat;

	    decimal_part = (u32)((f64Copyfloat - integer_part) * 10);

	    LCD_vid_8bit_writeint(integer_part);

	    LCD_vid_8bit_writechar('.');

	    LCD_vid_8bit_writeint(decimal_part);
}

#elif LCD_mode == LCD_4bit_mode

void LCD_vid_4bit_init(){
	DIO_VidSetPinsDir(LCD_4bit_data,4,Output_DDR_Pin);
	DIO_VidSetPinDir(RS,Output_DDR_Pin);
	DIO_VidSetPinDir(E,Output_DDR_Pin);
	_delay_ms(30);
	DIO_VidSetPinVal(RS,Low_Pin_Val);
		for (u8 i =0; i<4 ;i++){
			DIO_VidSetPinVal(LCD_4bit_data[i],GET_BIT(LCD_CMD_FUNCTION_SET_4BIT,(4+i)));
		}
		DIO_VidSetPinVal(E,High_Pin_Val);
		_delay_ms(1);
		DIO_VidSetPinVal(E,Low_Pin_Val);
		LCD_vid_4bit_writecmd(LCD_CMD_FUNCTION_SET_4BIT);
		_delay_us(39);
		LCD_vid_4bit_writecmd(LCD_CMD_DISPLAY_ON);
		_delay_us(39);
		LCD_vid_4bit_writecmd(LCD_CMD_CLEAR_DIS);
		_delay_ms(1.53);
		LCD_vid_4bit_writecmd(LCD_CMD_ENTRY_MODE_INC);
}
void LCD_vid_4bit_writecmd(u8 u8Copycommand){
	DIO_VidSetPinVal(RS,Low_Pin_Val);
	for (u8 i =0; i<4 ;i++){
		DIO_VidSetPinVal(LCD_4bit_data[i],GET_BIT(u8Copycommand,(4+i)));
	}
	DIO_VidSetPinVal(E,High_Pin_Val);
	_delay_ms(1);
	DIO_VidSetPinVal(E,Low_Pin_Val);

	for (u8 i =0; i<4 ;i++){
		DIO_VidSetPinVal(LCD_4bit_data[i],GET_BIT(u8Copycommand,(i)));
		}
		DIO_VidSetPinVal(E,High_Pin_Val);
		_delay_ms(1);
		DIO_VidSetPinVal(E,Low_Pin_Val);
}
void LCD_vid_4bit_GOTO(u8 u8CopyRow ,u8 u8CopyCol ){
	u8 address = 0;
		switch (u8CopyRow){
		case Row1:address = u8CopyCol + LCD_CMD_SET_DDRAM  ;break;
		case Row2:address = u8CopyCol + LCD_CMD_SET_DDRAM + 0x40  ;break;
		}
		LCD_vid_4bit_writecmd(address);
}
void LCD_vid_4bit_writechar(u8 u8Copychar){
	DIO_VidSetPinVal(RS,High_Pin_Val);
	for (u8 i =0; i<4 ;i++){
		DIO_VidSetPinVal(LCD_4bit_data[i],GET_BIT(u8Copychar,(4+i)));
	}
	DIO_VidSetPinVal(E,High_Pin_Val);
	_delay_ms(1);
	DIO_VidSetPinVal(E,Low_Pin_Val);

	for (u8 i =0; i<4 ;i++){
		DIO_VidSetPinVal(LCD_4bit_data[i],GET_BIT(u8Copychar,(i)));
		}
		DIO_VidSetPinVal(E,High_Pin_Val);
		_delay_ms(1);
		DIO_VidSetPinVal(E,Low_Pin_Val);

}
void LCD_vid_4bit_writestr(u8 *u8Copystr){
	DIO_VidSetPinVal(RS,High_Pin_Val);
	for (u8 i =0; u8Copystr[i] != '\0' ;i++){
		LCD_vid_4bit_writechar(u8Copystr[i]);
	}
}
void LCD_vid_4bit_writeint(s32 s32Copyint){
	u32 u32Number;

	    if(s32Copyint < 0)
	    {
	        LCD_vid_4bit_writechar('-');

	        u32Number = -(s32Copyint + 1);
	        u32Number++;
	    }
	    else
	    {
	        u32Number = s32Copyint;
	    }

	    if(u32Number >= 10)
	    {
	        LCD_vid_4bit_writeint(u32Number / 10);
	    }

	    LCD_vid_4bit_writechar((u32Number % 10) + '0');

}
void LCD_vid_4bit_writefloat(f64 f64Copyfloat){
	    s32 integer_part;
	    u32 decimal_part;

	    /* Negative number */
	    if(f64Copyfloat < 0)
	    {
	        LCD_vid_4bit_writechar('-');
	        f64Copyfloat = -f64Copyfloat;
	    }

	    integer_part = (s32)f64Copyfloat;

	    decimal_part = (u32)((f64Copyfloat - integer_part) * 10);

	    LCD_vid_4bit_writeint(integer_part);

	    LCD_vid_4bit_writechar('.');

	    LCD_vid_4bit_writeint(decimal_part);
}

#endif
