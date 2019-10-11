/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */
#include"uart.h"
#include"keypad.h"
#include"LCD.h"
#include"Timers.h"


int main(void){

    DDRB&=0xFB;
    DDRC&=0xF7;
	unit8 num=0;
	LCD_init();
	//timer_init();
	UART_init();
	LCD_displayStrRowCol(0,0,"Num is: ");

	while(1){

		if(PINB&(1<<PB2))
		{
			while((PINB & (1<<PB2) ) );
			   num++;
		}

		else if(PINC&(1<<PC4))
		{


			while((PINC & (1<<PC4) ) );
			   num--;


		}

		LCD_gotoRawCol(0,10);

		if(num==255)
		   num=0;

		LCD_IntToStr(num);
		LCD_displayString("   ");

		UART_sendByte(num);

 }

}
