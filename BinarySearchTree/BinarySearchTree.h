#pragma once
#include "Include.h"
#include "Node.h"

class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	Node *seek(int kValue);
	Node * seek(string &value);
	bool insert(Node*);
	bool destroy(int kValue);
	bool destroy(string value);
	bool destroy(Node*);
	bool check(Node *start);
	void displayTree();
//private:

	Node* root;
};

