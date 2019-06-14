 #ifndef TEAM_CLASS
#define TEAM_CLASS

#include <iomanip>
#include <iostream>
#include <string>
#include <set>
#include "player.h"

using namespace std;

class team {
protected:
	string teamName;
	string homeField;
	set <player, less<player>> roster;
public:
	team() {
		teamName = "No name";
		homeField = "left of nowhere";
	}
	team(string name, string home, set <player> list) {
		teamName = name;
		homeField = home;
		roster = list;
	}

	void setTeamName(string name) {
		teamName = name;
	}

	void setHomeField(string name) {
		homeField = name;
	}

	string getTeamName() {
		return teamName;
	}

	string getHomeField() {
		return homeField;
	}
	//interface to roster
	string to_string() {
		return homeField + " " + teamName;
	}
	set<player> getRosterSet() {
		return roster;
	}

	void setRosterSet(set<player> list) {
		roster = list;
	}

	//add a player
	void addPlayer(player newPlayer) {
		roster.insert(newPlayer);
	}

	void addPlayer(int playerNum, string fname, string lname) {
		roster.insert(player(playerNum, fname, lname));
		//constructor call
	}

	//delete a player
	void deletePlayer(player toKill) {
		roster.erase(toKill);
	}


};


#endif
