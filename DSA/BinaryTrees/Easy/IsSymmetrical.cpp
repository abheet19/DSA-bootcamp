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

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {

        if (root == NULL) // An empty tree is symmetric
            return true;

        return dfs(root->left, root->right);
    }

private:
    bool dfs(TreeNode *left, TreeNode *right)
    {

        if (left == NULL && right == NULL)
            return true; // Both nodes are null, so symmetric

        if (left == NULL || right == NULL)
            return false; // One of the nodes is null, so not symmetric

        if (left->data != right->data) // The values of the nodes do not match, so not symmetric
            return false;

        bool isLeftSymmetric = dfs(left->left, right->right);
        bool isRightSymmetric = dfs(left->right, right->left);

        return isLeftSymmetric && isRightSymmetric;
    }
};

int main()
{
    Solution solution;

    // Create a sample tree: 1, 2, 2, 3, 4, 4, 3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Test the symmetric tree
    std::cout << std::boolalpha << solution.isSymmetric(root) << std::endl; // Output: true

    return 0;
}
