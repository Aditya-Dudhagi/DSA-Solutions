class Solution {
public:
    string maximumXor(string s, string t) {
        map<int, int> mp;
        for(int i=0; i<s.size(); i++){
            // mp[s[i]-'0']++;
            mp[t[i] - '0']++;
        }

        string rearrT = "", ans = "";
        for(int i=0; i<s.size(); i++){
            if((s[i] == '0' && mp[1]>0) || (s[i] == '1' && mp[0]==0)){
                rearrT.push_back('1');
                mp[1]--;
            } else if((s[i] == '1' && mp[0]>0) || (s[i] == '0' && mp[1]==0)){
                rearrT.push_back('0');
                mp[0]--;
            }
        }
        for(int i=0; i<s.size(); i++){
            int t1 = s[i] - '0', t2 = rearrT[i] - '0';
            ans += (t1^t2) + '0';
        }
        return ans;
    }
};