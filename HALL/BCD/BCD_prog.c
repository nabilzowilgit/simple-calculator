/*
 * BCD_prog.c
 *
 *  Created on: Aug 5, 2026
 *      Author: zowil
 */

#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "BCD_config.h"
#include "BCD_init.h"
//initalization
void BCD_vidinit(){
	//pins direction
	DIO_VidSetPinsDir(BCD_PINS , 4 , Output_DDR_Pin);
	//enable
	DIO_VidSetPinDir(BCD_EN1,Output_DDR_Pin);
	DIO_VidSetPinDir(BCD_EN2,Output_DDR_Pin);

}
//write data
void BCD_vidwritedata(u8 u8CopyData){
	for (u8 i =0; i<4 ;i++){
		DIO_VidSetPinVal(BCD_PINS[i],GET_BIT(u8CopyData,i));
	}
}

//enable disable
void BCD_videnabledisable(u8 u8CopyBCD_segnum,u8 u8CopyMode){
	switch(u8CopyBCD_segnum){
	case BCD_seg1:DIO_VidSetPinVal(BCD_EN1,u8CopyMode);break;
	case BCD_seg2:DIO_VidSetPinVal(BCD_EN2,u8CopyMode);break;
	}
}
