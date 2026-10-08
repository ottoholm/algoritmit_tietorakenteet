#include "linkedList.h"
#include "iostream"


int main() {

	LinkedList ll;  // calls the constructor -> head = null

	// Checks if the list is empty
	std::cout << "IsEmpty(): " << ll.IsEmpty() << std::endl;
	
	// insert 100 values to the list -> 9,8,7...
	for (int i = 1; i < 100; i++) ll.Insert(i);
	// for (int i = 1; i < 100; i++) ll.InsertEnd(i);

	// Print list values
	ll.Print();

	// Find testing
	std::cout << "Find(42): " << ll.Find(42) << std::endl;
	std::cout << "Find(66): " << ll.Find(66) << std::endl;
	std::cout << "Find(100): " << ll.Find(100) << std::endl;

	// Delete testing
	std::cout << "Delete(77): " << ll.Delete(77) << std::endl;
	std::cout << "Delete(21): " << ll.Delete(21) << std::endl;
	std::cout << "Delete(-1)): " << ll.Delete(-1) << std::endl;

	// Delete all
	for (int i = 1; i < 100; i++) ll.Delete(i);

	// Checks if the list is empty
	std::cout << "IsEmpty(): " << ll.IsEmpty() << std::endl;


	return EXIT_SUCCESS;
}
