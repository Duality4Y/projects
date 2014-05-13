#ifndef CXK58257_H
#define CXK58257_H

#include "pinDefs.h"
#include "cxk58257.c"

void initSram();

void setAddress(uint16_t address);
void write(unsigned int address, uint8_t data);
uint8_t read(unsigned int address);

#endif
