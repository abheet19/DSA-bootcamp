#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Time Complexity-> O(n)
// Space Complexity -> O(h)
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        dfsHeight(root, diameter);
        return diameter;
    }

private:
    int dfsHeight(TreeNode *node, int &diameter)
    {
        if (node == nullptr)
            return 0;

        int lh = dfsHeight(node->left, diameter);
        int rh = dfsHeight(node->right, diameter);

        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};

int main()
{
    // Create a binary tree for testing
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create a Solution object and find the diameter
    Solution sol;
    std::cout << "Diameter of the binary tree is: " << sol.diameterOfBinaryTree(root) << std::endl;

    // Clean up the tree to avoid memory leaks
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}