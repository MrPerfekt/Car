/*!
Copyright 2013 Andreas Gruber
*/

#include "DisplayProxy.h"

DisplayProxy::DisplayProxy(){
	return;
	d = new gLCD(
		Config::getPinDisplayRST(),
		Config::getPinDisplayCS(),
		Config::getPinDisplayClk(),
		Config::getPinDisplayData(),
		1);//! 1= High Speed

	d->Init(0,2,0,1,1);//! xzero = 0, yzero = 2, invertColor = 0, philips = true, xRevers = true
	d->Contrast(0x2B);//! Range: -0x3F to 0x3F
	d->SetBackColour(15,15,15);
	d->SetForeColour(0,0,15); 
}