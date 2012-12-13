/*!
Copyright 2012 Andreas Gruber
*/

#include "Path.h"
#include "List.h"

Path::Path()
:movements(new List<Movement*>()){
}
Path::~Path(){
	movements->destructAll();
	delete movements;
}
List<Movement*>& Path::getMovements(){
	return *movements;
}
Iterator<Movement*>* Path::initializeIterator(){
	return new Iterator<Movement*>(getMovements());
}
void Path::addMovement(Movement*mov){
	movements->addBehind(mov);
}