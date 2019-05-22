// UnorderedListString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "unorderedArrayListTypeString.h"
unorderedArrayListType myList(300);//size of list

int menu() {
	cout << "1 to display the list\n";
	cout << "2 to add to the list\n";
	cout << "3 to find an item in the list\n";
	cout << "4 to remove an item from the list\n";
	cout << "-1 to exit"<<endl;
	int choice;
	cin >> choice;
	return choice;
}
void fillListWithWords() {
	myList.add("word");
	myList.add("chicken");
	myList.add("computer");
	myList.add("bike");
	myList.add("apple");
}
void findInList() {
	string theWord;
	cout << "Enter a word to find";
	cin >> theWord;

	int position = myList.seqSearch(theWord);
	if (position >= 0) {
		cout << theWord << " is in position " << position << endl;
	}
	else {
		cout << theWord << " is not in the list " << endl;
	}
}

void removeFromList() {
	string theWord;
	cout << "Enter a word to kill ";
	cin >> theWord;

	myList.remove(theWord);
}

void addWordsToList() {
	string theWord="";
	cout << "Enter words for the list. 99 to exit.\n";
		while (theWord != "99") {
			cin >> theWord;
			if (theWord != "99" && myList.seqSearch(theWord) < 0) {
				myList.add(theWord);
			}
	}

}
int main()
{
	int choice;
	fillListWithWords();
	//displayList();
	do {
		choice = menu();
		switch (choice) {
		case 1:
			//PRINT
			myList.print();
			break;
		case 2:
			//ADD TO LIST
			addWordsToList();
			break;
		case 3:
			//find in list
			findInList();
			break;
		case 4:
			//remove from the list
			removeFromList();
			break;
		}
		
	} while (choice >= 0);

}
