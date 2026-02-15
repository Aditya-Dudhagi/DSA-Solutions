class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // solution 2: check each bit from 0th to 31st for each element and then count it , if it is 1 more than multiple of 3 , then set that index of ans
        int ans = 0;
        for(int bitInd = 0; bitInd < 32; bitInd++){
            int cnt = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] & (1<<bitInd)) cnt++;
            }
            if(cnt%3 == 1) {
                ans = ans | (1<<bitInd);
            }
        }
        return ans;
    }
};