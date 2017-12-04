#include "BinarySearchTree.h"



BinarySearchTree::BinarySearchTree()
{
	root = NULL;
	height = 0;
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



void BinarySearchTree::seeknDestroy(string value)
{
	queue<Node *> st;
	if (root == NULL) return;

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
			destroy(i);
	}
}

bool BinarySearchTree::check(Node * start)
{
	if (start->left != NULL)
		checkChildsLeft(start->left, start->getKey());
	if (start->right != NULL)
		checkChildsRight(start->right, start->getKey());

	if (start->left != NULL)
		check(start->left);
	if (start->right != NULL)
		check(start->right);

	return true;
}

void BinarySearchTree::checkChildsRight(Node *node, const int vergleiche)
{

	if (!(vergleiche < node->getKey()))
		throw string("Fail");
	
	if (node->left != NULL)
		checkChildsRight(node->left, vergleiche);
	if (node->right != NULL)
		checkChildsRight(node->right, vergleiche);
}

void BinarySearchTree::checkChildsLeft(Node *node, const int vergleiche)
{

	if (!(node->getKey() < vergleiche))
		throw string("Fail");

	if (node->left != NULL)
		checkChildsLeft(node->left, vergleiche);
	if (node->right != NULL)
		checkChildsLeft(node->right, vergleiche);
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

void BinarySearchTree::calcHigh(Node *node, unsigned int step = -1)
{
	step++;
	stufeSumme += step;
	anzahl++;

	if (step > height)
		height = step;

	if (node->left != NULL)
		calcHigh(node->left,step);
	if (node->right != NULL)
		calcHigh(node->right,step);
}


unsigned int BinarySearchTree::getHeight()
{
	calcHigh(root);
	return height + 1;
}

double BinarySearchTree::getAvgLevel()
{
	anzahl = 0;
	stufeSumme = 0;
	calcHigh(root);

	return (double)stufeSumme / (double)anzahl;
}

