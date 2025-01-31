#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize the node with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
//Time Complexity:O(N log N)
//Space Complexity:O(N)
class Solution {
public:
    // Function to get the bottom View of the binary tree
    vector<int> bottomView(TreeNode *root) {
        vector<int> bottomView;
        if (root == nullptr) {
            return bottomView;
        }
        // Create a map to store the horizontal distance and the node value
        map<int, int> mpp;


        // Create a queue to store the node and its horizontal distance
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto p=q.front();
            q.pop();

            TreeNode *node = p.first;
            int hd = p.second;

            mpp[hd] = node->data;

            if(node->left){
                q.push({node->left, hd - 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1});
            }

        }
        for (auto x : mpp) {
            bottomView.push_back(x.second);
        }
        return bottomView;
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    Solution solution;

    // Get the top view traversal
    vector<int> bottomView = solution.bottomView(root);

    // Print the result
    cout << "Bottom View Traversal: " << endl;
    for (auto node : bottomView) {
        cout << node << " ";
    }

    return 0;
}