/*
 * Projektor.cpp
 *
 *  Created on: Dec 29, 2023
 *      Author: jakob
 */

#include "Projektor.h"

uint8_t Portwert;
uint8_t Pinwert;


void Manipulate_Bit_LCD(uint8_t val){
	Portwert = val / 8;
	Pinwert = val - (Portwert*8);
	Pinwert = 7 - Pinwert;

	Projektor_Buffer[Portwert] |= 1UL << Pinwert;
}



void Projektor_display(char *Buffer){

	if((Buffer[0] == '1') || (Buffer[0] == 'I')){
		Manipulate_Bit_LCD(Projektor_mapping[21]);
	}

	Map_7seg(Buffer[1],0);

	if(Buffer[2] == ':'){
		Manipulate_Bit_LCD(Projektor_mapping[22]);
	}

	Map_7seg(Buffer[3],1);
	Map_7seg(Buffer[4],2);



}

void Map_7seg(uint8_t numb, uint8_t col){
	uint8_t seg7;
	seg7 = Seven_SegmentASCII[numb-32];
	for(uint8_t i = 0;i<8;i++){
		if((seg7 >> i) & 1U){
			Manipulate_Bit_LCD(Projektor_mapping[((col*7)+i)]);
		}
	}
}

void Projektor_Send_Buffer(){
	for(uint8_t i = 0;i<10;i++){
		Write_1621(i,Projektor_Buffer[i]);
	}
}

void Projektor_Clear_Buffer(){
	for(uint8_t i = 0;i<10;i++){
		Projektor_Buffer[i] = 0;
	}
}

