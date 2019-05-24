// SportingEvent2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SportEvent.h"
using namespace std;

SportEvent games[10];

void fillTheArray() {
	games[0] = SportEvent("Soccer", "Brookline", "Uniontown", 3, 2);
	
	games[1].setSportName("Baseball");
	games[1].setHomeTeam("Pirates");
	games[1].setAwayTeam("Cubs");
	games[1].setHomeScore(7);
	games[1].setAwayScore(5);

	games[2].setSportName("Soccer");
	games[2].setHomeTeam("Carrick");
	games[2].setAwayTeam("Carlynton");
	games[2].setHomeScore(1);
	games[2].setAwayScore(4);

	/*while (not eof) {
		read into awayName
		read into homeName
			...
		games[counter].setAwayTeam(awayName)
		games[counter].setHomeTeam(homeName)

		counter++
	}*/
}

int findHomeTeam(string teamToFind) {
	//sequential search
	//ask for the item to find
	//walk through the array, comparing the getHomTeam
	//return the location in the list
	

	for (int x = 0; x < 10; x++) {
		if (games[x].getHomeTeam() == teamToFind) {
			//cout << games[x].to_string << endl;
			//cout << teamToFind << " at " << x << endl;
			return x;
		}
	}//end for
	return -1;//not found
}

void displayWinners() {
	for (int x = 0; x < 10; x++) {
		cout << "Game " << (x + 1) << " " <<
			games[x].winner() << endl;
	}
}

double avgHomeScore() {
	int total = 0;
	for (int x = 0; x < 10; x++) {
		total += games[x].getHomeScore();
	}
	return total / 10.0;
}
int menu() {
	cout << "0 to quit\n";
	cout << "1 to print array\n";
	cout << "2 to display the winners\n";
	cout << "3 to display avg home score\n";
	cout << "4 search for home team\n";
	int choice;
	cin >> choice;
	return choice;
}

void printArray() {
	for (int x = 0; x < 10; x++) {
		cout << games[x].to_string() << endl;
		cout << "----------------------------\n";
	}
}
int main()
{
	string teamToFind;
	int choice = -1;
	double avg;
	fillTheArray();
	int found;
	do {
		choice = menu();
		switch (choice) {
		case 1:
			printArray();
			break;
		case 2:
			//display winners
			displayWinners();
			break;
		case 3:
			//avg  home score
			avg = avgHomeScore();
			cout << "Average home score " << setprecision(2)
				<< avg << endl;
			break;
		case 4:
			//search
			cin.ignore(100, '\n');
			
			cout << "Enter team name ";
			getline(cin, teamToFind);

			found = findHomeTeam(teamToFind);
			if (found < 0) {
				cout << "Not found" << endl;
			}
			else {
				cout << games[found].to_string() << endl;
			}
			break;
		case 0:
			cout << "Bye bye!\n";
			break;
		default:
			cout << choice << "is invalid\n";
			break;
		}
	} while (choice != 0);
}
