/*
 * bit_math.h
 *
 *  Created on: Jul 24, 2026
 *      Author: zowil
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NO) REG|=(1<<BIT_NO)
#define TOG_BIT(REG,BIT_NO) REG^=(1<<BIT_NO)
#define CLR_BIT(REG,BIT_NO) REG&=(~(1<<BIT_NO))
#define GET_BIT(REG,BIT_NO) ((REG>>BIT_NO)&1)

#endif /* BIT_MATH_H_ */
