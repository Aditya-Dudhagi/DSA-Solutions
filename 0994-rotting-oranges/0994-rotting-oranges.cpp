class Pair{
    public:
    int x, y, t;
    Pair(int r, int c, int t){
        x = r, y = c, this->t = t;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis = grid;
        int dx[] = {-1, 0 , 1, 0};
        int dy[] = { 0 , 1, 0, -1};

        queue<Pair> q;
        int time = 0, fresh = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push(Pair(i, j, 0));
                } else if(grid[i][j] == 1) fresh++;
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int row = q.front().x, col = q.front().y;
            time = q.front().t;

            q.pop();
            for(int i=0; i<4; i++){
            int nrow = row + dx[i], ncol = col + dy[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && vis[nrow][ncol]!=2){
                    vis[nrow][ncol] = 2;
                    cout<<nrow<<" "<<ncol<<" "<<time+1<<endl;
                    q.push(Pair(nrow, ncol, time+1));
                    cnt++;
                }
            }
        }

        return cnt == fresh ? time : -1;

    }
};