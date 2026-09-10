class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topo sort
        int v = numCourses;
        vector<int> indeg(v, 0);

        vector<int> adj[v];

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;
        for(int i=0; i<v; i++){
            if(indeg[i] == 0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt ++;

            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }

        return cnt == v;
    }
};