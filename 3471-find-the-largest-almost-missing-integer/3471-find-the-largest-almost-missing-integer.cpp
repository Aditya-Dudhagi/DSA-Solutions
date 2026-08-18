class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> windowCnt;
        for(int i=0; i<=n-k; i++){
            set<int> seenInWindow;
            for(int j=i; j<i+k; j++){
                seenInWindow.insert(nums[j]);
            }

            for(auto it : seenInWindow){
                windowCnt[it]++;
            }
        }

        if(k == 1 || k == n){
            int ans = INT_MIN;
            for(auto it : windowCnt){
                if(it.second == 1){
                    ans = max(it.first, ans);
                }
            }
            return ans == INT_MIN ? -1 : ans;
        }
        else {
            bool validA = (windowCnt[nums[0]] == 1), validB = (windowCnt[nums[n-1]] == 1);

            if(validA && validB) return max(nums[0] , nums[n-1]);
            if(validA) return nums[0];
            if(validB) return nums[n-1];
            return -1;
        }
    }
};