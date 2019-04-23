// ch5num28 - Apartment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int rent = 600, increase = 40, maintenance = 27, units = 50;
	int  prevProfit = 0, newProfit = 1;
	//1320 is the correct answer here

	prevProfit = (rent - maintenance) * units;
	
	
	do {
		//cout << units << " " << rent << " " << newProfit << " " << prevProfit << endl;
		prevProfit = newProfit;
		rent += 40;
		units--;
		newProfit = (rent - maintenance) * units;
		//cout << units << " " << rent << " " << newProfit << " " << profit << endl;

	} while (prevProfit < newProfit);
	//retract the last combination
	rent -= 40;
	units++;
	cout << "-------------" << endl;
	//cout << units << " " << rent << " " << newProfit << " " << profit << endl;
	cout << "Rent of " << rent << " will maximize profit" << endl;
	cout << units << " will be rented" << endl;
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
