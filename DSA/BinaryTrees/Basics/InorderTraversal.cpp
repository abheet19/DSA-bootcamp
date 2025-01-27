#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{

public:
    void helper(TreeNode *root, vector<int> &result)
    {
        if (root == NULL)
        {
            return;
        }
        helper(root->left, result);
        result.push_back(root->data);
        helper(root->right, result);
    }
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    vector<int> InOrderRecursive(TreeNode *root)
    {
        vector<int> result;
        helper(root, result);
        return result;
    }
    vector<int> InOrderIterative(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (!st.empty() || curr)
        { // If we have a current node (not NULL), push it to the stack and move to its left child
            if (curr)
            {
                st.push(curr);
                curr = curr->left; // Move to left child
            }
            else
            {
                // If we've reached the end of a subtree (stack not empty), pop the top node
                curr = st.top();
                st.pop();
                result.push_back(curr->data); // Add the popped node's value to the result
                curr = curr->right;           // Move to the right child of the popped node
            }
        }

        return result;
    }
};

// Main function to test the inorder traversal
int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance of the Solution class
    Solution solution;
    // Getting inorder traversal
    vector<int> resultRecursive = solution.InOrderRecursive(root);
    vector<int> resultIterative = solution.InOrderIterative(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal Recursive: ";
    for (int val : resultRecursive)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder Traversal Iterative: ";
    for (int val : resultIterative)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}