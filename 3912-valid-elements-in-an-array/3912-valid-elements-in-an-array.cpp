class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2) return nums;
        vector<int> prefg(n, 0), sufg(n, 0);
        int maxi = -1;
        for(int i=0; i<nums.size(); i++){
            if(maxi == -1) maxi = nums[i];
            else maxi = max(maxi, nums[i]);
            prefg[i] = maxi;
        }
        maxi = -1;
        for(int i=n-1; i>=0; i--){
            if(maxi == -1) maxi = nums[i];
            else maxi = max(maxi, nums[i]);
            sufg[i] = maxi;
        }
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n-1; i++){
            if(prefg[i]>prefg[i-1]){
                if(prefg[i] == prefg[i-1]) continue;
                else ans.push_back(prefg[i]);
            } else if(sufg[i]>sufg[i+1]){
                if(sufg[i] == sufg[i+1]) continue;
                else ans.push_back(sufg[i]);
            }
        }
        ans.push_back(nums[n-1]);
        return ans;
    }
};