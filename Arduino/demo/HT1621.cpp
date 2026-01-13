/*
 * HT1621.cpp
 *
 *  Created on: Dec 29, 2023
 *      Author: jakob
 */

#include "HT1621.h"


uint8_t CS = 13;
uint8_t WR = 12;
uint8_t DATA = 11;

void SendBit_1621(uchar sdata,uchar cnt)
{
  //data cnt HT1621
  uchar i;
  for(i=0;i<cnt;i++)
  {
    WR0;
    //HAL_Delay(1);
    if(sdata&0x80){
    	DATA1;
    } else{
    	DATA0;
    }
    WR1;
    sdata<<=1;
  }
}

void SendCmd_1621(uchar command)
{
  CS0;
  SendBit_1621(0x80,4);
  SendBit_1621(command,8);
  CS1;
}

void Write_1621(uchar addr,uchar sdata)
{
  addr<<=2;
  CS0;
  SendBit_1621(0xa0,3);
  SendBit_1621(addr,6);
  SendBit_1621(sdata,8);
  CS1;
}

void HT1621_all_off(uchar num)
{
  uchar i;
  uchar addr=0;
  for(i=0;i<num;i++)
  {
    Write_1621(addr,0x00);
    addr+=2;
  }
}

void HT1621_all_on(uchar num)
{
  uchar i;
  uchar addr=0;
  for(i=0;i<num;i++)
  {
    Write_1621(addr,0xff);
    addr+=2;
  }
}

void Init_1621(int cs, int wr, int data)
{
  CS = cs;
  WR = wr;
  DATA = data;
  
  SendCmd_1621(Sys_en);
  SendCmd_1621(RCosc);
  SendCmd_1621(ComMode);
  SendCmd_1621(LCD_on);
}
