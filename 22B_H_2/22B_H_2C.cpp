/**
 CIS 22B: Homework 2C
 2D Arrays
 
 Project: Minesweeper Counter
 
 NAME: Jonathan Lagos
 IDE: None (Linux, VSCode for my editor)
 
 */

#include <iostream>
#include <fstream>

using namespace std;

const int MAXGRIDSIZE = 100;  // the maximum table size is 100
//Prototypes
bool	readGrid(string, int[][MAXGRIDSIZE], int&, int&);
void	makeGrid(int[][MAXGRIDSIZE], int, int, int[][MAXGRIDSIZE]);
void	writeScreen(string, int, int, int[][MAXGRIDSIZE], string);
void	writeGrid(string, int[][MAXGRIDSIZE], int, int);

int main( void )
{
    string infileName[] = {"g0.txt", "g1.txt", "abc.txt", "g2.txt", "g3.txt", ""};
    string outfileName[] = {"out0.txt", "out1.txt", "abcOut.txt", "out2.txt", "out3.txt", ""};
    int grid[MAXGRIDSIZE][MAXGRIDSIZE] = {0};       // given grid
    int cntGrid[MAXGRIDSIZE][MAXGRIDSIZE] = {0};    // grid of counters
    int rows;     // number of rows
    int cols;     // number of columns
    int choice = 1;  // to stop the program to allow the user to see the results one table at a time
    bool fileFound;
    
    // test loop: takes the names of the input files from an array of names
    for (int i = 0; choice == 1 && infileName[i] != ""; i++)
    {
        fileFound = readGrid(infileName[i], grid, rows, cols);
        if (fileFound)
        {
            makeGrid(grid, rows, cols, cntGrid);
            writeScreen(infileName[i], rows, cols, cntGrid, outfileName[i]);
            writeGrid(outfileName[i], cntGrid, rows, cols);
        }
        else
        {
            cout << "\"" << infileName[i] << "\" not found!" << endl;
        }
        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
		cout << endl;
    }
    
    return 0;
}

bool	readGrid(string finName, int grid[][MAXGRIDSIZE], int &rows, int &cols)
{
	ifstream fin;

	fin.open(finName.c_str());
	if (fin.fail())
		return false;
	fin >> rows >> cols;
	for (int r = 0; r <= rows + 1; r++)
	{
		for (int c = 0; c <= cols + 1; c++)
		{
			if (r == 0 || r == rows + 1 || c == 0 || c == cols + 1)
				grid[r][c] = 0;
			else
				fin >> grid[r][c];
		}
	}
	fin.close();
	return true;
}

void	makeGrid(int grid[][MAXGRIDSIZE], int rows, int cols, int cntGrid[][MAXGRIDSIZE])
{
	for (int r = 1; r <= rows; r++)
	{
		for (int c = 1; c <= cols; c++)
		{
			if (grid[r][c] == 1) //Current spot
				cntGrid[r - 1][c - 1]++;
			if (grid[r][c - 1] == 1) //Left
				cntGrid[r - 1][c - 1]++; 
			if (grid[r][c + 1] == 1) //Right
				cntGrid[r - 1][c - 1]++;
			if (grid[r + 1][c] == 1) //Bottom
				cntGrid[r - 1][c - 1]++;
			if (grid[r - 1][c] == 1) //Up
				cntGrid[r - 1][c - 1]++;
			if (grid[r - 1][c - 1] == 1) //Up left
				cntGrid[r - 1][c - 1]++;
			if (grid[r - 1][c + 1] == 1) //Up right
				cntGrid[r - 1][c - 1]++;
			if (grid[r + 1][c - 1]) //Bottom left
				cntGrid[r - 1][c - 1]++;
			if (grid[r + 1][c + 1]) //Bottom right
				cntGrid[r - 1][c - 1]++;
		}
	}
}

void	writeScreen(string finName, int rows, int cols, int cntGrid[][MAXGRIDSIZE], string foutName)
{
	cout << "Input file name: \"" << finName << "\""
	<< "\nGrid size: " << rows << " x " << cols
	<< "\nCorners: " << cntGrid[0][0] << ", " << cntGrid[0][cols - 1]
	<< ", " << cntGrid[rows - 1][cols - 1] << ", " << cntGrid[rows - 1][0]
	<< "\nOutput file name: \"" << foutName << "\"" << endl;
}

void	writeGrid(string foutName, int cntGrid[][MAXGRIDSIZE], int rows, int cols)
{
	ofstream fout;

	fout.open(foutName.c_str());
	if (fout.fail())
	{
		cerr << "An issue occured in attempting to open output file" << endl;
		exit(EXIT_FAILURE);
	}
	fout << rows << " " << cols << endl;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			fout << cntGrid[r][c];
			cntGrid[r][c] = 0; //Resetting current location to 0
			if (c != cols - 1)
				fout << " ";
		}
		fout << endl;
	}
	fout.close();
}

/** Save the output below
Input file name: "g0.txt"
Grid size: 3 x 5
Corners: 1, 2, 3, 0
Output file name: "out0.txt"
Please enter 1 to continue 0 to stop
1

Input file name: "g1.txt"
Grid size: 6 x 5
Corners: 1, 0, 2, 0
Output file name: "out1.txt"
Please enter 1 to continue 0 to stop
1

"abc.txt" not found!
Please enter 1 to continue 0 to stop
1

Input file name: "g2.txt"
Grid size: 5 x 4
Corners: 4, 4, 4, 4
Output file name: "out2.txt"
Please enter 1 to continue 0 to stop
1

Input file name: "g3.txt"
Grid size: 15 x 10
Corners: 1, 2, 1, 1
Output file name: "out3.txt"
Please enter 1 to continue 0 to stop
1

 */
