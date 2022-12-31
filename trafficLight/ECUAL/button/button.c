/*
 * button.c
 *
 * Created: 12/11/2022 12:59:20 PM
 *  Author: MoHaridy
 */ 
#include "button.h"



//input button
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);
}

void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
	DIO_read(buttonPort,buttonPin,value);
}