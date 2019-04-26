// ch6Num21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//this program will input a date, verify that the date is correct and output
//the number of day in the year
//i am intentionally using reference parameters just to show how they work
//i will use an array to determine the number of days in a month
//

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <cstdlib>

using namespace std;

int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//using a dummy value for the first position
//simplifies the math, no need to -1 on month number

//prototypes
string inputDate();
void convertDate(string dateString, int& month, int& day, int& year);
int main()
{
	int month = 0, day = 0, year = 0;
	string dateString;
	dateString = inputDate();
	cout << dateString << endl;

	convertDate(dateString, month, day, year);
}

string inputDate() {
	string dateString;
	regex date ("^\\d{1,2}-\\d{1,2}-\\d{4}$");
	//stole from regexlib.com
	//modified using \\ instead of \
	
	do {
		cout << "Enter MM-DD-YYYY ";
		getline(cin, dateString);
		//^\d{1,2}\/\d{1,2}\/\d{4}$

	} while (!regex_match(dateString, date));
	

	return dateString;
}

void convertDate(string dateLine, int& month, int& day, int& year) {
	
	
	
	

}
