#pragma once

#include <stdexcept>
#include "IntListNode.h"

using namespace std;

class IntegerList {				// a singly linked list
public:
	IntegerList();				// empty list constructor
	~IntegerList();				// destructor
	int& front();					// return front element
	void addFront(int e);		// add to front of list
	void removeFront();			// remove front item list
	void print();
	int size() const;					// list size
private:
	IntListNode* head;				// head of the list
	int     n;							// number of items
};


