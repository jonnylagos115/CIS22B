// Implementation file for the College class
// Written By: Jonathan Lagos
// IDE: None (Linux/VS Code)

#include <iostream>         // For cout  and NULL
#include <iomanip>
#include "College.hpp"
using namespace std;

void College::hDdisplay()
{
    cout << "====== ==== ============================= =========" << endl;
    cout << " Code" << setw(10) << "Rank" << setw(20) << "Name" << setw(20) << "Cost" << setw(10) << endl;
    cout << "";
}

void College::vDisplay()
{
    cout << setw(20) << "Rank: " << getRank() << endl;
    cout << setw(20) << "School Name: " << getName() << endl;
    cout << "Cost of Attendance: $" << getCost() << endl;
}