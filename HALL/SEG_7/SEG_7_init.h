/*
 * SEG_7_init.h
 *
 *  Created on: Aug 1, 2026
 *      Author: zowil
 */

#ifndef SEG_7_INIT_H_
#define SEG_7_INIT_H_

#include "../../MCAL/DIO/dio_init.h"

//define segment enable disable
#define Seg1    0
#define Seg2    1
#define SEG_enable  0
#define SEG_disable 1

void SEG7_Vid_init_DDR();
void SEG7_Vid_writedata(u8 u8Copydata);
void SEG7_Vid_enabledisable(u8 u8CopySegment,u8 u8CopyMode);
#endif /* SEG_7_INIT_H_ */
