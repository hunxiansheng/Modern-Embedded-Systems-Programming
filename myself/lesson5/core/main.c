extern void SystemInit(void);

#include "stm32c031xx.h"
	
int main(void)
{
  
    RCC_IOPENR_R = 0x001U; 
	  GPIOA_MODER_R = 0x28000400U; 
    GPIOA_OTYPER_R = 0x000U; 
		GPIOA_OSPEEDR_R = 0x400U; 
		GPIOA_PUPDR_R = 0x000U; 
		while(1)
		{
			 GPIOA_BSRR_R  = 0x20U; //  led on
			 //delay
			 int counter = 0;
       while (counter < 500000) {  // delay loop
              ++counter;
       }
			 GPIOA_BSRR_R  = 0x200000U; //  led off
			 //delay
			 counter = 0;
       while (counter < 500000) {  // delay loop
             ++counter;
       }
		}
}

void SystemInit(void)
{
}
