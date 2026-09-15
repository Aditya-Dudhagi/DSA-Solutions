class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int diff = 0;
        vector<int> tmp = nums;
        sort(tmp.begin() , tmp.end());

        int start = -1, end = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != tmp[i]){
                start = i;
                break;
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] != tmp[i]){
                end = i;
                break;
            }
        }

        if(start == -1 || end == -1) return 0;
        return end - start + 1;
    }
};