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
    int height(TreeNode* node, int &maxsum){
        if(node == nullptr) return 0;
        int left = max(0, height(node->left, maxsum));
        int right = max(0,height(node->right, maxsum));

        maxsum = max(maxsum, node->val + left + right);

        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        height(root, maxsum);
        return maxsum;
    }
};