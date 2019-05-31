// FunctionAndClassTemplatesLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "GenClass.h"
#include "PTCList.h"
#include "Food.h"
using namespace std;
/*
int bigger(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

float bigger(float a, float b) {
	if (a < b)
		return a;
	else
		return b;
}
*/

template <class T>
T bigger(T a, T b) {
	if (a > b)
		return a;
	else
		return b;
}


//more than one template class at a time
template <class T1, class T2>
T1 addEm(T1 a, T2 b) {
	return a + b;
}

int main()
{
	cout << bigger("Lee", "Coby")<< endl;
	cout << bigger("Lee", "coby") << endl;
	cout << bigger(5, 15) << endl;
	
	int x = 100;
	double y = 3.14;

	cout << addEm(x, y) << endl;
	cout << addEm(y, x) << endl;

	GenClass<string> c1("Lee");
	GenClass<int> c2;

	cout << c1.getTheValue() << endl;
	
	c2.setTheValue(42);
	cout << c2.getTheValue() << endl;

	PTCList<string> aList;

	aList.add("Lee");
	aList.add("Joe");
	aList.add("Carys");

	aList.remove("Joe");

	aList.print();


	PTCList<int> numbers;
	numbers.add(100);
	numbers.add(123);
	numbers.add(234);

	PTCList<FoodItem> dinner;
	dinner.add(FoodItem("Steak", 100, 6));
	dinner.add(FoodItem("Potato", 100, 6));
	dinner.add(FoodItem("Salad", 100, 6));

	dinner.print();


	//string name = "Lee";
	//cout << "WTF" << addEm(name, 5) << endl;


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
