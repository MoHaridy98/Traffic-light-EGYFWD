/*
 * timer.c
 *
 * Created: 15-Dec-22 10:00:00 AM
 *  Author: MoHaridy
 */ 

#include "timer.h"
#include <math.h>
#include "../../UDL/bitControl.h"

//initializes the timer into normal mode
void TIMER_init()
{
	TCCR0 = 0x00;
}

void TIMER_delay(uint16_t ms)
{
	uint16_t Numberofoverflows, initialtimer;
	float TimerMAXdelay, TimerTick, prescaler = 265.0, frequency = 1000.0;
	uint32_t overflowcounter = 0;
	TimerTick = prescaler/frequency;
	TimerMAXdelay = TimerTick * 256;
	if(ms < TimerMAXdelay)
	{
			initialtimer = (TimerMAXdelay-ms)/TimerTick;
			Numberofoverflows = 1;
	}
	else if(ms == (int)TimerMAXdelay)
	{
		initialtimer = 0;
		Numberofoverflows = 1;
	}
	else
	{
			Numberofoverflows = ceil((double)ms/TimerMAXdelay);
			initialtimer = (1<<8) - ((double)ms/TimerTick)/Numberofoverflows;
	}
	TCNT0 = initialtimer;
	SET_BIT(TCCR0,2);
	while(overflowcounter < Numberofoverflows)
	{
		while(READ_BIT(TIFR,0)==0);
		SET_BIT(TIFR,0);
		overflowcounter++;
	}
	overflowcounter = 0;
	
	TCCR0 = 0x00;
}