class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i:nums) mp[i]++;
        int pair = 0;

        for(auto it: mp){
            if(k==0){
                if(it.second>1) pair++;
            } else{
                if(mp.count(it.first+k)) pair++;
            }
        }
        return pair;
    }
};