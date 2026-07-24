class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n, INT_MAX));
        for(auto it:edges){
            int from = it[0], to = it[1], wt = it[2];
            matrix[from][to] = wt;
            matrix[to][from] = wt;
        }
        for(int i=0; i<n; i++) matrix[i][i] = 0;

        for(int k=0; k<n; k++){
            for(int i=0; i<n ; i++){
                for(int j=0; j<n; j++){
                    if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX) continue;
                    matrix[i][j] = min(matrix[i][k] + matrix[k][j] , matrix[i][j]);
                }
            }
        }

        int cntCity = n, cityNo = -1;

        for(int city = 0; city<n; city++){
            int cnt = 0;
            for(int adjCity = 0; adjCity<n; adjCity++){
                if(matrix[city][adjCity]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntCity){
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }
};