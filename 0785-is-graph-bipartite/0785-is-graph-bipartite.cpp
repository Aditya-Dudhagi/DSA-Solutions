class Solution {
public:
    bool dfs(int start, int color, vector<vector<int>>& graph, vector<int> &colorMat){
        colorMat[start] = color;
        for(int adjnode : graph[start]){
            if(colorMat[adjnode] == -1){
                if(dfs(adjnode, !color, graph , colorMat) == false) return false;
            } 
            else if(colorMat[adjnode] == color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(dfs(i,0, graph, color) == false) return false;
            } 
        }        
        return true;
    }
};