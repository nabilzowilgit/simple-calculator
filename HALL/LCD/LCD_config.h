/*
 * LCD_config.h
 *
 *  Created on: Aug 9, 2026
 *      Author: zowil
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


//mode
#define LCD_8bit_mode  0
#define LCD_4bit_mode  1
#define LCD_mode  LCD_8bit_mode

//control pins
#define RS    PinB0
#define E     PinB1

//data pins 8bit
#define LCD_Port  PortA

//data pins 4bit
extern u8 LCD_4bit_data [4];

#endif /* LCD_CONFIG_H_ */
