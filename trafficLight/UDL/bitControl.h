/*
 * bitControl.h
 *
 * Created: 12/11/2022 10:55:23 AM
 *  Author: MoHaridy
 */ 


#ifndef BITCONTROL_H_
#define BITCONTROL_H_


#define CLEAR_BIT(REG,NUM) REG&=~(1<<NUM) //clear bit
#define SET_BIT(REG,NUM) REG|=(1<<NUM) //set bit
#define TOGGLE_BIT(REG,NUM) REG^=(1<<NUM) //toggle bit
#define READ_BIT(REG,NUM) ((REG&(1<<NUM))>>NUM) //read bit


#endif /* BITCONTROL_H_ */