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
public: // iterative solution 
    void flatten(TreeNode* root) {
        if(!root) return;    
        // to make it work, we have to connect the right thing to left, so putting right node first in stack will help to connect the right nodes to the left since it is FIFO
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);

            if(!st.empty()) {
                curr->right = st.top();
            }

            curr->left = NULL;
        }
    }
};