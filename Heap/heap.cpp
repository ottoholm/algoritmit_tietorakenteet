#include "heap.h"
#include <iostream>

void Heap::Insert(int key)
{
	if (Length() >= MAX_SIZE) {
		std::cerr << "ERROR: Too large heap size" << std::endl;
	}

	// If the heap is empty
	if (Length() < 1) {
		heapArray[1] = key; // put the key into index 1
		heapArray[0]++;
		return;
	}

	// 1. Insert the key into first available slot
	int index = Length() + 1;
	heapArray[index] = key;

	// 2. Incerement length of the heap
	heapArray[0]++;

	// 3. While heaporder not guaranteed:
	//		- track the newly inserted element
	//		- swap places with parent
	int parent_index = index / 2;
	while (heapArray[parent_index] > heapArray[index] && index > 1) {
		// SWAP:
		int tmp_parent = heapArray[parent_index];

		heapArray[parent_index] = heapArray[index];
		heapArray[index] = tmp_parent;

		index = parent_index;
		parent_index = index / 2;
	}
}

int Heap::DelMin()
{
	// Smallest is the first in a min heap
	int min_value = heapArray[1];

	// Delete the smallest -> last will become first 
	heapArray[1] = heapArray[Length()];
	// Decerement length of the heap
	heapArray[0]--;
	
	// Reordering:
	int parent_index = 1;
	int child_index = parent_index * 2;

	while (child_index <= Length())
	{
		// if there is a second children and it is smaller, lets use it
		if (child_index + 1 <= Length() && heapArray[child_index + 1] < heapArray[child_index])
		{
			child_index++;
		}

		// If order is already okay, then quit
		if (heapArray[parent_index] <= heapArray[child_index])
		{
			break;
		}

		// Swtich older and the children
		int tmp = heapArray[parent_index];
		heapArray[parent_index] = heapArray[child_index];
		heapArray[child_index] = tmp;

		// And move forward in the heap for next check
		parent_index = child_index;
		child_index = parent_index * 2;
	}

	// Delete the min_value_index from heapArray
	return min_value;
}

void Heap::Print()
{
	for (int i = 1; i <= Length(); i++)
	{
		std::cout << heapArray[i] << " ";
	}
	std::cout << std::endl;
}

