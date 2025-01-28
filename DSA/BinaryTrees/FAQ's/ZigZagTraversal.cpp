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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {   
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        bool leftToRight = true;
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for(int i=0;i<size;i++)
            {
                TreeNode *current =q.front();
                q.pop();

                int index = leftToRight ? i : size-1-i;
                level[index]=current->data;

                if(current->left != NULL)
                    q.push(current->left);

                if(current->right != NULL)
                    q.push(current->right);


            }
            result.push_back(level);
            leftToRight= !leftToRight;
        }
        return result;
    }
};

// Helper function to print the result
void printResult(const vector<vector<int>> &result)
{
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    // Print the result
    printResult(result);

    return 0;
}