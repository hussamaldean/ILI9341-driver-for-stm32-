#ifndef __adc__h
#define __adc__h
#include "stm32f4xx.h"                  // Device header

#include <stdint.h>

void ADC_init(void);
uint8_t readADC(void);



#endif