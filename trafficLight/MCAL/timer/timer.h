/*
 * timer.h
 *
 * Created: 15-Dec-22 9:59:49 AM
 *  Author: MoHaridy
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "../../UDL/registers.h"
#include "../../UDL/bitControl.h"


void TIMER_init();//initialize Timer0
void TIMER_delay(uint16_t ms); //delay of specific amount


#endif /* TIMER_H_ */