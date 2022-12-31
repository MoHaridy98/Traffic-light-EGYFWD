/*
 * trafficLight.c
 *
 * Created: 31-Dec-22 10:11:07 AM
 * Author : Mohammad Yasser
 */ 

#include "APP/app.h"


int main(void)
{
	APP_init();
	//BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
	//LED_init(CAR_PORT,CAR_G_PIN);
	//LED_init(CAR_PORT,PED_G_PIN);
	//TIMER_init();
	//uint8_t value;
	while (1)
	{
		APP_start();
		//BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&value);
		//if(value==HIGH){
			//LED_toggle(CAR_PORT,CAR_G_PIN);
			//LED_on(PED_PORT,PED_G_PIN);
			//TIMER_delay(500);
			//LED_off(PED_PORT,PED_G_PIN);
			//TIMER_delay(500);
//
			//}else{
			//LED_on(CAR_PORT,CAR_G_PIN);
		//}
	}
}

