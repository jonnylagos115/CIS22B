// Implementation file for the LinkedList class
// Written By: Jonathan Lagos
// IDE: None (Linux/VS Code)

#include <iostream>         // For cout  and NULL
#include "LinkedList.hpp"
using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
LinkedList::LinkedList()
{
    head = new ListNode;
    head->next = NULL;
    count = 0;
}

//**************************************************
// The insertNode function inserts a node with
// stu copied to its value member.
//**************************************************
void LinkedList::insertNode(College dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node
    
    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->col = dataIn;
    
    // Initialize pointers
    pPre = head;
    pCur = head->next;
    // Find location: skip all nodes whose college code is less than pCur's college code
    while (pCur != NULL && pCur->col.getCode() < newNode->col.getCode())
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode->next = pCur;
    
    // Update the counter
    count++;
}

//**************************************************
// The deleteNode function searches for a node
// with num as its value. The node, if found, is
// deleted from the list and from memory.
//**************************************************
bool LinkedList::deleteNode(std::string target)
{
    ListNode *pCur;       // To traverse the list
    ListNode *pPre;        // To point to the previous node
    bool deleted = false;
    
    // Initialize pointers
    pPre = head;
    pCur = head->next;
    while (pCur != NULL && pCur->col.getCode() != target)
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // If found, delete the node
    if (pCur != NULL)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        count--;
    }
    return deleted;
    
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.
//**************************************************
void LinkedList::displayList() const
{
    ListNode *pCur;  // To move through the list
    
    // Position pCur: skip the head of the list.
    pCur = head->next;
    
    // While pCur points to a node, traverse the list.
    while (pCur)
    {
        // Display the value in this node.
        cout << pCur->col.getRank() << " " << pCur->col.getCode() << " "
        << pCur->col.getName() << " " << pCur->col.getCost() << endl;
        
        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}

//***********************f***************************
// searchList traverses through the linked list
// attempting locate node by it's college code
//**************************************************
bool LinkedList::searchList(College &col, std::string target) const
{
    ListNode *pCur; //To move through the list
    bool ret = false;

    pCur = head->next;
    while (pCur && pCur->col.getCode() != target)
        pCur = pCur->next;
    if (pCur)
    {
        col = pCur->col;
        ret = true;
    }
    return (ret);
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
LinkedList::~LinkedList()
{
    ListNode *pCur;   // To traverse the list
    ListNode *pNext;  // To point to the next node
    
    // Position nodePtr at the head of the list.
    pCur = head->next;
    
    // While pCur is not at the end of the list...
    while (pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;
        
        // Delete the current node.
        cout << "DEBUG - Destructor: Now deleting " << pCur->col.getCode() << endl;
        delete pCur;
        
        // Position pCur at the next node.
        pCur = pNext;
    }
    cout << "DEBUG - Destructor: Now deleting the sentinel node code = " << head->col.getCode() << endl;
    delete head; // delete the sentinel node
}