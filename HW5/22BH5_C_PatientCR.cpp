#include "Patient.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    Patient patient[100];
    ifstream fin;
    string line, name;
    double height;
    int age, weight;

    fin.open("patient.txt");
    if (fin.fail())
    {
        cerr << "Input file could not be opened\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 100; i++)
    {
        fin >> age;
        patient[i].setAge(age);
        fin >> height;
        patient[i].setHeight(height);
        fin >> weight;
        patient[i].setWeight(weight);
        fin.ignore(); //Skips over space character
        getline(fin, name);
        patient[i].setName(name);
        patient[i].display();
    }
    return 0;
}
