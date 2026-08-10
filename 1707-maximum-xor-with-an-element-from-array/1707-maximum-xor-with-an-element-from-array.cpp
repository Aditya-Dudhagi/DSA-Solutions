struct Node {
    Node* links[2];
    
    bool containsKey(int bit) {
        return links[bit];
    }

    void put(int bit){
        links[bit] = new Node();
    }

    Node* get(int bit){
        return links[bit];
    }
};   

class Trie{
private:
    Node* root;
public: 
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit);
            }
            node = node->get(bit);
        }
    }

    int findMax(int num){
        Node* node = root;
        int maxnum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(node->containsKey(!bit)){
                maxnum |= 1<<i;
                node = node->get(!bit);
            } else node = node->get(bit);
        }
        return maxnum;
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ ; // offline queries;
        int q = queries.size();
        for(int i=0; i<q; i++){
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(oQ.begin(), oQ.end());

        vector<int> ans(q, 0);

        Trie trie;
        int ind = 0;
    
        for(int i=0; i<q; i++){
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;
            while(ind<nums.size() && nums[ind]<=ai){
                trie.insert(nums[ind]);
                ind++;
            }

            if(ind == 0) ans[qInd] = -1;
            else ans[qInd] = trie.findMax(xi);
                
        }
        return ans;
    }
};