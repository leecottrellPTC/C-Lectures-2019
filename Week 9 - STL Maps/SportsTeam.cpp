// SportsTeam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "player.h"
#include "team.h"
#include <iterator>

using namespace std;

int main()
{
	team PTC;
	PTC.addPlayer(1, "Jason", "Tressler");
	PTC.addPlayer(player(2, "Dirk", "Stathers"));
	PTC.addPlayer(player(3, "Joe", "Smith"));
	PTC.addPlayer(player(4, "Amy", "Troiano"));
	PTC.addPlayer(player(5, "Amanda", "Bowers"));
	set<player> rst = PTC.getRosterSet();

	set <player, less<player>>::iterator itr;

	//iterate through the roster, display the name
	for (itr = rst.begin(); itr != rst.end(); itr++) {
		player temp = *itr;
		cout << temp.getFname() << endl;
	}



}
