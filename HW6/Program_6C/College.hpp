// Specification file for the College class
// Written By: Jonathan Lagos
// IDE: None (Linux/VS Code)

#ifndef COLLEGE_H
#define COLLEGE_H

class College
{
private:
    std::string code;
    std::string name;
    int rank;
    int cost;

public:
    College() {code = ""; name = ""; rank = -1; cost = -1;} // Constructor
    //College() overloaded constructor

    //Setters
    void setCode(std::string c) {code = c;}
    void setName(std::string n) {name = n;}
    void setRank(int r) {rank = r;}
    void setCost(int co){cost = co;}
    //Getters
    std::string getCode() const {return code;}
    std::string getName() const {return name;}
    int getRank() const {return rank;}
    int getCost() const {return cost;}
    //Other functions
    void hDdisplay();
    void vDisplay();
    
};
#endif
