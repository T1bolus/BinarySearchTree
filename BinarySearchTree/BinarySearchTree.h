#include "Node.h"

class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	Node *seek(int kValue);
	bool insert(Node*);
	bool destroy(int kValue);
	void seeknDestroy(string value);
	bool destroy(Node*);
	bool check(Node *start);
	void checkChildsRight(Node *start, const int vergleich);
	void checkChildsLeft(Node *start, const int vergleich);
	void displayTree();
	unsigned int getHeight();
	double getAvgLevel();
//private:

	void calcHigh(Node *, unsigned int step);
	unsigned int height;
	unsigned int stufeSumme;
	unsigned int anzahl;
	Node* root;
};

