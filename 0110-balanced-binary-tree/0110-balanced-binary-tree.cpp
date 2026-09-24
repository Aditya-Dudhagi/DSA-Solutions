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
bool ansi = true;
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = 0;
        int rh = 0;

        if(root->left) lh = height(root->left); 
        if(root->right) rh = height(root->right); 

        if(lh == -1 || rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;
        return 1 + max(height(root->left), height(root->right));

        // return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1; 
        
    }
};