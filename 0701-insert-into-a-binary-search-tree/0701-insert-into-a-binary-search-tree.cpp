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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root, *prev = nullptr;
        if(root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        while(cur){
            if(cur->val<val){
                prev = cur;
                cur = cur->right;
                if(cur==nullptr){
                    prev->right = new TreeNode(val);
                    break;
                }
            } else {
                prev = cur;
                cur = cur->left;
                if(cur==nullptr){
                    prev->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};