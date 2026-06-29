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
class BSTIterator {
private: 
    stack<TreeNode *> st;
    // reverse = true -> before()
    // reverse = false -> next()
    bool reverse ;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    // returns the next smallest number
    int next() {
        TreeNode *tmp = st.top();
        st.pop();
        if(!reverse) pushAll(tmp->right);
        else  pushAll(tmp->left);
        return tmp->val;
    }

    void pushAll(TreeNode* node){   // pushes all the left nodes ; left left left
        for( ; node != NULL; ){
            st.push(node);
            if(reverse == true){
                node = node->right;
            } else node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next(), j = r.next();
        cout<<i<<j;
        while(i<j){
            if(i+j == k) return true;
            else if(i+j < k) i=l.next();
            else j = r.next();
        }
        return false;
    }
};