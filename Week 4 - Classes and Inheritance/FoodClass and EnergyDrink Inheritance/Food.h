#ifndef FOOD_CLASS// build this fir
#define FOOD_CLASS
#include <string>

using namespace std;
class FoodItem {
	
public:
	FoodItem();
	FoodItem(string Name, int Calories, double Cost);
	~FoodItem();
	void setName(string Name);
	void setCalories(int Cal);
	void setCost(double Cost);
	string to_string();

	string getName();
	int getCalories();
	double getCost();

protected:
	string name;
	int calories;
	double cost;
};
//constructors
#pragma region Constructors and Destructors
FoodItem::FoodItem() {
	name = "No name";
	calories = 0;
	cost = 0;
}

FoodItem::FoodItem(string Name, int Calories, double Cost) {
	name = Name;
	calories = Calories;
	cost = Cost;
}

FoodItem::~FoodItem() {
	//destructor
	//only needed to clean up memory
}

#pragma endregion 

#pragma region Setters and Getters

void FoodItem::setName(string Name) {
	name = Name;
}

void FoodItem::setCalories(int Cal) {
	calories = Cal;
}

void FoodItem::setCost(double Cost) {
	cost = Cost;
}

string FoodItem::getName() {
	return name;
}
int FoodItem::getCalories() {
	return calories;
}

double FoodItem::getCost() {
	return cost;
}
#pragma endregion

string FoodItem::to_string() {
	string output = "";
							//why type std??
	output = name + " has " + std::to_string(calories) + " calories "
		+ "and costs $" +  std::to_string(cost);

	//we will do this better next week
	return output;
}

#endif	//end of the define