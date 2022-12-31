/*
 * dio.h
 *
 * Created: 12/11/2022 10:36:22 AM
 *  Author: MoHaridy
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../UDL/registers.h"
#include "../UDL/bitControl.h"
//******************************//
//all driver macros*************//
//******************************//
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Direction defines
#define IN 0
#define OUT 1

//Value defines
#define LOW 0
#define HIGH 1

//******************************//
//all driver function prototypes//
//******************************//
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); //initialization DIO direction

void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); //write data to DIO

void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); //toggle DIO

void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); //read DIO


#endif /* DIO_H_ */