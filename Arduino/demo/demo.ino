#include "Projektor.h"



int pin_CS = 13;
int pin_WR = 12;
int pin_DATA = 11;




void setup() {
  pinMode(pin_CS,OUTPUT);
  pinMode(pin_WR,OUTPUT);
  pinMode(pin_DATA,OUTPUT);

  Init_1621(pin_CS,pin_WR,pin_DATA);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  Init_1621(pin_CS,pin_WR,pin_DATA);

  char buffer[10]={0};

  sprintf(buffer,"%02d%c%02d",12,':',34);

  Projektor_Clear_Buffer();
  Projektor_display(buffer);
  Projektor_Send_Buffer();

  delay(5000);

}
