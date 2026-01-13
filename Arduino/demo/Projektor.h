/*
 * Projektor.h
 *
 *  Created on: Dec 29, 2023
 *      Author: jakob
 */

#ifndef PROJEKTOR_H_
#define PROJEKTOR_H_

#include <stdint.h>
#include "HT1621.h"
#include <stdio.h>

extern uint8_t Projektor_mapping[23];
extern uint8_t Projektor_Buffer[9];
extern uint8_t Seven_SegmentASCII[96];


void Manipulate_Bit_LCD(uint8_t val);

void Projektor_display(char *Buffer);

void Map_7seg(uint8_t numb, uint8_t col);

void Projektor_Send_Buffer();

void Projektor_Clear_Buffer();


#endif /* PROJEKTOR_H_ */
