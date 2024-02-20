#include <bits/stdc++.h>

using namespace std;
template <typename DataType>

/* Class definition for Singly linked list which can have any DataType*/

class Node{
    public: // access modifier

    DataType data; // the data value
    Node* next; // the pointer to the next value
    
    // constructor
    Node (DataType data1, Node* next1=NULL){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
};
/* ================================ Singly Linked List Basic Snippets ============================================*/

void printLL(Node<int>* head) {                  // Time - O(n)
    Node<int>* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int lengthOfLinkedList(Node<int>* head) {       // Time - O(n) and Space - O(1)
    Node<int>* temp = head;
    int counter = 0;
    // Traverse the linked list and count nodes
    while (temp != NULL) {
        temp = temp->next;
        counter++; // increment cnt for every node traversed
    }
    return counter;
}
bool checkifDataPresent(Node<int>* head, int desiredElement) { // Time - O(n) and Space - O(1)
    Node<int>* temp = head;
    // Traverse the linked list
    while (temp != NULL) {
        // Check if the current node's data is equal to the desired element
        if (temp->data == desiredElement)
            return 1;  // Return 1 if the element is found
        // Move to the next node
        temp = temp->next;
    }
    return 0;  // Return 0 if the element is not found in the linked list
}


Node<int>* convertarr2LL(vector<int>& arr){      // Time - O(n) and Space - O(1)
    Node<int>* head = new Node<int>(arr[0]); //creating head 
    Node<int>* mover = head; // temp pointer pointing towards head

    for (int i = 1; i < arr.size(); i++){
        mover->next = new Node<int>(arr[i]); //creating new node and assigning it to mover->next
        mover = mover->next; //moving mover to the next node
    }
    return head;
}

Node<int>* deleteHead(Node<int>* head) {  // Time - O(1) and Space - O(1)
    // Check if the linked list is empty
    if (head == NULL)
        return head;
    // Create a temporary pointer to the current head
    Node<int>* temp = head;
    // Move the head to the next node
    head = head->next;
    // Delete the original head
    delete temp;
    // Return the updated head of the linked list
    return head;
}
Node<int>* deleteTail(Node<int>* head) {     // Time - O(n) and Space - O(1)
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    // Initialize a temporary pointer to traverse the list
    Node<int>* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = NULL;
    // Return the head of the modified list
    return head;
}

Node<int>* deleteAtIndex(Node<int>* head, int index) {  // Time - O(n) and Space - O(1)
    // Check if the list is empty
    // int index starts from 1
    if (head == NULL)
        return head;

    // If k is 1, delete the first node
    if (index == 1) {
        Node<int>* temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    // Traverse the list to find the k-th node
    Node<int>* temp = head;
    Node<int>* prev = NULL;
    int counter = 0;

    while (temp != NULL) {
        counter++;
        // If the k-th node is found
        if (counter == index) {
            // Adjust the pointers to skip the k-th node
            prev->next = prev->next->next;
            // Delete the k-th node
            delete temp;
            break;
        }
        // Move to the next node
        prev = temp;
        temp = temp->next;
    }

    return head;
}


Node<int>* insertHead(Node<int>* head, int val) {         // Time - O(1) and Space - O(1)
    Node<int>* temp = new Node<int>(val, head);
    return temp;
}

Node<int>* insertTail(Node<int>* head, int val) {           // Time - O(n) and Space - O(1)
    if (head == NULL)
        return new Node<int>(val);
    Node<int>* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node<int>* newNode = new Node<int>(val);
    temp->next = newNode;
    return head;
}

Node<int>* insertAtIndex(Node<int>* head, int val, int index) {         // Time - O(n) and Space - O(1)
    // If the linked list is empty and k is 1, insert the new node as the head
    // int index starts from 1
    if (head == NULL) {
        if (index == 1)
            return new Node<int>(val);      
        else
            return head;
    }

    // If k is 1, insert the new node at the beginning of the linked list
    if (index == 1)
        return new Node<int>(val, head);

    int counter = 0;
    Node<int>* temp = head;

    // Traverse the linked list to find the node at position k-1
    while (temp != NULL) {
        counter++;
        if (counter == index - 1) {
            // Insert the new node after the node at position k-1
            Node<int>* newNode = new Node<int>(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}
// Function to insert a new node with data 'el' after the node with data 'val'
Node<int>* insertBeforeNode(Node<int>* head, int newElement, int value) {  // Time - O(n) and Space - O(1)
    if (head == NULL) {
        return NULL;
    }

    // Insert at the beginning if the value matches the head's data
    if (head->data == value)
        return new Node<int>(newElement, head);

    Node<int>* temp = head;
    while (temp->next != NULL) {
        // Insert at the current position if the next node has the desired value
        if (temp->next->data == value) {
            Node<int>* newNode = new Node<int>(newElement, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}


/* ======================== DRIVER CODE ================================*/

signed main(){
    vector<int> list ;   //generate empty list/array
    srand(time(0));     // Use current time as seed for random generator
    for(int i = 0; i < 10; i++) {
        list.push_back((rand() % 201) - 100); // Generate random numbers between -100 and 100
    }
    Node<int>* head =convertarr2LL(list);

    //Length and search
    cout << "Length of Linked List: " << lengthOfLinkedList(head) << '\n';
    cout<<"Memory value of current head: " <<head<<'\n'; // returns the memory value
    cout<<"Data at current head: "<<head->data<<'\n'; // returns the data stored at that memory point 
    cout<< (checkifDataPresent(head,5)? "Yes data is present": "Data is not present")<<'\n';

    //Deletions

    cout<<"Linked List before element removal"<<'\n';
    printLL(head);

    head = deleteHead(head);
    head = deleteTail(head);
    head=deleteAtIndex(head,5);         //remember here 5 is the 5th index at which we have to delete
    
    cout<<"Linked List after element removal"<<'\n'; 
    printLL(head);

    //Insertions

    cout<<"Linked List before element insertion"<<'\n';
    printLL(head);

    head = insertHead(head, 100);
    head=insertTail(head,-100);
    head=insertAtIndex(head,-69,5);  //remember here 5 is the 5th index at which we have to insert
    head = insertBeforeNode(head, 5, -69);  //insert 5 berfore -69 value node

    cout<<"Linked List before element insertion"<<'\n';
    printLL(head);


    //free up space
    delete head;
}

