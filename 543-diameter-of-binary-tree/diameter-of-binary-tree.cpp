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
    int height(TreeNode *node, int &maxdia){
        if(node == nullptr) return 0;
        int lh = height(node->left, maxdia), rh =  height(node->right, maxdia);
        maxdia = max(maxdia, lh+rh);
        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root, maxdia);
        return maxdia;
    }
};