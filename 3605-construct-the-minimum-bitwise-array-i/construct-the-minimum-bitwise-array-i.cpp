class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        
    
        for(int i=0; i<nums.size(); i++){
            long long temp=0;
            while( (temp | (temp+1)) != nums[i] && temp<nums[i]) {
                temp++;
            }
            if((temp|(temp+1)) == nums[i]) ans.push_back(temp);
            else ans.push_back(-1);
        }
        return ans;
        
    }
};