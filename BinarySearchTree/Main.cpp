#include "BinarySearchTree.h"

int main()
{
	//srand(time(0));
	//vector<unsigned int> traversierung;
	//for (size_t i = 0; i < 1000000; i++)
	//{
	//	traversierung.push_back(i);
	//}
	//for (size_t i = 0; i < 10000000; i++)
	//{
	//	swap(traversierung[rand() % 1000000], traversierung[rand() % 1000000]);
	//}

	BinarySearchTree baum;
	
	//char *bufValue = new char[1000];
	//sprintf(bufValue, "hjdkashdjksajk");

	Node *buf = new Node("root", 10);
	baum.insert(buf);
	buf = new Node("hjdkashdjksajk", 5);
	baum.insert(buf);
	buf = new Node("hjdk435435sajk", 15);
	baum.insert(buf);
	buf = new Node("hjdka3456456jk", 3);
	baum.insert(buf);
	buf = new Node("hjdkash13576jk", 8);
	baum.insert(buf);
	buf = new Node("hjdka4667567jk", 12);
	baum.insert(buf);
	buf = new Node("hjdkas123348jk", 20);
	baum.insert(buf);
	buf = new Node("hjd1323557sajk", 1);
	baum.insert(buf);
	buf = new Node("hjdka8908908jk", 6);
	baum.insert(buf);
	buf = new Node("hjd345h324235k", 13);
	baum.insert(buf);

	//baum.root->left->key = 100;
	
	try {
		cout << baum.check(baum.root) << endl;
	}
	catch (...)
	{
		cerr << "Fehler!\n";
	}

	Node *bla = baum.seek(5);
	cout << bla->value << endl;
	baum.destroy(5);
	bla = baum.seek(5);
	if (bla != NULL)
		cout << bla->value << endl;
	else
		cout << "Cant find dis Node!"<<endl;

	try {
		cout << baum.check(baum.root) << endl;
	}
	catch (...)
	{
		cerr << "Fehler!\n";
	}

}