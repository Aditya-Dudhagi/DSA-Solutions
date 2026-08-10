class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int>mp;
        vector<pair<int, char>> v;
        for(char c:s){
            mp[c]++;
        }

        for(auto &[ch, cnt]:mp){
            v.push_back({cnt, ch});
        }

        sort(v.begin(), v.end(), greater<pair<int, char>>());

        for(auto it: v){
            ans += string(it.first, it.second);
        }
        return ans;
    }
};