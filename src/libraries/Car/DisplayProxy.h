/*!
Copyright 2012 Andreas Gruber
*/

#ifndef DISPLAY_PROXY
#define DISPLAY_PROXY

#include "DefineLib.h"
#include "gLCD.h"

class DisplayProxy{
public:
	enum Color{
		black=0x000,
		blue=0x00F,
		green=0x0F0,
		red=0xF00,
		white=0xFFF,
	};
private:
	gLCD* d;//! Display driver
public:
	DisplayProxy();
	void DrawLine(int color,uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
	void DrawRect(int color,uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
	void FillRect(int color,uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
	void DrawCirkle(int color,uint8_t x, uint8_t y, uint8_t r);
	void FillCirkle(int color,uint8_t x, uint8_t y, uint8_t r);
};

#endif