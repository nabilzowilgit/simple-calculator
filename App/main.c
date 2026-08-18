#define F_CPU 16000000UL
#include <avr/io.h>
#include "../Service/bit_math.h"
#include "../Service/STD_types.h"
#include <util/delay.h>
#include "../HALL/KEYPAD/Keypad_init.h"
#include "../HALL/LCD/LCD_init.h"


int main(){

s16 num1=0;
s16 num2=0;
f32 result=0;

u8 key=0;
u8 operation=0;

KEYPAD_vid_init();
LCD_vid_8bit_init();


while(1){

	if (KEYPAD_u8_Getstate(&key)==PRESSED){
		if ((key>='0')&&(key<='9')){
			if (operation==0){
				num1 = (num1*10)+(key-'0');
			}
			else {
				num2 = (num2*10)+(key-'0');
			}
			LCD_vid_8bit_writechar(key);
		}
		else if ((key=='-')|(key=='+')|(key=='*')|(key=='/')){
			operation = key;
			LCD_vid_8bit_writechar(operation);
		}
		else if (key=='='){
			switch (operation){
			case '+': result = num1+num2          ;break;
			case '-': result = num1-num2          ;break;
			case '*': result = (float)num1*num2   ;break;
			case '/': result = ((float)num1)/num2 ;break;
			}
			LCD_vid_8bit_writecmd(LCD_CMD_CLEAR_DIS);
			LCD_vid_8bit_writechar(key);
			LCD_vid_8bit_writefloat(result);
		}
		else if (key=='C'){
			num1=0;
			num2=0;
			operation=0;
			result=0;
			LCD_vid_8bit_writecmd(LCD_CMD_CLEAR_DIS);

		}

	}













	}

	return 0;

}
