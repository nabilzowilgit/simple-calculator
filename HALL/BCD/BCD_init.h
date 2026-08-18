/*
 * BCD_init.h
 *
 *  Created on: Aug 5, 2026
 *      Author: zowil
 */

#ifndef BCD_INIT_H_
#define BCD_INIT_H_

#include "../../MCAL/DIO/dio_init.h"
#define BCD_seg1    0
#define BCD_seg2    1

#define BCD_enable  1
#define BCD_disable 0

void BCD_vidinit();
void BCD_vidwritedata(u8 u8CopyData);
void BCD_videnabledisable(u8 u8CopyBCD_segnum,u8 u8CopyMode);

#endif /* BCD_INIT_H_ */
