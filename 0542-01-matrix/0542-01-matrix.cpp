class Pair{
    public:
    int row, col, dist;
    Pair(int i, int j, int d){
        row = i, col = j, dist = d;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis = mat;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        // 0 means visited , 1 means not visited
        queue<Pair> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0) q.push(Pair(i, j, 0));   
                             
            }
        }

        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

        int dis = 0;
        while(!q.empty()){
            int row = q.front().row, col = q.front().col, dis = q.front().dist;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + dx[i], ncol = col + dy[i];
                if(nrow>=0 && nrow <m && ncol>=0 && ncol <n && mat[nrow][ncol] == 1 && vis[nrow][ncol] != 0){
                    vis[nrow][ncol] = 0;
                    ans[nrow][ncol] = dis+1;
                    q.push(Pair(nrow, ncol, dis+1));

                }
            }
        }
        return ans;
    }
};