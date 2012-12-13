/*!
Copyright 2012 Andreas Gruber
*/

#include "PathExecutor.h"

PathExecutor::PathExecutor(SteeringManager&steeringManager)
	:steeringManager(steeringManager)
	,movementItor(NULL){
}
PathExecutor::~PathExecutor(){
}
void PathExecutor::update(){
	if(movementItor == NULL) return;
	
Serial.println("-ab-");
	if(steeringManager.getState() == SteeringManager::ss_stop){
Serial.println("ab");
		if(movementItor->hasNext()){
Serial.println("a");
			steeringManager.driveMovement(*movementItor->getCurrent());
		}else{
Serial.println("b");
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