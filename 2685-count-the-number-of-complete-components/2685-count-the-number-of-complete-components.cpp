class Solution {
public:
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int &degSum, int &nodes){
        vis[node] = 1;
        degSum += adj[node].size();
        nodes++;

        for(int adjnode : adj[node]){
            if(!vis[adjnode]){
                dfs(adjnode, node, vis, adj, degSum, nodes);
            }   
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> vis(n, 0);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int components = 0;

        for(int i=0; i<n; i++){
            int deg = 0, nodes = 0;
            if(!vis[i]){
                dfs(i, -1, vis, adj, deg, nodes);

                int edges = deg/2;
                if(edges == nodes*(nodes-1)/2){
                    components++;
                }
            }
        }

        return components;
    }
};