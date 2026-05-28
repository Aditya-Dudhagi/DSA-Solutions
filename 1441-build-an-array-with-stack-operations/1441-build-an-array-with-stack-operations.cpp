class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int last = n;
        vector<int> hash(n+1, 0);
        for(int i:target){
            hash[i]++;
        }
        vector<string> ans;
        for(int i=1; i<=target[target.size()-1]; i++){
            if(hash[i]){
                ans.push_back("Push");
            }else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};