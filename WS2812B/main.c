//This example lights 100 LEDs in green

#include "ws2812b.h"

int main(void)
{
	initLEDs();
	
	uint8_t red = 0;
	uint8_t green = 255;
	uint8_t blue = 0;

	for (uint8_t i = 0; i < 100; ++i)
	{
		setColor(red, green, blue);
	}

	flush();

	while (1)
	{
		
	}
}
