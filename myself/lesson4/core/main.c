extern void SystemInit(void);

int main(void)
{
    // enable GPIOA clock port for the LED LD4
    *((unsigned int *)0x40021034U) = 0x001U; // RCC IOPENR register
	  *((unsigned int *)0x50000000U) = 0x400U; // GPIOA MODER register
    *((unsigned int *)0x50000004U) = 0x000U; // GPIOA OTYPER register
		*((unsigned int *)0x50000008U) = 0x400U; // GPIOA OSPEEDR register
		*((unsigned int *)0x5000000CU) = 0x000U; // GPIOA PUPDR register
		while(1)
		{
			 *((unsigned int *)0x50000018U) = 0x20U; // GPIOA BSRR register led on
			 //delay
			  int volatile counter = 0;
        while (counter < 500000) {  // delay loop
            ++counter;
        }
			 *((unsigned int *)0x50000018U) = 0x200000U; // GPIOA BSRR register led off
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
