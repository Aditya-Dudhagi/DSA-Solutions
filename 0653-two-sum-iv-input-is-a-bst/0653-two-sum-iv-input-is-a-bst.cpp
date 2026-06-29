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
    stack<TreeNode*> stb, stn;
    void pushAllb(TreeNode* node){
        for(; node != NULL; stb.push(node), node = node->right);
    }
    void pushAlln(TreeNode* node){
        for(; node != NULL; stn.push(node), node = node->left);
    }
    int before(){
       TreeNode* tmp = stb.top();
       stb.pop();
       pushAllb(tmp->left); 
       return tmp->val;
    }
    int next(){
       TreeNode* tmp = stn.top();
       stn.pop();
       pushAlln(tmp->right); 
       return tmp->val;
    }
    bool findTarget(TreeNode* root, int k) {
        bool flag = false;
        pushAllb(root);
        pushAlln(root);
        int i = next(), j = before();
        while(i<j){
            if(i+j == k && i!=j) {
                flag = true;
                break;
            }
            else if(i+j<k){
                i=next();
            } else j=before();
        }
        return flag;
    }
};