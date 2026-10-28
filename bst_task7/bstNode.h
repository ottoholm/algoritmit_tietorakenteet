#pragma once

class BSTNode
{
public:
	int key;
	BSTNode* pLeft;
	BSTNode* pRight;

	BSTNode()
	{
		key = -1;
		pLeft = nullptr;
		pRight = nullptr;
	}

	//Constructor with key value as a parameter
	BSTNode(int value)
	{
		key = value;
		pLeft = nullptr;
		pRight = nullptr;
	}
};