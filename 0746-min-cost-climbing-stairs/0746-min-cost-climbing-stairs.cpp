class Solution {
public:
    int t[1001];
    Solution(){
        memset(t, -1, sizeof(t));
    }
    int solve(int i, vector<int>& cost){
        if(i<=1) return 0;
        if(t[i] != -1) return t[i];
        return t[i] = min(solve(i-1, cost)+cost[i-1], solve(i-2, cost) + cost[i-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return solve(cost.size(), cost);
    }
};