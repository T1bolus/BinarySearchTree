#include "Include.h"
#define usign unsigned int


class Node
{
public:

	Node(string value,/* usign valueLength,*/ int key) : key(key) , value(value)/*, valueLength(valueLength)*/
	{
		right = NULL;
		left = NULL;
		parent = NULL;
		red = false;
	}

	//virtual ~Node()
	//{
	//	if(value!=NULL) delete[]value;
	//}

	Node(const Node &other)
	{
		//value = new char[other.valueLength];
		//memcpy(value, other.value, other.valueLength - 1);
		//valueLength = other.valueLength;
		key = other.key;
		right = NULL;
		left = NULL;
		parent = NULL;
		red = false;
	}

	int getKey() { return key; }
	const string &getValue() { return value; }
	bool isRed() { return red; }
	bool setBlack() { red = false; }
	bool setRed() { red = true; }


	Node* right;
	Node* left;
	Node* parent;
	bool red;


private:
	int key;
	string value;
	
	//char *value;
	/*usign valueLength;*/
};

