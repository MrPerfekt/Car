/*
* Copyright 2012 Andreas Gruber
*/

#ifndef DISPLAY_PROXY
#define DISPLAY_PROXY

#include "DefineLib.h"

class DisplayProxy{
private:
	char pinRST;
	char pinCS;
	char pinClk;
	char pinData;
public:
	DisplayProxy(uint8_t pinRST, uint8_t pinCS, uint8_t pinClk, uint8_t pinData);
	void DrawLine(int color,uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
	void DrawRect(int color,uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
	void FillRect(int color,uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
	void DrawCirkle(int color,uint8_t x, uint8_t y, uint8_t r);
	void FillCirkle(int color,uint8_t x, uint8_t y, uint8_t r);
};

#endif