/*
 * LCD_init.h
 *
 *  Created on: Aug 9, 2026
 *      Author: zowil
 */

#ifndef LCD_INIT_H_
#define LCD_INIT_H_


//write cmd

#define LCD_CMD_CLEAR_DIS           0x01
#define LCD_CMD_RETURN_HOME         0x02
#define LCD_CMD_ENTRY_MODE_INC      0x06   //move cursor right
#define LCD_CMD_ENTRY_MODE_DEC      0x04   //moves cursor left
#define LCD_CMD_DISPLAY_ON          0x0F
#define LCD_CMD_DISPLAY_OFF         0x08
#define LCD_CMD_SHIFT_LEFT          0x18
#define LCD_CMD_SHIFT_RIGHT         0x1C
#define LCD_CMD_FUNCTION_SET_8BIT   0x38
#define LCD_CMD_FUNCTION_SET_4BIT   0x28
#define LCD_CMD_SET_CGRAM           0x40
#define LCD_CMD_SET_DDRAM           0x80

#define Row1                        0
#define Row2                        1

//write functions 8bit
void LCD_vid_8bit_init();
void LCD_vid_8bit_writecmd(u8 u8Copycommand);
void LCD_vid_8bit_GOTO(u8 u8CopyRow ,u8 u8CopyCol );
void LCD_vid_8bit_writechar(u8 u8Copychar);
void LCD_vid_8bit_writestr(u8 *u8Copystr);
void LCD_vid_8bit_writeint(s32 s32Copyint);
void LCD_vid_8bit_writefloat(f64 f64Copyfloat);

//write functions 4bit
void LCD_vid_4bit_init();
void LCD_vid_4bit_writecmd(u8 u8Copycommand);
void LCD_vid_4bit_GOTO(u8 u8CopyRow ,u8 u8CopyCol );
void LCD_vid_4bit_writechar(u8 u8Copychar);
void LCD_vid_4bit_writestr(u8 *u8Copystr);
void LCD_vid_4bit_writeint(s32 s32Copyint);
void LCD_vid_4bit_writefloat(f64 f64Copyfloat);

#endif /* LCD_INIT_H_ */
