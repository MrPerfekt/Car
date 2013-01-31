/*!
Copyright 2012 Andreas Gruber
*/

#include "EnvironmentKnowledgeBase.h"

const Coordinates& EnvironmentKnowledgeBase::getLastObject() const{
	return *lastObject;
}

EnvironmentKnowledgeBase::EnvironmentKnowledgeBase(){
	lastObject = new Coordinates();
}
EnvironmentKnowledgeBase::~EnvironmentKnowledgeBase(){
}

void EnvironmentKnowledgeBase::detectPoint(Coordinates& coordinates){
	lastObject->set(coordinates);
	notifyAll();
}