#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //Time Complexity -> O(n)
    //Space Complexity -> O(n)
    int maxDepth(TreeNode *root){
        if(root == NULL)
            return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh,rh);
    }

    int maxDepthIterative(TreeNode *root){
        int result=0;

        if(root == NULL){
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int size =q.size();

            for(int i=0; i<size;i++){
                TreeNode *current=q.front();
                q.pop();

                // Enqueue left child if it exists
                if (current->left != NULL) {
                    q.push(current->left);
                }

                // Enqueue right child if it exists
                if (current->right != NULL) {
                    q.push(current->right);
                }
            }
            result++;
        }
        return result;
        
    }

};

int main() {
    Solution solution;
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Maximum Depth: " << solution.maxDepth(root) << endl;
    return 0;
}