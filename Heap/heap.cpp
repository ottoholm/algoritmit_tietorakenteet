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
		int tmp = heapArray[parent_index];

		heapArray[parent_index] = heapArray[index];
		heapArray[index] = tmp;

		index = parent_index;
		parent_index = index / 2;
	}
}

void Heap::Print()
{
	for (int i = 1; i <= Length(); i++)
	{
		std::cout << heapArray[i] << " ";
	}
	std::cout << std::endl;
}