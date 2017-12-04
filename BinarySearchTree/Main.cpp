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
	buf = new Node("g", 5);
	baum.insert(buf);
	buf = new Node("a", 15);
	baum.insert(buf);
	buf = new Node("a", 3);
	baum.insert(buf);
	buf = new Node("a", 8);
	baum.insert(buf);
	buf = new Node("v", 12);
	baum.insert(buf);
	buf = new Node("v", 20);
	baum.insert(buf);
	buf = new Node("b", 1);
	baum.insert(buf);
	buf = new Node("n", 6);
	baum.insert(buf);
	buf = new Node("n", 13);
	baum.insert(buf);



	try {
		cout << boolalpha << baum.check(baum.root) << endl;
	}
	catch (...)
	{
		cerr << "Fehler!\n";
	}

	Node *bla = baum.seek(3);
	if (bla != NULL)
		cout << bla->value << endl;
	else
		cout << "Cant find dis Node!" << endl;

	baum.displayTree();
	cout << "Tree height: " << baum.getHeight() << endl;
	cout << "Tree AvgLevel: " << baum.getAvgLevel() << endl;
	baum.seeknDestroy("a");
	baum.displayTree();
	cout << "Tree height: " << baum.getHeight() << endl;
	cout << "Tree AvgLevel: " << baum.getAvgLevel() << endl;




	bla = baum.seek(3);
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

	cin.get();
}