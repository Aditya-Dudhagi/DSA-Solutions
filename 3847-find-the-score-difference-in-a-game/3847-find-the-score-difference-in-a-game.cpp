class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        bool p1 = true;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2){
                p1 ^= 1;
            }
            if((i+1)%6 == 0){
                p1 ^= 1;
            }
                if(p1) s1+= nums[i];
                else s2 += nums[i];
        }
        return s1-s2;
    }
};