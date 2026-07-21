class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]==1) return -1;
        if(n == 1 && grid[0][0] == 0) return 1;
        
        vector<vector<int>> dist(n, vector<int>(n , 1e9));
        dist[0][0] = 1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first, col = it.second.second;

            for(int delrow = -1; delrow <=1 ; delrow ++){
                for(int delcol = -1; delcol <= 1; delcol ++){
                    int newr = row + delrow, newc = col + delcol;

                    if(newr>=0 && newr < n && newc>=0 && newc<n &&
                        grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]){
                            dist[newr][newc] = dis + 1;
                            if((newr == n-1) && (newc == n-1)){
                                return dis + 1 ;
                            }
                            q.push({dis+1, {newr, newc}});
                        }
                }
            }
        }
        return -1;
    }
};