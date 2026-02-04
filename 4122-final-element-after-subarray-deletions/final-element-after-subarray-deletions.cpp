class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums[nums.size()-1], nums[0]);
    }
};