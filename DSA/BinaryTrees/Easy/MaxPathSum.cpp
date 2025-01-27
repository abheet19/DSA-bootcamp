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
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        dfsSum(root, maxSum);
        return maxSum;
    }

private:
    int dfsSum(TreeNode *node, int &maxSum)
    {
        if (node == nullptr)
            return 0;

        int leftSum = max(0,dfsSum(node->left,maxSum));
        int rightSum = max(0,dfsSum(node->right,maxSum));

        maxSum = max(maxSum, leftSum + rightSum + node->data);
        return node->data + max(leftSum, rightSum);
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
    std::cout << "Max Path Sum is " << sol.maxPathSum(root) << std::endl;

    // Clean up the tree to avoid memory leaks
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}