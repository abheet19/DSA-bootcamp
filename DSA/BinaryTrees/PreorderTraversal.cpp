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
        result.push_back(root->data);
        helper(root->left, result);
        helper(root->right, result);
    }
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    vector<int> preorderRecursive(TreeNode *root)
    {
        vector<int> result;
        helper(root, result);
        return result;
    }
    vector<int> preorderIterative(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;

        if (root == NULL)
        {
            return result;
        }
        st.push(root);

        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            result.push_back(curr->data);

            if (curr->right != NULL)
            {
                st.push(curr->right);
            }
            if (curr->left != NULL)
            {
                st.push(curr->left);
            }
        }
        return result;
    }
};

// Main function to test the preorder traversal
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
    // Getting preorder traversal
    vector<int> resultRecursive = solution.preorderRecursive(root);
    vector<int> resultIterative = solution.preorderIterative(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal Recursive: ";
    for (int val : resultRecursive)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Preorder Traversal Iterative: ";
    for (int val : resultIterative)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}