// FoodClassLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Food.h"
#include "EnergyDrink.h"

using namespace std;

int main()
{
	cout << "Food class" << endl;
	//instantiate
	FoodItem pie("Cherry Pie", 250, 5.5);
	cout << pie.to_string() << endl;

	FoodItem menu[5];

	menu[0] = FoodItem("Cookie", 100, 1);
	menu[1] = FoodItem("Soda", 280, 2.5);
	menu[2] = FoodItem("Personal Pizza", 600, 4.5);
	menu[3] = FoodItem("Beer", 200, 5);
	menu[4] = FoodItem("Coffee", 150, 4.5);

	for (int x = 0; x < 5; x++) {
		cout << menu[x].to_string() << endl;
	}

	EnergyDrink monster("Monster", 200, 5, 1000);
	//cout << monster.to_string() << monster.getCaffeine();
	cout << monster.to_string() << endl;

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
