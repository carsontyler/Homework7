//
// Created by Hugo Valle on 11/12/17.
//
#include <memory>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
    nlength = 0;
    internalCString = make_unique<char[]>(1);
}

MyString::MyString(const char *cString)
{
    int temp = 0;
    for(int i = 0; i <= sizeof cString; i++)
    {
        temp++;
    }
    internalCString = make_unique<char[]>(temp+1);
    for(int i = 0; i <= temp + 1; i++)
    {
        if(i <= temp)
        {
            internalCString[i] = cString[i];
        }
        if(i > temp)
        {
            internalCString[i] = '\0';
        }
    }
}

char *MyString::getInternalCString() const
{
    return internalCString.get();
}

int MyString::getNlength() const
{
    char *temp = getInternalCString(), i;
    i = sizeof(temp);
    return i;
}

int MyString::compareStr(const MyString &lhs, const MyString &rhs)
{
    lhs.getNlength();
    return 0;
}

void MyString::reverseit()
{

}
