class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dfs(int row, int col, vector<vector<int>> &grid){
        int n = grid.size(), m = grid[0].size();
        int area = 1;

        grid[row][col] = 0;

        for(int i=0; i<4; i++){
            int nr = row + dx[i], nc = col + dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                area += dfs(nr, nc, grid);
            }
        }
        return area;        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans = max(ans , dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};