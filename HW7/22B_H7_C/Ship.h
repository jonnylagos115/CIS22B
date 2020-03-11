// Specification file for the Ship class
#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <iostream>

class Ship
{
    protected:
        std::string name;
        std::string year;
    public:
        // Default constructor
        Ship()
        {   name = "";
            year = "";
        }

        // Constructor #2
        Ship(std::string n, std::string y)
        {
            name = n;
            year = y;
        }
        // Accessors
        std::string getName() const
        { return name; }

        std::string getYear() const
        { return year; }

        // Mutators
        void setName(std::string n)
        { name = n; }

        void setYear(std::string y)
        { year = y;}

        // Other function(s)
        virtual void printShipInfo()
        { std::cout << "Ship: " << name << " was built in " << year << std::endl;}
};
#endif