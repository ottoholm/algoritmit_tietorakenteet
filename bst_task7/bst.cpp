#include "bst.h"
#include <iostream>

//This inserts smaller values left and EQUAL or greater values right

void BST::Insert(int key)
{
	//Create the new node
	BSTNode* pNewNode = new BSTNode(key);

	if (IsEmpty())
	{
		//Set the new node with key values as the root node
		pRoot = pNewNode;
		return;
	}
	else
	{
		//The tree is NOT empty...
		BSTNode* pCurrent = pRoot;
		BSTNode* pCandidate = pRoot;

		while (pCandidate != nullptr)
		{
			pCurrent = pCandidate;

			if (pNewNode->key < pCurrent->key)
			{
				pCandidate = pCurrent->pLeft;
			}
			else
			{
				pCandidate = pCurrent->pRight;
			}
		}

		//Check which direction we need to put the new node
		if (pNewNode->key < pCurrent->key)
		{
			pCurrent->pLeft = pNewNode;
		}
		else
		{
			pCurrent->pRight = pNewNode;
		}
	}
}

void BST::Print()
{
	Print(pRoot, 0);
}

void BST::Print(BSTNode* pNode, int depth)
{
	if (pNode == nullptr)
	{
		return;
	}

	Print(pNode->pRight, depth + 1);

	// Luodaan kiva puurakenne vasemmalta oikealle
	std::cout << std::string(depth * 4, ' ') << pNode->key << std::endl;

	Print(pNode->pLeft, depth + 1);
}

bool BST::Find(int key)
{
	BSTNode* pCurrent = pRoot;

	while (pCurrent != nullptr)
	{
		if (key == pCurrent->key)
		{
			return true;
		}
		else if (key < pCurrent->key)
		{
			pCurrent = pCurrent->pLeft;
		}
		else
		{
			pCurrent = pCurrent->pRight;
		}
	}
	return false;
}

int BST::CountNodes()
{
	return CountNodes(pRoot);
}

int BST::CountNodes(BSTNode* pNode)
{
	if (pNode == nullptr)
	{
		return 0;
	}

	return CountNodes(pNode->pLeft) + CountNodes(pNode->pRight) + 1;
}

int BST::CountLeaves()
{
	return CountLeaves(pRoot);
}

int BST::CountLeaves(BSTNode* pNode)
{
	if (pNode == nullptr)
	{
		return 0;
	}

	if (pNode->pLeft == nullptr && pNode->pRight == nullptr)
	{
		return 1;
	}

	return CountLeaves(pNode->pLeft) + CountLeaves(pNode->pRight);
}