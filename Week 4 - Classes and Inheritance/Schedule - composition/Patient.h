#ifndef DOCTOR
#define DOCTOR

#include <string>
#include "person.h"

using namespace std;

class patient :public person {
public:
	patient();
	patient(string first, string last, string complaint);
	string to_string() {
		return "Patient " + person::to_string();
	}
protected:
	string complaint;
};
patient::patient() :person() {
	complaint = "";
}
patient::patient(string first, string last, string concern) : person(first, last) {
	complaint = concern;
}
#endif