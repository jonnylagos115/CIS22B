/*
 CIS 22B: Homework 6C
 
 Build and process a sorted linked list of College objects.
 The list is sorted in ascending order by the college code.
 Assume that the college code is unique.
 
 Written by: Jonathan Lagos
 IDE: None (Linux/VS Code)
 
 */
#include <iostream>
#include <fstream>
#include "LinkedList.hpp"
using namespace std;

void buildList(string filename, LinkedList &list);
void deleteManager(LinkedList &list);
void searchManager(LinkedList &list);

int main()
{
    const char inputFileName[] = "colleges.txt";
    LinkedList list;

    buildList(inputFileName, list);
    list.displayList();
    searchManager(list);
    cout << "Number of nodes: " << list.getCount();
    deleteManager(list);
    list.displayList();
    cout << "Number of nodes: " << list.getCount();
    
    return 0;
}

/*****************************************************************************
 This function reads data from a given file and inserts them
 into a sorted linked list.
 *****************************************************************************/
void buildList(string filename, LinkedList &list)
{
    ifstream fin;
    College col;
    int rank, cost;
    string code, name;

    fin.open(filename.c_str());
    if (fin.fail())
    {
        cerr << "Input file cannot be opened at this time" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; !fin.eof(); i++)
    {
        fin >> rank;
        fin >> code;
        fin.ignore(); //Skips over space character before college name
        getline(fin, name, ';');
        fin >> cost;
        col.setRank(rank);
        col.setCode(code);
        col.setName(name);
        col.setCost(cost);
        list.insertNode(col);
    }
    fin.close();
    
}

/*****************************************************************************
 Delete manager: delete items from the list until the user enters Q to quit
 deleting
 Input Parameter: list
 *****************************************************************************/
void deleteManager(LinkedList &list)
{
    string targetName = "";
    
    cout << "\n Delete\n";
    cout << "=======\n";
    
    while(targetName != "Q")
    {
        cout << endl << "Enter a college code (or Q to stop deleting) : \n";
        getline(cin, targetName);
        
        if(targetName != "Q")
        {
            if (list.deleteNode(targetName))
            {
                cout << "College with code \"" << targetName
                << "\" has been deleted from this list." << endl;
            }
            else
            {
                cout << "College with code \"" << targetName
                << "\" has not been found in this list." << endl;
            }
        }
    }
    cout << "___________________END DELETE SECTION_____\n";
}

/*****************************************************************************
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 *****************************************************************************/
void searchManager(LinkedList &list)
{
    string targetName = "";
    College col;

    cout << "\n Search\n";
    cout <<   "=======\n";
    
    while(targetName != "Q")
    {
        cout << "\nEnter a college code (or Q to stop searching) : \n";
        getline(cin, targetName);
        
        if(targetName != "Q")
        {
            if (list.searchList(col, targetName))
                col.vDisplay();
            else
            {
                cout << "College with code \"" << targetName 
                << "\" has not been found in this list." << endl;
            }
        }
    }
    cout << "___________________END SEARCH SECTION _____\n";
}



