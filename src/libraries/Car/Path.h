/*!
Copyright 2012 Andreas Gruber
*/

#ifndef PATH
#define PATH

#include "DefineLib.h"
#include "Movement.h"
#include "List.h"

class Path{
	List<Movement*>* movements;
public:
	Path();
	~Path();
	List<Movement*>& getMovements();
	Iterator<Movement*>* initializeIterator();
	void addMovement(Movement*mov);
};
#endif