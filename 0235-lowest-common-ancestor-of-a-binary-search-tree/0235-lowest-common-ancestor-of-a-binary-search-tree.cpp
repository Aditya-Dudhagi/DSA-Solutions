/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        int u = min(p->val, q->val), v = max(p->val, q->val);
        while(curr){
            if(u<curr->val & v<curr->val){
                curr = curr->left;
            } else if(u>curr->val && v>curr->val){
                curr = curr->right;
            } else if(curr->val > u && curr->val < v){
                return curr;
            } else return curr->val == p->val ? curr : q;
        }
        return curr;
    }
};