#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor with a value parameter for TreeNode
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Time complexity: O(N) where N is the number of nodes in the binary tree. We visit each node exactly once.
// Space complexity: O(N) where N is the number of nodes in the binary tree.
// The maximum number of nodes in a level is N/2 for the last level of a complete binary tree.
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result; // Create a 2D vector to store levels

        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> q; // Create a queue to store nodes for level-order traversal
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level; // Create a vector to store nodes at the current level
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();  // Get the front node in the queue
                q.pop();                        // Remove the front node from the queue
                level.push_back(current->data); // Store the node value in the current level vector
                if (current->left != nullptr)
                {
                    q.push(current->left); // Enqueue the child nodes if they exist
                }
                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
            }
            result.push_back(level); // Store the current level in the answer vector
        }
        return result;
    }

    // Add destructor helper
    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};
// Function to print the elements of a vector
void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}
// Main function
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
    // Perform level-order traversal
    vector<vector<int>> result = solution.levelOrder(root);

    cout << "Level Order Traversal of Tree: " << endl;

    // Printing the level order traversal result
    for (const vector<int> &level : result)
    {
        printVector(level);
    }

    // Add cleanup before exit
    solution.deleteTree(root);
    return 0;
}