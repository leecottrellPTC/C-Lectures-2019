// InheritConsolidateLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
// based on ch11 prog ex 11
// patient and doctor based on person
// bill will merge the two with composition
//

#include <iostream>
using namespace std;
#include "Schedule.h"

int main()
{
	cout << "The schedule" << endl;
	patient Lee("Lee", "Cottrell", "headache");
	doctor Spock("Leonard", "Nimoy", "brain");
	schedule appt(Lee, Spock);
	schedule appt2;

	cout << appt.to_string() << endl;

	cout << appt2.to_string() << endl;

}
