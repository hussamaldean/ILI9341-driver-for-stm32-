#include "stm32f4xx.h"                  // Device header
#include "adc.h"
void ADC_init(void){
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN; //enable gpio a clock
RCC->APB2ENR|=RCC_APB2ENR_ADC1EN; //enable adc clock
GPIOA->MODER|=GPIO_MODER_MODER1;  //set the PA1 to analog mode
ADC1->CR2=0; //disable the adc 	
ADC1->SQR3|=1; 
ADC1->CR2|=1; //enable the adc 	 

}


uint8_t readADC(void)
{
	unsigned long adcValue;
	ADC1->CR2|=ADC_CR2_SWSTART; //start adc conversion
	while(!(ADC1->SR)&ADC_SR_EOC){;}
	adcValue=ADC1->DR;		
	return adcValue;
}
	