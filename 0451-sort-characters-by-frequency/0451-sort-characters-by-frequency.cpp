class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int>mp;
        priority_queue<pair<int, char>> pq;

        for(char c:s){
            mp[c]++;
        }

        for(auto &[ch, cnt]:mp){
            pq.push({cnt, ch});
        }

        while(!pq.empty()){
            auto [cnt, ch] = pq.top();
            pq.pop();
            while(cnt--){
                ans += ch;
            }
        }
        return ans;
    }
};