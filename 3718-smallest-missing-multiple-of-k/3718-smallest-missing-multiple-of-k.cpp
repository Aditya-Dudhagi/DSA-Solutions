class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }

        for(int i=k; i>=0; i+=k){
            if(mp[i] == 0) return i;
        }

        return -1;
    }
};