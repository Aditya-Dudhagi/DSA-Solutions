class Solution {
public:
    
    void fs(int ind, int targ, vector<int>& candi, vector<int> &ds, int n, vector<vector<int>> &ans){
        if(ind == n){
            if(targ == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if(candi[ind]<=targ){
            ds.push_back(candi[ind]);
            fs(ind, targ - candi[ind], candi, ds, n, ans);
            ds.pop_back();
        }

        fs(ind+1, targ,candi, ds, n, ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        fs(0, target, candidates, ds, n, ans);
        return ans;
    }
};