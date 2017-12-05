#include "RBSearchTree.h"



RBSearchTree::RBSearchTree()
{

}


RBSearchTree::~RBSearchTree()
{

}

bool RBSearchTree::insert(Node *node)
{
	Node* y = NULL;
	Node* x = root;
	while (x != NULL) 
	{
		y = x;
		if (node->getKey() < x->getKey()) 
			x = x->left;
		else 
			x = x->right;
		
	}
	node->parent = y;
	if (y == NULL) 
		root = node;

	else 
	{
		if (node->getKey() < y->getKey())
			y->left = node;
		else 
			y->right = node;
	}
	node->left = NULL;
	node->right = NULL;
	node->red = true;
	this->repairInsert(node);

	return true;
}

void RBSearchTree::repairInsert(Node* node)
{

	if (node->parent)
	{
		while (node->parent->red) 
		{
			if (node->parent->parent) 
				if (node->parent == node->parent->parent->left)
				{
					//Fall 1
					Node* y = node->parent->parent->right;

					if (y && y->red)
					{
						node->parent->red = false;
						y->red = false;
						node->parent->parent->red = true;
						node = node->parent->parent;
					}
					//Fall 2
					else 
					{
						if (node == node->parent->right) 
						{
							node = node->parent;
							this->rotateLeft(node);
						}
						//Fall 3
						node->parent->red = false;
						node->parent->parent->red = true;
						this->rotateRight(node->parent->parent);
					}
				}
				else 
				{
					//Fall 4
					Node* y = node->parent->parent->left;

					if (y && y->red)
					{
						node->parent->red = false;
						y->red = false;
						node->parent->parent->red = true;
						node = node->parent->parent;
					}
					//Fall 5
					else 
					{
						if (node == node->parent->left) 
						{
							node = node->parent;
							this->rotateRight(node);
						}
						//Fall 6
						node->parent->red = false;
						node->parent->parent->red = true;
						this->rotateLeft(node->parent->parent);
					}
				}
			//ob parent des parent vorhanden
			if (!node->parent || !node->parent->parent)
				break;
		}
	}
	root->red = false;
}

void RBSearchTree::rotateLeft(Node * node)
{
	Node* y = node->right;
	node->right = y->left;

	if (y->left)
		y->left->parent = node;

	if (node == root) 
		root = y;
	else
	{
		if (node == node->parent->left) 
			node->parent->left = y;
		else 
			node->parent->right = y;
	
		y->parent = node->parent;
	}
	y->left = node;
	node->parent = y;
}

void RBSearchTree::rotateRight(Node * node)
{
	Node* y = node->left;
	node->left = y->right;

	if (y->right) 
		y->right->parent = node;

	if (node == root) 
		root = y;
	else
	{
		if (node == node->parent->right) 
			node->parent->right = y;
		else 
			node->parent->left = y;
		
		y->parent = node->parent;
	}
	y->right = node;
	node->parent = y;
}

bool RBSearchTree::check(Node * start, unsigned int step)
{
	////Prüfen ob BinarySearchTree Eigenschaften sind erfüllt
	if (start->left != NULL)
		checkChildsLeft(start->left, start->getKey());
	if (start->right != NULL)
		checkChildsRight(start->right, start->getKey());

	//RB Tests
	//Fall1:
	//Wurzel schwarz
	if (step == 0 && start->red != false)
	{
		throw string("fail");
	}
	//Fall2:
	//Bei rotem Knoten, schwarze Kinder
	if (start->red == true)
	{
		if (start->left && start->right)
		{
			if (start->left->red != false || start->right->red != false)
				throw string("fail");
		}
	}
	//Fall3:
	//Bei nur einem nachfolger, ist dieses Blatt rot.
	if (!(start->left && start->right))
	{
		if (start->left && !start->left->red)
			throw string("fail");
		if (start->right && !start->right->red)
			throw string("fail");
	}
	//Fall4:
	//Prüfe ob alle Stränge gleich lang sind
	if (!checkBheight(start)) throw string("fail");




	if (start->left != NULL)
		check(start->left, ++step);
	if (start->right != NULL)
		check(start->right, ++step);

	return true;
}



unsigned int RBSearchTree::bheight()
{
	Node *x = root;
	unsigned int steps = 0;
	while (x != NULL)
	{
		if(x->red == false) steps++;
		x = x->right;
	}
	return steps;
}


bool RBSearchTree::checkBheight(Node* node) {
	int height = 0;
	bool result = true;
	bheight(height, node, result);
	return result;
}

void RBSearchTree::bheight(int &height, Node *node, bool &result) {
	int lleft = height;
	int rright = height;

	if (node->left) 
		bheight(lleft, node->left, result);

	if (node->right)
		bheight(rright, node->right, result);
	

	if (lleft != rright)
		result = false;

	height = lleft;
	if (!node->red) height++;
}