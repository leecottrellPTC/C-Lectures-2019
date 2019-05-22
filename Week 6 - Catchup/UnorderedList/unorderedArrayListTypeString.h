#ifndef H_unorderedArrayListType
#define H_unorderedArrayListType
   
#include "arrayListTypeString.h" 

class unorderedArrayListType: public arrayListType
{
public:
    void insertAt(int location, string insertItem);
    void add(string insertItem);
    void replaceAt(int location, string repItem);
    int seqSearch(string searchItem) const;
    void remove(string removeItem);

    unorderedArrayListType(int size = 100);
      //Constructor
}; 


#endif
