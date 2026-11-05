#pragma once
#define MAX_SIZE 255
class Heap 
{
public:
	Heap()
	{
		heapArray[0] = 0;
	}

	void Insert(int key);

	//int DelMin();

	void Print();

	int Length()
	{
		return heapArray[0];
	}
private:
	int heapArray[MAX_SIZE + 1];
};