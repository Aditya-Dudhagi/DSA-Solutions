class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> board, int dx[], int dy[]){
        vis[row][col] = 0;
        int n = board.size(), m = board[0].size();
        for(int i=0; i<4; i++){
            int nrow = row + dx[i], ncol = col + dy[i];
            if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && board[nrow][ncol] == 'O' && vis[nrow][ncol] != 0){
                dfs(nrow, ncol, vis, board, dx, dy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis (n, vector<int> (m, 1));
        // 0 means cant visit, 1 means can visit
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'X'){
                    vis[i][j] = 0;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j] == 'O'){
                    dfs(i, j, vis, board, dx, dy);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 1){
                    board[i][j] = 'X';
                }
            }
        }
    }
};