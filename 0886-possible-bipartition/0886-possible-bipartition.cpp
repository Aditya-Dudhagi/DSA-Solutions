class Solution {
public:
    bool bipartite(int node, vector<int> adj[], vector<int> &vis, int color) {
        vis[node] = color;

        for(int adjnode : adj[node]){
            if(vis[adjnode] == -1){
                if(bipartite(adjnode, adj, vis, !color) == false) return false;
            }
            else if(vis[adjnode] == color) return false;
        }

        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        vector<int> vis(n+1, -1);

        for(auto it : dislikes){
            int u = it[0], v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1; i<=n; i++){
            if(vis[i] == -1){
                if(bipartite(i, adj, vis, 0) == false) return false;
            }
        }
        return true;

    }
};