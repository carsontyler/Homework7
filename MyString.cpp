//
// Created by Hugo Valle on 11/12/17.
//
#include <memory>
#include "MyString.h"
using namespace std;

/*!
 * Default constructor, sets default values
 */
MyString::MyString()
{
    nlength = 0;
    internalCString = make_unique<char[]>(1);
}

/*!
 * Constructor. Sets values to the appropriate variables
 * @param cString: passed in string which we assign to internalCString
 */
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

/*!
 * @return Returns the stored string
 */
char *MyString::getInternalCString() const
{
    return internalCString.get();
}

/*!
 * @return Returns the length of the string, including the null escape character
 */
int MyString::getNlength() const
{
    return nlength;
}

/*!
 * Compares two strings and returns different values depending on the comparison:
 * (1) Left Hand Side (lhs) is greater than Right Hand Side (rhs)
 * (-1) lhs is less than rhs
 * (0) lhs is equivalent to rhs, both in length and string
 * (-2) lhs is equivalent to rhs only in length, the string is different
 * @param lhs Left Hand Side string passed in
 * @param rhs Right Hand Side string passed in
 * @return return the calculated number
 */
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

/*!
 * Takes a string and reverses it, i.e. from Hello to olleH
 */
void MyString::reverseit()
{
    char cString[nlength];
    for(int i = 0; i <= nlength; i++)
    {
        if(i < nlength)
        {
            cString[i] = internalCString[nlength - 1 - i];
        }
        else if(i >= nlength)
        {
            cString[i] = '\0';
        }
    }

    for(int i = 0; i <= nlength; i++)
    {
        if(i < nlength)
        {
            internalCString[i] = cString[i];
        }
        else if(i >= nlength)
        {
            internalCString[i] = '\0';
        }
    }
}

/*!
 * Overloads the output stream operator so the string can be ouputed
 * @param os: The passed in ostream
 * @param myString: the passed in string to be outputed
 * @return Returns the outputed string
 */
ostream &operator<<(ostream &os, const MyString &myString)
{
    os << myString.getInternalCString();
    return os;
}
