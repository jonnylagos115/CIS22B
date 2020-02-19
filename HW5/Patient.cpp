#include "Patient.h"   // Needed for the Rectangle class
#include <iostream>      // Needed for cout
#include <string>
#include <cstdlib>       // Needed for the exit function
using namespace std;

void Patient::setName(string n)
{   name = n; }

void Patient::setAge(int a)
{
    if (a >= 1)
        age = a;
    else
    {
        cout << "Invalid age" << endl;
        exit(EXIT_FAILURE);
    }   
}

void Patient::setWeight(int w)
{
    if (w >= 0)
        weight = w;
    else
    {
        cout << "Invalid weight\n";
        exit(EXIT_FAILURE);
    }
}

void Patient::setHeight(double h)
{
    if (h >= 0)
        height = h;
    else
    {
        cout << "Invalid height\n";
        exit(EXIT_FAILURE);
    }
}

string Patient::weightStatus()
{
    string status;
    double BMI;

    BMI = (weight * 703.) / (height * height);
    if (BMI < 18.5)
        status = "Underweight";
    else if (BMI >= 18.5 && BMI <= 24.9)
        status = "Normal";
    else if (BMI >= 25. && BMI <= 29.9)
        status = "Overweight";
    else
        status = "Obese";
    return status;
}

void Patient::display()
{
    cout << "Name: " << name
    << "\nAge: " << age
    << "\nHeight: " << height << " inches"
    << "\nWeight: " << weight << " pounds"
    << "\nWeigh Status: " << weightStatus() << "\n" << endl;
}
