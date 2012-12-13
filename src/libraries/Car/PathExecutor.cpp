/*!
Copyright 2012 Andreas Gruber
*/

#include "PathExecutor.h"

PathExecutor::PathExecutor(SteeringManager&steeringManager)
:steeringManager(steeringManager){
}
PathExecutor::~PathExecutor(){
}
void PathExecutor::update(){
	if(movementItor == 0 || movementItor->getCurrent() == NULL) return;
	
	if(steeringManager.getState() == SteeringManager::ss_stop){
		if(movementItor->hasNext()){
			steeringManager.driveMovement(*movementItor->getCurrent());
		}else{
			movementItor = 0;
			steeringManager.stop();//Notify Pathplaner instead
		}	
	}
}
/*!
Set the path of the PathExecutor.
This method can also be used to delete the path. This is possible by infoking
*/
void PathExecutor::setPath(Path*path){
	if(movementItor != 0)
		delete movementItor;
	movementItor = path->initializeIterator();
}