#ifndef H_unorderedPTCList
#define H_unorderedPTCList
#include <iostream>

using namespace std;
template <class Type>
class PTCList
{
protected:
	Type* list;    //array to hold the list elements
	int length;   //variable to store the length of the list
	int maxSize;  //variable to store the maximum 
				  //size of the list
public:
	void insertAt(int location, Type insertItem)
	{
		if (location < 0 || location >= maxSize)
			cout << "The position of the item to be inserted "
			<< "is out of range." << endl;
		else if (length >= maxSize)  //list is full
			cout << "Cannot insert in a full list" << endl;
		else
		{
			for (int i = length; i > location; i--)
				list[i] = list[i - 1];	//move the elements down

			list[location] = insertItem; //insert the item at 
										 //the specified position

			length++;	//increment the length
		}
	} //end insertAt

	void add(Type insertItem) {
		if (length >= maxSize)  //the list is full
			cout << "Cannot insert in a full list." << endl;
		else
		{
			list[length] = insertItem; //insert the item at the end
			length++; //increment the length
		}
	} //end insertEnd

	void replaceAt(int location, Type repItem)
	{
		if (location < 0 || location >= length)
			cout << "The location of the item to be "
			<< "replaced is out of range." << endl;
		else
			list[location] = repItem;
	} //end replaceAt

	int seqSearch(Type searchItem) const
	{
		int loc;
		bool found = false;

		loc = 0;

		while (loc < length && !found)
			if (list[loc] == searchItem)
				found = true;
			else
				loc++;

		if (found)
			return loc;
		else
			return -1;
	} //end seqSearch

	void remove(Type removeItem)
	{
		int loc;

		if (length == 0)
			cout << "Cannot delete from an empty list." << endl;
		else
		{
			loc = seqSearch(removeItem);

			if (loc != -1)
				removeAt(loc);
			else
				cout << "The item to be deleted is not in the list."
				<< endl;
		}
	} //end remove

	bool isEmpty() const
	{
		return (length == 0);
	} //end isEmpty

	bool isFull() const
	{
		return (length == maxSize);
	} //end isFull

	int listSize() const
	{
		return length;
	} //end listSize

	int maxListSize() const
	{
		return maxSize;
	} //end maxListSize

	void print() const
	{
		for (int i = 0; i < length; i++)
			cout << list[i] << " ";
		cout << endl;
	} //end print

	bool isItemAtEqual(int location, Type item) const
	{
		if (location < 0 || location >= length)
		{
			cout << "The location of the item to be removed "
				<< "is out of range." << endl;

			return false;
		}
		else
			return (list[location] == item);
	} //end isItemAtEqual

	void removeAt(int location) {
		if (location < 0 || location >= length)
			cout << "The location of the item to be removed "
			<< "is out of range." << endl;
		else
		{
			for (int i = location; i < length - 1; i++)
				list[i] = list[i + 1];

			length--;
		}
	} //end removeAt

	Type retrieveAt(int location) const
	{
		if (location < 0 || location >= length)
			return "Out of range";
		else
			return list[location];
	} //end retrieveAt
	
	void clearList()
	{
		length = 0;
	} //end clearList
	
	PTCList(int size = 100)
	{
		if (size <= 0)
		{
			cout << "The array size must be positive. Creating "
				<< "an array of the size 100." << endl;

			maxSize = 100;
		}
		else
			maxSize = size;

		length = 0;

		list = new Type[maxSize];
	}  //end constructor

	PTCList(const PTCList& otherList)
	{
		maxSize = otherList.maxSize;
		length = otherList.length;

		list = new Type[maxSize]; 	//create the array

		for (int j = 0; j < length; j++)  //copy otherList
			list[j] = otherList.list[j];
	}//end copy constructor
	
	~PTCList()
	{
		delete[] list;
	} //end destructor
};
#endif
