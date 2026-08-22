class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i: nums){
            sum += i;
            cnt += mp[sum-goal];
            mp[sum]++;
        }

        return cnt;
    }
};