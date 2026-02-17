class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, int> mp;
        for(int i:bulbs) mp[i]++;
        vector<int> ans;
        for(auto it:mp){
            if(it.second%2 == 1) ans.push_back(it.first);
        }
        return ans;
    }
};