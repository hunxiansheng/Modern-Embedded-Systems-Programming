extern void SystemInit(void);

#include "stm32c031xx.h"
#include <stdint.h>
#include "delay.h"

// LED marked "LD4" on the NUCLEO-C031C6 board
#define LD4_PIN 5U
#define BITBAND_REG(REG, BIT) (*((uint32_t volatile *)(0x42000000u + (((uint32_t) & (REG) - (uint32_t)0x40000000u) << 5) + (((uint32_t)(BIT)) << 2))))



int main(void)
{

	// enable GPIOA clock port for the LEDs
	RCC_IOPENR_R |= (1U << 0U);
	// NUCLEO-C031C6 board has LED LD4 on GPIOA pin LD4_PIN
	GPIOA_MODER_R &= ~(3U << 2U * LD4_PIN);
	GPIOA_MODER_R |= (1U << 2U * LD4_PIN);
	GPIOA_OTYPER_R &= ~(1U << LD4_PIN);
	GPIOA_OSPEEDR_R &= ~(3U << 2U * LD4_PIN);
	GPIOA_OSPEEDR_R |= (1U << 2U * LD4_PIN);
	GPIOA_PUPDR_R &= ~(3U << 2U * LD4_PIN);
	while (1)
	{
		GPIOA_BSRR_R = (1U << LD4_PIN); // turn LD4 on
		// delay
		delay(1000000U);
		GPIOA_BSRR_R = (1U << (LD4_PIN + 16U)); // turn LD4 off
		// delay
		delay(500000U);
	}
}

void SystemInit(void)
{
}
