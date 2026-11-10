#include "heap.h"
#include <iostream>
#include <vector>
#include <random>       
#include <chrono>       

void measureHeapSort(int size);

int main() {

	/* Programming task 8.1.  Heap-class implementation
	Heap myHeap;

	myHeap.Insert(17);
	myHeap.Insert(11);
	myHeap.Insert(6);
	myHeap.Insert(14);
	myHeap.Insert(22);
	myHeap.Insert(8);
	myHeap.Insert(1);
	myHeap.Insert(16);
	myHeap.Insert(10);
	myHeap.Insert(19);
	myHeap.Insert(12);
	myHeap.Insert(3);
	myHeap.Insert(5);
	myHeap.Insert(15);
	myHeap.Insert(13);

	myHeap.Print();

	// Sorting of the heap
	std::vector<int> sort_result;
	int size = myHeap.Length();
	for (int i = 0; i < size; i++)
	{
		sort_result.push_back(myHeap.DelMin());
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << sort_result[i] << " " << std::endl;
	} */

	
	// Programming task 8.2. Heap sort speed
	
	measureHeapSort(100000);
	measureHeapSort(1000000);
	measureHeapSort(10000000);

	return EXIT_SUCCESS;
}

// Time measurements heap sort
void measureHeapSort(int size) {

	// Heap myHeap; crashes to stack overflow, because array of 10 000 000 elements is too large
	auto myheap = std::make_unique<Heap>();

	// Random numbers into a vector
	std::mt19937 generator(100);
	std::uniform_int_distribution<int> distribution(0, 1000000000);
	std::vector<int> input(size);
	for (int i = 0; i < size; i++) {
		input[i] = distribution(generator);
	}

	// result vector to store the deleted min values
	std::vector<int> result;
	result.reserve(size);

	// Insert the random numbers into the heap
	for (int i = 0; i < size; i++) {
		myheap->Insert(input[i]);
	}

	// Start calculating time for deletion sort
	auto start_time = std::chrono::steady_clock::now();
	// Sort the heap py delete min
	for (int i = 0; i < size; i++) {
		result.push_back(myheap->DelMin());
	}
	auto end_time = std::chrono::steady_clock::now();


	// Total time that the sorting took in milliseconds
	auto sortTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
	std::cout << "Heap size: " << size << "\n";
	std::cout << "Sort time: " << sortTime << " milliseconds\n";
}