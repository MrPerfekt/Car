/*!
Copyright 2012 Andreas Gruber
*/

#include "PathExecutor.h"
#include "TurnMovement.h"
#include "StraightMovement.h"
#include "Path.h"

const SteeringManager& PathExecutor::getSteeringManager() const{
	return steeringManager;
}

PathExecutor::PathExecutor(SteeringManager&steeringManager)
	:steeringManager(steeringManager)
	,movementItor(NULL){
}
PathExecutor::~PathExecutor(){
}
void PathExecutor::update(){
	if(movementItor == NULL) return;
	if(steeringManager.hasFinished()){
		if(movementItor->hasNext()){
			//! TODO
			if(movementItor->getCurrent()->getAngle() == 0)
				((StraightMovement*)movementItor->getCurrent())->invokeOnSteeringManager(steeringManager);
			else
				((TurnMovement*)movementItor->getCurrent())->invokeOnSteeringManager(steeringManager);
			//! TODO

		}else{
			setPath(NULL);
			//!TODO: Notify car main logic
		}	
	}
}
/*!
Set the path of the PathExecutor.
This method can also be used to delete the path. This is possible by infoking
*/
void PathExecutor::setPath(Path*path){
	if(movementItor != NULL)
		delete movementItor;

	if(path == NULL)
		movementItor = NULL;
	else
		movementItor = path->initializeIterator();
}