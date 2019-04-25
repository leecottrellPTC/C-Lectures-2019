// ch5Num28Lecgture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int rent = 600, increase = 40, maintenance = 27, units = 50;
	int prevProfit = 0, newProfit = 1;

	do {
		prevProfit = newProfit;//hold onto the profit value
		rent += increase;
		units--;
		newProfit = (rent - maintenance) * units;

	} while (prevProfit < newProfit);
	//solve the problem
	rent -= increase;
	units++;
	newProfit = (rent - maintenance) * units;

	cout << "Rent is " << rent;
	cout << " newProfit = " << newProfit << endl;
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
