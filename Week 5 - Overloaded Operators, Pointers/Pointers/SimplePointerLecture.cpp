// SimplePointerLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//this class shows how to build pointers for double
//you will honestly never do this with int or doubles
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//basic variables
	double payroll = 12345.90;
	double tax = payroll * .07;

	//pointers hold the memory location of data
	double* payrollPtr, * taxPtr;	//* here indicates pointer variable not multipication
									//called derefenrencing operator

	//link payroll and tax pointers
	payrollPtr = &payroll; //& is the address of operator
	taxPtr = &tax;
	cout << "PayrollPtr address is " << payrollPtr << endl;
	cout << "taxPtr address is " << taxPtr << endl;

	//ptrs are good to pass large values and classes around

	cout << "Value in payrollPtr " << *payrollPtr << endl;	//derefenrencing
	cout << "Value in taxPtr " << *taxPtr << endl;

	//pointers have access to the memory location of referenced variable
	//can change referenced variable
	*payrollPtr = 54321.9;
	cout << "Value updated in payroll " << payroll << endl;

	payrollPtr = NULL;//reset the pointer

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
