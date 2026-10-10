class Pair{
public:
    int x, y, dist;
    Pair(int a, int b, int d){
        x = a;
        y = b;
        dist = d;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis = mat;
        vector<vector<int>> ans(m, vector<int> (n, 0));
        
        queue<Pair> q;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        // assume 0 means rotten orange and 1 is fresh orange

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push(Pair(i, j, 0));
                    vis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int row = it.x, col = it.y, dis = it.dist;

            for(int i=0; i<4; i++){
                int nrow = row + dx[i], ncol = col + dy[i];
                if(nrow>=0 && nrow<m && ncol >=0 && ncol < n && mat[nrow][ncol] == 1 && vis[nrow][ncol] != 0){
                    ans[nrow][ncol] = dis + 1;
                    vis[nrow][ncol] = 0;
                    q.push(Pair(nrow, ncol, dis + 1));
                }
            }
        }
        return ans;
    }
};