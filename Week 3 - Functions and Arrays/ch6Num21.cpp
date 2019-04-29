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

int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//using a dummy value for the first position
//simplifies the math, no need to -1 on month number

//prototypes
string inputDate();
void convertDate(string dateString, int& month, int& day, int& year);
int checkDate(int month, int day, int year);
int numDays(int month, int day);

int main()
{
	
	int month = 0, day = 0, year = 0;
	int check = 0;
	string dateString;
	dateString = inputDate();
	cout << dateString << endl;

	convertDate(dateString, month, day, year);
	cout << month << endl;
	cout << day << endl;
	cout << year << endl;

	check = checkDate(month, day, year);

	if (check != 0) {
		cout << "Day " << numDays(month, day) << " in the year" << endl;
	}
	else {
		cout << dateString << " is a bad date, no calculation " << endl;
	}

	
}

string inputDate() {
	string dateString;
	regex date ("^\\d{1,2}-\\d{1,2}-\\d{4}$");
	//stole from regexlib.com
	//modified using \\ instead of \
	
	do {
		cout << "Enter MM-DD-YYYY ";
		getline(cin, dateString);
		//    ^\d{1,2}\/\d{1,2}\/\d{4}$

	} while (!regex_match(dateString, date));
	

	return dateString;
}

void convertDate(string dateLine, int& month, int& day, int& year) {
	int firstDash = dateLine.find_first_of('-');
	int secondDash = dateLine.find('-', firstDash+1);
	//cout << "first dash = " << firstDash << endl;
	//cout << "second dash = " << secondDash << endl;
	//string dateMonth = dateLine.substr(0, dateLine.find_first_of('-'));
	//cout << dateMonth << endl;

	month = atoi(dateLine.substr(0, firstDash).c_str());
											//concert to Char *
											//define old school String  as char *

	day = atoi(dateLine.substr(firstDash + 1, secondDash).c_str());
	year = atoi(dateLine.substr(secondDash + 1).c_str());
	
}


int checkDate(int month, int day, int year) {
	//return -0 if a bad date
	if (month < 1 || month > 12) {
		cout << "Months must be between 1 and 12" << endl;
		return 0;
	}
	//leap year
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 > 0))) {
		//discuss shortcut if logic here
		cout << year << " is a Leap year" << endl;
		daysInMonth[2] = 29;
	}
	else {
		daysInMonth[2] = 28;
	}

	//check days
	if (day < 1 || day > daysInMonth[month]) {
		cout << "Day must be above 0 and less than " << daysInMonth[month] << endl;
		return 0;
	}
}

int numDays(int month, int day) {
	int dayOfYear = 0;
	// add up the 
	for (int m = 1; m < month; m++) {
		dayOfYear += daysInMonth[m];
	}
	dayOfYear += day;
	return dayOfYear;
}