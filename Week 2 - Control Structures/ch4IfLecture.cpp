//this lecture will calculate term life insurance rates based on term, gender, age
//if statement are demonstrated

//the rates generated will be per 100,000 of life insurance per month

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

using namespace std;


int main()
{
	int age;
	int term;
	double perHundred;
	//double amount;
	double totalMonthly;
	char smoke;
	char overweight;
	string name;

	//get a string
	cout << "Enter your name ";
	getline(cin, name);
	//cout << name;

	cout << "How old are you " << name << "? ";
	cin >> age;

	//cout << "How much life insurance do you want (enter in 100000s) " << name << "? ";
	//cin >> amount;

	cout << "Do you smoke " << name << " (Y/N)? ";
	cin >> smoke;

	cout << "Are you overweight " << name << " (Y/N)? ";
	cin >> overweight;

	//force to uppercase
	smoke = toupper(smoke);
	overweight = toupper(overweight);

	if (age >= 10 && age < 20) {
		perHundred = 6.54;

	}
	else if (age >= 20 && age < 30) {
		perHundred = 7.77;
	}
	else if (age >= 30 && age < 40) {
		perHundred = 9.65;
	}
	else if (age >= 40 && age < 50) {
		perHundred = 10.21;
	}
	else if (age >= 50 && age < 60) {
		perHundred = 12.45;
	}
	else if (age >= 60 && age < 100) {
		perHundred = 14.45;
	}
	else {
		perHundred = -1;//this is an error condition
	}


	//assert(perHundred >0);
	if (perHundred < 0) {
		cout << "We cannot offer insurance for your age of " << age << endl;
		cout << "Ending program" << endl;
		return 1;
	}

	if (smoke == 'Y') {
		perHundred += .02 * (static_cast<int>(100) - age);	//2 % of the difference of your age from 100
		

	}

	if (overweight == 'N') {
		perHundred *= .90;	//10 percent discount
	}


	cout << name << " your cost per $100,000 of life insurance is $" << fixed << setprecision(2) << perHundred << endl;


    
}
