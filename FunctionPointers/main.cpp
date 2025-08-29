#include <iostream>
using namespace std;

const char* Hello()
{
	return "Hello";
}

int main()
{
	setlocale(LC_ALL, "");

	cout << Hello << endl;

	const char* (*pHello) = Hello;

	cout << pHello() << endl;

	return 0;
}