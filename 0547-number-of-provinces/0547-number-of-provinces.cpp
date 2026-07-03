class Solution {
public:
    void dfs(int node, vector<bool> &visited, vector<int> isConnected[]){
        visited[node] = true;
        for(auto it: isConnected[node]){
            if(!visited[it]){
                dfs(it, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sum = 0;
        int n = isConnected.size();
        vector<int> adj [n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n+1, false);
        // dfs(1, vis, isConnected, sum);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                sum++;
                dfs(i, vis, adj);
            }
        }
        return sum;
    }
};