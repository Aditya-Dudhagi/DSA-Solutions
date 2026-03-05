class Solution {
public:
    vector<vector<int>> ans;
    void fs(int ind, int targ, vector<int>& candi, vector<int> &ds, int n){
        if(ind == n){
            if(targ == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if(candi[ind]<=targ){
            ds.push_back(candi[ind]);
            fs(ind, targ - candi[ind], candi, ds, n);
            ds.pop_back();
        }

        fs(ind+1, targ,candi, ds, n);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        int n = candidates.size();
        fs(0, target, candidates, ds, n);
        return ans;
    }
};