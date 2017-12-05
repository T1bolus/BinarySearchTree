#include "BinarySearchTree.h"
#include "RBSearchTree.h"

int main()
{
	srand(time(0));

	const int min = 0;
	const int max = 1000000-1;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(min, max);


	vector<unsigned int> traversierung;
	for (size_t i = 0; i < max+2; i++)
	{
		traversierung.push_back(i);
	}
	for (size_t i = 0; i < max*5; i++)
	{
		swap(traversierung[distribution(generator)], traversierung[distribution(generator)]);
	}

	RBSearchTree baum;
	cout << "Insert..\n";
	int end, start = clock();
	for (size_t i = 1; i < max; i++)
	{
		baum.insert(new Node(string("Node_") + to_string(traversierung[i] / 10), traversierung[i]));

	}
	end = clock();
	cout << "Time: " << ((end - start) * 1000) / CLOCKS_PER_SEC << endl;


	//Node *buf = new Node("root", 10);
	//baum.insert(buf);
	//buf = new Node("g", 5);
	//baum.insert(buf);
	//buf = new Node("a", 15);
	//baum.insert(buf);
	//buf = new Node("a", 3);
	//baum.insert(buf);
	//buf = new Node("a", 8);
	//baum.insert(buf);
	//buf = new Node("v", 12);
	//baum.insert(buf);
	//buf = new Node("v", 20);
	//baum.insert(buf);
	//buf = new Node("b", 1);
	//baum.insert(buf);
	//buf = new Node("n", 6);
	//baum.insert(buf);
	//buf = new Node("n", 13);
	//baum.insert(buf);


	cout << "Da height:" << baum.bheight() << endl;
	try {
		cout << boolalpha << baum.check(baum.root) << endl;
	}
	catch (...)
	{
		cerr << "Fehler!\n";
	}

	//Node *bla = baum.seek(3);
	//if (bla != NULL)
	//	cout << bla->value << endl;
	//else
	//	cout << "Cant find dis Node!" << endl;

	//baum.displayTree();
	cout << "Tree height: " << baum.getHeight() << endl;
	cout << "Tree AvgLevel: " << baum.getAvgLevel() << endl;
	//baum.seeknDestroy("a");
	//baum.displayTree();
	//cout << "Tree height: " << baum.getHeight() << endl;
	//cout << "Tree AvgLevel: " << baum.getAvgLevel() << endl;




	//bla = baum.seek(3);
	//if (bla != NULL)
	//	cout << bla->value << endl;
	//else
	//	cout << "Cant find dis Node!"<<endl;


	//try {
	//	cout << baum.check(baum.root) << endl;
	//}
	//catch (...)
	//{
	//	cerr << "Fehler!\n";
	//}

	cin.get();
}