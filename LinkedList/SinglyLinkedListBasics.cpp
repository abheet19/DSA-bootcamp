#include <bits/stdc++.h>

using namespace std;
template <typename DataType>

/* Class definition for Singly linked list which can have any DataType*/

class Node
{
public:            // access modifier
    DataType data; // the data value
    Node *next;    // the pointer to the next value

    // constructor
    Node(DataType newData, Node *newNext = NULL)
    {
        this->data = newData; // Initialize data with the provided value
        this->next = newNext; // Initialize next with the provided
    }
};
template <typename DataType>

class LinkedList
{
private:
    Node<DataType> *head;

public:
    LinkedList() : head(nullptr)
    {
    }

    Node<DataType> *getHead() const
    {
        return head;
    }

    /* ================================ Singly Linked List Basic Snippets ============================================*/

    void printLL()
    { // Time - O(n) and Space - O(1)
        Node<int> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL"
             << "\n";
    }

    int lengthOfLinkedList()
    { // Time - O(n) and Space - O(1)
        Node<int> *temp = head;
        int counter = 0;
        // Traverse the linked list and count nodes
        while (temp != NULL)
        {
            temp = temp->next;
            counter++; // increment cnt for every node traversed
        }
        return counter;
    }
    bool checkifDataPresent(int desiredElement)
    { // Time - O(n) and Space - O(1)
        Node<int> *temp = head;
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

    Node<DataType> *convertarr2LL(vector<DataType> &arr)
    {                                            // Time - O(n) and Space - O(1)
        head = new Node<DataType>(arr[0]); // creating head
        Node<DataType> *mover = head;                 // temp pointer pointing towards head

        for (size_t i = 1; i < arr.size(); i++)
        {
            mover->next = new Node<DataType>(arr[i]); // creating new node and assigning it to mover->next
            mover = mover->next;                 // moving mover to the next node
        }
        return head;
    }

    Node<DataType> *deleteHead()
    { // Time - O(1) and Space - O(1)
        // Check if the linked list is empty
        if (head == NULL)
            return head;
        // Create a temporary pointer to the current head
        Node<DataType> *temp = head;
        // Move the head to the next node
        head = head->next;
        // Delete the original head
        delete temp;
        // Return the updated head of the linked list
        return head;
    }
    Node<DataType> *deleteTail()
    { // Time - O(n) and Space - O(1)
        // If the list is empty or has only one node, return NULL
        if (head == NULL || head->next == NULL)
            return NULL;
        // Initialize a temporary pointer to traverse the list
        Node<DataType> *temp = head;
        // Traverse to the second last node in the list
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        // Delete the last node
        delete temp->next;
        // Set the next of the second last node to nullptr, effectively removing the last node
        temp->next = NULL;
        // Return the head of the modified list
        return head;
    }

    Node<DataType> *deleteAtIndex(int index)
    { // Time - O(n) and Space - O(1)
        // Check if the list is empty
        // int index starts from 1
        if (head == NULL)
            return head;

        // If k is 1, delete the first node
        if (index == 1)
        {
            Node<DataType> *temp = head;
            head = head->next;
            delete (temp);
            return head;
        }

        // Traverse the list to find the k-th node
        Node<DataType> *temp = head;
        Node<DataType> *prev = NULL;
        int counter = 0;

        while (temp != NULL)
        {
            counter++;
            // If the k-th node is found
            if (counter == index)
            {
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

    Node<DataType> *insertHead(int val)
    { // Time - O(1) and Space - O(1)
        Node<DataType> *newHead = new Node<DataType>(val, head);
        return newHead;
    }

    Node<DataType> *insertTail(int val)
    { // Time - O(n) and Space - O(1)
        if (head == NULL)
            return new Node<DataType>(val);
        Node<DataType> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node<DataType> *newNode = new Node<DataType>(val);
        temp->next = newNode;
        return head;
    }

    Node<DataType> *insertAtIndex(int val, int index)
    { // Time - O(n) and Space - O(1)
        // If the linked list is empty and k is 1, insert the new node as the head
        // int index starts from 1
        if (head == NULL)
        {
            if (index == 1)
                return new Node<DataType>(val);
            else
                return head;
        }

        // If k is 1, insert the new node at the beginning of the linked list
        if (index == 1)
            return new Node<DataType>(val, head);

        int counter = 0;
        Node<DataType> *temp = head;

        // Traverse the linked list to find the node at position k-1
        while (temp != NULL)
        {
            counter++;
            if (counter == index - 1)
            {
                // Insert the new node after the node at position k-1
                Node<DataType> *newNode = new Node<DataType>(val, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }

        return head;
    }
    // Function to insert a new node with data 'el' after the node with data 'val'
    Node<DataType> *insertBeforeNode(int newElement, int value)
    { // Time - O(n) and Space - O(1)
        if (head == NULL)
        {
            return NULL;
        }

        // Insert at the beginning if the value matches the head's data
        if (head->data == value)
            return new Node<DataType>(newElement, head);

        Node<DataType> *temp = head;
        while (temp->next != NULL)
        {
            // Insert at the current position if the next node has the desired value
            if (temp->next->data == value)
            {
                Node<DataType> *newNode = new Node<DataType>(newElement, temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
    void deleteHeadAndFreeList()
    {
        // Delete the head node
        Node<DataType> *temp = head;
        if (head != nullptr)
        {
            head = head->next;
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
/* ======================== DRIVER CODE ================================*/

int main()
{
    vector<int> list; // generate empty list/array
    srand(time(0));   // Use current time as seed for random generator
    for (int i = 0; i < 10; i++)
    {
        list.push_back((rand() % 201) - 100); // Generate random numbers between -100 and 100
    }
    LinkedList<int> LL;
    Node<int> *head = LL.convertarr2LL(list);
    
    // Length and search
    cout << "Length of Linked List: " << LL.lengthOfLinkedList() << '\n';
    cout << "Memory value of current head: " << head << '\n'; // returns the memory value
    cout << "Data at current head: " << head->data << '\n';   // returns the data stored at that memory point
    cout << (LL.checkifDataPresent(5) ? "Yes data is present" : "Data is not present") << '\n';

    // Deletions

    cout << "Linked List before element removal" << '\n';
    LL.printLL();

    head = LL.deleteHead();
    head = LL.deleteTail();
    head = LL.deleteAtIndex(5); // remember here 5 is the 5th index at which we have to delete

    cout << "Linked List after element removal" << '\n';
    LL.printLL();

    // Insertions

    cout << "Linked List before element insertion" << '\n';
    LL.printLL();

    head = LL.insertHead(100);
    head = LL.insertTail(-100);
    head = LL.insertAtIndex(-69, 5);    // remember here 5 is the 5th index at which we have to insert
    head = LL.insertBeforeNode(5, -69); // insert 5 berfore -69 value node

    cout << "Linked List before element insertion" << '\n';
    LL.printLL();

    // free up space
    LL.deleteHeadAndFreeList();
    LL.printLL();
}
