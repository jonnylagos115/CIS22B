#include <iostream>
#include <iomanip>
#include <string>
#include "Patient.h"
using namespace std;

int main()
{
    Patient patJane, patTim, patLinda;

    patJane.setName("Jane North");
    patTim.setName("Tim South");
    patLinda.setName("Linda East");

    patJane.setAge(25);
    patTim.setAge(64);
    patLinda.setAge(52);

    patJane.setHeight(66);
    patTim.setHeight(72);
    patLinda.setHeight(69);

    patJane.setWeight(120);
    patTim.setWeight(251);
    patLinda.setWeight(175);

    cout << "Name: " << patJane.getName()
    << "\nAge: " << patJane.getAge()
    << "\nHeight: " << patJane.getHeight() << " inches"
    << "\nWeight: " << patJane.getWeight() << " pounds"
    << "\nWeigh Status: " << patJane.weightStatus() << "\n" << endl;
    patTim.display();
    patLinda.display();

    return 0;
}