/*
 * Keypad_config.h
 *
 *  Created on: Aug 15, 2026
 *      Author: zowil
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEY_NO_ROWS    4
#define KEY_NO_COLS    4

extern u8 KeyPad_ROW_PINS[KEY_NO_ROWS];
extern u8 KeyPad_COL_PINS[KEY_NO_COLS];
extern u8 KeyPad_Pattern[KEY_NO_ROWS][KEY_NO_COLS];

#endif /* KEYPAD_CONFIG_H_ */
