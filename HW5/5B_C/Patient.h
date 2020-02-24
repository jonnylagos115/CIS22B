#ifndef PATIENT_H
#define PATIENT_H

#include <string> //ask about this
//using namespace std; why is it bad practice on .h files
class Patient
{
    private:
        std::string name;
        double height;
        int age, weight;
    public: //Public Interface 
        void setName(std::string);
        void setAge(int);
        void setWeight(int);
        void setHeight(double);
        void display();
        std::string weightStatus();

        std::string getName() const //inline functions
            { return name; }
        
        int getAge() const
            { return age; }

        int getWeight() const
            { return weight; }
        
        double getHeight() const
            { return height; }
        
        
};
#endif