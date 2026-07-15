class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // using topo sort
        int V = numCourses;
        vector<int> indeg(V, 0);
        vector<int> adj[V];
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }   

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indeg[i]==0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it: adj[node]){
                indeg[it] --;
                if(indeg[it] == 0) q.push(it);
            }
        }

        if(ans.size() == V) return ans;
        return {};
    }
};