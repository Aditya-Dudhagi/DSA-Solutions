class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = n*(n+1)/2;
        int nums_sum = 0, unique_sum = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for(int i: nums) nums_sum += i;

        for(int i:s) unique_sum += i;

        int missing = actual_sum - unique_sum;
        int duplicate = nums_sum - unique_sum;

        return {duplicate, missing};
    }
};