class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        vector<int> hash(100001, 0);
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        map<int, int> mp;
        for(int i=0; i<hash.size(); i++){
            if(hash[i]>0) mp[hash[i]]++;
            
        }
        int ans = -1;
        for(int i:nums){
            if(mp[hash[i]] == 1) return i;
        }

        return -1;
    }
};