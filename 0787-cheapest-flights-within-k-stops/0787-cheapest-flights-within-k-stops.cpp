class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        int price = 0;

        queue< pair<int, pair<int, int>>> pq;

        pq.push({0, {0, src}});

        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int currk = it.first;
            int currp = it.second.first, node = it.second.second;

            // if(currk>k) return prices[dst];
            
            for(auto tmp : adj[node]){
                if(currk<=k){
                    if(tmp.second+currp < prices[tmp.first]){
                        prices[tmp.first] = tmp.second + currp;
                        pq.push({currk+1, {prices[tmp.first],tmp.first}});
                    }
                }
            }
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};