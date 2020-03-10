// Specification file for the NumDays class
#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"
#include <iostream>
using namespace std;

class ProductionWorkers: public Employee
{
    private:
        int shift;
        double HPR;
    public:
        ProductionWorkers() : Employee()
         { shift = -1; HPR = -1;}
        
        ProductionWorkers(std::string n, int nID, std::string h, int s, double hpr) :
            Employee(n, nID, h)
            { shift = s; HPR = hpr;}

        //Mutator functions
        void setShift(int s) {shift = s;}
        void setHPR(int h) {HPR = h;}

        //Accessor functions
        int getShift() const {return shift;}
        double getHPR() const {return HPR;}

        //Other functions
        void displayWorkerInfo()
        {
            cout << "Employee: " << getName() << endl;
            cout << "Employee number: " << getNumberID() << endl;
            cout << "Hire date: " << getHireDate() << endl;
            cout << "Shift: " << getShift() << endl;
            cout << "Hourly pay rate: " << getHPR() << endl;
            cout << endl;
        }
};
#endif