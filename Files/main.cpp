#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef WRITE_TO_FILE
	std::ofstream fout;

	//fout.open("file.txt"); // Rewrite
	fout.open("file.txt", std::ios_base::app); // Append

	fout << "Hello Files" << endl;

	fout.close();

	system("notepad file.txt");
#endif // WRITE_TO_FILE

	std::ifstream fin("file.txt");

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string buffer;
			std::getline(fin, buffer);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

	fin.close();

	return 0;
}