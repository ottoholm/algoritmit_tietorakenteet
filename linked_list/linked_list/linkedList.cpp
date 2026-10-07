#include "linkedList.h"
#include "iostream"

bool LinkedList::IsEmpty()
{
	/*
	if (this->pHead == nullptr) {
		return true;
	}
	*/

	// Nopeampi tapa kuin if lause
	return this->pHead == nullptr;
}

void LinkedList::Insert(int value)
{
	// List is emty
	if (IsEmpty()) {
		// Create new node
		Node* pNewNode = new Node(value);
		//
		this->pHead = pNewNode;
	}
	// List is not empty
	else {
		// Create new node
		Node* pNewNode = new Node(value);
		// Set new node's pNext to equal pHead
		pNewNode->pNext = pHead;
		// Set pHead to point to the new node
		pHead = pNewNode;
	}
}

void LinkedList::Print()
{
	Node* temp = this->pHead;
	while (temp != nullptr) {
		std::cout << "List value: " << temp->data << std::endl;
		temp = temp->pNext;
	}
	
}

bool LinkedList::Find(int value)
{
	return false;
}

bool LinkedList::Delete(int value)
{
	return false;
}
