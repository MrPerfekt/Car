/*!
Copyright 2012 Andreas Gruber
*/

#include "PathExecutor.h"
#include "TurnMovement.h"
#include "StraightMovement.h"
#include "Path.h"


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
			//steeringManager.driveMovement(*movementItor->getCurrent());
			
			//! TODO
			if(movementItor->getCurrent()->getAngle() == 0)
				((StraightMovement*)movementItor->getCurrent())->invokeOnSteeringManager(steeringManager);
			else
				((TurnMovement*)movementItor->getCurrent())->invokeOnSteeringManager(steeringManager);
			//! TODO

		}else{
			movementItor = NULL;
			steeringManager.stop();//Notify Pathplaner instead
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
	movementItor = path->initializeIterator();
}