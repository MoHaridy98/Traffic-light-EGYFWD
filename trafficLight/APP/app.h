/*
 * app.h
 *
 * Created: 18-Dec-22 9:54:23 AM
 *  Author: MoHaridy
 */ 


#ifndef APP_H_
#define APP_H_


#include "../ECUAL/LED/led.h"
#include "../ECUAL/button/button.h"
#include "../MCAL/timer/timer.h"
#include "../UDL/interrupts.h"


void APP_init(void);
void APP_start(void);


#endif /* APP_H_ */