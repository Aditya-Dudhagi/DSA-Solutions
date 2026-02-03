class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0;
        int n = nums.size();
        bool flag = true;
        while(p<n){
            if(p+1<n && nums[p]<nums[p+1]) p++;
            else break;
        }
        int q = p;
        while(q<n){
            if(q+1<n && nums[q]>nums[q+1]) q++;
            else break;
        }
        int r = q;
        for(; r<n-1; r++){
            if(nums[r]<nums[r+1]) continue;
            else {
                flag = false;
                break;
            }
        }
        return(p!=0 && q<r && flag);
    }
};