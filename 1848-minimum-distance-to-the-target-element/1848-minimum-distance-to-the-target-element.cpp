class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        vector<vector<int>> hash(10001);
        int ans = INT_MAX;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]].push_back(i);
        }

        for(int i: hash[target]){
            ans = min(ans, abs(start - i));
        }
        return ans;
        
    }
};