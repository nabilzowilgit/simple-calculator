/*
 * SEG_7_priviteconfig.h
 *
 *  Created on: Aug 2, 2026
 *      Author: zowil
 */

#ifndef SEG_7_PRIVITECONFIG_H_
#define SEG_7_PRIVITECONFIG_H_
//include macl
#include "../../MCAL/DIO/dio_init.h"

//define pins active of the segment
#define Segment_act_1  PinB1
#define Segment_act_2  PinB2

//define pins segment leds
#define SEG_A  PinA0
#define SEG_B  PinA1
#define SEG_C  PinA2
#define SEG_D  PinA3
#define SEG_E  PinA4
#define SEG_F  PinA5
#define SEG_G  PinA6
//define the display output
#define DSEG_ZERO  0b00111111
#define DSEG_ONE   0b00000110
#define DSEG_TWO   0b01011011
#define DSEG_THREE 0b01001111
#define DSEG_FOUR  0b01100110
#define DSEG_FIVE  0b01101101
#define DSEG_SIX   0b01111101
#define DSEG_SEVEN 0b00000111
#define DSEG_EIGHT 0b01111111
#define DSEG_NINE  0b01101111
//extern
extern u8 SEG_ARR_Pins[7];
extern u8 DSEG[10];

//the mode
#define cathode_mode 0
#define anode_mode 1

#define SEG_type cathode_mode



#endif /* SEG_7_PRIVITECONFIG_H_ */
