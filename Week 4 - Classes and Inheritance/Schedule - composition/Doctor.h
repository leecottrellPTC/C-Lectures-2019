#ifndef DOCTOR_CLASS
#define DOCTOR_CLASS

#include <string>
#include "person.h"

using namespace std;

class doctor :public person {
public:
	
	doctor();
	doctor(string first, string last, string Speciality);
	doctor(string first, string last, string Speciality, string id);
	string to_string() {
		return "Doctor " + person::to_string();
	}//inline function definition - faster

	void buildID() {
		id = "Dr" + firstName.substr(1) + lastName + "-" + speciality.substr(3);
	}
protected:
	string speciality;
	string id;
	
};

#pragma region constructors
doctor::doctor() :person() {
	speciality = "";
	id = "";
}


doctor::doctor(string first, string last, string Speciality) :person(first, last) {
	speciality = Speciality;
	buildID();
}

doctor::doctor(string first, string last, string Speciality, string ID) : person(first, last) {
	speciality = Speciality;
	id = ID;
}
#pragma endregion




#endif
