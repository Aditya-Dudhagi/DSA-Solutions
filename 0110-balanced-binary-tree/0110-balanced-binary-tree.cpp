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
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        if(!root->left && !root->right) return 1;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;

        q.push(root);
        bool ans = true;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            int lefth = 0,  righth = 0; 
            lefth = height(curr->left);
            righth = height(curr->right);
            if(abs(lefth - righth) > 1) ans &= false;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        return ans;
    }
};