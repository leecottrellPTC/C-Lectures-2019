// batAvgLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert> //need for assert
using namespace std;
int main()
{
	int atBats, hits, walks;
	int bottom;//bottom of fraction
	double batAvg;
	ifstream fin;
	//input from a file
	fin.open("stats.txt");
	//check if file opened
	assert(!fin.fail());
	//die if the fin fails
	//input

	do {
		fin >> atBats >> hits >> walks;
		cout << atBats << " " << hits << " " << walks << endl;
		//echo the input

		//processing
		bottom = atBats - walks;
		if (bottom > 0) {
			batAvg = hits / (double)(bottom);
			cout << "Bat avg " << fixed << setprecision(3) << batAvg << endl;
		}
		else {
			cout << "No Bat Avg" << endl;
		}



		//cast to double
//cout << "File opened" << endl;
//output
		
	} while (!fin.eof());
	//loop until end of file
	fin.close();

	cout << "Program closing" << endl;
    
}

