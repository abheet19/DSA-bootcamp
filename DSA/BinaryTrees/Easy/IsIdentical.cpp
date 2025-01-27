#include <bits/stdc++.h>
using namespace std;
// Definition of a binary tree node
struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Time Complexity -> O(n)
    // Space Complexity -> O(h)

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL)
        {
            return false;
        }
        if (p->data != q->data)
        {
            return false;
        }
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame;
    }
};

int main()
{
    // Example usage
    Solution solution;

    // Creating two sample trees
    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // Checking if the trees are identical
    bool result = solution.isSameTree(tree1, tree2);
    cout << "Are the trees identical? " << result << endl; // Output: 1 (true)

    // Clean up
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}