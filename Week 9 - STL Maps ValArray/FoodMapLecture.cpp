// FoodHashLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Food.h"
#include <map>
#include <fstream>
#include <set>
#include <valarray>//use for really large arrays

using namespace std;
map <string, double> gradePoints;
void basic_map() {
	//associate the grades with the scores
	gradePoints["A+"] = 4.25;
	gradePoints["A"] = 4.0;
	gradePoints["A-"] = 3.75;
	gradePoints["B+"] = 3.50;
	gradePoints["B"] = 3.0;
	gradePoints["B-"] = 2.75;
	gradePoints["C+"] = 2.5;
	gradePoints["C"] = 2.0;
	gradePoints["D+"] = 1.25;
	gradePoints["D"] = 1.0;
	gradePoints["D-"] = .75;
	gradePoints["F"] = 0;
}

void calcGrades() {
	double totalScore = 0;
	int count = 0;
	string grade = "";
	do {
		cout << "Enter a letter grade from A - F, including +, -. X to exit\n";
		cin >> grade;
		//if(gradePoints.at(grade)
		//gradePoints.
		if (gradePoints[grade] != NULL) {
			totalScore += gradePoints[grade];
			count++;
		}
	} while (grade != "X");
	cout << "GPA = " << totalScore / count << endl;
}

map<string, FoodItem> foodMap;
void map_toclass() {
	//read in from file
	//food name will be the key
	ifstream fin("foodlist.txt");
	string foodName;
	FoodItem someFood;
	int calories, cost;

	if (fin.fail()) {
		cout << "File failed to open " << endl;
	}

	while (!fin.eof()) {
		fin >> foodName >> calories >> cost;
		someFood = FoodItem(foodName, calories, cost);
		//foodList.insert(pair<string, FoodItem>(foodName, someFood));
		foodMap[foodName] = someFood;
	}

	fin.close();
	cout << foodMap.size() << " records read" << endl;
}

void useFood() {
	//display the food items
	//FoodItem aFood;
	string foodName;
	multiset <FoodItem, less <FoodItem>> eaten;
	int totalCalories = 0;
	do {
		cout << "Enter food you ate, done to quit ";
		cin >> foodName;
		//cout << foodMap[foodName].getName() << endl;
		if (foodMap[foodName].getName() != "No name")
		{
			//aFood = foodMap[foodName];
			eaten.insert(foodMap[foodName]);
			totalCalories += foodMap[foodName].getCalories();
		}
	} while (foodName != "done");

	cout << "You ate " << totalCalories << " calories " << endl;
}

int main()
{
	//basic_map();
	//calcGrades();

	/*map_toclass();
	useFood();*/



}
