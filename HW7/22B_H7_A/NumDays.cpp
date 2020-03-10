// Implementation file for the NumDays class
#include "NumDays.h"

void NumDays::convertNumDays()
{
    days = hours / 8.;
}

//**********************************************
// Overloaded binary + operator.               *
//**********************************************

NumDays NumDays::operator+(const NumDays &right)
{
    NumDays temp;

    temp.hours = hours + right.hours;
    temp.convertNumDays();
    return temp;
}

//**********************************************
// Overloaded binary - operator.               *
//**********************************************

NumDays NumDays::operator-(const NumDays &right)
{
    NumDays temp;

    temp.hours = hours - right.hours;
    temp.convertNumDays();
    return temp;
}

//*************************************************************
// Overloaded prefix ++ operator. Causes the inches member to *
// be incremented. Returns the incremented object.            *
//*************************************************************

NumDays NumDays::operator++()
{
    ++hours;
    convertNumDays();
    return *this;
}

//***************************************************************
// Overloaded postfix ++ operator. Causes the inches member to  *
// be incremented. Returns the value of the object before the   *
// increment.                                                   *
//***************************************************************

NumDays NumDays::operator++(int)
{
    NumDays temp(hours);

    hours++;
    convertNumDays();
    return temp;
}


//***************************************************************
// Overloaded prefix -- operator. Causes the inches member to   *
// be decremented. Returns the value of the object before the   *
// decrement.                                                   *
//***************************************************************

NumDays NumDays::operator--()
{
    --hours;
    convertNumDays();
    return *this;
}

//***************************************************************
// Overloaded postfix -- operator. Causes the inches member to  *
// be decremented. Returns the value of the object before the   *
// decrement.                                                   *
//***************************************************************

NumDays NumDays::operator--(int)
{
    NumDays temp(hours);

    hours--;
    convertNumDays();
    return temp;
}
