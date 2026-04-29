class Solution {
public:
    int INF = INT_MAX - 1;
    int ret(vector<int> &coins, int n, int amount, vector<vector<int>> &t){
        if(amount == 0) return 0;
        if(n == 0) return INF;

        if(t[n][amount] != -1) return t[n][amount];

        if(coins[n-1]<=amount){
            return t[n][amount] = min(1 + ret(coins, n, amount - coins[n-1], t) , ret(coins, n-1, amount, t));
        } else{
            return t[n][amount] = ret(coins, n-1, amount, t);
        }
            
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n+1, vector<int> (amount + 1, -1));
        int ans = ret(coins, n, amount, t);
        return ans >= INF ? -1 : ans;
        
    }
};