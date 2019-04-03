 #include "ws2812b.h"

 #define F_CPU 16000000UL
 #include <util/delay.h>

 #define RST 50
 #define SET_BIT(PORT, POS, VALUE) PORT = (PORT & ~(1 << POS)) | (VALUE << POS)
 #define GET_BIT(PORT, POS) (PORT & (1 << POS)) >> POS
 #define WAIT_SMALL ({asm("nop");asm("nop");})
 #define WAIT_BIG ({asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");})

 void initLEDs()
 {
	SET_BIT(DDRx, DATA_PIN, 1);
 }

 void SendBit(uint8_t BIT)
 {
	 SET_BIT(DATA_PORT, DATA_PIN, 1);
	 if (BIT)
	 WAIT_BIG;
	 else
	 WAIT_SMALL;

	 SET_BIT(DATA_PORT, DATA_PIN, 0);
	 if (BIT)
	 WAIT_SMALL;
	 else
	 WAIT_BIG;
 }

 void flush()
 {
	 SET_BIT(DATA_PORT, DATA_PIN, 0);
	 _delay_us(RST);
 }

 void setColor(uint8_t red, uint8_t green, uint8_t blue)
 {
	 SendBit(GET_BIT(green, 7));
	 SendBit(GET_BIT(green, 6));
	 SendBit(GET_BIT(green, 5));
	 SendBit(GET_BIT(green, 4));
	 SendBit(GET_BIT(green, 3));
	 SendBit(GET_BIT(green, 2));
	 SendBit(GET_BIT(green, 1));
	 SendBit(GET_BIT(green, 0));
	 
	 SendBit(GET_BIT(red, 7));
	 SendBit(GET_BIT(red, 6));
	 SendBit(GET_BIT(red, 5));
	 SendBit(GET_BIT(red, 4));
	 SendBit(GET_BIT(red, 3));
	 SendBit(GET_BIT(red, 2));
	 SendBit(GET_BIT(red, 1));
	 SendBit(GET_BIT(red, 0));
	 
	 SendBit(GET_BIT(blue, 7));
	 SendBit(GET_BIT(blue, 6));
	 SendBit(GET_BIT(blue, 5));
	 SendBit(GET_BIT(blue, 4));
	 SendBit(GET_BIT(blue, 3));
	 SendBit(GET_BIT(blue, 2));
	 SendBit(GET_BIT(blue, 1));
	 SendBit(GET_BIT(blue, 0));
 }