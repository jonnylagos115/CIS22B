/**
 CIS 22B: Homework 4C
 Strings and Structures

 Project: Star Search

 NAME: Jonathan Lagos
 IDE: None (Linux, with VSCode

 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Performer
{
    string name;
    double scores[5];
    double final;
};

// Function prototypes, feel free to change the data return type
void printWelcome(void);
Performer* readPerfData(Performer*, string, int*);
void calculateScore(Performer *perf, int);
void sortFinalScore(Performer *perf, int arrSize);
void insertionSort(double *score, double *lastscore);
void writeFile(Performer *perf, string fileName, int arrSize);
void displayResults(Performer *perf, string fileName, int arrSize);
void printEnd(void);

int main( void )
{
    string inFileName[] = {"performers.txt", "contestants.txt", "test.txt", "testempty.txt", ""};
    int choice = 1, SIZE;  // to stop the program to allow the user to see the results one file at a time
    Performer *perf = nullptr;

    printWelcome();
    for (string *ptr = inFileName; choice == 1 && *ptr != ""; ptr++)
    {
        perf = readPerfData(perf, *ptr, &SIZE);
        if (perf != nullptr)
        {
            calculateScore(perf, SIZE);
            sortFinalScore(perf, SIZE);
            writeFile(perf, *ptr, SIZE);
            displayResults(perf, *ptr, SIZE);
        }
        cout << "Please enter 1 to continue 0 to stop" << endl;
        cin >> choice;
        delete [] perf;
    }
    printEnd();
    return 0;
}
/**********************
Prints welcome in ASCII
 */
void printWelcome(void)
{
    cout << "__          __  _                          _ " << endl;
    cout << "\\ \\        / / | |                        | |" << endl;
    cout << " \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___| |" << endl;
    cout << "  \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ |" << endl;
    cout << "   \\  /\\  /  __/ | (_| (_) | | | | | |  __/_|" << endl;
    cout << "    \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___(_)\n" << endl;
}

/**********************
Parses through input file reading in names and scores, then
its stored in a dynamically allocated array of structs (Performers)
 */
Performer* readPerfData(Performer *perf, string inputFile, int *sizeArr)
{
    ifstream fin;
    string line;
    int size;
    int flag = 0;

    fin.open(inputFile);
    fin >> *sizeArr; //Reading in number of performers, always first line in input file
    if (fin.eof() || inputFile == "") //Invalid if file is empty or if string inputFile is empty
    {
        cerr << "Input file is empty" << endl;
        return nullptr;
    }
    perf = new Performer[*sizeArr]; //allocates the array of structs
    fin.ignore(); //skips over semi-colon ';'
    for (int i = 0; i < *sizeArr; i++)
    {
        getline(fin, line, ';');
        perf[i].name = line;
        getline(fin, line, '\r'); //Window's text file ends each line with "\r\n", may not be the case for other OS
        for (int k = 0; k < 5; k++)
        {
            perf[i].scores[k] = stod(line.substr(0, 4)); //Retrieve substring of score, converts into double data type with stod
            if (k != 4) //No need to update line if last score has been read
                line = line.substr(4);
        }
    }
    fin.close();
    return perf;
}

/**********************
Calculates the average score out of 3 of each performer,
drops the highest and lowest scores
 */
void calculateScore(Performer *perf, int sizeArr)
{
    int numOfP;
    double sum = 0;

    for (int i = 0; i < sizeArr; i++)
    {
        insertionSort(perf[i].scores, perf[i].scores + 4); //Sorted each performers scores to easily drop both lowest and highest scores
        for(int k = 1; k < 4; k++)
            sum += perf[i].scores[k];
        perf[i].final = sum / 3.;
        sum = 0;
    }
}
/**********************
Definition of function insertionSort.
This function performs an ascending order insertion sort on
array.
*/
void insertionSort(double *score, double *lastscore)
{
    for (double *curr = score + 1; curr <= lastscore; curr++)
    {
        double hold = *curr;                       // copy current element to hold
        double *back = curr - 1;
        while (back >= score && hold < *back)   // search where to insert the current element
        {
            *(back + 1) = *back;                // shift to the right
            back--;
        }
        *(back + 1) = hold;                     // put hold back to the array
    }
}
/**********************
This function performs an descending order insertion sort on
the array of structures based on the final scores of each.
arrSize is the number of elements in the array.
*/
void sortFinalScore(Performer *perf, int arrSize)
{
    for (int curr = 1; curr < arrSize; curr++)
    {
        Performer hold = perf[curr];                       // copy current element to hold
        Performer *back = &perf[curr - 1];
        while ((*back).final >= perf[curr - 1].final && hold.final > (*back).final)   // search where to insert the current element
        {
            *(back + 1) = *back;                // shift to the right
            back--;
        }
        *(back + 1) = hold;                     // put hold back to the array
    }
}

/**********************
Writes the sorted array to an output file, in a table format
with the names on the first column followed by the final score
in the second column in descending order (highest to lowest scores)
 */
void writeFile(Performer *perf, string fileName, int arrSize)
{
    ofstream fout;

    fileName = fileName.substr(0, fileName.find_first_of(".")) + "out.txt"; //located '.' position then append with "out.txt"
    fout.open(fileName);
    if (fout.fail())
    {
        cerr << "Error in opening output file" << endl;
        exit(EXIT_FAILURE);
    }
    fout << "+--------------------+-----------------+" << endl;
    fout << "|" << setw(15) << "Performers" << setw(6) << "|" << setw(15) << "Final Scores" << setw(3) << "|" << endl;
    fout << "+--------------------+-----------------+" << endl;;
    for (int i = 0; i < arrSize; i++)
    {
        fout << "|" << setw(16) << perf[i].name << setw(15);
        fout << perf[i].final << setw(8) << "|" << endl;
    }
    fout << "+--------------------+-----------------+" << endl;
    fout.close();
}

/**********************
Displays the winner's name and score
There may be more than one winner if highest scores are tied
 */
void displayResults(Performer *perf, string fn, int arrSize)
{
    int track = 0;

    cout << "The winner(s) with the highest final score of " << perf[0].final <<" is:\n"; //sorted array will have the winner on first element
    for (int i = 0; i < arrSize; i++)
    {
        if (perf[0].final == perf[i].final) //any performers with the same score as the highest score is also an winner
        {
            cout << " " << perf[i].name << endl;
            track++;
        }
    }
    cout << "Congratulations! ";
    if (track == arrSize)
        cout << "Everyone is a winner! ";
    cout << "The final score results of all performers is located in "
    << fn.substr(0, fn.find_first_of(".")) + "out.txt" << endl;
}

/**********************
Prints Goodbye in ASCII
*/
void printEnd(void)
{
    cout << "  _____                 _ _                _ " << endl;
    cout << " / ____|               | | |              | |" << endl;
    cout << "| |  __  ___   ___   __| | |__  _   _  ___| |" << endl;
    cout << "| | |_ |/ _ \\ / _ \\ / _` | '_ \\| | | |/ _ \\ |" << endl;
    cout << "| |__| | (_) | (_) | (_| | |_) | |_| |  __/_|" << endl;
    cout << " \\_____|\\___/ \\___/ \\__,_|_.__/ \\__, |\\___(_)" << endl;
    cout << "                                 __/ |       " << endl;
    cout << "                                |___/        " << endl;
}

/** Save the output below
__          __  _                          _
\ \        / / | |                        | |
 \ \  /\  / /__| | ___ ___  _ __ ___   ___| |
  \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ |
   \  /\  /  __/ | (_| (_) | | | | | |  __/_|
    \/  \/ \___|_|\___\___/|_| |_| |_|\___(_)

The winner(s) with the highest final score of 9.13333 is:
 Ann Peterson
Congratulations! The final score results of all performers is located in performersout.txt
Please enter 1 to continue 0 to stop
1
The winner(s) with the highest final score of 9.6 is:
 Linda Johnson
 James Michael Owen
 Marie Kondo
 Tina Queen
 Jonathan Edwards
Congratulations! The final score results of all performers is located in contestantsout.txt
Please enter 1 to continue 0 to stop
1
The winner(s) with the highest final score of 8.6 is:
 John Lee
 David T. Ng
 Mary Johnson
 Andy V. Garcia
 John Lee
 Ann Peterson
 Dan Nguyen
Congratulations! Everyone is a winner! The final score results of all performers is located in testout.txt
Please enter 1 to continue 0 to stop
1
Input file is empty
Please enter 1 to continue 0 to stop
1
  _____                 _ _                _
 / ____|               | | |              | |
| |  __  ___   ___   __| | |__  _   _  ___| |
| | |_ |/ _ \ / _ \ / _` | '_ \| | | |/ _ \ |
| |__| | (_) | (_) | (_| | |_) | |_| |  __/_|
 \_____|\___/ \___/ \__,_|_.__/ \__, |\___(_)
                                 __/ |
                                |___/

 */
