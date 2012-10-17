/*
* Copyright 2012 Andreas Gruber
*/

#include "DisplayProxy.h"

DisplayProxy::DisplayProxy(uint8_t pinRST, uint8_t pinCS, uint8_t pinClk, uint8_t pinData)
	:pinRST(pinRST),pinCS(pinCS),pinClk(pinClk),pinData(pinData){
}