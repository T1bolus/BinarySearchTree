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

Node * BinarySearchTree::seek(string &value)
{
	queue<Node *> st;
	if (root == NULL) return NULL;

	if (root->left != NULL)
		st.push(root->left);
	if (root->right != NULL)
		st.push(root->right);

	while (!st.empty())
	{
		Node *i = st.front();
		st.pop();

		if (i->left != NULL)
			st.push(i->left);
		if (i->right != NULL)
			st.push(i->right);

		if (i->getValue() == value)
			return i;
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
	return destroy(res);
}

bool BinarySearchTree::destroy(Node *res)
{
	if (res == NULL)
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
		else root = NULL;
	}
	else if (res->left == NULL) //Wenn links kein Child
	{
		if (isNotRoot)
		{
			//Einzigen Rechten Parent ersetzen des rechten Parents
			res->right->parent = res->parent;

			//Parent neues Child beibringen
			if (res->parent->right == res)
				res->parent->right = res->right;
			else
				res->parent->left = res->right;
		}
		else
			root = res->right;

	}
	else if (res->right == NULL) //Wenn rechts kein Child
	{
		if (isNotRoot)
		{
			//Einzigen Rechten Parent ersetzen des rechten Parents
			res->left->parent = res->parent;

			//Parent neues Child beibringen
			if (res->parent->right == res)
				res->parent->right = res->left;
			else
				res->parent->left = res->left;
		}
		else
			root = res->left;

	}
	else
	{
		if (isNotRoot)
		{
			//Parent beibringen das der linke Knoten sein neues Child ist
			if (res->parent->right == res)
				res->parent->right = res->left;
			else
				res->parent->left = res->left;
		}
		else
			root = res->left;

		//Größten Knoten des neuen Child suchen
		Node *buf = res->left;
		while (buf->right != NULL)
			buf = buf->right;

		//An diesen dann den alten Rechten Zweig anhängen
		buf->right = res->right;


	}

	delete res;
	return true;
}

bool BinarySearchTree::destroy(string value)
{
	bool ergebnis = false;
	Node *res = seek(value);
	while (res != NULL)
	{
		ergebnis = true;
		destroy(res);
		res = seek(value);
	}
	return ergebnis;
}

bool BinarySearchTree::check(Node *node)
{
	if (node->left == NULL && node->right == NULL)
		return true;
	else if (node->left == NULL)
	{
		if (node->getKey() < node->right->getKey())
			check(node->right);
		else
			throw string("fail");
	}
	else if (node->right == NULL)
	{
		if (node->left->getKey() < node->getKey())
			check(node->left);
		else
			throw string("fail");
	}
	else
	{
		if (node->left->getKey() < node->getKey() && node->getKey() < node->right->getKey())
		{
			check(node->left);
			check(node->right);
		}
		else
			throw string("fail");
	}

	return true;
}

void BinarySearchTree::displayTree()
{
	queue<Node *> st;
	if (root == NULL) return;
	cout << root->getKey() << endl;
	
	if(root->left != NULL)
	st.push(root->left);
	if (root->right != NULL)
	st.push(root->right);

	while (!st.empty())
	{
		Node *i = st.front();
		st.pop();

		if (i->left != NULL)
			st.push(i->left);
		if (i->right != NULL)
			st.push(i->right);

		cout << i->getKey() << endl;
	}
	cout << "_________________\n";


}

