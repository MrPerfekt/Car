/*
* Copyright 2012 Andreas Gruber
*/

#include "DisplayProxy.h"

DisplayProxy::DisplayProxy(char pinRST, char pinCS, char pinClk, char pinData)
	:pinRST(pinRST),pinCS(pinCS),pinClk(pinClk),pinData(pinData){
}