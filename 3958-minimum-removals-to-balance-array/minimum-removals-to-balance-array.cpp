class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1) return 0;
        long long kk = k;
        int i=0, j=1, n = nums.size();
        int ans = 0;
        while(i<n && j<n){
            long long mini = nums[i], maxi = nums[j];
            if(nums[j]<=kk*nums[i]){
                ans = max(ans, j-i+1);
            } else{
                i++;
                continue;
            }
            j++;
        }
        return n - ans;
    }
};