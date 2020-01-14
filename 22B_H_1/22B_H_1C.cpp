/***
 22B - PROGRAM 1C: Search a Sorted List of Strings
 BINARY SEARCH
 
 
 Written by: Jonathan Lagos
 IDE: None (Linux, VScode as editor)
 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// Function prototypes
void	printIntro(void);
void	parseDictionary(string englishWords[], string hawaiianWords[], int &size, const int MAX_SIZE);
int		binarySearch(const string englishWords[], int numElems, string target);
void 	insertionSort(string savedSearches[], int countedSearches[], int size);
void	search_results(string option, string searched_w = "default");

int main()
{
    const int SIZE = 128;
	//const int NO_STUDENTS = 55;  // maximum size of arrays

    string englishWords[SIZE];
    string hawaiianWords[SIZE];
	string word;
	char ret;
	int	size = 0, idx;

	printIntro();

    parseDictionary(englishWords, hawaiianWords, size, SIZE);
	do
	{
		cout << "Please enter a word in English: ";
		cin >> word;
		if ((idx = binarySearch(englishWords, size, word)) != -1)
		{
			cout << "\"" << englishWords[idx] << "\" in Hawaiian is "
			<< "\"" << hawaiianWords[idx]  << "\"" << endl;
			search_results("save", englishWords[idx] + " " + hawaiianWords[idx]);
		}
		else
		{
			cout << "Sorry, we do not have \"" << word 
			<< "\" in our dictionary.\n";
		}
		cout << "\nDo you want to search again? (y/n): ";
		cin >> ret;
	}while (ret == 'y' || ret == 'Y');

	cout << "Your search history has been saved into an output file named \"results.txt\".\n";
	search_results("write");
    return 0;
}

/***************************************************
 Welcome message to program
 */
void printIntro(void)
{
	cout << "Welina!\nWelcome!\n"
	<< "This program translates English Words to Hawaiian.\n\n";
}

/***************************************************
 This function reads through an input file that should contain a list of English words
 with its translated Hawaiian word on the same line seperated by a space character, storing 
 both words to their respective string arrays (parallel arrays)
 */
void parseDictionary(string englishWords[], string hawaiianWords[], int &size, const int MAX_SIZE)
{
	ifstream inputFile;
	string inputfileName;
	int idx = 0;

	cout << "What is the input file's name?" << endl;
	cin >> inputfileName;

	cout << endl;
	inputFile.open(inputfileName.c_str());
	if (inputFile.fail())
    {
        cerr << "Please check the name of the input file and try again\n";
        exit(EXIT_FAILURE);
    }
	while (idx < MAX_SIZE && inputFile >> englishWords[idx] >> hawaiianWords[idx])
		idx++;
	size = idx;
	if (size == MAX_SIZE)
	{
		cout << "The input file contains more than " << size
		<< " lines!\n";
		exit(EXIT_FAILURE);
	}
	inputFile.close();
}

/***************************************************
 This function is from pg.468 (Program 8-3) from textbook
 */
int binarySearch(const string englishWords[], int numElems, string target)
{
	int first = 0,		 // First array element
    last = numElems - 1, // Last array element
    middle,				 // Midpoint of search
    position = -1;		 // Position of search value
    // Assume not found

    while (-1 == position && first <= last)
    {
        middle = (first + last) / 2;  // Calculate midpoint
        if (englishWords[middle] == target)	  // If value is found at mid
        {
            position = middle;
        }
        else if (englishWords[middle] > target) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;			// If value is in upper half
    }
    return position;
}

/***************************************************
 This function sorts an array in ascending order
 using the Insertion Sort algorithm
 I got this function from HW0, with minor changes
 */
void insertionSort(string savedSearches[], int countedSearches[], int size)
{
    string temp_s;
	int	temp_i;
    int curr;
    int walk;

    for (curr = 1; curr < size; curr++)
    {
        // make a copy of the current element
        temp_s = savedSearches[curr];
		temp_i = countedSearches[curr];

        // shift elements in the sorted part of the list to make room
        walk = curr - 1;
        while (walk >= 0 && temp_s < savedSearches[walk])
        {
            savedSearches[walk + 1] = savedSearches[walk];
			countedSearches[walk + 1] = countedSearches[walk];
            walk--;
        }

        // put the copy of the current element back into the list
        savedSearches[walk + 1] = temp_s;
		countedSearches[walk + 1] = temp_i;
    }// end of for: move to the next element to be inserted
}

/***************************************************
 * This function serves two purposes depending on what option is passed as an argument
 * For "save" option:
 * 		-Function is called in succession
 * 		-Parameter string "searched_w" is an concatenation of an English word and its translated
 * 		Hawaiian word, seperated by space character (" ") inbetween
 * 		-Saves each word that was searched by the user (in savedSearches[])
 * 		-Tracks the number of times each word was searched (in countedSearches[])
 * For "write" option:
 * 		-First it sorts both savedSearches[] and countedSearches in ascending order respectively
 * 		-Then writes to output file named "results.txt" 
 */
void	search_results(string option, string searched_w)
{
	static string	savedSearches[128];
	static int		countedSearches[128];
	static int		nbrSavedSearches; //the current number of saved searched words
	int	i;

	if (option == "save")
	{
		for (i = 0; i < nbrSavedSearches; i++)
		{
			if (savedSearches[i] == searched_w)
			{
				countedSearches[i]++;
				break ;
			}
		}
		if (i == nbrSavedSearches)
		{
			savedSearches[i] = searched_w;
			countedSearches[i]++;
			nbrSavedSearches++;
		}
	}
	else if (option == "write")
	{
		ofstream outputFile;

		outputFile.open("results.txt");
		if (outputFile.fail())
		{
			cerr << "Please check the name of the output file and try again\n";
			exit(EXIT_FAILURE);
		}
		insertionSort(savedSearches, countedSearches, nbrSavedSearches);
		for (int k = 0; k < nbrSavedSearches; k++)
		{
			outputFile << countedSearches[k] << " "
			<< savedSearches[k] << endl;
		}
		outputFile.close();
	}
}


/****************** OUTPUT ******************
1 father makuakane
2 triggerfish humuhumunukunukuapua'a
9 wave nanea

 */
