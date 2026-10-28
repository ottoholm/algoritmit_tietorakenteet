#pragma once
#include "bstnode.h"

class BST
{
public:

	//Constructor, just set the root-node pointer to null
	BST()
	{
		pRoot = nullptr;
	}

	bool IsEmpty()
	{
		return pRoot == nullptr;	//Returns true if pRoot is null
	}

	void Insert(int key);
	void Print();
	bool Find(int key);
	int CountNodes();
	int CountLeaves();
	bool Delete(int key);

private:

	//Pointer to the root-node of the BST
	BSTNode* pRoot;


	// Apu funktioita 
	void Print(BSTNode* pNode, int depth);
	int CountNodes(BSTNode* pNode);
	int CountLeaves(BSTNode* pNode);
};