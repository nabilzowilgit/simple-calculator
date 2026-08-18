/*
 * dio_init.h
 *
 *  Created on: Jul 25, 2026
 *      Author: zowil
 */

#ifndef DIO_INIT_H_
#define DIO_INIT_H_
//--------------------------------------------------//
//define port parameters

#define PortA  (u8)0
#define PortB  (u8)1
#define PortC  (u8)2
#define PortD  (u8)3

#define Input_DDR_Port   (u8)0x00
#define Output_DDR_Port  (u8)0xff

#define High_Port_Val (u8)0xff
#define Low_Port_Val  (u8)0x00


void DIO_VidSetPortDir(u8 u8CopyPort,u8 u8CopyDir);
void DIO_VidSetPortVal(u8 u8CopyPort,u8 u8CopyVal);
u8   DIO_u8GetPortVal(u8 u8CopyPort);

//-----------------------------------------------------//
//define pin parameters

//#define PinA0  (u8)0
//#define PinA1  (u8)1
//#define PinA2  (u8)2
//#define PinA3  (u8)3
//#define PinA4  (u8)4
//#define PinA5  (u8)5
//#define PinA6  (u8)6
//#define PinA7  (u8)7
//#define PinB0  (u8)8
//#define PinB1  (u8)9
//#define PinB2  (u8)10
//#define PinB3  (u8)11
//#define PinB4  (u8)12
//#define PinB5  (u8)13
//#define PinB6  (u8)14
//#define PinB7  (u8)15
//#define PinC0  (u8)16
//#define PinC1  (u8)17
//#define PinC2  (u8)18
//#define PinC3  (u8)19
//#define PinC4  (u8)20
//#define PinC5  (u8)21
//#define PinC6  (u8)22
//#define PinC7  (u8)23
//#define PinD0  (u8)24
//#define PinD1  (u8)25
//#define PinD2  (u8)26
//#define PinD3  (u8)27
//#define PinD4  (u8)28
//#define PinD5  (u8)29
//#define PinD6  (u8)30
//#define PinD7  (u8)31

typedef enum {
    PinA0, PinA1, PinA2, PinA3, PinA4, PinA5, PinA6, PinA7,
    PinB0, PinB1, PinB2, PinB3, PinB4, PinB5, PinB6, PinB7,
    PinC0, PinC1, PinC2, PinC3, PinC4, PinC5, PinC6, PinC7,
    PinD0, PinD1, PinD2, PinD3, PinD4, PinD5, PinD6, PinD7
} PIN_NUM;

#define Input_DDR_Pin   (u8)0
#define Output_DDR_Pin  (u8)1

#define High_Pin_Val (u8)1
#define Low_Pin_Val  (u8)0
#define Toggle_Pin_Val (u8)2

void DIO_VidSetPinDir(u8 u8CopyPin,u8 u8CopyDir);
void DIO_VidSetPinVal(u8 u8CopyPin,u8 u8CopyVal);
u8   DIO_u8GetPinVal(u8 u8CopyPin);
//---------------------------------------------------------//
// for multiple pin from different ports at the same time //

void DIO_VidSetPinsDir(u8 *u8ARR_Pins,u8 u8CopyBound,u8 u8CopyDir);
void DIO_VidSetPinsVal(u8 *u8ARR_Pins,u8 u8CopyBound,u8 u8CopyVal);

//---------------------------------------------------------//
#endif /* DIO_INIT_H_ */
