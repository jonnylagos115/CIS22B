/**
 CIS 22B: Homework 4A
 Using c-string manipulation functions: strcpy, strcat, strrchr, etc.

 Write a function that given a c-string of words removes the last word and inserts
 it in the beginning of the string. All words are separated by spaces.
 You may assume that there is only one space between two words.
 Strings that are either empty or consists of only one word will not be changed.
 // HINT: Use a temp string

 Example: 	  	 "Two Three Four Five One"
 After processing: "One Two Three Four Five"

 Save the output as a comment at the end of the program.

 NAME: Jonathan Lagos
 ============================================================================================= */
#include <iostream>
#include <cstring>
using namespace std;


bool moveFront( char s[] );

int main( void )
{
    char sList[5][100] = {"One Two Three Four Five Zero", "", "Three Two One Four", "Second First", "Done!"};
    bool change;

    // test the function with 5 strings
    for (int i = 0; i < 5; i++)
    {
        cout << "Before: [" << sList[i] << "]\n";
        change = moveFront(sList[i]);
        cout << " After: [" << sList[i] << "]\n";
        if (!change)
            cout << "\t\t The string is either empty or it has only one word!";
        cout << endl;
    }
    return 0;
}

/* ============================================= */
bool moveFront( char s[] ) //No for-loops, only call C-string functions
{
    bool success = false;
    char temp[100];
    int i = strlen(s) - 1;
    int len;

    if (strchr(s, ' ') != NULL) //checks if string is either empty or contains only one word
    {
        strcpy(temp, strrchr(s, ' ') + 1); //Copy last word into string temp
        len = strlen(temp); //Finds the length of last word, then uses this to access last char
        temp[len] = ' '; //Replaces null byte with a space char
        temp[len + 1] = '\0'; //Puts an null byte ahead of the space char
        while (s[i] != ' ') //locates pos of the first space char
            i--;
        s[i] = '\0'; //Inserts the null byte in that position
        strcat(temp, s); //Concatenates string s at the end of string temp
        strcpy(s, temp); //Copies string temp to string s so the changes are made once returning to main()
        success = true;
    }
    else
        success = false;
    return success;
}
/***************************************************************
 Save the OUTPUT below
Before: [One Two Three Four Five Zero]
 After: [Zero One Two Three Four Five]

Before: []
 After: []
                 The string is either empty or it has only one word!
Before: [Three Two One Four]
 After: [Four Three Two One]

Before: [Second First]
 After: [First Second]

Before: [Done!]
 After: [Done!]
                 The string is either empty or it has only one word!

 */
