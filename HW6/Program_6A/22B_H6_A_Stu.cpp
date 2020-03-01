/*
 CIS 22B: Homework 6A // Student is a struct
 
 This program demonstrates the insertNode, deleteNode, getCount(), and displayList member functions.
 It builds and displays a sorted list
 The list is sorted by gpa
 
 Write a function that displays students with gpa <= a given gpa as show below
 
 list.displayList(3.0);  //<===== see line# 61
 
 
 Run the program once and save the output as a comment at the end of this source file.
 
 Modified by: Jonathan Lagos
 IDE: None (Linux/VS Code)
 
 */
#include <iostream>
#include "StudentList.h"
using namespace std;

int main()
{
    // Define a StudentList object.
    StudentList list;
    Student s1 = {3.1, "Paul"};
    Student s[10] =
    {{2.5, "John"}, {3.9, "Linda"}, {3.6, "Bob"}, {2.7, "Ann"}, {4.0, "Mary"}, {3.2, "Andy"}};
    Student s2 = {2.3, "Tom"};
    
    //******************************
    cout << "TESTING INSERT\n\n";
    //Insert one value to the list.
    cout << "\tInsert " << s1.gpa << " " << s1.name << endl;
    list.insertNode(s1);
    // Display the values in the list.
    list.displayList();
    cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    
    //Insert more values to the list
    for (int i = 0; i < 6; i++)
    {
        cout << "\tInsert " << s[i].gpa << " " << s[i].name << endl;
        list.insertNode(s[i]);
        // Display the values in the list.
        list.displayList();
        cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    }
    
    //Insert one value to the list.
    cout << "\tInsert " << s2.gpa << " " << s2.name << endl;
    list.insertNode(s2);
    list.displayList();
    int n = list.getCount();
    cout << "\t\tThis list has " << n << " student[s]\n\n";
    
    //******************************
    cout << "TESTING DISPLAY\n\n";
    list.displayList();
    list.displayList(3.0);  //<====================================
    
    //******************************
    cout << "TESTING DELETE\n\n";
    // Delete the first node
    cout << "\tDelete the first node\n";
    list.deleteNode(2.3);
    list.displayList();
    
    // Delete the last node
    cout << "\tDelete the last node\n";
    list.deleteNode(4.0);
    list.displayList();
    
    // Delete a node in the middle
    cout << "\tDelete 3.1\n";
    if( list.deleteNode(3.1) )
        cout << "Deleted\n";
    else
        cout << "Target (3.1) not found\n";
    list.displayList();
    
    // Try to delete an item not in the list
    cout << "\tTry to delete 3.0\n";
    if( list.deleteNode(3.0) )
        cout << "Deleted\n";
    else
        cout << "Target (3.0) not found\n";
    list.displayList();
    
    cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    
    return 0;
}
/***************************************************************
 Save the OUTPUT below
TESTING INSERT

	Insert 3.1 Paul
3.1 Paul

		This list has 1 student[s]

	Insert 2.5 John
2.5 John
3.1 Paul

		This list has 2 student[s]

	Insert 3.9 Linda
2.5 John
3.1 Paul
3.9 Linda

		This list has 3 student[s]

	Insert 3.6 Bob
2.5 John
3.1 Paul
3.6 Bob
3.9 Linda

		This list has 4 student[s]

	Insert 2.7 Ann
2.5 John
2.7 Ann
3.1 Paul
3.6 Bob
3.9 Linda

		This list has 5 student[s]

	Insert 4 Mary
2.5 John
2.7 Ann
3.1 Paul
3.6 Bob
3.9 Linda
4 Mary

		This list has 6 student[s]

	Insert 3.2 Andy
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda
4 Mary

		This list has 7 student[s]

	Insert 2.3 Tom
2.3 Tom
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda
4 Mary

		This list has 8 student[s]

TESTING DISPLAY

2.3 Tom
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda
4 Mary

Students with gpa less than or equal to 3
2.3 Tom
2.5 John
2.7 Ann

TESTING DELETE

	Delete the first node
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda
4 Mary

	Delete the last node
2.5 John
2.7 Ann
3.1 Paul
3.2 Andy
3.6 Bob
3.9 Linda

	Delete 3.1
Deleted
2.5 John
2.7 Ann
3.2 Andy
3.6 Bob
3.9 Linda

	Try to delete 3.0
Target (3.0) not found
2.5 John
2.7 Ann
3.2 Andy
3.6 Bob
3.9 Linda

		This list has 5 student[s]

DEBUG - Destructor: Now deleting John
DEBUG - Destructor: Now deleting Ann
DEBUG - Destructor: Now deleting Andy
DEBUG - Destructor: Now deleting Bob
DEBUG - Destructor: Now deleting Linda
DEBUG - Destructor: Now deleting the sentinel node gpa = -1
 
 */
