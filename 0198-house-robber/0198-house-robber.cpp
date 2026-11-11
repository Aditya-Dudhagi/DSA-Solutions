class Solution {
public:
    int rob(vector<int>& nums) {
        // tabulation
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];

        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];

            int notPick = 0 + dp[i-1];

            dp[i] = max(pick , notPick);
        }
        
        return dp[n-1];
    }
};