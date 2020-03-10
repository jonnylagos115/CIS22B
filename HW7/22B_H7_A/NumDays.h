// Specification file for the NumDays class
#ifndef NUMDAYS_H
#define NUMDAYS_H

// The NumDays class stores a value that represents a number
// of work hours and convert it to a number of days

class NumDays
{
    private:
        double days;
        int hours;
    public:
        NumDays(int h) {hours = h; days = 0;}
        
        // Mutator functions
        void setHours(int h)
            { hours = h;}
        
        void setDays(double d)
            { days = d;}

        //Accessor functions
        double getDays() const
            { return days;}

        int getHours() const
            {return hours;}
        
        //Overloaded operator functions
        NumDays operator+(const NumDays&); // Overloaded +
        NumDays operator-(const NumDays&); // Overloaded -
        NumDays operator++(); // Prefix ++
        NumDays operator++(int); //Postfix ++
        NumDays operator--(); // Prefix --
        NumDays operator--(int); //Postfix --

};

#endif