class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int inicolor, int newcolor, int dx[], int dy[]){
        int n = image.size(), m = image[0].size();
        ans[row][col] = newcolor;
        for(int i=0; i<4; i++){
            int nrow = row + dx[i], ncol = col + dy[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == inicolor && ans[nrow][ncol]!=newcolor){
                ans[nrow][ncol] = newcolor;
                dfs(nrow, ncol, ans, image, inicolor, newcolor, dx, dy);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, inicolor, color, dx, dy);
        return ans;
    }
};