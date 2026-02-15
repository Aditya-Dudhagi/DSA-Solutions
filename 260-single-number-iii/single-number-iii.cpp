class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        map<int, int> mp;
        for(int i:nums) mp[i]++;
        vector<int> ans;
        for(auto it: mp){
            if(it.second == 1) ans.push_back(it.first);
        }
        return ans;
    }
};