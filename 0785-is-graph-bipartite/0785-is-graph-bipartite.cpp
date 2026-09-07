class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, int color){
        vis[node] = color;

        for(int adjNode : graph[node]){
            if(vis[adjNode] == -1){
                if(dfs(adjNode, graph, vis, !color) == false) return false;
            }
            else if(vis[adjNode] == color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                if(dfs(i, graph, vis, 0) == false){
                    return false;
                }
            }
        }
        return true;
    }
};