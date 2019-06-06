
#include <iostream>
#include <iomanip>
#include "customer.h"
#include <queue>
using namespace std;

queue<customer> checkoutLine;

int curCustTime = 0;
int custCount = 0;
int itemsSold = 0;

void addCustomer() {
	int newCust = int(rand() % 20);//higher number means fewer customers
	switch (newCust) {
	
	case 0:
		//add two customer
		checkoutLine.push(customer());
		checkoutLine.push(customer());
		break;
	case 1:
	case 2:
		checkoutLine.push(customer());
		//add one customers
		break;
	
	default:
		//nothing added
		break;
	}
}
void checkout() {
	customer current = checkoutLine.front();
	curCustTime++;	//add a minute to current time
	if (curCustTime >= current.getCheckoutTime()) {
		custCount++;
		curCustTime = 0;
		cout << "checkout " << current << endl;
		itemsSold += current.getItemsInBuggy();
		checkoutLine.pop();//remove from the queue
	}
}
int main()
{
	srand(time(NULL));
	//customer aCust;
	//cout << aCust.to_string();
	int minutes = 0;

	for (minutes = 1; minutes <= 120; minutes++) {
		addCustomer();
		if (!checkoutLine.empty()) {
			checkout();
		}
	}
	cout << "After 2 hours " << endl;
	cout << checkoutLine.size() << " left in queue" << endl;
	cout << custCount << " customers checked out" << endl;
	cout << itemsSold << " items sold" << endl;

}
