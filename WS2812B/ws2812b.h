/*
 * ws2812b.h
 *
 * Created: 31.03.2019
 * Author : Alexander Velilyaev
 * Contact: Alexandervelilyaev@gmail.com
 *
 * This library allows to control a chain of WS2812B LEDs
 */

#ifndef WS2812B_H_
#define WS2812B_H_

#define DATA_PIN 5
#define DATA_PORT PORTD
#define DDRx DDRD

#include <avr/io.h>

//Initialize DIN pin of LEDs chain
void initLEDs();

//Set color of the current LED
void setColor(uint8_t red, uint8_t green, uint8_t blue);

//Flush all LEDs in the chain
void flush();

#endif /* WS2812B_H_ */