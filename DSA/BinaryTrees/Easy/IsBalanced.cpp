#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Time Complexity -> O(n)
// Space Complexity -> o(h)
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {

        return dfsHeight(root) != -1;
    }

private:
    int dfsHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int lh = dfsHeight(root->left);
        if (lh == -1)
            return -1;

        int rh = dfsHeight(root->right);
        if (rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
            return -1;

        return 1 + max(lh, rh);
    }
};

// Main function
int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Checking if the tree is balanced
    if (solution.isBalanced(root))
    {
        std::cout << "The tree is balanced." << std::endl;
    }
    else
    {
        std::cout << "The tree is not balanced." << std::endl;
    }

    return 0;
}
