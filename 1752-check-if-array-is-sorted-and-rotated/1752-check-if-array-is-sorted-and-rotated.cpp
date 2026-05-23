class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;

        int change = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>nums[(i+1)%n]) change++;
        }
        return change<=1;
    }
};