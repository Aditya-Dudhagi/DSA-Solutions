class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size();
        sort(tmp.begin(), tmp.end());
        map<int, int> pref;
        int num = nums[0], smallcnt = 0, same = 0;
        for(int i=0; i<nums.size(); i++){
            if(i==0) pref[tmp[i]] = 0;
            else if(tmp[i] != tmp[i-1]){
                pref[tmp[i]] = i;
            } else {
                if(pref.find(tmp[i]) == pref.end()) pref[tmp[i]] = i; 
            }
        }

        vector<int> ans ;
        for(int i=0; i<n; i++){
            ans.push_back(pref[nums[i]]);
        }   
        return ans;
    }
};