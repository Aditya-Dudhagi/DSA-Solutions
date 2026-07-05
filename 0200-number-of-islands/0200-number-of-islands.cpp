class Solution {
public:
    void bfs(int row, int col,vector<vector<bool>> &vis, vector<vector<char>> &grid ){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push(pair{row, col});
        int n = grid.size(), m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse the neighbours and mark them visited if it's a land
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nrow = row + dx[i], ncol = col + dy[i];
                    if(nrow>=0 && nrow < n && ncol >= 0 && ncol < m && 
                        grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                    }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> vis(row, vector<bool> (col, false));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(vis[i][j] != 1 && grid[i][j] == '1'){
                    bfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};