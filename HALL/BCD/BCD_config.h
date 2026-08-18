/*
 * BCD_config.h
 *
 *  Created on: Aug 5, 2026
 *      Author: zowil
 */

#ifndef BCD_CONFIG_H_
#define BCD_CONFIG_H_

#include "../../MCAL/DIO/dio_init.h"
//define pins
#define BCD_PIN_1  PinC0
#define BCD_PIN_2  PinC1
#define BCD_PIN_3  PinC2
#define BCD_PIN_4  PinC3
extern u8 BCD_PINS[4];
//enable
#define BCD_EN1    PinC4
#define BCD_EN2    PinC5


#endif /* BCD_CONFIG_H_ */
