/**
 CIS 22B: Homework 2A
 2D Arrays

 This program prints a 2D array as a table, one column per line.
 It compiles and runs, but it provides an unexpected output.

 Find and fix the errors. Run the program and save the output
 as a comment at the end of the program.

 NAME: Jonathan Lagos
*/

#include <iostream>

using namespace std;

const int ROWS = 10;  // maximum number of rows
const int COLS = 5;   // maximum number of columns

int main (void)
{
    int table [ROWS] [COLS] =
    {
        {111, 90, 50, 60, 20},
        {222, 15, 25, 45, 35},
        {333, 49, 89, 29, 59},
        {444, 82, 92, 52, 22}
       };

    int n_rows = 4; // actual number of rows
    int n_cols = 5; // actual number of columns

    // print the table one column at a time
    for (int c = 0; c < n_cols; c++)
    {
        for (int r = 0; r < n_rows; r++)
        {
            cout << table[r][c] << " ";
        }
         cout  << endl;
    }

    return 0;
}

/** Save the correct output below
111 222 333 444 
90 15 49 82 
50 25 89 92 
60 45 29 52 
20 35 59 22 
*/
