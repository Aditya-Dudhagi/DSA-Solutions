class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> indeg(V, 0);
        vector<int> adjRev[V];
        for(int i=0; i<V; i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indeg[i]==0) q.push(i);
        }
        
        vector<int> safe;

        while(!q.empty()){
            int node = q.front(); 
            q.pop();
            safe.push_back(node);

            for(int it: adjRev[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};