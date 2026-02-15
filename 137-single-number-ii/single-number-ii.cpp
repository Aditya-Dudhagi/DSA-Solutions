class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // solution 1: using sorting and traversing middle element;
        sort(nums.begin(), nums.end());
        int i=1, n = nums.size();
        for(; i<n; i+=3){
            if(nums[i] != nums[i-1]) return nums[i-1];
        }
        return nums[i-1];
    }
};