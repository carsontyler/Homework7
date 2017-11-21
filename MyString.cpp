//
// Created by Hugo Valle on 11/12/17.
//
#include <memory>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
    nlength = 0;
    internalCString = make_unique<MyString>("");
}

MyString::MyString(const char *cString)
{
    int temp = sizeof cString;
    /*for(int i = 0; i <= sizeof cString; i++)
    {
        temp = i;
    }*/
    internalCString = make_unique<char[]>(temp+1);
    internalCString = cString;
}

char *MyString::getInternalCString() const
{
    return internalCString;
}
