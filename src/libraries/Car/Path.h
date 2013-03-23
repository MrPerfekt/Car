/*!
Copyright 2013 Andreas Gruber
*/

#ifndef PATH
#define PATH

#include "DefineLib.h"
#include "ExecutableMovement.h"
#include "List.h"

class Path : public Observer, public SingleObservable{
private:
	bool finished;
	bool deleteAfterCompletion;
	void setFinished(bool finished);
	List<ExecutableMovement*>* movements;
	Iterator<ExecutableMovement*>* movementItor;
public:
	Path();
	~Path();
	List<ExecutableMovement*>& getMovements();
	Iterator<ExecutableMovement*>* initializeIterator();
	void addMovement(ExecutableMovement*mov);
	void execute();
	void executeAndDelete();
	void update();
	void setToStart();
	bool hasFinished() const;
	void getNotified();
};
#endif