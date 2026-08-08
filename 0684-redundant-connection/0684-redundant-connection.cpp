class DisjointSet{
private: 
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u), ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return ;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } 
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } 
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] ++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // vector<int> graph[n+1];

        // for(auto it:edges){
        //     graph[it[0]].push_back(it[1]);
        //     graph[it[1]].push_back(it[0]);
        // }

        DisjointSet ds(n);

        for(auto it: edges){
            if(ds.findUPar(it[0]) == ds.findUPar(it[1])){
                return it;

            } else {
                ds.unionByRank(it[0], it[1]);
            }
        }
        return {};
    }
};