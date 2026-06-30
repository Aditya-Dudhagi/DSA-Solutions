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
    vector<int> in;
    void inorderTraverse(TreeNode *root){
        if(!root) return;
        inorderTraverse(root->left);
        in.push_back(root->val);
        inorderTraverse(root->right);
    }
    void inorder(TreeNode *root, int &i){
        if(!root) return;
        inorder(root->left, i);
        if(root->val != in[i]){
            root->val = in[i];
        }
        i++;
        inorder(root->right, i);
    }
    void recoverTree(TreeNode* root) {
        inorderTraverse(root);
        sort(in.begin(), in.end());
        int i=0;
        inorder(root, i);
    }
};