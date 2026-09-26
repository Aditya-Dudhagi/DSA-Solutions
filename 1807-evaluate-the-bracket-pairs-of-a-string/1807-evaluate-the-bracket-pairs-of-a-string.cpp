class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int cnt = 0;
        unordered_map<string, string> mp;
        for(auto it : knowledge){
            mp[it[0]] = it[1];
        }
        string key = "";
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') cnt++;
            else if(s[i] == ')'){
                cnt--;
                if(mp.find(key) == mp.end()){
                    ans.push_back('?');
                }
                else ans += mp[key];
                key = "";
            }
            else if(cnt == 1){
                key += s[i];
            }
            else if(cnt != 1){
                ans += s[i];
            }

        }
        return ans;
    }
};