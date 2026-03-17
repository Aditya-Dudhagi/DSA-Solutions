class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(prev == nums[i]) return true;
            
            prev = nums[i];
        }
        return false;
    }
};