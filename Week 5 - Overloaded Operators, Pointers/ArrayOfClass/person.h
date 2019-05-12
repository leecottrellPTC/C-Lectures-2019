#ifndef PERSON_TYPE
#define PERSON_TYPE
//personType.h
    
#include <string> 

using namespace std;

class person
{
public:
	//inline to_string - makes the function call faster - only with short methods
	string to_string() {

		return lastName + ", " + firstName;;
	}
    void setName(string first, string last);
	void setFirstName(string first);
	void setLastName(string last);
    string getFirstName() ;
    string getLastName() ;
    person(string first, string last);
	person();
        

 protected:
    string firstName; //variable to store the first name
    string lastName;  //variable to store the last name
};



#pragma region setters and getters
void person::setName(string first, string last) {
	firstName = first;
	lastName = last;
}
void person::setFirstName(string first) {
	firstName = first;
}

void person::setLastName(string last) {
	lastName = last;
}
string person::getFirstName() {
	return firstName;
}
string person::getLastName() {
	return lastName;
}

#pragma endregion

#pragma region constructors
person::person(string first, string last) {

	firstName = first;
	lastName = last;
}
person::person() {
	firstName = "";
	lastName = "";
}
#pragma endregion


#endif