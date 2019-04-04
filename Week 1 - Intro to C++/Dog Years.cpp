// Week1Day1Lecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This file will demonstrate how to create a simple input and output program
//it will generate the user's dog age
//start with simple math, then migrate to input
//

#include <iostream>
#include <iomanip>//need for endl
using namespace std;

int main()
{
	int age = 49;
	int dogAge = age * 7;
	string yourName;
	//input
	cout << "Enter your name ";
	cin >> yourName;
	
	//grr the newline problem with strings
	cin.ignore(1000, '\n');//strips the newline from the input
	cin.clear();	//resets the error flag on cin

	cout << yourName << " enter your age in human years ";
	cin >> age;

	//processing
	dogAge = age * 7;

	//output
	
	/*//original output lines
	cout << "You are " << age << " years old" << endl;
	cout << "You are " << dogAge << " in dog years\n";*/

	cout << yourName <<  " you are " << age << " years old" << endl;
	cout << yourName << " you are " << dogAge << " in dog years\n";


	
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
