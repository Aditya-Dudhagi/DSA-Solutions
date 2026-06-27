/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *parent = nullptr;
        TreeNode *curr = root;

        // Search for the node
        while (curr && curr->val != key) {
            parent = curr;
            if (key < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // Key not found
        if (!curr) return root;

        // Case 1 & 2 : Node has at most one child
        if (!curr->left || !curr->right) {

            TreeNode *child;

            if (curr->left)
                child = curr->left;
            else
                child = curr->right;

            // Deleting root
            if (!parent) {
                delete curr;
                return child;
            }

            if (parent->left == curr)
                parent->left = child;
            else
                parent->right = child;

            delete curr;
        }

        // Case 3 : Node has two children
        else {
            TreeNode *succParent = curr;
            TreeNode *succ = curr->right;

            while (succ->left) {
                succParent = succ;
                succ = succ->left;
            }

            // Copy successor's value
            curr->val = succ->val;

            // Remove successor
            if (succParent->left == succ)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            delete succ;
        }

        return root;
    }
};