#include <iostream>
using namespace std;

int NSD(int a, int b) {
	if (a <= 0) throw "A less zero\n";
	if (b <= 0) throw "B less zero\n";
	while (a != b)
		if (a > b)
			a -= b;
		else
			b -= a;

	return a;
}

void test() noexcept // noexcept не викидає виняткової ситуації 
					 // noexcept(false) викидає виняткової ситуації 
{
	try {
		cout << "try 1\n";
		int a = 10, b = 0;
		try {
			cout << "try 2\n";
			if (b == 0) throw "b = 0";
			cout << "end try 2\n";
		}
		catch (const char* str) {
			b = 1;
			cout << "try 2" << str << endl; throw;
		}
		cout << "end try 1\n";
	}
	catch (const char* str) { cout << "Try 1 " << str << endl; }
}

void test2() {

	try {
		cout << "try 1\n";
		int a = 10, b = 0;

		//if (b == 0) throw exception("Div by zero");
		if (b == 0) throw new out_of_range("Hello");

	}
	catch (exception* ex) { cout << "Try 1 " << ex->what() << endl; }
}

int main()
{
	//try {
	//	cout << NSD(-1, 12) << endl;
	//	cout << "Begin\n";
	//	int a = 10, b = 0;
	//	if (b == 0) throw 9.99;
	//	a = a / b;
	//	cout << "EndTry\n";
	//}
	///*catch (int n) {
	//	cout << "Error Number = " << n << endl;
	//}
	//catch (const char* str) {
	//	cout << "Error " << str << endl;
	//}*/
	//catch (...) { cout << "catch(...) Error\n"; }   // Пишеться в остання чургу


	//cout << "The end\n";

	/*cout << "function test\n";
	test();*/
	cout << "function test2\n";
	test2();
}