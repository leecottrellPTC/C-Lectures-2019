// SportingEvent2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SportEvent.h"
using namespace std;

int main()
{
	SportEvent game1;
	SportEvent game2("Soccer", "Riverhounds", "LA Fusion", 3, 2);

	cout << game1.to_string() << endl;
	cout << game2.to_string() << endl;
	cout << game2.winner() << " wins!" << endl;
}
