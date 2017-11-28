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
    while(cString[temp] != '\0')
    {
        temp++;
    }

    nlength = temp;
    internalCString = make_unique<char[]>(nlength);

    for(int i = 0; i <= nlength; i++)
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
    return nlength;
}

int MyString::compareStr(const MyString &lhs, const MyString &rhs)
{
    int i = 0;
    if(lhs.getNlength() > rhs.getNlength())
    {
        i = 1;
    }
    else if(lhs.getNlength() < rhs.getNlength())
    {
        i = -1;
    }
    else if(lhs.getNlength() == rhs.getNlength())
    {
        for(int j = 0; j < lhs.getNlength() + 1; j++)
        {
            if(lhs.internalCString[j] == rhs.internalCString[j])
            {
                i = 0;
            }
            else
            {
                i = -2;
                j = lhs.getNlength() + 1;
            }
        }

    }
    else
    {
        cout << "internal error";
    }

    return i;
}

void MyString::reverseit()
{
    char cString[nlength];
    for(int i = 0; i <= nlength; i++)
    {
        if(i <= nlength)
        {
            cString[i] = internalCString[nlength - 1 - i];
        }
        else if(i > nlength)
        {
            cString[i] = '\0';
        }
    }

    for(int i = 0; i <= nlength; i++)
    {
        if(i <= nlength)
        {
            internalCString[i] = cString[i];
        }
        else if(i > nlength)
        {
            internalCString[i] = '\0';
        }
    }
}

ostream &MyString::operator<<(ostream &os, const MyString &myString)
{
    os << myString.getInternalCString();
    return os;
}
