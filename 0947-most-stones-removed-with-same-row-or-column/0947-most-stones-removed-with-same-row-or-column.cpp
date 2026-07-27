class DisjointSet{
    public:
    vector<int> parent, rank, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n ; i++){
            parent[i] = i;
        }
    }
        
    int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        
    void unionByRank(int u, int v){
            int ulp_u = findUPar(u), ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] > rank[ulp_v]){
                rank[ulp_u] ++;
                parent[ulp_v] = ulp_u;
            }else if(rank[ulp_v] > rank[ulp_u]){
                rank[ulp_v]++;
                parent[ulp_u] = ulp_v;
            } else{
                rank[ulp_v]++;
                parent[ulp_u] = ulp_v;
            }
        }
    void unionBySize(int u, int v){
            int ulp_u = findUPar(u), ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] > size[ulp_v]){
                size[ulp_u] += size[ulp_v];
                parent[ulp_v] = ulp_u;
            }else{
                size[ulp_v]+= size[ulp_u];
                parent[ulp_u] = ulp_v;
            }
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0 , maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNode;
        for(auto it : stones){
            int nodeRow = it[0], nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNode[nodeRow] = 1;
            stoneNode[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it: stoneNode){
            if(ds.findUPar(it.first) == it.first) cnt++;
        }
        return n - cnt;
    }
};