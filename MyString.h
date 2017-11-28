//
// Created by Hugo Valle on 11/12/17.
//

#ifndef HW7_MYSTRING_H
#define HW7_MYSTRING_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>
using namespace std;

class MyString
{
private:
    int nlength;
    unique_ptr<char[]> internalCString;
public:
    MyString();
    MyString(const char * cString);

    char * getInternalCString() const;
    int getNlength() const;
    int compareStr (const MyString & lhs,const MyString & rhs);
    void reverseit();
};

ostream& operator<< (ostream& os, const MyString& myString);
#endif //HW7_MYSTRING_H
