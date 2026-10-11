#pragma once
#include "node.h"

// Template class!
template <typename T> class Stack{
public:

	Stack() { pTop = nullptr; }
	bool IsEmpty() { return pTop == nullptr;}

	void Push(T data) {
		Node<T>* pNewNode = new Node<T>(data); // Create new node
		pNewNode->pNext = pTop;			 // New node's next points to the old top Node
		pTop = pNewNode;				 // Make top point to the new node
	};

	// Calling Pop() for an empty stack is NOT recommanded!
	T Pop() {
		if (IsEmpty()) {
			return T();
		}

		// Stack is not empty -> POP!
		Node<T>* pToBeDeleted = pTop;		// Store current top in a local pointer
		T value = pToBeDeleted->data;		// Store the data 	
		pTop = pToBeDeleted->pNext;			// Update Top-pointer	
		delete pToBeDeleted;				// Remove the node to be deleted	
		return value;						// Return the saved value/data
	};

	T Top() {
		if (IsEmpty()) {
			return T();
		}
		return pTop->data;
	};

private:
	Node<T>* pTop;
};