#include "delay.h"
volatile uint64_t x;


void systick_init(void){
//__disable_irq();
	SysTick->LOAD=168000-1;
	SysTick->VAL=0;
	SysTick->CTRL=7; //0b00000111;
//	__enable_irq();	
}

void delayuS(int ms)
{

	SysTick->LOAD=168-1;
	SysTick->VAL=0;
	SysTick->CTRL=0x5;
		for (int i=0;i<ms;i++)
		{
			while(!(SysTick->CTRL &0x10000)){}
		}
	SysTick->CTRL=0;	
	

			 
	}

void delay(int ms)
{

	SysTick->LOAD=168000-1;
	SysTick->VAL=0;
	SysTick->CTRL=0x5;
		for (int i=0;i<ms;i++)
		{
			while(!(SysTick->CTRL &0x10000)){}
		}
	SysTick->CTRL=0;	

}