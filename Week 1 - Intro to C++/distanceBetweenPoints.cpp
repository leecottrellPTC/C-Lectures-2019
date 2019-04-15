// distanceBetweenPoints.cpp : This file contains the 'main' function. Program execution begins and ends there.
//this program demonstrates the use of math.h
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	int x1= 10, x2=5, y1=6, y2 = 8;
	//(10, 6) and (5, 8)
	int xSub = x1 - x2;
	int ySub = y1 - y2;

	double dist = sqrt(pow(xSub, 2) + pow(ySub, 2));
	cout << "Distance between (" << x1 << ", " << y1 << ")";
	cout << " and (" << x2 << ", " << y2 << ")";
	cout << " is " << fixed << setprecision(2) << dist << endl;
	//

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
