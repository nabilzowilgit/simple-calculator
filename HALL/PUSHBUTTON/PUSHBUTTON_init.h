/*
 * PUSHBUTTON_init.h
 *
 *  Created on: Aug 17, 2026
 *      Author: zowil
 */

#ifndef PUSHBUTTON_INIT_H_
#define PUSHBUTTON_INIT_H_



 #define button1   0
 #define button2   1
 #define button3   2

#define PRESSED       1
#define NOT_PRESSED   0

void PUSH_BUTTON_vid_init();
u8 PUSH_BUTTON_u8_Getstate(u8 u8copyButton);

#endif /* PUSHBUTTON_INIT_H_ */
