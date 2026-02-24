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
    void dfs(TreeNode* node, string bin, int &ans){
        if(node->right == nullptr && node->left == nullptr) {
            int tmp = 0, n = bin.size();
            for(int i=bin.size()-1; i>=0; i--){
                tmp += (bin[i]-'0')*pow(2, n-i-1);
            }
            ans += tmp;
            return;
        }
        
        if(node->left) dfs(node->left, bin + to_string(node->left->val), ans);
        if(node->right) dfs(node->right, bin + to_string(node->right->val), ans);

    }
    int sumRootToLeaf(TreeNode* root) {
        TreeNode* node = root;
        string bin = to_string(root->val);
        int ans = 0;
        dfs(root, bin, ans);
        return ans;
    }
};