#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // List to store the final result
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        // Map to store the nodes at each vertical distance and level
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> nodesMap;

        // Queue for BFS traversal (stores node along with its x and y coordinates)
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});  // (node, {x, y})

        // Perform BFS
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            // Add the node's value to the map at the correct x and y
            nodesMap[x][y].push(node->data);

            // Add the left child with updated coordinates to the queue
            if (node->left != nullptr) {
                q.push({node->left, {x - 1, y + 1}});
            }

            // Add the right child with updated coordinates to the queue
            if (node->right != nullptr) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        // Prepare the result by sorting keys and compiling nodes
        for (auto& p : nodesMap) {
            vector<int> column;
            for (auto& q : p.second) {
                while (!q.second.empty()) {
                    column.push_back(q.second.top());
                    q.second.pop();
                }
            }
            result.push_back(column);
        }

        return result;
    }
};


// Main method to test the verticalTraversal function
int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Creating an instance of Solution
    Solution sol;

    // Getting the vertical order traversal
    vector<vector<int>> result = sol.verticalTraversal(root);

    // Printing the result
    cout << "Vertical Order Traversal: " << endl;
    for (const auto& col : result) {
        for (int num : col) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}