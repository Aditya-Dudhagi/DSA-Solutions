class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        int fresh = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }


        while(!q.empty() && fresh>0){
            
            int size = q.size();
            time++;


            while(size--){
                auto it = q.front();
                q.pop();
                
                int r = it.first, c = it.second;


                for(int i=0; i<4; i++){
                    int nr = r + dx[i], nc = c + dy[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                        q.push({nr, nc});
                        fresh--;
                        grid[nr][nc] = 2;
                    }
                }

            }
        }

        return fresh == 0 ? time : -1;


    }
};