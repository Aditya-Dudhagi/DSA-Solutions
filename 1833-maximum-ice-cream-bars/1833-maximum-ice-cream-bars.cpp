class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
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