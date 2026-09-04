class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> vis = image;
        int iniColor = image[sr][sc];
        queue<pair<int, int>> q;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = { 0, 1, 0, -1};

        q.push({sr, sc});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int row = it.first, col = it.second;
            if(image[row][col] == iniColor && vis[row][col] != color) vis[row][col] = color;

            for(int i=0; i<4; i++){
                int nrow = row + dx[i] , ncol = col + dy[i];

                if(nrow>=0 && nrow<m && ncol >= 0 && ncol<n && image[nrow][ncol] == iniColor &&  vis[nrow][ncol] != color){
                    vis[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        return vis;
    }
};