#include <bits/stdc++.h>

using namespace std;
template <typename DataType>

/* Class definition for Doubly linked list which can have any DataType*/

class Node
{
public:            // access modifier
    DataType data; // the data value
    Node *next;    // Pointer to the next node in the list (forward direction)
    Node *back;    // Pointer to the previous node in the list (backward direction)

    // constructor
    Node(DataType newData, Node *newNext = NULL, Node *newBack = NULL)
    {
        this->data = newData; // Initialize data with the provided newData
        this->next = newNext; // Initialize next with the provided newNext
        this->back = newBack; // Initialize back with the provided newBack
    }
};
template <typename DataType>

class DoublyLinkedList
{
private:
    Node<DataType> *head;

public:
    DoublyLinkedList() : head(nullptr)
    {
    }

    /* ================================ Doubly Linked List Basic Snippets ============================================*/

    // Member functions

    Node<DataType> *getHead() const
    {
        return head;
    }

    Node<DataType> *convertArr2DLL(vector<DataType> &arr)
    {
        // Create the head node with the first element of the array
        head = new Node<DataType>(arr[0]);
        // Initialize 'prev' to the head node

        Node<DataType> *prev = head;
        for (size_t i = 1; i < arr.size(); i++)
        {
            // Create a new node with data from the array and set its 'back' pointer to the previous node
            Node<DataType> *temp = new Node<DataType>(arr[i], NULL, prev);
            // Update the 'next' pointer of the previous node to point to the new node

            prev->next = temp;
            // Move 'prev' to the newly created node for the next iteration

            prev = temp;
        }
        // Return the head of the doubly linked list

        return head;
    }

    // Function to print the elements of the doubly linked list
    void printLL()
    { // Time - O(n) and Space - O(1)
        Node<DataType> *temp = head;
        while (temp != NULL)
        {
            // Print the data in the current node
            cout << temp->data << " <-> ";
            // Move to the next node
            temp = temp->next;
        }
        cout << "NULL"
             << "\n";
    }

    int lengthOfLinkedList()
    { // Time - O(n) and Space - O(1)
        Node<DataType> *temp = head;
        int counter = 0;
        // Traverse the linked list and count nodes
        while (temp != NULL)
        {
            temp = temp->next;
            counter++; // increment cnt for every node traversed
        }
        return counter;
    }

    bool checkifDataPresent(DataType desiredElement)
    { // Time - O(n) and Space - O(1)
        Node<DataType> *temp = head;
        // Traverse the linked list
        while (temp != NULL)
        {
            // Check if the current node's data is equal to the desired element
            if (temp->data == desiredElement)
                return 1; // Return 1 if the element is found
            // Move to the next node
            temp = temp->next;
        }
        return 0; // Return 0 if the element is not found in the linked list
    }

    Node<DataType> *deleteHead()
    { // Time - O(1) and Space - O(1)
        if (head == NULL || head->next == NULL)
        {
            // Return NULL if the list is empty or contains only one element
            return NULL;
        }
        // Store the current head as 'prev'
        Node<DataType> *prev = head;
        // Move 'head' to the next node
        head = head->next;

        // Set 'back' pointer of the new head to nullptr
        head->back = NULL;

        // Set 'next' pointer of 'prev' to nullptr
        prev->next = NULL;

        // Return the new head
        return head;
    }
    Node<DataType> *deleteTail()
    { // Time - O(n) and Space - O(1)
        if (head == NULL || head->next == NULL)
        {
            // If the list is empty or has only one node, return null
            return NULL;
        }
        Node<DataType> *tail = head;
        while (tail->next != NULL)
        {
            // Traverse to the last node (tail)
            tail = tail->next;
        }

        Node<DataType> *newTail = tail->back;
        newTail->next = NULL;
        tail->back = NULL;

        // Free memory of the deleted node
        delete tail;

        return head;
    }
    // Time - O(n) and Space - O(1) Note : if node is known at index then time is o(1)
    Node<DataType> *deleteAtIndex(int index)
    {
        if (head == NULL)
        {
            return NULL; // If the list is empty or has only one node, return null
        }
        int counter = 0;
        Node<DataType> *temp = head;

        // Traverse the list to find the k-th node
        while (temp != NULL)
        {
            counter++;
            if (counter == index)
            {
                break;
            }
            temp = temp->next;
        }
        // now temp is at the kth node

        Node<DataType> *prev = temp->back;
        Node<DataType> *front = temp->next;

        if (prev == NULL && front == NULL)
        { // if list has 1 element only
            delete temp;
            return NULL;
        }
        else if (prev == NULL)
        { // temp is at the head , so call deletehead()
            return deleteHead();
        }
        else if (front == NULL)
        {
            return deleteTail(); // temp is at the head , so call deleteTail()
        }

        prev->next = front; // connect k-1 node to k+1 node forward
        front->back = prev; // connect k+1 node to k-1 node backward

        // Delete connections for k-th node
        temp->next = NULL;
        temp->back = NULL;
        // Delete the k-th node
        delete temp;

        return head;
    }

    void deleteNode(Node<DataType> *temp)
    {
        // Time - O(1) and Space - O(1)

        Node<DataType> *prev = temp->back;
        Node<DataType> *front = temp->next;
        // edge case if temp is the tail node
        if (front == NULL)
        {
            prev->next = NULL;
            temp->back = NULL;
            delete (temp);
            return;
        }
        // Disconnect temp from the doubly linked list
        prev->next = front;
        front->back = prev;

        // Set temp's pointers to NULL
        temp->next = NULL;
        temp->back = NULL;

        // Free memory of the deleted node
        delete (temp);
        return;
    }
    Node<DataType> *insertBeforeHead(DataType val)
    {
        // Time - O(1) and Space - O(1)

        // Create new node with data as val
        Node<DataType> *newHead = new Node<DataType>(val, head, NULL);
        head->back = newHead;

        return newHead;
    }
    Node<DataType> *insertBeforeTail(DataType val)
    {
        // Time - O(n) and Space - O(1)

        // Edge case, if dll has only one elements
        if (head->next == NULL)
        {
            // If only one element
            return insertBeforeHead(val);
        }

        // Create pointer tail to traverse to the end of list
        Node<DataType> *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        // Keep track of node before tail using prev
        Node<DataType> *prev = tail->back;

        // Create new node with value val
        Node<DataType> *newNode = new Node<DataType>(val, tail, prev);

        // Join the new node into the doubly linked list
        prev->next = newNode;
        tail->back = newNode;

        // Return the updated linked list
        return head;
    }

    Node<DataType> *insertBeforeIndex(DataType val, int index)
    {

        if (index == 1)
        {
            // index = 1 means node has to be insert before the head
            return insertBeforeHead(val);
        }

        // temp will keep track of the node
        Node<DataType> *temp = head;

        // count so that the Kth element can be reached
        int counter = 0;
        while (temp != NULL)
        {
            counter++;
            // On reaching the Kth position, break out of the loop
            if (counter == index)
                break;
            // keep moving temp forward till count != K
            temp = temp->next;
        }
        // now temp points to node at given index k

        // track the node before the Kth node
        Node<DataType> *prev = temp->back;

        // create new node with data as val and next as

        Node<DataType> *newNode = new Node<DataType>(val, temp, prev);

        // join the new node in between prev and temp
        prev->next = newNode;
        temp->back = newNode;

        // Set newNode's pointers to prev and temp
        newNode->next = temp;
        newNode->back = prev;

        // Return the head of the updated doubly linked list
        return head;
    }
    void insertBeforeNode(Node<DataType> *node, DataType val)
    {
        // Get the node before the given node
        Node<DataType> *prev = node->back;

        // Create a new node with the given val
        Node<DataType> *newNode = new Node<DataType>(val, node, prev);

        // Connect the newNode to the doubly linked List
        prev->next = newNode;
        node->back = newNode;

        // void function to just update
        return;
    }
    void deleteHeadAndFreeList()
    {
        // Delete the head node
        Node<DataType> *temp = head;
        if (head != nullptr)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->back = nullptr;
            }
            delete temp;
        }

        // Free the remaining nodes in the list
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
    vector<int> list; // generate empty list/array
    // srand(time(0));   // Use current time as seed for random generator
    for (int i = 0; i < 10; i++)
    {
        list.push_back((rand() % 201) - 100); // Generate random numbers between -100 and 100
    }
    DoublyLinkedList<int> DLL;
    Node<int> *head = DLL.getHead();
    head = DLL.convertArr2DLL(list);

    // Length and search
    cout << "Length of Doubly Linked List: " << DLL.lengthOfLinkedList() << '\n';
    cout << "Memory value of current head: " << DLL.getHead() << '\n'; // returns the memory value
    cout << "Data at current head: " << DLL.getHead()->data << '\n';         // returns the data stored at that memory point
    cout << (DLL.checkifDataPresent(5) ? "Yes data is present" : "Data is not present") << '\n';

    // Deletions

    cout << "Doubly Linked List before element removal" << '\n';
    DLL.printLL();

    head = DLL.deleteHead();
    head = DLL.deleteTail();
    head = DLL.deleteAtIndex(5); // remember here 5 is the 5th index at which we have to delete
    DLL.deleteNode(head->next);  // deletes given node in o(1)

    cout << "Doubly Linked List after element removal" << '\n';
    DLL.printLL();

    // Insertions
    Node<int> *newHead = DLL.convertArr2DLL(list);
    cout << "Doubly Linked List before element insertion" << '\n';
    DLL.printLL();

    newHead = DLL.insertBeforeHead(100);
    newHead = DLL.insertBeforeTail(-100);
    newHead = DLL.insertBeforeIndex(-69, 5);        // remember here 5 is the 5th index at which we have to insert
    DLL.insertBeforeNode(newHead->next->next, -69); // insert 5 berfore -69 value node

    cout << "Doubly Linked List after element insertion" << '\n';
    DLL.printLL();

    // free up space
    DLL.deleteHeadAndFreeList();

    DLL.printLL();
}