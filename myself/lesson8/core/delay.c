#include "delay.h"


void delay(uint32_t iter)
{
	int counter = 0;
	while (counter < iter)
	{
		++counter; // delay loop
	}
}