#pragma once
#include "BinarySearchTree.h"

class RBSearchTree : public BinarySearchTree
{
public:
	RBSearchTree();
	~RBSearchTree();
	bool insert(Node *z);
	void repairInsert(Node *z);
	void rotateLeft(Node *x);
	void rotateRight(Node *x);
	bool check(Node *start, unsigned int step=0);
	unsigned int bheight();
	bool checkBheight(Node* node);
	void bheight(int& schwarzehoehe, Node* node, bool& schwarz);
};

