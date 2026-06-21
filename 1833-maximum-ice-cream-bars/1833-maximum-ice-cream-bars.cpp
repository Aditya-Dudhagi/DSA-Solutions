class Solution {
public:
    // int solve(int i, int coins, int &sum, vector<int>& costs){
    //     if(i==costs.size() || coins == 0) return sum;


    //     solve(i+1, coins - costs[i], sum+1, costs);
        
    //     solve(i+1, coins, sum, costs);
    // }
    int maxIceCream(vector<int>& costs, int coins) {
        // return solve(0, coins, 0, costs);
        int cnt = 0;
        sort(costs.begin(), costs.end());
        while(coins>0){
            if(cnt == costs.size() || coins<costs[cnt]) break;
            coins -= costs[cnt];
            cnt++;
        }
        return cnt;

    }
};