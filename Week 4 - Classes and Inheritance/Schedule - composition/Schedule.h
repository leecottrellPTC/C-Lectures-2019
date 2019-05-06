#ifndef SCHEDULE
#define SCHEDULE

#include <string>
#include "patient.h"
#include "doctor.h"

class schedule {
public:
	schedule();
	schedule(patient pat, doctor doc);
	string to_string();
protected:
	patient thePatient;
	doctor theDoctor;
};

schedule::schedule() {

}
schedule::schedule(patient pat, doctor doc) {
	thePatient = pat;
	theDoctor = doc;
}


string schedule::to_string() {
	return thePatient.to_string() + " will see " + theDoctor.to_string();
}
#endif