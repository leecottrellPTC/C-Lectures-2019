#ifndef CUSTOMER_CLASS
#define CUSTOMER_CLASS
using namespace std;
#include <string>
#include "person.h"

class customers {
protected:
	person cust;
	string creditCard;
	double balance;
	string country;
	const double INT_RATE = .01;
public:
	customers();
	customers(string first, string last, string cc, double bal, string cntry);
	string getFirstName();
	string getLastName();
	string getCreditCard();
	double getBalance();
	string getCountry();

	void setFirstName(string first);
	void setLastName(string last);
	void setCreditCard(string cc);
	void setBalance(double bal);
	void setCountry(string cntry);

	string to_string();
	void makePayment(double pmt);
	void addToBalance(double amt);
	void payoff();
	void addInterest();

};
#pragma region constructors
customers::customers() {
	cust = person();
	this->balance = 0;
	this->creditCard = "";
	this->country = "";
}

customers::customers(string first, string last, string cc, double bal, string cntry) {
	cust = person(first, last);
	this->creditCard = cc;
	this->setBalance(bal);
	country = cntry;
}
#pragma endregion

#pragma region setters and getters
void customers::setBalance(double bal) {
	if(bal >= 0){
		this->balance = bal;
	}
	else {
		balance = 0;
	}
}

void customers::setCreditCard(string cc) {
	this->creditCard = cc;
}

void customers::setFirstName(string first) {
	this->cust.setFirstName(first);
}

void customers::setLastName(string last) {
	this->cust.setLastName(last);
}

void customers::setCountry(string cntry) {
	country = cntry;
}

double customers::getBalance() {
	return balance;
}

string customers::getCreditCard() {
	return creditCard;
}

string customers::getFirstName() {
	return cust.getFirstName();
}

string customers::getLastName() {
	return cust.getLastName();
}

string customers::getCountry() {
	return country;
}
#pragma endregion

#pragma region member functions
string customers::to_string() {
	return cust.to_string() + "\n" + creditCard + 
		" Balance " + std::to_string(balance) + "\nCountry " + country;
}

void customers::makePayment(double pmt) {
	if (pmt > 0) {
		this->balance -= pmt;
	}
}

void customers::addToBalance(double amt) {
	if (amt > 0) {
		balance += amt;
	}
}

void customers::payoff() {
	balance = 0;
}
void customers::addInterest()
{
	if (balance > 0) {
		balance += balance * INT_RATE;
	}
}

#pragma endregion 
#endif
