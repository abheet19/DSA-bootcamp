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
    // Time complexity: O(N)
    // Space complexity: O(N)
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *r)
    {
        if (root == nullptr || root == p || root == q || root == r)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q, r);
        TreeNode *right = lowestCommonAncestor(root->right, p, q, r);

        int count = 0;
        if (left != nullptr)
            count++;
        if (right != nullptr)
            count++;
        if (root == p || root == q || root == r)
            count++;

        // Modify the count condition to correctly identify LCA for three nodes
        if (count >= 2)
        {
            return root;
        }
        return (left != nullptr) ? left : right;
    }
};

int main()
{
    // Construct a simple binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution solution;
    TreeNode *p = root->left;        // Node with value 5
    TreeNode *q = root->right;       // Node with value 1
    TreeNode *r = root->left->right; // Node with value 2

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q, r);
    if (lca != nullptr)
        cout << "Lowest Common Ancestor: " << lca->data << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
