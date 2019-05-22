#ifndef SPORT_EVENT
#define SPORT_EVENT

#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

class SportEvent {
public:
	//methods
	//setters and getters
	//constructors
	//to_string
	//operators

	string getHomeTeam();
	void setHomeTeam(string name);

	int getHomeScore();
	void setHomeScore(int score);

	string getAwayTeam();
	void setAwayTeam(string name);

	int getAwayScore();
	void setAwayScore(int score);

	string* getHomeRoster();
	void setHomeRoster(string*);

	string* getAwayRoster();
	void setAwayRoster(string*);

	void increaseHomeScore(int addToScore);
	void increaseAwayScore(int addToScore);
	string winner();

	//Cottrell's method
	SportEvent();
	SportEvent(string homeName, string awayName,
		int homePoints, int awayPoints,
		string ball);
	SportEvent(string homeName, string awayName,
		int homePoints, int awayPoints,
		string ball, int homeRosterSize, int awayRosterSize);
	string to_string();

protected:
	string homeTeam;
	string awayTeam;
	int homeScore;
	int awayScore;
	string ballType;
	string* homeRoster;
	string* awayRoster;
private:

};

#pragma region constructors
//constructors
SportEvent::SportEvent() {
	homeTeam = "Pirates";
	awayTeam = "Losers";
	homeScore = 100;
	awayScore = 0;
	ballType = "Baseball";
	homeRoster = new string[15];
	awayRoster = new string[15];
}
SportEvent::SportEvent(string homeName, string awayName,
	int homePoints, int awayPoints,
	string ball) {
	homeTeam = homeName;
	awayTeam = awayName;
	homeScore = homePoints;
	awayScore = awayPoints;
	ballType = ball;
	homeRoster = new string[15];
	awayRoster = new string[15];
}
SportEvent::SportEvent(string homeName, string awayName,
	int homePoints, int awayPoints,
	string ball, int homeRosterSize, int awayRosterSize) {
	homeTeam = homeName;
	awayTeam = awayName;
	homeScore = homePoints;
	awayScore = awayPoints;
	ballType = ball;
	homeRoster = new string[homeRosterSize];
	awayRoster = new string[awayRosterSize];
}

#pragma endregion


#pragma region methods
string SportEvent::to_string() {
	return homeTeam + " " + std::to_string(homeScore) +
		"\n" + awayTeam + " " + std::to_string(awayScore);
}

string SportEvent::winner() {
	if (homeScore > awayScore) {
		return homeTeam;
	}
	else if (homeScore < awayScore) {
		return awayTeam;
	}
	else if (homeScore == awayScore) {
		return "Tie";
	}
	else {
		return "Error in score";
	}
}

void SportEvent::increaseHomeScore(int addToScore = 1) {
	homeScore += addToScore;
}

void SportEvent::increaseAwayScore(int addToScore = 1) {
	awayScore += addToScore;
}
#pragma endregion


#pragma region setters and getters
string SportEvent::getHomeTeam() {
	return homeTeam;
}

string SportEvent::getAwayTeam() {
	return awayTeam;
}

string* SportEvent::getHomeRoster() {
	return homeRoster;
}

string* SportEvent::getAwayRoster() {
	return awayRoster;
}

int SportEvent::getHomeScore() {
	return homeScore;
}

int SportEvent::getAwayScore() {
	return awayScore;
}


void SportEvent::setHomeTeam(string name) {
	homeTeam = name;
}

void SportEvent::setAwayTeam(string name) {
	awayTeam = name;
}

void SportEvent::setHomeRoster(string* roster) {
	//rebuild the dynamic array
	homeRoster = new std::string[sizeof(roster)/sizeof(roster[0])];
	homeRoster = roster;
}

void SportEvent::setAwayRoster(string* roster) {
	//rebuild the dynamic array
	awayRoster = new std::string[sizeof(roster) / sizeof(roster[0])];
	awayRoster = roster;
}

void SportEvent::setHomeScore(int score) {
	homeScore = score;
}

void SportEvent::setAwayScore(int score) {
	awayScore = score;
}

#pragma endregion
#endif
