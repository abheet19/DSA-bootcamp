#include <bits/stdc++.h>

using namespace std;
template <typename DataType>

/* Class definition for Doubly linked list which can have any DataType*/


class Node{
    public: // access modifier

    DataType data; // the data value
    Node* next; // Pointer to the next node in the list (forward direction)
    Node* back; //Pointer to the previous node in the list (backward direction)

    
    // constructor
    Node (DataType newData, Node* newNext=NULL,Node* newBack=NULL){
        this->data=newData;  // Initialize data with the provided newData
        this->next=newNext;  // Initialize next with the provided newNext
        this->back=newBack;  // Initialize back with the provided newBack
    }
};