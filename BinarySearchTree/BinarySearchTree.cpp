#include "BinarySearchTree.h"



BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}


BinarySearchTree::~BinarySearchTree()
{
}

Node * BinarySearchTree::seek(int k)
{
	Node *v = root;
	while (v != NULL)
	{
		if (k < v->getKey())
		{
			v = v->left;
		}
		else if (k == v->getKey())
		{
			return v;
		}
		else
		{
			v = v->right;
		}
	}

	return NULL;
}

bool BinarySearchTree::insert(Node *u)
{
	if (root == NULL) { root = u; return true; }

	Node *v = root;
	 
	u->left = NULL; u->right = NULL;
	while (v != NULL)
	{
		if (u->getKey() < v->getKey())
		{
			if (v->left == NULL)
			{
				v->left = u;
				u->parent = v;
				return true;
			}
			else
				v = v->left;
		}
		else if (u->getKey() > v->getKey())
		{
			if (v->right == NULL)
			{
				v->right = u;
				u->parent = v;
				return true;
			}
			else
				v = v->right;
		}
		else return false;
			
	}
	root = u;
}

bool BinarySearchTree::destroy(int kValue)
{
	Node *res = seek(kValue);
	if(res == NULL)
		return false;
	bool isNotRoot = res->parent;


	//Wenn Child keine Nachfolger hat
	if (res->left == NULL && res->right == NULL)
	{
		if (isNotRoot)
		{
			if (res->parent->right == res)
				res->parent->right = NULL;
			else
				res->parent->left = NULL;
		}
	}
	else if (res->left == NULL) //Wenn links kein Child
	{
		//Einzigen Rechten Parent ersetzen des rechten Parents
		res->right->parent = res->parent;

		if(isNotRoot)
		{
			//Parent neues Child beibringen
			if (res->parent->right == res)
				res->parent->right = res->right;
			else
				res->parent->left = res->right;
		}
		
	}
	else if (res->right == NULL) //Wenn rechts kein Child
	{
		//Einzigen Rechten Parent ersetzen des rechten Parents
		res->left->parent = res->parent;

		if (isNotRoot)
		{
			//Parent neues Child beibringen
			if (res->parent->right == res)
				res->parent->right = res->left;
			else
				res->parent->left = res->left;
		}
	}
	else
	{
		//parent_replacement = res;
		//replacement = res->left;
		//is_left = 1; /* Replacement is left child of parent */
		//while (replacement->right != NULL)
		//{
		//	parent_replacement = replacement;
		//	replacement = replacement->right;
		//	is_left = 0; // Replacement is right child of parent
		//}


		///* Copy data */
		//ptr->data = replacement->data;
		///* Two broad cases
		//* i) Replacement is left child of ptr
		//*   (and could be having 0 or 1 children)
		//* ii) Replacement is right (grand)child of ptr->left
		//*/

		//if (is_left)
		//{
		//	// case i : replacement is left child of ptr.
		//	assert(replacement->right == NULL);
		//	ptr->left = replacement->left;
		//	free(replacement);
		//}
		//else
		//{
		//	// case ii : replacement is right grand(child of ptr->left
		//	parent_replacement->right = replacement->left;
		//	free(replacement);
		//}
	}

	delete res;
	return true;

}

