/*!
Copyright 2012 Andreas Gruber
*/

#ifndef OBSERVER
#define OBSERVER

class Observer{
private:
public:
	virtual void getNotified() = 0;
};

class Observable {
private:
public:
	virtual void notifyAll() const = 0;
	virtual void addObserver(Observer *observer) = 0;
	virtual void delObserver(Observer *observer) = 0;
};

class SingleObservable {
private:
	Observer *observer;
public:
	void notifyAll() const;
	void addObserver(Observer *observer);
	void delObserver(Observer *observer);
};


#endif