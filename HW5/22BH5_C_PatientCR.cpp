#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void readPatientData(Patient*);
void displayAtRiskPatients(Patient*, string, int);
void writePatientReport(Patient*, int);

int main()
{
    Patient patArr[100];

    readPatientData(patArr);
    cout << "The underweight patients: " << endl;
    displayAtRiskPatients(patArr, "Underweight", 17);
    cout << "The overweight patients: " << endl;
    displayAtRiskPatients(patArr, "Overweight", 17);
    cout << "The obese patients: " << endl;
    displayAtRiskPatients(patArr, "Obese", 17);
    writePatientReport(patArr, 17);
    return 0;
}

void readPatientData(Patient* patArr)
{
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
    for (int i = 0; i < 17; i++)
    {
        fin >> age;
        patArr[i].setAge(age);
        fin >> height;
        patArr[i].setHeight(height);
        fin >> weight;
        patArr[i].setWeight(weight);
        fin.ignore(); //Skips over space character
        getline(fin, name);
        patArr[i].setName(name);
    }
    fin.close();
}

void writePatientReport(Patient* patArr, int size)
{
    ofstream fout;
    string name;

    fout.open("patientReport.txt");
    if (fout.fail())
    {
        cerr << "Output file cannot be opened at this time" << endl;
        exit(EXIT_FAILURE);
    }
    fout << "Weight Status Report\n"
    << "==================== === ====== ====== =============\n"
    << "Name " << setw(40) << "Age Height Weight Status" << "\n"
    << "==================== === ====== ====== =============" << endl;
    for (int i = 0; i < size; i++)
    {
        fout << setw(22) << left << patArr[i].getName()
        << setw(5) << patArr[i].getAge() << setw(7) << patArr[i].getHeight()
        << setw(5) << patArr[i].getWeight() << " " << patArr[i].weightStatus()
        << endl;
    }
    fout << "==================== === ====== ====== =============" << endl;
    fout << "Number of patients: " << size << endl;
    fout.close();
}

void displayAtRiskPatients(Patient* patArr, string w_status, int size)
{
    for (int i = 0; i < size; i++)
        if (patArr[i].weightStatus() == w_status)
            cout << patArr[i].getName() << endl;
    cout << endl;
}