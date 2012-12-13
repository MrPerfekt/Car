/*!
Copyright 2012 Andreas Gruber
*/

#ifndef LIST
#define LIST

#include "DefineLib.h"

template <class T>
class Node{
	Node*next;
	T data;
public:
	void setNext(Node*next){
		this->next = next;
	}
	Node*getNext(){
		return next;
	}
	void setData(T data){
		this->T = data;
	}
	T getData(){
		return data;
	}
	
	Node(T data)
	:data(data){
	}
	Node(T data, Node*next)
	:data(data),next(next){
	}
	~Node(){
		if(next != NULL)
			delete next;
	}
};

template <class T>
class List{
	Node<T>* first;
	Node<T>* last;
public:
	Node<T>* getFirst(){
		return first;
	}
	List(){
	}
	~List(){
		delete first;
	}

	void addBehind(T data){
		if(first == NULL)
			first = last = new Node<T>(data);
		else
			last->setNext(new Node<T>(data));
			last = last->getNext();
	}
	void destructAll(){
		Node<T>* current = first;
		while(current != NULL){
			delete current;
		}
	}
};

template <class T>
class Iterator{
private:
	List<T>& list;
	Node<T>* current;
public:
	Iterator(List<T>& list)
	:list(list){
	}
	T getCurrent(){
		return current->getData();
	}
	void setToStart(){
		current = NULL;
	}
	bool hasNext(){
		if(current == NULL){
			current = list.getFirst();
			return true;
		}else{
			current = current->getNext();
			return current != NULL;
		}
	}
};



#endif