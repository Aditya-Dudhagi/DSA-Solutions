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
        // striver solution
        TreeNode* cur = root;
        if(root == nullptr) {
           return new TreeNode(val);
        }
        while(true){
            if(cur->val<=val){
                if(cur->right !=nullptr){
                    cur = cur->right;
                } else{
                    cur->right = new TreeNode(val);
                    break;
                }
            } else {
                if(cur->left !=nullptr){
                    cur = cur->left;
                }
                else{
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};