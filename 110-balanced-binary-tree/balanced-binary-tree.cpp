/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode *node){
        if(node == nullptr) return 0;

        return 1 + max(height(node->left), height(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh- rh) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;

        return true;

        // this is O(N^2) solution 
    }
};