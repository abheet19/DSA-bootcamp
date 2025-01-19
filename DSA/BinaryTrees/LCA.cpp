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
    // Time complexity: O(N) where N is the number of nodes in the binary tree. We visit each node exactly once.
    // Space complexity: O(N) where N is the number of nodes in the binary tree.
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left != nullptr && right != nullptr)
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
    TreeNode *p = root->left;  // Node with value 5
    TreeNode *q = root->right; // Node with value 1

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << lca->data << endl;

    return 0;
}
