/*In C++, a binary tree is represented using pointers, forming a hierarchical structure where each node can point to two further nodes: a left child and a right child.
This representation uses pointers to establish connections between nodes in the tree, allowing traversal and navigation throughout the structure.

Node Structure: A binary tree node is represented using a struct or class that contains the following components:

    -> Data Component: Holds the value of the node, which could be of any data type (e.g., integer, string, object).
    -> Pointers to Children: Two pointers, left and right, pointing to the left and right child nodes, respectively.
       These pointers store the memory addresses of the child nodes, allowing navigation and access to further nodes in the tree.

Node Constructor: The constructor function is named Node, which is the same as the structure name. It takes an integer val as a parameter,
which represents the value to be stored in the node.

-> data = val; : Assigns the value passed as a parameter (val) to the data member of the node. This sets the value of the node to the input integer.
-> left = right = NULL; : Initialises both the left and right pointers to NULL. This is done to ensure that initially, the node does not have any left or right children.
   Setting pointers to NULL indicates that there are no connections to other nodes at the time of node creation.

Node Connection: When constructing a binary tree using pointers, each node stores references (memory addresses) to its left and right children.
These references form the connections between nodes, enabling the hierarchical structure.

When creating a new node, memory is allocated, and the node's data is stored. Pointers left and right are initialised as nullptr or NULL to signify that the node currently has no children.
Later, nodes are connected by assigning the left and right pointers of a parent node to the memory addresses of its respective left and right child nodes.

*/

#include <bits/stdc++.h>
using namespace std;

// Structure definition for a node in a binary tree
struct Node
{
    int data;    // Defining the value of the node (integer data)
    Node *left;  // Reference pointer to the left child node
    Node *right; // Reference pointer to the right child node

    Node(int val) // Method to initialize the node with a value
    {
        data = val;          // Set the value of the node to the passed integer
        left = right = NULL; // Initialize left and right pointers as NULL
    }
    // Constructor can also be written as:
    // Node(int val) : data(val), left(NULL), right(NULL) {}
};

int main()
{
    Node *root = new Node(1); // Creating a new node for the root of the binary tree using dynamic allocation

    root->left = new Node(2); // Creating left and right child nodes for the root node
    root->right = new Node(3);
    root->left->right = new Node(5); // Creating a right child node for the left child node of the root
    return 0;
}