/*this is a lecture for week2 - control structures
it will demonstrate the ROT encryption algorithm and strings*/

//be sure to look at asciitable.com for clarification on the +5

#include <iostream>
#include <iomanip>
#include <string>	//need to enhancements on string
#include <fstream>

using namespace std;

int main() {
	string line;
	string encrypted;
	ifstream fin;
	ofstream fout;
	int rotation = 5;		//the rotation key
	int c;					//faster to declare c here
	fin.open("frost.txt");
	fout.open("frost.enc");

	if (fin.fail()) {
		cout << "Could not open the file. Quiting the program. Have a nice day!" << endl;
		return 1;//error code
	}

	//read the file in a slick way
	//if the file is empty, the while loop never starts
	//getline allows the inputting of spaces. It stops at a newline
	//getline(iostream, string, [delimiter='\n']);

	while (getline(fin, line)) {
		//cout << line << endl;
		//walk through each char in the line and add 5
		encrypted = "";
		for (c = 0; c < line.length(); c++) {
			encrypted += line.at(c) + rotation;
			//at returns the char at the given integer position
		}
		fout << encrypted << endl;		//replace endl with !
		cout << encrypted << endl;		//write out to screen just for proof
	}
	//cout << "File opened!" << endl;

	fout.close();	//close in opposite order of opening is proper
	fin.close();

	return 0;	//no errors
}