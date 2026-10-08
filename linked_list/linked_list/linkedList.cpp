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
	// Create new node
	Node* pNewNode = new Node(value);

	// List is emty
	if (IsEmpty()) {
		this->pHead = pNewNode;
	}
	// List is not empty
	else {
		// Set new node's pNext to equal pHead
		pNewNode->pNext = pHead;
		// Set pHead to point to the new node
		pHead = pNewNode;
	}
}

void LinkedList::InsertEnd(int value)
{
	// Create new node
	Node* pNewNode = new Node(value);

	// // List is emty
	if (IsEmpty()) {
		this->pHead = pNewNode;
		return;
	}

	// mennään taas koko listan läpi kunnes temp on vika
	Node* temp = this->pHead;
	while (temp->pNext != nullptr) {
		temp = temp->pNext;
	}
	// ja sit edellinen vika osoittamaan uuteen nodeen
	temp->pNext = pNewNode;
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
	// Samalla tavalla kun printissä käydään kaikki läpi
	// ja etsityn arvon kohalla return true
	Node* temp = this->pHead;
	while (temp != nullptr) {
		if (temp->data == value) {
			return true;
		}		
		temp = temp->pNext;
	}
	return false;
}

bool LinkedList::Delete(int value)
{
	// Sama kun find, mut pitää poistaa löydetty 
	// sekä korjata edellinen osoittamaan poitetusta seuraavaan nodeen
	Node* temp = this->pHead;
	Node* pPrevious = nullptr;

	while (temp != nullptr) {
		if (temp->data == value) {
			if (pPrevious == nullptr) {
				// jos poistetava on eka, niin head osoitus pitää korjata
				this->pHead = temp->pNext;
			}
			else {
				// korjaa edellisen osoittamaan poistettavasta seuraavaan
				pPrevious->pNext = temp->pNext;
			}
			delete temp;
			return true;
		}
		pPrevious = temp;
		temp = temp->pNext;
	}
	return false;
}
