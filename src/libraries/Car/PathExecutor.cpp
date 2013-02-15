/*!
Copyright 2012 Andreas Gruber
*/

#include "ExecutableMovement.h"
#include "PathExecutor.h"
#include "TurnMovement.h"
#include "SteeringManager.h"
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
			((StraightMovement*)movementItor->getCurrent())->execute();
		}else{
			setPath(NULL);
			steeringManager.stop(); //!TODO: Notify car main logic instead
		}	
	}
}
/*!
Set the path of the PathExecutor.
This method can also be used to delete the path. This is possible by invoking
*/
void PathExecutor::setPath(Path*path){
	if(movementItor != NULL)
		delete movementItor;

	if(path == NULL)
		movementItor = NULL;
	else
		movementItor = path->initializeIterator();
}