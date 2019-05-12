//create a dynamic array full of random numbers between 0 and and some specified max value
//doing 100 first, then asking for value

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int arraySize = 0;
int maxVal = 100;
int x;
int* dynArray;	//pointer to an int
int* dynCount;


void fillArray() {
	for (x = 0; x < arraySize; x++) {
		//dynArray[x] = rand() % 100 + 1;//between 1 and 100
		dynArray[x] = rand() % maxVal;//between 0 and maxVal
	}

	for (x = 0; x < maxVal; x++) {
		dynCount[x] = 0;
	}
}

void displayArray() {
	for (x = 0; x < arraySize; x++) {
		cout << x << " " << dynArray[x] << endl;
	}
}

void countArray() {
	for (x = 0; x < arraySize; x++) {
		dynCount[dynArray[x]] ++;
	}

	//display the count
	for (x = 0; x < maxVal; x++) {
		cout << x << ":" << dynCount[x] << endl;
	}
}

//only if time will I sort
//generic function, can take any type of pointer
//describe the pointer type in the class
//we will do this better with template functions and classes
int compare(const void* arg1, const void* arg2) {
	//https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/qsort.htm
	if (*(int *)arg1 < *(int*)arg2) {
		return -1;	// <0
	}
	else if (*(int*)arg1 > * (int*)arg2) {
		return 1;	// >0
	}
	else {
		return 0;
	}
}
int main() {
	srand(time(NULL));	//seed the random number generator
						//need to get 'random' numbers

	
	cout << "How many random numbers in the array? ";
	cin >> arraySize;

	cout << "Max size of value ";
	cin >> maxVal;

	dynArray = new int[arraySize];	//dynArray points to an array in RAM
	dynCount = new int[maxVal];
	fillArray();

	//qsort((void *)dynArray, arraySize, sizeof(int), compare);

	//displayArray();

	countArray();

}