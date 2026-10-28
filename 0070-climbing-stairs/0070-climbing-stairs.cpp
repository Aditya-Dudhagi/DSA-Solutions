class Solution {
public:
    int solve(int ind, vector<int> &dp){
        if(ind <= 1) return 1;
        if(dp[ind] != -1) return dp[ind];
        int left = solve(ind-1, dp) ;
        int right = solve(ind-2, dp);

        return dp[ind] = left + right;
    }
    int climbStairs(int n) {
        vector<int> dp(46, -1);
        return solve(n, dp);
    }
};