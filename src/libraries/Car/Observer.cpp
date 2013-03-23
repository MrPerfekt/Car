/*!
Copyright 2013 Andreas Gruber
*/

#include "DefineLib.h"
#include "Observer.h"

void SingleObservable::notifyAll() const{
	if(observer != NULL)
		observer->getNotified();
}
void SingleObservable::addObserver(Observer *observer){
	this->observer = observer;
}
void SingleObservable::delObserver(Observer *observer){
	if(this->observer == observer)
		this->observer = 0;
}