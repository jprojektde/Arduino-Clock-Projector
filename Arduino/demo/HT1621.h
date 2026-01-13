/*
 * HT1621.h
 *
 *  Created on: Dec 29, 2023
 *      Author: jakob
 */

#ifndef HT1621_H_
#define HT1621_H_

#include <stdint.h>
#include <Arduino.h>
#pragma once


extern uint8_t DATA;
extern uint8_t WR;
extern uint8_t CS;


#define CS1    digitalWrite(CS,HIGH);
#define CS0    digitalWrite(CS,LOW);
#define WR1    digitalWrite(WR,HIGH);
#define WR0    digitalWrite(WR,LOW);
#define DATA1  digitalWrite(DATA,HIGH);
#define DATA0  digitalWrite(DATA,LOW);

#define  ComMode    0x40  //2COM,1/2bias  1000    010 1001  0
#define  RCosc      0x30  //1000 0011 0000
#define  LCD_on     0x06
#define  LCD_off    0x04
#define  Sys_en     0x02  //1000   0000 0010
#define  CTRl_cmd   0x80
#define  Data_cmd   0xa0

#define sbi(x, y)  (x |= (1 << y))
#define cbi(x, y)  (x &= ~(1 <<y ))
#define uchar   unsigned char
#define uint   unsigned int

void SendBit_1621(uchar sdata,uchar cnt);

void SendCmd_1621(uchar command);

void Write_1621(uchar addr,uchar sdata);

void HT1621_all_off(uchar num);

void HT1621_all_on(uchar num);

void Init_1621(int cs, int wr, int data);



#endif /* HT1621_H_ */
