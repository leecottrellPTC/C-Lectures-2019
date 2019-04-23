// Ch6Lecture-Averages.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Menu driven function example for different types of averages
//https://en.wikipedia.org/wiki/Mean#Harmonic_mean_(HM)
//

#include <iostream>
#include <iomanip>

using namespace std;

//prototype functions here - solves declaration problem
void line();
void input(double list[]);
void showNumbers(double list[]);
double arithmeticMean(double list[]);
double geometricMean(double list[]);
double harmonicMean(double list[]);
int menu();
const int ARRAY = 5;


int main()
{
	//4, 36, 45, 50, 75
	double values[ARRAY] = { 4, 36, 45, 50, 75 };
	int choice = -1;
	double average;
	cout << fixed << setprecision(2);	//turn on the two decimals

	while (choice != 0) {
		choice = menu();

		switch (choice) {
		case 0:
			cout << "Bye bye!" << endl;
			return 0;
			
		case 1:
			input(values);
			line();
			//sneaky - no break
			//case 1 flows into case 2
		case 2:
			cout << "You entered these numbers" << endl;
			showNumbers(values);
			break;
			
		case 3:
			average = arithmeticMean(values);
			cout << "Arithmetic mean is " << average << endl;
			break;
		case 4:
			average = geometricMean(values);
			cout << "Geometric mean is " << average << endl;
			break;
		case 5:
			average = harmonicMean(values);
			cout << "Harmonicic mean is " << average << endl;
			break;
		default:
			choice = -1;
			cout << "Enter a number between 0 and 4" << endl;

		}
	}


    cout << "Hello World!\n"; 
}

//write functions here

int menu() {
	int choice = -1;
	
	line();
	cout << "Enter 0 to quit" << endl;
	cout << "Enter 1 to enter values" << endl;
	cout << "Enter 2 to display values" << endl;
	cout << "Enter 3 to display arithmetic mean" << endl;
	cout << "Enter 4 to display gemoetric mean" << endl;
	cout << "Enter 5 to display harmonic mean" << endl;
	cin >> choice;
	
	return choice;
}

void input(double list[]) {
	for (int x = 0; x < ARRAY; x++) {
		//sizeof returns memory elements in the array
		cout << "Enter number " << x << ": ";
		cin >> list[x];
	}
}

void showNumbers(double list[]) {
	for (int x = 0; x < ARRAY; x++) {
		//sizeof returns memory elements in the array
		cout << "Number " << x << ": " << list[x] << endl;
	}
}

void line() {
	cout << "-----------------------------------" << endl << endl;
}

double arithmeticMean(double list[]) {
	//4, 36, 45, 50, 75 = 42
	double total = 0;
	double average = 0;
	for (int x = 0; x < ARRAY; x++) {
		total += list[x];
	}
	average = total / ARRAY;
	return average;

}

double geometricMean(double list[]) {
	/*The geometric mean is an average that is useful for sets of positive numbers that are 
	interpreted according to their product and not their sum(as is the case with the arithmetic mean);
	e.g., rates of growth.*/

	//4, 36, 45, 50, 75 = 30
	double total = 1;
	double average = 0;
	for (int x = 0; x < ARRAY; x++) {
		total *= list[x];
	}
	average = pow(total, 1.0/ARRAY);
	return average;
}

double harmonicMean(double list[]) {
	//4, 36, 45, 50, 75 = 15
	/*The harmonic mean is an average which is useful for sets of 
	numbers which are defined in relation to some unit,
		for example speed (distance per unit of time).*/

	double total = 0;
	double average = 0;
	for (int x = 0; x < ARRAY; x++) {
		total += 1 / list[x];
	}
	average = 5 / total;
	return average;
}