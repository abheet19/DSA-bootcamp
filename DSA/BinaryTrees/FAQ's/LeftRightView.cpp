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
//Time complexity O(N)
//Space complexity: O(h) where h is the height of the tree
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if (root == nullptr) {
            return rightView;
        }
        //reverse pre order traversal through recursive function
        rightViewTraversal(root, rightView, 0);
        return rightView;
    }
    vector<int> leftSideView(TreeNode* root) {
        vector<int> leftView;
        if (root == nullptr) {
            return leftView;
        }
        //reverse pre order traversal through recursive function
        leftViewTraversal(root, leftView, 0);
        return leftView;
    }

private:
    void rightViewTraversal(TreeNode* root, vector<int>& rightView, int level) {
        if (root == nullptr) {
            return;
        }
        // If the size of the right view is equal to the level
        // then add the node value to the right view
        if (rightView.size() == level) {
            rightView.push_back(root->data);
        }
        // Traverse the right child first
        rightViewTraversal(root->right, rightView, level + 1);
        // Traverse the left child
        rightViewTraversal(root->left, rightView, level + 1);
    }

    void leftViewTraversal(TreeNode* root, vector<int>& leftView, int level) {
        if (root == nullptr) {
            return;
        }
        // If the size of the left view is equal to the level
        // then add the node value to the left view
        if (leftView.size() == level) {
            leftView.push_back(root->data);
        }
        // Traverse the left child first
        leftViewTraversal(root->left, leftView, level + 1);
        // Traverse the right child
        leftViewTraversal(root->right, leftView, level + 1);
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    Solution solution;

    // Get the Right View traversal
    vector<int> rightView = solution.rightSideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for (auto node : rightView) {
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = solution.leftSideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for (auto node : leftView) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}