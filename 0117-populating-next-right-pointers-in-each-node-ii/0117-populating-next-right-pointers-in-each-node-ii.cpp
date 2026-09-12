/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        vector<vector<Node*>> nodes;

        while(!q.empty()){
            vector<Node*> tmp;
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* no = q.front();
                tmp.push_back(no);
                q.pop();
                if(no->left) q.push(no->left);
                if(no->right) q.push(no->right);
            }
            nodes.push_back(tmp);
        }

        for(auto it : nodes){
            int n = it.size();
            for(int i=0; i<it.size()-1; i++){
                it[i]->next = it[i+1];
            }
            it[n-1]->next = NULL;
        }

        return root;
    }
};