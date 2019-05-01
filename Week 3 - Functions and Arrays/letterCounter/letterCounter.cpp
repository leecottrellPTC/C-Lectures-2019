// letterCounter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//this program will show how to use an array as a counter
//the beginnings of try-catch will be handled
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
int letters[26];
int l;
char let;

void parseFile(string path);
void countLetters(string line);
void showCounts();

int main()
{
	for (l = 0; l < 26; l++) {
		letters[l] = 0;
	}
	string fileName = "frost.txt";
	cout << "Enter the file name ";
	cin >> fileName;
	parseFile(fileName);
	cout << "Letter counts in " << fileName << endl;
	showCounts();
}
void parseFile(string path) {
	ifstream fin;
	string line="";
	fin.open(path);
	if (fin.fail())
	{
		cout << path << " did not open" << endl;
		exit(1);
	}
	while (getline(fin, line)) {
		countLetters(line);
	}
	fin.close();
}

void countLetters(string line) {
	//capital A = 65. Subtracting 65 from the letter will get to 
	for (l = 0; l < line.length(); l++) {
		
		let = toupper(line.at(l));	//convert to uppercase
	//	cout << let;
		
			if (let >=65 && let <=90) {	//verify the item is a letter
				letters[let - 65] ++;
			}
		}
		
		
	}//end of countLetters
void showCounts() {
	for (let = 'A'; let <= 'Z'; let++) {
		cout << let << setw(10) << letters[let - 65] << endl;
	}
}