// p118Num12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//added just for testing Git

#include "pch.h"
#include <iostream>
#include <iomanip>	//need for setfill and setw

using namespace std;
int main()
{
	int seconds = 0;
	int hours = 0;
	int minutes = 0;
	const int secInHour = 60 * 60;
	const int secInMin = 60;
	
	cout << "Time converter!!\n";
	cout << "Enter number of seconds: ";
	cin >> seconds;
	hours = seconds / secInHour;
	seconds = seconds % secInHour;

	minutes = seconds / secInMin;
	seconds = seconds % secInMin;

	cout << setfill('0') << setw(2) << hours << ":";
	cout << setfill('0') << setw(2) << minutes << ":";
	cout << setfill('0') << setw(2) << seconds << endl;

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
