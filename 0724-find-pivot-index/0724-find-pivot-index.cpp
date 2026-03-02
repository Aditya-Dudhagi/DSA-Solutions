class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftsum = 0;
        int pivot = -1;
        int n = nums.size();
        total -= nums[0];
        for(int i=0; i<n; i++){
            if(leftsum == total){
                pivot = i;
                break;
            }
            leftsum += nums[i];
            if(i+1<n) total -= nums[i+1];
            
        }
        return pivot;
    }
};