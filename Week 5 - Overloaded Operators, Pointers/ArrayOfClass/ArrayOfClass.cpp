// ArrayOfClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Customers.h"
#include <fstream>
#include <string>

const int ARRAY = 100;
customers custList[ARRAY];
//data generated from https://www.generatedata.com/
int menu();
void menuRespond(int choice);
void searchByCountry(string country);
void findBalanceOver();
void fillArray(string fileName);
int main()
{
	int choice = 1;
	fillArray("creditData.txt");

	while (choice > 0) {
		choice = menu();
		menuRespond(choice);
	}
	cout << "Bye Bye";
}
void fillArray(string fileName) {
	ifstream fin;
	string input;
	double bal;
	int c = 0;

	fin.open(fileName);
	if (fin.fail()) {
		cout << "Could not open " << fileName << endl;
		system("exit");
	}

	do {
		getline(fin, input);
		custList[c].setFirstName(input);

		getline(fin, input);
		custList[c].setLastName(input);

		getline(fin, input);
		custList[c].setCreditCard(input);
		
		getline(fin, input);
		custList[c].setBalance(stof(input));	//convert to float

		getline(fin, input);
		custList[c].setCountry(input);

		//cout << custList[c].getFirstName() << " " + c << endl;
		c++;//count the array
		
	} while (!fin.eof());

	cout << c << " Records read" << endl;
	fin.close();
}

void showRecords() {
	for (int c = 0; c < ARRAY; c++) {
		cout << setw(19) << setfill('-') << '\n';
		cout << custList[c].to_string() << endl;
		if ((c + 1) % 10 == 0) {
			system("pause");
		}
	}
	cout << setw(19) << setfill('-') << '\n';
}

void addInterest() {
	for (int c = 0; c < ARRAY; c++) {
		custList[c].addInterest();
	}
	
}
void searchByCountry() {
	//Mexico has one, Iceland has 2
	string country;
	cout << "Enter country name " << endl;
	getline(cin, country);
	
	for (int c = 0; c < ARRAY; c++) {
		if (custList[c].getCountry() == country) {
			cout << setw(19) << setfill('-') << '\n';
			cout << custList[c].to_string() << endl;
		}
		
	}
	cout << setw(19) << setfill('-') << '\n';
}

void makePayment() {
	string first = "", last = "";
	cout << "Enter first and last name";
	cin >> first >> last;

	double payment;
	for (int c = 0; c < ARRAY; c++) {
		if (custList[c].getFirstName() == first
			&& custList[c].getLastName() == last) {
			cout << "Balance is " << custList[c].getBalance() << endl;
			cout <<"Enter payment amount ";
			cin >> payment;
			custList[c].makePayment(payment);
			cout << "New Balance is " << custList[c].getBalance() << endl;
			return;//kick out of loop
		}
	}
}
void findBalanceOver() {
	//4500 has 5
	double bal;
	cout << "Enter balance ";
	cin >> bal;
	int display = 0;
	for (int c = 0; c < ARRAY; c++) {
		if (custList[c].getBalance() >bal) {
			cout << setw(19) << setfill('-') << '\n';
			cout << custList[c].to_string() << endl;
			display++;
			if (display % 10 == 0) {
				system("pause");
				display = 0;
			}
		}

	}
	cout << setw(19) << setfill('-') << '\n';
}
void menuRespond(int choice) {
	switch (choice) {
	case 1:
		showRecords();
		break;
	case 2:
		searchByCountry();
		break;
	case 3:
		findBalanceOver();
		break;
	case 4:
		addInterest();
		break;
	case 5:
		makePayment();
		//Noel
		//Mcknight
		break;
	case 0:
		cout << "Thank you for using the bank software" << endl;
		break;
	default:
		cout << choice << " is not a valid choice, 0-5 only" << endl;
	}
}
int menu() {
	int choice = 0;
	cout << "Enter 1 to display the customer list" << endl;
	cout << "Enter 2 to search by country" << endl;
	cout << "Enter 3 to search for high balance" << endl;
	cout << "Enter 4 to add interest to the balances" << endl;
	cout << "Enter 5 to make a payment" << endl;
	cout << "Enter 0 to quit" << endl;
	cin >> choice;
	//delete newline
	cin.ignore();
	return choice;
}
