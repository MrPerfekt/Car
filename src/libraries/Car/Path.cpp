/*!
Copyright 2012 Andreas Gruber
*/

#include "Path.h"
#include "List.h"

Path::Path()
:movements(new List<ExecutableMovement*>())
,finished(true){
}
Path::~Path(){
	movements->destructAll();
	delete movements;
	delete movementItor;
}
List<ExecutableMovement*>& Path::getMovements(){
	return *movements;
}
Iterator<ExecutableMovement*>* Path::initializeIterator(){
	return new Iterator<ExecutableMovement*>(getMovements());
}
void Path::addMovement(ExecutableMovement*mov){
	movements->addBehind(mov);
}



void Path::setFinished(bool finished){
	if(finished == true) notifyAll();
	this->finished = finished;
}
bool Path::hasFinished() const{
	return finished;
}
void Path::execute(){
	setToStart();
}
void Path::update(){
	if(finished)
		return;
	if(movementItor == NULL)
		movementItor = initializeIterator();
	if(!movementItor->hasNext()){
		setFinished(true);
		return;
	}
	ExecutableMovement* m = movementItor->getCurrent();
	if(m == NULL)
		return;
	m->execute();
}
void Path::setToStart(){
	setFinished(false);
	movementItor->setToStart();
}
void Path::getNotified(){
	update();
}