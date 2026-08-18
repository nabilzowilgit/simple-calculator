/*


* SEG_7_prog.c
 *
 *  Created on: Aug 1, 2026
 *      Author: zowil
 */

#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "SEG_7_priviteconfig.h"
#include "SEG_7_init.h"

#if SEG_type == cathode_mode

void SEG7_Vid_init_DDR(){
	DIO_VidSetPinsDir(SEG_ARR_Pins , 7 , Output_DDR_Pin );
	DIO_VidSetPinDir(Segment_act_1,Output_DDR_Pin);
	DIO_VidSetPinDir(Segment_act_2,Output_DDR_Pin);

}
//--------------------------------------------------------//
void SEG7_Vid_writedata(u8 u8Copydata){

    	  for (u8 i=0;i<7;i++){
    	      	  DIO_VidSetPinVal(SEG_ARR_Pins[i],GET_BIT(DSEG[u8Copydata],i));
    	        }


}
void SEG7_Vid_enabledisable(u8 u8CopySegment,u8 u8CopyMode){
	switch (u8CopySegment){
	case Seg1:DIO_VidSetPinVal(Segment_act_1,u8CopyMode) ;break;
	case Seg2:DIO_VidSetPinVal(Segment_act_2,u8CopyMode) ;break;

	}
}

//-----------------------------------------------//

#elif SEG_type == anode_mode

DIO_VidSetPinsDir(SEG_ARR_Pins , 7 , Output_DDR_Pin );
DIO_VidSetPinDir(Segment_act_1,Output_DDR_Pin);
DIO_VidSetPinDir(Segment_act_2,Output_DDR_Pin);
DIO_VidSetPinVal(Segment_act_1,High_Pin_Val);
DIO_VidSetPinVal(Segment_act_2,High_Pin_Val);
}
//--------------------------------------------------------//
void SEG7_Vid_writedata(u8 u8Copydata){


	  for (u8 i=0;i<7;i++){
	      	  DIO_VidSetPinVal(SEG_ARR_Pins[i],~(GET_BIT(DSEG[u8Copydata],i)));
	        }

}
void SEG7_Vid_enabledisable(u8 u8CopySegment,u8 u8CopyMode){
	switch (u8CopySegment){
	case Seg1:DIO_VidSetPinVal(Segment_act_1,(u8CopyMode)^1) ;break;
	case Seg2:DIO_VidSetPinVal(Segment_act_2,(u8CopyMode)^1) ;break;

	}
}

#endif
