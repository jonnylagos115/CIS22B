/**
 CIS 22B: Homework 2B
 2D Arrays
 
 This program calls a function that takes a table of quizzes and calculates
 and stores the average for each student.
 
 
 Find and fix the errors. Run the program and save the output
 as a comment at the end of the program.
 
 NAME: Jonathan Lagos
*/

#include <iostream>

using namespace std;

const int STU = 5;
const int QUIZZES = 10;

void calcStuAvg(int table[][QUIZZES], int nStu, int nQuiz,  double stuAvg[] );

int main( void )
{
    int stu     = 4; //  actual number of students
    int quizzes = 8; //  a total of 8 quizzes
    int table [STU] [QUIZZES] =
    {
        {10,  8,  9, 10,  4,  7, 10,  9},
        {10,  8,  9,  8,  6,  8,  9, 10},
        {10,  8,  9,  8,  9,  8,  8,  9},
        {10,  8,  9, 10,  9,  8, 10, 10},
    };
    double stuAvg[QUIZZES];
    
    calcStuAvg(table, stu, quizzes, stuAvg);
    
    for (int i = 0; i < stu; i++)
        cout << stuAvg[i] << " ";
    cout << endl;
    
    return 0;
}   // main

/*********************************************************************
 This function takes a table of quizzes and calculates and stores the
 average of each quiz
 PRE: - table[][] - has data
      - nStu
      - nQuiz
      - qAvg[] - empty
 POST: qAvg[] - contains the average for each quiz
 */
void calcStuAvg(int table[][QUIZZES], int nQuiz, int nStu, double stuAvg[])
{
    double sum = 0;
    
    for (int r = 0; r < nQuiz; r++)
    {
        for (int c = 0; c < nStu; c++)
        {
            sum += table[r][c];
            stuAvg[r] = sum / static_cast<double>(nStu); 
        }
		sum = 0;
    }
}

/** Save the correct output below
8.375 8.5 8.625 9.25 
*/
