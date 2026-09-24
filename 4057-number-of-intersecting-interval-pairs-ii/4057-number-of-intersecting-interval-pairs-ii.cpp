class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        vector<int> startingPos;
        sort(intervals.begin(), intervals.end());

        for(auto it : intervals){
            startingPos.push_back(it[0]);
        }

        long long ans = 0; 

        for(int i=0; i<intervals.size(); i++){
            int pos = upper_bound(startingPos.begin(), startingPos.end(), intervals[i][1]) - startingPos.begin();

             ans += pos - i -1;
        }

        return ans;
    }
};