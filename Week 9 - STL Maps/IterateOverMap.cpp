// TeamRosterLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "player.h"
#include "Team.h"
#include <map>
using namespace std;
int main()
{

	map<string, team> teams;
	teams["A"] = team("A", "A field");
	teams["B"] = team("B", "B field");
	teams["C"] = team("C", "C field");
	teams["D"] = team("D", "D field");
	teams["E"] = team("E", "E field");
	map<string, team>::iterator itr;
	//team aTeam;
	for(itr = teams.begin(); itr != teams.end(); itr++){
		cout << itr->first << endl;	//key
		cout << itr->second.to_string() << endl;	//data
	}


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
