class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int> &color){
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()){
            int node = q.front();
            cout<<"Node: "<<node<<" "<<color[node]<<endl;
            q.pop();

            for(int adjnode : graph[node]){
                // if adj node is not colored, then give it opposite color and push into queue
                if(color[adjnode] == -1){
                    color[adjnode] = !color[node];
                    cout<<"Coloring adj node "<<adjnode<<" by color: "<<color[adjnode]<<" & push "<<adjnode<<endl;
                    q.push(adjnode);
                } 
                // if adj node has same color then someone have colored it from other path
                else if(color[adjnode] == color[node]){
                    cout<<"BINGOOO you found someone already colored , that is node: "<<adjnode<<endl;
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(bfs(i, graph, color) == false) return false;
            } 
        }        
        return true;
    }
};