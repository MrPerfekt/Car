/*!
Copyright 2012 Andreas Gruber
*/

#ifndef PATHEXECUTOR
#define PATHEXECUTOR

#include "DefineLib.h"
#include "List.h"
//#include "Path.h"
class ExecutableMovement;
class Path;
class SteeringManager;

class PathExecutor{
	SteeringManager& steeringManager;
	Iterator<ExecutableMovement*>* movementItor;
public:
	const SteeringManager& getSteeringManager() const;

	PathExecutor(SteeringManager& steeringManager);
	~PathExecutor();
	/*!
	Executes the setted path.
	Before this method can be called SteeringManager::update have to be called at least one.
	This method check if SteeringManager has allready finished (and if it will notify PositionPlaner)
	*/
	void update();
	void setPath(Path*path);
};
#endif