/*
 * button.h
 *
 * Created: 12/11/2022 1:00:15 PM
 *  Author: MoHaridy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/timer/timer.h"
#include "../../MCAL/interrupt/interrupts.h"


//Button port and pin
#define BUTTON_1_PORT PORT_D
#define BUTTON_1_PIN PIN2

void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);


#endif /* BUTTON_H_ */