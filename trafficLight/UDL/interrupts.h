/*
 * interrupts.h
 *
 * Created: 13-Dec-22 9:46:02 AM
 *  Author: MoHaridy
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_


//Interrupt vectors
#define EXT_INT_0 __vector_1
//#define EXT_INT_1 __vector_2

//Enable interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

//Rising edge
#define RISING_EDGE() MCUCR|= (1<<1) | (1<<0)

//Setup use INT0
#define EXT_INT0() GICR|=(1<<6)


//ISR macro
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)


#endif /* INTERRUPTS_H_ */