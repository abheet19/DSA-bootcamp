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
//Time complexity O(N log N)
//Space complexity: O(N)
class Solution{
    public:
    // Function to get the top view of the binary tree
    vector<int> topView(TreeNode *root){
        vector<int> topView;
        if(root == nullptr){
            return topView;
        }
        // Create a map to store the horizontal distance and the node value
        map<int, int> mpp;
        // Create a queue to store the node and its horizontal distance
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int hd = p.second;

            // If the horizontal distance is not present in the map
            // then add the node value to the map
            if(mpp.find(hd) == mpp.end()){
                mpp[hd] = node->data;
            }

            // If the left child is present, push it into the queue
            if(node->left){
                q.push({node->left, hd - 1});
            }

            // If the right child is present, push it into the queue
            if(node->right){
                q.push({node->right, hd + 1});
            }
        }
        for(auto x : mpp){
            topView.push_back(x.second);
        }
        return topView;
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
    vector<int> topView = solution.topView(root);

    // Print the result
    cout << "Top View Traversal: " << endl;
    for (auto node : topView) {
        cout << node << " ";
    }

    return 0;
}
