class Solution {
public:
    int solve(vector<int> &coins, int n, int amount, vector<vector<int>> &t){
        if(amount == 0) return 1;
        if(n==0) return 0;
        if(t[n][amount] != -1) return t[n][amount];
        if(coins[n-1] <= amount){
            return t[n][amount] =  solve(coins, n, amount - coins[n-1], t) + solve(coins, n-1, amount, t);
        } else return t[n][amount] =  solve(coins, n-1, amount, t);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> t(n+1, vector<int> (amount+1, -1));
        for(int i=0; i<n+1; i++){
            for(int j = 0; j<amount+1; j++){
                if(i==0) t[i][j] = 0;
                if(j==0) t[i][j] = 1;
            }
        }
        
        return solve(coins, n, amount, t);
    }
};