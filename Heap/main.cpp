#include "heap.h"
#include <iostream>

int main() {

	Heap myHeap;

	myHeap.Insert(4);
	myHeap.Insert(2);
	myHeap.Insert(5);
	myHeap.Insert(3);
	myHeap.Insert(1);

	myHeap.Print();

	return EXIT_SUCCESS;
}