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
        helper(root->right, result);
        result.push_back(root->data);
    }
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    vector<int> postOrderRecursive(TreeNode *root)
    {
        vector<int> result;
        helper(root, result);
        return result;
    }
    vector<int> postOrderIterative(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        TreeNode *prev = nullptr;

        while (!st.empty() || curr)
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if (temp == nullptr || temp == prev)
                {
                    prev = st.top();
                    result.push_back(prev->data);
                    st.pop();
                }
                else
                {
                    curr = temp;
                }
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
    // Getting postorder traversal
    vector<int> resultRecursive = solution.postOrderRecursive(root);
    vector<int> resultIterative = solution.postOrderIterative(root);

    // Displaying the postorder traversal result
    cout << "Postorder Traversal Recursive: ";
    for (int val : resultRecursive)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder Traversal Iterative: ";
    for (int val : resultIterative)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}