#include <stdexcept>
#include <iostream>
#include "IntegerList.h"

using namespace std;

int main() {

	IntegerList mylist;

	for (int i = 0; i < 5; i++) {
		mylist.addFront(i);
	}

	mylist.print();
}
