// Specification file for the CruiseShip class
#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "Ship.h"
#include <string>
#include <iostream>

// The CruiseShip class represents a cruise ship
class CruiseShip : public Ship
{
    private:
        int max_passengers;
    
    public:
        // Default constructor
        CruiseShip() : Ship()
        { max_passengers = 0; }

        // Constructor #2
        CruiseShip(std::string name, std::string year, int m) :
            Ship(name, year)
        { max_passengers = m; }

        //Accessor for max passengers attribute
        int getMaxP()
        { return max_passengers; }

        // Other function(s)
        void printShipInfo()
        { std::cout << "Cruiseship: " << name << " has a maximum number of " 
        << max_passengers << " passengers" << std::endl;}
};
#endif