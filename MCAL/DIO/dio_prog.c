#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "dio_reg_privite.h"
#include "dio_init.h"
//------------------------------------------------------//
//port functions//

void DIO_VidSetPortDir(u8 u8CopyPort,u8 u8CopyDir){
   switch(u8CopyPort){
 case PortA: DDRA_REG = u8CopyDir;break;
 case PortB: DDRB_REG = u8CopyDir;break;
 case PortC: DDRC_REG = u8CopyDir;break;
 case PortD: DDRD_REG = u8CopyDir;break;
  }
}
//--------------------------------------------//

void DIO_VidSetPortVal(u8 u8CopyPort,u8 u8CopyVal){
  switch(u8CopyPort){
 case PortA: PORTA_REG = u8CopyVal;break;
 case PortB: PORTB_REG = u8CopyVal;break;
 case PortC: PORTC_REG = u8CopyVal;break;
 case PortD: PORTD_REG = u8CopyVal;break;
	}
}
//-----------------------------------------------//
u8   DIO_u8GetPortVal(u8 u8CopyPort){
	u8 Data =0;
	  switch(u8CopyPort){
		case PortA: Data = PINA_REG;break;
		case PortB: Data = PINB_REG;break;
		case PortC: Data = PINC_REG;break;
		case PortD: Data = PIND_REG;break;
		}
	  return Data;
}
//----------------------------------------------------------//

//pin functions//

void DIO_VidSetPinDir(u8 u8CopyPin,u8 u8CopyDir){

if ((u8CopyPin<=PinA7) && (u8CopyPin>=PinA0)){
	if (u8CopyDir == Output_DDR_Pin){
		SET_BIT(DDRA_REG,u8CopyPin);
	}
	else{
		CLR_BIT(DDRA_REG,u8CopyDir);
	}
 }

else if ((u8CopyPin<=PinB7) && (u8CopyPin>=PinB0)){
	if (u8CopyDir == Output_DDR_Pin){
			SET_BIT(DDRB_REG,(u8CopyPin - 8));
		}
		else{
			CLR_BIT(DDRB_REG,(u8CopyDir - 8));
		}
 }

else if ((u8CopyPin<=PinC7) && (u8CopyPin>=PinC0)){
	if (u8CopyDir == Output_DDR_Pin){
			SET_BIT(DDRC_REG,(u8CopyPin - 16));
		}
		else{
			CLR_BIT(DDRC_REG,(u8CopyDir - 16));
		}
 }

else if ((u8CopyPin<=PinD7) && (u8CopyPin>=PinD0)){
	if (u8CopyDir == Output_DDR_Pin){
			SET_BIT(DDRD_REG,(u8CopyPin - 24));
		}
		else{
			CLR_BIT(DDRD_REG,(u8CopyDir - 24));
		}
 }
}
//----------------------------------------------------//
void DIO_VidSetPinVal(u8 u8CopyPin,u8 u8CopyVal){

	if ((u8CopyPin<=PinA7) && (u8CopyPin>=PinA0)){
		if (u8CopyVal == High_Pin_Val){
			SET_BIT(PORTA_REG,u8CopyPin);
		}
		else if (u8CopyVal == Low_Pin_Val){
			CLR_BIT(PORTA_REG,u8CopyPin);
		}
		else if (u8CopyVal == Toggle_Pin_Val){
			TOG_BIT(PORTA_REG,u8CopyPin);
		}
	 }

	else if ((u8CopyPin<=PinB7) && (u8CopyPin>=PinB0)){
		if (u8CopyVal == High_Pin_Val){
				SET_BIT(PORTB_REG,(u8CopyPin - 8));
			}
			else if (u8CopyVal == Low_Pin_Val){
				CLR_BIT(PORTB_REG,(u8CopyPin - 8));
			}
			else if (u8CopyVal == Toggle_Pin_Val){
				TOG_BIT(PORTB_REG,(u8CopyPin - 8));
			}
	 }

	else if ((u8CopyPin<=PinC7) && (u8CopyPin>=PinC0)){
		if (u8CopyVal == High_Pin_Val){
				SET_BIT(PORTC_REG,(u8CopyPin - 16));
			}
		else if (u8CopyVal == Low_Pin_Val){
						CLR_BIT(PORTC_REG,(u8CopyPin - 16));
					}
					else if (u8CopyVal == Toggle_Pin_Val){
						TOG_BIT(PORTC_REG,(u8CopyPin - 16));
					}
	 }

	else if ((u8CopyPin<=PinD7) && (u8CopyPin>=PinD0)){
		if (u8CopyVal == High_Pin_Val){
				SET_BIT(PORTD_REG,(u8CopyPin - 24));
			}
		else if (u8CopyVal == Low_Pin_Val){
								CLR_BIT(PORTD_REG,(u8CopyPin - 24));
							}
							else if (u8CopyVal == Toggle_Pin_Val){
								TOG_BIT(PORTD_REG,(u8CopyPin - 24));
							}
	 }
}
//------------------------------------------------------//
u8   DIO_u8GetPinVal(u8 u8CopyPin){

	if ((u8CopyPin<=PinA7) && (u8CopyPin>=PinA0)){
			return GET_BIT(PINA_REG,u8CopyPin);
		 }

		else if ((u8CopyPin<=PinB7) && (u8CopyPin>=PinB0)){
			if (u8CopyPin<=PinB7){
						return GET_BIT(PINB_REG,(u8CopyPin - 8));
					 }
		 }

		else if ((u8CopyPin<=PinC7) && (u8CopyPin>=PinC0)){
			if (u8CopyPin<=PinC7){
						return GET_BIT(PINC_REG,(u8CopyPin - 16));
					 }
		 }

		else if ((u8CopyPin<=PinD7) && (u8CopyPin>=PinD0)){
			if (u8CopyPin<=PinD7){
						return GET_BIT(PIND_REG,(u8CopyPin - 24));
					 }
		 }
	return 0;
}
//-----------------------------------------------------//
// for multiple pin from different ports at the same time //


void DIO_VidSetPinsDir(u8 *u8ARR_Pins,u8 u8CopyBound,u8 u8CopyDir){
	u8 i = 0;
	for (i=0;i<u8CopyBound;i++){
		DIO_VidSetPinDir(u8ARR_Pins[i],u8CopyDir);
	}
}

//------------------------------------------------//
void DIO_VidSetPinsVal(u8 *u8ARR_Pins,u8 u8CopyBound,u8 u8CopyVal){
	u8 i = 0;
		for (i=0;i<u8CopyBound;i++){
			DIO_VidSetPinVal(u8ARR_Pins[i],u8CopyVal);
		}
}

//------------------------------------------------------------//


