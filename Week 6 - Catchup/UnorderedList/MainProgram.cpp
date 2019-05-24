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
	myList.add("bicycle");
	myList.add("computer");
	myList.add("food");
	myList.add("trees");
	myList.add("doggies");
	myList.add("chocolate");
	/*
		array[0] = "bicycle";
		array[1] = "computer";
		array[3] = "food";
		array[3] = "trees";
		array[4] = "doggies";
	*/

}

int main()
{
	string theWord;
	int choice, pos;
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
			cout << "Enter words to add (99 to quit)\n";
			do {
				cin >> theWord;
				if (theWord != "99" && 
					myList.seqSearch(theWord) < 0) 
				{
					myList.add(theWord);
				}
			} while (theWord != "99");

			break;
		case 3:
			//find in list
			cout << "What do you want to find? ";
			cin >> theWord;
			pos = myList.seqSearch(theWord);
			if (pos < 0) {
				cout << theWord << " is not found" << endl;
			}
			else {
				cout << theWord << " is found at pos " 
					<< pos << endl;
			}
			break;
		case 4:
			//remove from the list
			cout << "What do you want to kill? ";
			cin >> theWord;

			myList.remove(theWord);
			break;
		}
		
	} while (choice >= 0);

}
