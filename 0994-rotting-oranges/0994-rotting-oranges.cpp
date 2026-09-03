class Pair{
public:
    int x, y, t;
    Pair(int x, int y, int t){
        this->x = x;
        this->y = y;
        this->t = t;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<Pair> pq;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    pq.push(Pair(i, j, 0));
                }
            }
        }

        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int row = it.x, col = it.y, time = it.t;
            
            ans = time;

            for(int i=0; i<4; i++){
                int nrow = row + dx[i], ncol = col + dy[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                    pq.push(Pair(nrow, ncol, time + 1));
                    grid[nrow][ncol] = 2;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};