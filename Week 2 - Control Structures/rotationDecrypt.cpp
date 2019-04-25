// rotationDecrypt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string line;
	string encrypted;
	ifstream fin;
	ofstream fout;
	int rotation = 5;
	int c;
	fin.open("frost.enc");
	//fin.open("alpha.txt");
	//fout.open("frost.enc");

	if (fin.fail()) {
		cout << "Could not open the file. Quiting the program. Have a nice day!" << endl;
		return 1;//error code
	}

	//read the file in a slick way
	while (getline(fin, line)) {
		//cout << line << endl;
		//walk through each char in the line and add 5
		encrypted = "";
		for (c = 0; c < line.length(); c++) {
			encrypted += line.at(c) - rotation;
		}
		//fout << encrypted << endl;//replace endl with !
		cout << encrypted << endl;

	}
	//cout << "File opened!" << endl;

	//fout.close();
	fin.close();


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
