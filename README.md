![WS2812B Banner](https://github.com/Alexandervelilyaev/WS2812B/blob/master/resources/ws2812b.jpg)
# Simple AVR library for RGB LED (WS2812B)
This library allows to control a chain of WS2812B LEDs using microcontroller Atmega328p. Library implements most necessary functions(according to [datasheet](resources/ws2812b.pdf)).

## How to use:

* Initialize DIN pin of LEDs chain:
```c 
void initLEDs()
``` 

* Set color of the current LED:
```c
void setColor(uint8_t red, uint8_t green, uint8_t blue)
```

* Flush all LEDs in the chain:
```c
void flush() 
```

## Example
```c
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

```
