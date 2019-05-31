#ifndef GEN_CLASS
#define GEN_CLASS
#include <iostream>
#include <iomanip>
template <class C>
class GenClass {
protected:
	C theValue;
public:

	GenClass() {
		theValue = NULL;
	}
	GenClass(C data) {
		theValue = data;
	}
	void setTheValue(C data)
	{
		theValue = data;
	}
	C getTheValue() {
		return theValue;
	}
};


#endif
