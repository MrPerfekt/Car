/*!
Copyright 2012 Andreas Gruber
*/

#include "Observer.h"

void SingleObservable::notifyAll() const{
	if(observer != 0)
		observer->getNotified();
}
void SingleObservable::addObserver(Observer *observer){
	this->observer = observer;
}
void SingleObservable::delObserver(Observer *observer){
	if(this->observer == observer)
		this->observer = 0;
}