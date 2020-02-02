/**
 CIS 22B: Homework 3C
 
  Create and sort a ragged table
 
  NAME: Jonathan Lagos
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#ifdef _MSC_VER
#include <crtdbg.h>  // needed to check for memory leaks (Windows only!)
#endif

// Function prototypes
double **readTable(string filename);
void showTable(double **table);
void sortRows(double **table);
void sortTable(double **table);
double ** releaseTable(double **table);

int main()
{
    string filename = "ragged.txt";
    double **table;
    
    table = readTable(filename);
   	showTable(table);
   	sortRows(table);
   	showTable(table);
    sortTable(table);
    showTable(table);
    table = releaseTable(table); // now table should be NULL*/
    
    #ifdef _MSC_VER
        cout << _CrtDumpMemoryLeaks() ? "Memory Leak\n" : "No Memory Leak\n";
    #endif
    
    return 0;
}

/***************************************************
 * Reading from input file to create 2d table with double type values
 * The first column of every row will contain the size value for the row itself
 * Allocates an extra row to insert an NULL (a sentinel value) at the last row
 ****************************************************************/
double **readTable(string filename)
{
	ifstream fin;
	double **table, nbr;
	int	row_size, size;

	fin.open(filename.c_str());
	if (fin.fail())
	{
		cerr << "An error occured in attempting to open file" << endl;
		exit(EXIT_FAILURE);
	}
	fin >> size;
	table = new double*[size + 1];
	row_size = size;
	for (int row = 0; row < row_size; row++)
	{
		fin >> size;
		table[row] = new double[size + 1];
		table[row][0] = size;
		for (int col = 1; col <= size; col++)
		{
			fin >> nbr;
			table[row][col] = nbr;
		}
	}
	table[row_size] = NULL;
	fin.close();
	return table;
}

void showTable(double **table)
{
	for (int row = 0; table[row] != NULL; row++)
	{
		for (int col = 0; col <= table[row][0]; col++)
			cout << table[row][col] << " ";
		cout << endl;
	}
	cout << endl;
}

void sortRows(double **table)
{
	int col, back;
	double key;
	for (int row = 0; table[row] != NULL; row++)
    {
    	for (col = 2; col <= table[row][0]; col++)
		{
			key = table[row][col];
			back = col - 1;
			while (back >= 1 && table[row][back] < key)
			{
				table[row][back + 1] = table[row][back];
				back--;
			}
			table[row][back + 1] = key;
		}
    }
}

void sortTable(double **table)
{
	int back;
	double *key;
	for (int row = 1; table[row] != NULL; row++)
    {
		key = table[row];
		back = row - 1;
		while (back >= 0 && table[back][0] < key[0])
		{
			table[back + 1] = table[back];
			back--;
		}
		table[back + 1] = key;
	}
}

/***************************************************
 * First frees allocated memory in each row
 * Then frees the 2d array itself and sets the pointer
 * to NULL
 ****************************************************************/
double ** releaseTable(double **table)
{
	for (int row = 0; table[row] != NULL; row++)
		delete [] table[row];
	delete [] table;
	table = NULL;
	return table;
}
/***************************************************************
  Save the OUTPUT below
3 23.9 51.2 35.6 
5 12.2 23.5 54.6 5.8 56.8 
1 88.8 
2 12.1 34.9 
4 23.9 3.7 51.2 35.6 
6 12.2 23.5 888.8 54.6 10.8 56.8 
2 88.8 0.5 
3 12.1 111.5 34.9 
3 3.5 5.1 5.6 
11 1.2 3.5 1.6 0.8 6.2 7.5 2.1 1.2 9 8.9 5.3 
7 99.9 12.2 23.5 888.8 54.6 10.8 56.8 
2 2.9 384.5 
5 25.2 38.4 4.6 125.6 6.3 

3 51.2 35.6 23.9 
5 56.8 54.6 23.5 12.2 5.8 
1 88.8 
2 34.9 12.1 
4 51.2 35.6 23.9 3.7 
6 888.8 56.8 54.6 23.5 12.2 10.8 
2 88.8 0.5 
3 111.5 34.9 12.1 
3 5.6 5.1 3.5 
11 9 8.9 7.5 6.2 5.3 3.5 2.1 1.6 1.2 1.2 0.8 
7 888.8 99.9 56.8 54.6 23.5 12.2 10.8 
2 384.5 2.9 
5 125.6 38.4 25.2 6.3 4.6 

11 9 8.9 7.5 6.2 5.3 3.5 2.1 1.6 1.2 1.2 0.8 
7 888.8 99.9 56.8 54.6 23.5 12.2 10.8 
6 888.8 56.8 54.6 23.5 12.2 10.8 
5 56.8 54.6 23.5 12.2 5.8 
5 125.6 38.4 25.2 6.3 4.6 
4 51.2 35.6 23.9 3.7 
3 51.2 35.6 23.9 
3 111.5 34.9 12.1 
3 5.6 5.1 3.5 
2 34.9 12.1 
2 88.8 0.5 
2 384.5 2.9 
1 88.8 
  
*/

