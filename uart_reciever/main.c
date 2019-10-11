/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */
#include"uart.h"
#include"LCD.h"




int main(void){
	unit8 num;
	LCD_init();
	UART_init();
	LCD_displayStrRowCol(0,0,"Num is: ");
	while(1){
		num=UART_recieveByte();
		LCD_gotoRawCol(0,10);
		LCD_IntToStr(num);
		LCD_displayString("   ");

	}
}

