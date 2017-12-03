#pragma once

#define usign unsigned int


class Node
{
public:

	Node(string value,/* usign valueLength,*/ int key) : key(key) , value(value)/*, valueLength(valueLength)*/
	{
		right = NULL;
		left = NULL;
		parent = NULL;
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
	}

	int getKey() { return key; }
	string getValue() { return value; }


	Node* right;
	Node* left;
	Node* parent;

private:
	int key;
	//char *value;
	string value;
	/*usign valueLength;*/
};

