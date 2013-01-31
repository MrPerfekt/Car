/*!
Copyright 2012 Andreas Gruber
*/

#ifndef EVIRONMENT_KNOWLEDGE_BASE
#define EVIRONMENT_KNOWLEDGE_BASE

#include "DefineLib.h"
#include "Observer.h"

class EnvironmentKnowledgeBase : public SingleObservable{
private:
	Coordinates *lastObject;
public:
	const Coordinates& getLastObject() const;
	EnvironmentKnowledgeBase();
	~EnvironmentKnowledgeBase();
	void detectPoint(Coordinates& coordinates);
};

#endif