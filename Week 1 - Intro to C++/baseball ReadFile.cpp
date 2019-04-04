// Week1 C++ ReadFile Lecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream> //need for ifstream 
#include <string>	//may not need

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	int number, atBats, hits, walks;
	double batAvg;

	cout << "Baseball stats from a file" << endl;
	fin.open("baseball.txt");	//create in same folder
								//file | new file 
								//OR 
								//rt click source files in solution explorer | utility text 
	fin >> number >> atBats >> hits >> walks;
	cout << "Read in " << number << " " << atBats << " " << hits << " " << walks << endl;
	//batAvg = (hits) / (atBats - walks);
	//do wrong first
	batAvg = (hits) / static_cast<float> (atBats - walks);
	cout << "Batting Average " << setprecision(3) << fixed << batAvg << endl;
	fin.close();


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
