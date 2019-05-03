#ifndef ENERGY_DRINK
#define ENERGY_DRINK
//code goes here
#include "Food.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//inherits from FoodItem
//public items remain public, protected items remain protected
class EnergyDrink : public FoodItem
{
public:
	EnergyDrink(string Name, int Calories, double Cost, int Mgs);
	EnergyDrink();
	string to_string();	//override parent
	void setCaffeine(int Mgs);
	int getCaffeine();

private:
	int caffeine;
};

#pragma region Constructors and Destructors
EnergyDrink::EnergyDrink(string Name, int Calories, double Cost, int Mgs)
	: FoodItem(Name, Calories, Cost) {
	caffeine = Mgs;
}
//pass in the items to the parent class
EnergyDrink::EnergyDrink() :FoodItem() {
	caffeine = 0;
}


#pragma endregion

#pragma region Setter and Getters
int EnergyDrink::getCaffeine() {
	return caffeine;
}

void EnergyDrink::setCaffeine(int Mgs) {
	caffeine = Mgs;
}
#pragma endregion

string EnergyDrink::to_string() {
	string output = FoodItem::to_string();//call the parent to_string
	output += " and has " + std::to_string(caffeine) + " Mgs of caffeine";
	return output;
}
#endif

