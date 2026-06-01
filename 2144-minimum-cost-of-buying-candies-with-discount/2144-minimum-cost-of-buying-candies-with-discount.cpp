class Solution {
public:
    int minimumCost(vector<int>& cost) {
        priority_queue<int> q;
        for(int i:cost) q.push(i);
        int minCost = 0;
        while(!q.empty()){
            if(q.size()>=2){
                minCost += q.top();
                q.pop();
                minCost += q.top();
                q.pop();
                if(q.size()>=1) q.pop();
            } else{
                minCost += q.top();
                q.pop();
            }
        }
        return minCost;
    }
};