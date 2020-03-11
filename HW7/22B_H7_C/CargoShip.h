// Specification file for the CargoShip class
#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include "Ship.h"
#include <string>
#include <iostream>

// The CargoShip class represents a cargo ship
class CargoShip : public Ship
{
    private:
        int cap_tonnage;
    
    public:
        // Default Constructor
        CargoShip()
        { cap_tonnage = 0; }

        // Constructor #2
        CargoShip(std::string name, std::string year, int c) :
            Ship(name, year)
        { cap_tonnage = c; }

        //Accessor for cargo capacity in tonnage
        int getCapTonnage()
        { return cap_tonnage; } 

        // Other function(s)
        void printShipInfo()
        { std::cout << "Cargoship: " << name << " has a cargo capacity of " 
        << cap_tonnage << " tonnage" << std::endl;}
};
#endif