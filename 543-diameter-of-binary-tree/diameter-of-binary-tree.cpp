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
    int maxdia = 0;
    void dfs(TreeNode* root){
        if(root == nullptr) return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            maxdia = max(maxdia, height(curr->left)+height(curr->right));

            if(curr->left != nullptr) st.push(curr->left);
            if(curr->right != nullptr) st.push(curr->right);
        }
    }
    int height(TreeNode *node){
        if(node == nullptr) return 0;

        return 1 + max(height(node->left), height(node->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxdia;
    }
};