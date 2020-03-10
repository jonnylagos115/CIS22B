#include <iostream>
#include <iomanip>
#include "NumDays.h"
using namespace std;

int main()
{
    const int SIZE = 2;
    NumDays employee1(16), employee2(8);

    cout << "Employee 1" << " worked for " << employee1.getHours() << "hours which converted into days is "
    << employee1.getDays() << endl;

    cout << "Employee 2" << " worked for " << employee2.getHours() << "hours which converted into days is "
    << employee2.getDays() << endl;
    
    return 0;
}