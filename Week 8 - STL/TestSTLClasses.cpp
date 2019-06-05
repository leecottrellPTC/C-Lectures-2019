// TstOrderedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <set>
#include <iterator>
#include <fstream>
#include "fullname.h"
#include <stack>
#include <queue>
using namespace std;

void simpleSetUse() {
	set < string, less <string>> words;
	//sets require unique values stored in the list
	//stored in order based on comparatpr
	//less stores in ascending, greater in descending
	//have a fast search (o logn)
	words.insert("food");
	words.insert("computer");
	words.insert("student");
	words.insert("food");

	set <string>::iterator itr;	//use as a way to walk through the list

	for (itr = words.begin(); itr != words.end(); itr++) {
		cout << *itr << endl;
	}

	set < string >::iterator theWord;
	theWord = words.find("food");

	if (theWord != words.end()) {
		cout << *theWord << " is found" << endl;
	}
	else {
		cout << "not found" << endl;
	}
}

void showOstreamAndIstreamIterators() {
	//istream iterators read in from an object - must have << defined
	//ostream oterators read out from a container - must have >> >defined
	//both are single pass operators
	ifstream fin("wordlist.txt");
	//fin.open;
	if (fin.fail()) {
		cout << "File did not open" << endl;
	}
	set <string>::iterator itr;
	set < string, less <string>> words;
	itr = words.begin();	//start of list
	copy(istream_iterator<string>(fin), 
		istream_iterator<string>(), 
		inserter(words, itr));
		//use for objects with insert
		//back_insert for items with push_back like stack
	fin.close();

	ostream_iterator<string> screen(cout, "\n");	//ostream object, delimiter
	copy(words.begin(), words.end(), screen);
}

//build a set of names using a class
//read from a file using traditional input

void setWithClass() {
	set <fullName, less <fullName>> people;
	set <fullName>::iterator itr;
	fullName aPerson;
	string fname, lname;
	ifstream fin("fullnames.txt");
	if (fin.fail()) {
		cout << "File open failed\n";
		return;
	}
	while (!fin.eof()) {
		fin >> fname >> lname;
		aPerson = fullName(fname, lname);
		people.insert(aPerson);
	}
	fin.close();
	
	ostream_iterator<fullName> screen(cout, "\n");    //ostream object, delimiter
	copy(people.begin(), people.end(), screen);

	fullName findMe("Candi", "Coad");
	itr = people.find(findMe);
	cout << *itr << " was found " << endl;

}

void testStack() {
	stack <fullName> clownCar;
	clownCar.push(fullName("Lee", "Cottrell"));
	clownCar.push(fullName("Coby", "Frye"));
	clownCar.push(fullName("Kate", "Upton"));
	clownCar.push(fullName("Julianne", "Hough"));

	cout << clownCar.top() << " is at the top of the stack" << endl;
	clownCar.pop();
	cout << "after popping " << clownCar.top() << " is at the top of the stack" << endl;

	cout << "Empty the car" << endl;
	while (!clownCar.empty()) {
		cout << clownCar.top() << "get out" << endl;
		clownCar.pop();
	}
}

void testQueue() {
	queue <fullName> cafeteria;
	cafeteria.push(fullName("Lee", "Cottrell"));
	cafeteria.push(fullName("Coby", "Frye"));
	cafeteria.push(fullName("Kate", "Upton"));
	cafeteria.push(fullName("Julianne", "Hough"));

	cout << cafeteria.front().getFname() << " eats first" << endl;
	cafeteria.pop();
	while (!cafeteria.empty()) {
		cout << cafeteria.front().getFname() << " eats next" << endl;
		//demonstrate that it returns an object
		cafeteria.pop();
	}

}


int main()
{
	//cout << "Set" << endl;
	//simpleSetUse();
	//showOstreamAndIstreamIterators();
	//setWithClass();
	//testStack();
	testQueue();
	//fullName p1("JOe", "Smith");
	//fullName p2;

	//p2 = p1;
	//cout << p2;
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
