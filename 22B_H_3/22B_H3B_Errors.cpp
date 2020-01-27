/**
 CIS 22B: Homework 3B

 This program uses dynamic allocation of memory to create a
 copy of an array.

 It might compile; if it does, it should give a warning. If you run it, it will crash.
 Find and fix the errors. Write comments to explain the errors. Run the program and save
 the output as a comment at the end of the source file.
                                                    Hint: There are THREE logical errors.
NAME: Jonathan Lagos
 IDE: None (Linux/VS Code)
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
//Solution A
void createCopy ( double *pFirst, double *pLast, double *&newList );
//Solution B
double *createCopy( double *pFirst, double *pLast);
//Solution C: Multiple indirection example
void createCopy ( double *pFirst, double *pLast, double **newList );

void printList ( double *pFirst, double *pLast );

int main()
{
    int     size = 5;
    double  ary[100] = { 2.1, 3.5, 8.7, 1.9, 5.6 };
    double  *list; // will point to a replica of ary

    createCopy ( ary, ary + size - 1, list );
    //ary + size - 1 is the address of the last element in ary
    printList ( ary, ary + size - 1 );    // print the original array
    printList ( list, list + size - 1 );  // print its copy

    delete [] list; // release memory
    //delete [] ary; //Error #1

    return 0;
}

/***************************************************************
 This function prints an array
 PRE: pFirst - pointer to the first element
 pLast - pointer to the last element
 POST: list printed
 ****************************************************************/
void printList ( double *pFirst, double *pLast )
{
    double *pWalk;

    cout << setprecision(2) << fixed;
    for( pWalk = pFirst; pWalk <= pLast; pWalk++ )
    {
        cout <<  *pWalk << " ";
    }
    cout << endl;

    return;
}

/***************************************************************
 This function creates a copy of an array
 PRE: pFirst - pointer to the first element
 pLast - pointer to the last element
 POST: list copied to newList
 ****************************************************************/
void createCopy ( double *pFirst, double *pLast, double *&newList )
{
    double *pwSource;
    double *pwDest;

    newList = new double[pLast - pFirst + 1]; // allocate memory for the new array
    //cout << "DEBUG size = " << pLast - pFirst << endl;
    for( pwSource = pFirst, pwDest = newList; pwSource <= pLast; pwSource++, pwDest++ )
    {
        *pwDest = *pwSource;
        //cout << "DEBUG " << *pwDest << endl; // DEBUG
    }

    return;
}
/***************************************************************
  Save the OUTPUT below


*/

