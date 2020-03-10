#include <iostream>
#include <iomanip>
#include "NumDays.h"
using namespace std;

int main()
{
    NumDays employee1(16), employee2(8), employee3(12), totalNumDays;

    cout << "Employee 1" << " worked for " << employee1.getHours() << " hours which converts to "
    << employee1.getDays() << " day(s)" << endl;

    cout << "Employee 2" << " worked for " << employee2.getHours() << " hours which converts to "
    << employee2.getDays() << " day(s)" << endl;

    cout << "Employee 3" << " worked for " << employee3.getHours() << " hours which converts to "
    << employee3.getDays() << " day(s)\n" << endl;

    totalNumDays = employee1 + employee2 + employee3;

    cout << "Total hours worked of all employees is: " << totalNumDays.getHours()
    << " hours which converts to " << totalNumDays.getDays() << " day(s)\n" << endl;

    totalNumDays = totalNumDays - employee2;

    cout << "Subracting hours worked from employee2 brings the total hours worked to "
    << totalNumDays.getHours() << " hours which converts to " << totalNumDays.getDays() 
    << " day(s)\n" << endl;

    employee1++;
    employee2--;
    ++employee3;
    cout << "Employee 1 incremented(postfix) to " << employee1.getHours() << " hours which is " << employee1.getDays() << " days" << endl;
    cout << "Employee 2 decremented(postfix) to " << employee2.getHours() << " hours which is " << employee2.getDays() << " days" << endl;
    cout << "Employee 3 (prefix)incremented to " << employee3.getHours() << " hours which is " << employee3.getDays() << " days" << endl;
    --employee2;
    cout << "Employee 2 (prefix)decremented to " << employee2.getHours() << " hours which is " << employee2.getDays() << " days" << endl;
    return 0;
}