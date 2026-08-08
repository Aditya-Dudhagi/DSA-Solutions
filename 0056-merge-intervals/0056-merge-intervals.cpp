class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> inter = {intervals[0][0], intervals[0][1]};

        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0]<=inter[1]){
                inter[1] = max(inter[1], intervals[i][1]);
            } else{
                res.push_back(inter);
                inter = intervals[i];
            }
        }
        res.push_back(inter);
        return res;
    }
};