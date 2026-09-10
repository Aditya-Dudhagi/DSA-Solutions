class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> indeg(V, 0);

        vector<int> adjrev[V];

        for(int i=0; i<V; i++){
            for(auto it : graph[i]){
                adjrev[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> safe;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int i: adjrev[node]){
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }
            
        sort(safe.begin(), safe.end());
        return safe;
    }
};