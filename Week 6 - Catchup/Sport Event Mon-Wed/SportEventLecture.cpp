// SportEventLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "SportEvent.h"

using namespace std;
SportEvent games[10];
void fillArray();
void printSeason() {
	for (int x = 0; x < 3; x++) {
		cout << games[x].to_string() << endl;
		cout << "The winner is " << games[x].winner() << endl;
		/*if (games[x].getHomeScore() < games[x].getAwayScore()) {
			cout << "Winner is " << games[x].getAwayTeam() << endl;
		}*/
		cout << "-------------------" << endl;
	}
}
int menu() {
	cout << "Enter 1 to display season" << endl;
	cout << "Enter 2 to change a game stat" << endl;
	cout << "Enter 3 to score a touchdown for home" << endl;
	cout << "Enter 0 to quit" << endl;
	int choice;
	cin >> choice;
	return choice;
}
int main()
{
	/*cout << "Sporting Event Class test" << endl;
	SportEvent game1;
	SportEvent game2("Steelers", "Browns", 21,  14, "Football" );

	game1.setAwayTeam("Giants");
	cout << game1.to_string() << endl;
	cout << game2.to_string() << endl;*/

	
	fillArray();
	int choice;
	do {
		choice = menu();
		switch (choice) {
		case 1:
			printSeason();
			break;
		case 2:
			//change a stat
			//change home team score
			//ask for game number
			int gameNum, newScore;
			cout << "Enter game num 0-2 ";
			cin >> gameNum;

			cout << "Enter new score ";
			cin >> newScore;

			games[gameNum].setHomeScore(newScore);
			break;
		case 3:
			gameNum;
			cout << "Enter game num 0-2 ";
			cin >> gameNum;
			games[gameNum].increaseHomeScore(6);
			break;

		}
	} while (choice != 0);
	
}

void fillArray() {
	//initialize array
	/*for (int x = 0; x < 10; x++) {
		//initialize array
		games[x] = SportEvent();
	}*/

	games[0].setHomeTeam("Brookline");
	games[0].setAwayTeam("Carlynton");
	games[0].setHomeScore(5);
	games[0].setAwayScore(3);
	
	games[1].setHomeTeam("Uniontown");
	games[1].setAwayTeam("Brookline");
	games[1].setHomeScore(6);
	games[1].setAwayScore(2);

	games[2].setHomeTeam("Brookline");
	games[2].setAwayTeam("Carrick");
	games[2].setHomeScore(1);
	games[2].setAwayScore(7);


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
