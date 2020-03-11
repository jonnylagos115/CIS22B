// This program demonstrates the CruiseShip, and CargoShip
// classes that are derived from the Ship class.
#include <iostream>
#include <iomanip>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"
using namespace std;

int main()
{
    const int NUM_SHIPS = 3;

    Ship *ships[NUM_SHIPS] =
        {   new Ship("RMS Titanic", "1909"),
            new CruiseShip("Harmony of the Seas", "2014", 6780),
            new CargoShip("Panamax", "2009", 52500)
        };
    
    for (int i = 0; i < NUM_SHIPS; i++)
    {
        ships[i]->printShipInfo();
    }
    return 0;
}