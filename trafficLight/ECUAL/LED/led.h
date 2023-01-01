/*
 * led.h
 *
 * Created: 12/11/2022 12:26:03 PM
 *  Author: MoHaridy
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/timer/timer.h"

// Car port and pins
#define CAR_PORT PORT_A
#define CAR_R_PIN PIN0
#define CAR_Y_PIN PIN1
#define CAR_G_PIN PIN2

// Pedestrian port and pins
#define PED_PORT PORT_B
#define PED_R_PIN PIN0
#define PED_Y_PIN PIN1
#define PED_G_PIN PIN2

void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_on(uint8_t ledPort,uint8_t ledPin);
void LED_off(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);





#endif /* LED_H_ */