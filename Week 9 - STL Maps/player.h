#ifndef PLAYER_CLASS
#define PLAYER_CLASS

#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

class player {
protected:
	int playerNum;
	string fname;
	string lname;
public:
	player() {
		playerNum = 0;
		fname = "no";
		lname = "name";
	}
	player(int num, string First, string Last) {
		playerNum = num;
		fname = First;
		lname = Last;
	}

	void setPlayerNum(int num) {
		playerNum = num;
	}
	int getPlayerNum() {
		return playerNum;
	}

	void setFname(string First) {
		fname = First;
	}
	string getFname() {
		return fname;
	}

	void setLname(string Last) {
		lname = Last;
	}
	string getLname() {
		return lname;
	}

	string to_string() {
		return fname + " " + lname;
	}

	friend bool operator <(player lhs, player rhs) {
		return lhs.playerNum < rhs.playerNum;
	}

	friend bool operator >(player lhs, player rhs) {
		return lhs.playerNum > rhs.playerNum;
	}

	friend bool operator ==(player lhs, player rhs) {
		if ((lhs.playerNum == rhs.playerNum) &&
			(lhs.fname == rhs.fname) && (lhs.lname == rhs.lname))
		{
			return true;
		}
		else {
			return false;
		}
	}

};

#endif
