/*
 * app.c
 *
 * Created: 15-Dec-22 9:54:16 AM
 *  Author: MoHaridy
 */ 
#include "app.h"

uint8_t CLed,PLed,NMode;

void APP_init(void){
	// initialize normal mode	
	CLed = 0; //current car led green on -- start scenario --
	PLed = 1; //previous car led yellow was on
	NMode = 1; //normal mode default value
	
	//Car LED initialization
	LED_init(CAR_PORT,CAR_G_PIN);
	LED_init(CAR_PORT,CAR_Y_PIN);
	LED_init(CAR_PORT,CAR_R_PIN);
	
	//Pedestrian LED initialization
	LED_init(PED_PORT,PED_G_PIN);
	LED_init(PED_PORT,PED_Y_PIN);
	LED_init(PED_PORT,PED_R_PIN);
	
	//Button initialization
	BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
	
	//Timer initialization
	TIMER_init();
	
	//Enable Global interrupts & setup rising edge detection for button
	sei();
	RISING_EDGE();
	EXT_INT0();
}

void APP_start(void){
	if(NMode || CLed==0 || CLed==1){
		if(!NMode){
			CLed=1;
		}
		switch (CLed){
			case 0: /*green car led case*/
				LED_on(CAR_PORT,CAR_G_PIN);
				LED_off(CAR_PORT,CAR_Y_PIN);
				LED_off(CAR_PORT,CAR_R_PIN);
				
				LED_on(PED_PORT,PED_R_PIN);
				LED_off(PED_PORT,PED_G_PIN);
				LED_off(PED_PORT,PED_Y_PIN);
				
				for(uint8_t i=0;i<50;i++){
					TIMER_delay(98);
					if(!NMode)break; //if interrupt happened stop the timer and switch to the second case
				}
				CLed = 1;
				PLed = 0;
				break;
			
			case 1: /*yellow car led case*/
				if(!NMode){ //if this case come from the interrupt
					if(PLed!=2){
						LED_on(PED_PORT,PED_R_PIN);
						//blink both yellow leds
						for(uint8_t i=0;i<5;i++){
							LED_on(CAR_PORT,CAR_Y_PIN);
							LED_on(PED_PORT,PED_Y_PIN);
							TIMER_delay(315);
							LED_off(CAR_PORT,CAR_Y_PIN);
							LED_off(PED_PORT,PED_Y_PIN);
							TIMER_delay(315);
							LED_on(CAR_PORT,CAR_Y_PIN);
							LED_on(PED_PORT,PED_Y_PIN);
							TIMER_delay(315);
						}
					}
					PLed=1;
					CLed=2;
					LED_on(CAR_PORT,CAR_R_PIN);
					}else{ //if this case come from normal mode
					//blink car yellow led
					for(uint8_t i=0;i<5;i++){
						LED_on(CAR_PORT,CAR_Y_PIN);
						LED_on(PED_PORT,PED_Y_PIN);
						TIMER_delay(315);
						LED_off(CAR_PORT,CAR_Y_PIN);
						LED_off(PED_PORT,PED_Y_PIN);
						TIMER_delay(315);
						LED_on(CAR_PORT,CAR_Y_PIN);
						LED_on(PED_PORT,PED_Y_PIN);
						TIMER_delay(315);
						if(!NMode){//check if interrupt was called
							PLed=1;
							break;
						}
					}
				}
				LED_off(CAR_PORT,CAR_Y_PIN);
				LED_off(PED_PORT,PED_Y_PIN);
				//Configure current leds to switch in correct order
				if(PLed==0){
					CLed=2;
					PLed=1;
				}else if(PLed==2){
					CLed=0;
					PLed=1;
				}
				break;
			
			case 2: /*red car led case*/
				LED_off(CAR_PORT,CAR_G_PIN);
				LED_off(CAR_PORT,CAR_Y_PIN);
				LED_on(CAR_PORT,CAR_R_PIN);
				
				LED_off(PED_PORT,PED_R_PIN);
				LED_off(PED_PORT,PED_Y_PIN);
				LED_on(PED_PORT,PED_G_PIN);
				
				for(uint8_t i=0;i<50;i++){
					TIMER_delay(98);
					if(!NMode)break; //if interrupt happened stop the timer and switch to the second case
				}
				PLed=2;
				CLed=1;
				break;
			
			default:
				CLed=2;
				PLed=1;
				break;
			}
		}else{
		//Configure CAR LEDs
		LED_off(CAR_PORT,CAR_G_PIN);
		LED_off(CAR_PORT,CAR_Y_PIN);
		LED_on(CAR_PORT,CAR_R_PIN);
		
		//Configure PED LEDs
		LED_off(PED_PORT,PED_Y_PIN);
		LED_off(PED_PORT,PED_R_PIN);
		LED_on(PED_PORT,PED_G_PIN);
		TIMER_delay(5000);//5 sec delay
		
		//blink both yellow while ped green is on
		for(uint8_t i=0;i<5;i++){
			LED_on(CAR_PORT,CAR_Y_PIN);
			LED_on(PED_PORT,PED_Y_PIN);
			TIMER_delay(315);
			LED_off(CAR_PORT,CAR_Y_PIN);
			LED_off(PED_PORT,PED_Y_PIN);
			TIMER_delay(315);
			LED_on(CAR_PORT,CAR_Y_PIN);
			LED_on(PED_PORT,PED_Y_PIN);
			TIMER_delay(315);
		}
		//Turn off yellow LEDs
		LED_off(CAR_PORT,CAR_Y_PIN);
		LED_off(PED_PORT,PED_Y_PIN);
		//turn on PED red LED
		LED_on(PED_PORT,PED_R_PIN);
		//reset normal mode
		NMode=1;
		//Configure carLED variables
		CLed=0;
		PLed=1;
	}
}
ISR(EXT_INT_0)
{
	NMode = 0;
}