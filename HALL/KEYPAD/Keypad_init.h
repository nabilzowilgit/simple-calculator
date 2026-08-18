/*
 * Keypad_init.h
 *
 *  Created on: Aug 15, 2026
 *      Author: zowil
 */

#ifndef KEYPAD_INIT_H_
#define KEYPAD_INIT_H_



#define PRESSED       1
#define NOT_PRESSED   0

void KEYPAD_vid_init();
u8   KEYPAD_u8_Getstate(u8 *u8CopyKey);

#endif /* KEYPAD_INIT_H_ */
