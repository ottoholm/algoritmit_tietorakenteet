#include <iostream>
#include "bst.h"

int main()
{
	BST bst;

	bst.Insert(5);
	bst.Insert(3);
	bst.Insert(8);
	bst.Insert(2);
	bst.Insert(4);
	bst.Insert(1);
	bst.Insert(7);
	bst.Insert(6);
	bst.Insert(9);

	bst.Print();

	std::cout << "Find(6): " << bst.Find(6) << std::endl;
	std::cout << "Find(10): " << bst.Find(10) << std::endl;

	std::cout << "CountNodes(): " << bst.CountNodes() << std::endl;
	std::cout << "CountLeaves() " << bst.CountLeaves() << std::endl;

	return EXIT_SUCCESS;
}