// Specification file for the Employee class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
    private:
        std::string name;
        int numberID;
        std::string hireDate;
    public:
        Employee() {name = ""; numberID = -1; hireDate = "";}

        Employee(std::string n, int nID, std::string h) {name = n; numberID = nID; hireDate = h;}

        //Mutator functions
        void setName(std::string n) {name = n;}
        void setNumberID(int nID) {numberID = nID;}
        void setHireDate(std::string h) {hireDate = h;}

        //Accessor functions
        std::string getName() const {return name;}
        int getNumberID() const {return numberID;}
        std::string getHireDate() const {return hireDate;}
};
#endif