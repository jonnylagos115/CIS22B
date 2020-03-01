// Specification file for the LinkedList class
// Written By: Jonathan Lagos
// IDE: None (Linux/VS Code)

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "College.hpp"

class LinkedList
{
private:
    //Declare a structure for the list
    struct ListNode
    {
        College col;
        ListNode *next;
    };
    ListNode *head;
    int count;


public:
    LinkedList(); //Constructor
    ~LinkedList(); //Destructor

    int getCount() const {return count;}
    int getCount() const {return count;}
    void insertNode(College);
    bool deleteNode(string);
    void displayList() const;
    void searchList() const;
};
#endif
