class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_res = 0, zeros = 0;
        for(int i: nums){
            zeros += (i==0) ? 1 : 0;
            xor_res = xor_res ^ i;
        }
        
        if(xor_res != 0) return nums.size();
        else if(zeros == nums.size()) return 0;
        else return nums.size()-1;
    }
};

