class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int small = -1, large = -1;
        sort(nums.begin(), nums.end());
        int k=nums[0];
        for(int i=0; i<nums.size(); i++){
            if(k == nums[i]){
                k++;
                continue;
            } else {
                ans.push_back(k);
                i--;
            }
            k++;
        }
        return ans;
    }
};