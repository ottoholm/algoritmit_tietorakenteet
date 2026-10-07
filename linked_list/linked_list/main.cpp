#include "linkedList.h"
#include "iostream"


int main() {

	LinkedList ll;  // calls the constructor -> head = null

	// Checks if the list is empty
	std::cout << "IsEmpty(): " << ll.IsEmpty() << std::endl;
	
	// insert 10 values to the list -> 9,8,7...
	for (int i = 1; i < 10; i++) ll.Insert(i);

	// Print list values
	ll.Print();




	return EXIT_SUCCESS;
}
