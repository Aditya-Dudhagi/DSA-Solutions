class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // int n = nums.size();
        // int xorr = 0;
        // if(n%4 == 1) xorr = 1;
        // else if(n%4 == 2) xorr = n+1;
        // else if(n%4 == 3) xorr = 0;
        // else xorr = n;

        // for(int i:nums){
        //     xorr ^= i;
        // }   
        // cout<<xorr;
        // return {1, 1};
        int n = nums.size();
        vector<int> arr(n, -1);

        for(int i=0; i<n; i++){
            arr[nums[i]-1] ++;
        }

        int fir = -1, sec = -1;
        for(int i=0; i<n; i++){
            if(arr[i] == -1) fir = i+1;
            if(arr[i] == 1) sec = i+1;
        }

        return {sec, fir};
    }
};