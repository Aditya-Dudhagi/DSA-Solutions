class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        vector<int> hash(100001, 0);
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        vector< int> mp(100001, 0);
        for(int i=0; i<hash.size(); i++){
            if(hash[i]>0) mp[hash[i]]++;
        }

        for(int i:nums){
            if(mp[hash[i]] == 1) return i;
        }

        return -1;
    }
};