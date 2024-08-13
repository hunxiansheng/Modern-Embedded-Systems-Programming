extern void SystemInit(void);

#include "stm32c031xx.h"


// LED marked "LD4" on the NUCLEO-C031C6 board
#define LD4_PIN  5U


int main(void)
{
  
    // enable GPIOA clock port for the LEDs
    RCC_IOPENR_R |= (1U << 0U);
	  // NUCLEO-C031C6 board has LED LD4 on GPIOA pin LD4_PIN
	  GPIOA_MODER_R   &= ~(3U << 2U*LD4_PIN);  
    GPIOA_MODER_R   |=  (1U << 2U*LD4_PIN);
		GPIOA_OTYPER_R  &= ~(1U <<    LD4_PIN);
		GPIOA_OSPEEDR_R &= ~(3U << 2U*LD4_PIN);
	  GPIOA_OSPEEDR_R |=  (1U << 2U*LD4_PIN);
	  GPIOA_PUPDR_R   &= ~(3U << 2U*LD4_PIN);
		while(1)
		{
			 GPIOA_BSRR_R = (1U << LD4_PIN); // turn LD4 on
			 //delay
			 int counter = 0;
       while (counter < 500000) {  // delay loop
              ++counter;
       }
			 GPIOA_BSRR_R = (1U << (LD4_PIN + 16U)); // turn LD4 off
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
