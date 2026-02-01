class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin()+1, nums.end());
        ans += nums[0] + nums[1] + nums[2];
        return ans;
    }
};