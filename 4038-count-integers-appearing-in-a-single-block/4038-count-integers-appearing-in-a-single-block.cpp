class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> hash(101, 0);
        int dis = 0;
        int n = nums.size();
        int i=0;

        while(i<n){
            cout<<nums[i]<<" ";
            if(hash[nums[i]] == 0){
                while(i<n){
                    if(i+1<n && nums[i] == nums[i+1]) i++;
                    else break;
                }
                hash[nums[i]] = 1;
            }
            else if(hash[nums[i]] == 1){
                hash[nums[i]] = 2;
                cout<<nums[i]<<" ";
            }
            cout<<hash[nums[i]]<<endl;
            i++;
        }
        
        for(int i=0; i<=100; i++){
            if(hash[i] == 1) dis++;
        }

        return dis;
    }
};