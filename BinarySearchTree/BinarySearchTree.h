#pragma once
#include "Include.h"
#include "Node.h"

class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	Node *seek(int kValue);
	bool insert(Node*);
	bool destroy(int kValue);
	bool check(Node *start);
//private:

	Node* root;
};

