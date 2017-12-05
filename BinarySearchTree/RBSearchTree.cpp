#include "RBSearchTree.h"



RBSearchTree::RBSearchTree()
{

}


RBSearchTree::~RBSearchTree()
{

}

bool RBSearchTree::insert(Node *z)
{
	Node *y = NULL, *x = root;
	while (x != NULL)
	{
		y = x;
		if (z->getKey() < x->getKey())
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;

	if (y == NULL)
		root = z;
	else
	{
		if (z->getKey() < y->getKey())
			y->left = z;
		else
			y->right = z;
	}

	z->left = NULL;
	z->right = NULL;
	z->red = true;
	repairInsert(z);

	return true;
}

void RBSearchTree::repairInsert(Node * z)
{
	bool uncle;

	if (z->parent != NULL)
	{
		while (z->parent->red)
		{
			if (z->parent->parent)
			{
				if (z->parent == z->parent->parent->right)
				{
					Node *y = z->parent->parent->right;
					
					if (y) 
						uncle = y->right;
					else 
						uncle = false;

					if (uncle)
					{
						z->parent->red = false;
						y->red = false;
						z->parent->parent->red = true;
						z = z->parent->parent;
					}
					//Fall2
					else
					{
						if (z == z->parent->right)
						{
							z = z->parent;
							rotateLeft(z);
						}
						//Fall3
						z->parent->red = false;
						z->parent->parent->red = true;
						rotateRight(z->parent->parent);
					}
				}
				else
				{
					//Fall4:
					Node *y = z->parent->parent->left;
					//z->parent->parent->left;

					if (y)
						uncle = y->right;
					else
						uncle = false;

					if (uncle)
					{
						z->parent->red = false;
						y->red = false;
						z->parent->parent->red = true;
						z = z->parent->parent;
					}
					else
					{
						//Fall5:
						if (z == z->parent->left)
						{
							z = z->parent;
							rotateRight(z);
						}
						//fall6:
						z->parent->red = false;
						z->parent->parent->red = true;
						rotateLeft(z->parent->parent);
					}
				}
			}
			if (z->parent != NULL)
			{
				if (!z->parent->parent) break;
			}
			else
				break;

		}
	}
	root->red = false;
}

void RBSearchTree::rotateLeft(Node * x)
{
	Node *y = x->right;
	if (!y) return;
	x->right = y->left;

	if (y && y->left)
		y->left->parent = x;
	if (x == root)
		root = y;
	else
	{
		if (root->parent && x == root->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->parent = x->parent;
	}
	y->left = x;
	x->parent = y;
}

void RBSearchTree::rotateRight(Node * x)
{
	Node *y = x->left;
	if (!y) return;
	x->left = y->right;

	if (y && y->right)
		y->right->parent = x;
	if (x == root)
		root = y;
	else
	{
		if (root->parent && x == root->parent->left)
			x->parent->right = y;
		else
			x->parent->left = y;
		
		y->parent = x->parent;
	}
	y->right = x;
	x->parent = y;
}

bool RBSearchTree::check(Node * start, unsigned int step)
{
	//Prüfen ob BinarySearchTree Eigenschaften sind erfüllt
	if (start->left != NULL)
		checkChildsLeft(start->left, start->getKey());
	if (start->right != NULL)
		checkChildsRight(start->right, start->getKey());

	//RB Tests
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
	if (!checkBheight(start)) return false;



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
	bool ergebnis = true;
	bheight(height, node, ergebnis);
	return ergebnis;
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