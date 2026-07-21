class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0,0}});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int diff = it.first;

            int row = it.second.first, col = it.second.second;

            

            for(int i=0; i<4; i++){
                int newr = row + dx[i], newc = col + dy[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int neweff = max(abs(heights[row][col] - heights[newr][newc]), diff);
                    if(neweff < dist[newr][newc]){
                        dist[newr][newc] = neweff;
                        pq.push({neweff, {newr, newc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};