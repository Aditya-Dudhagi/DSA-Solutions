class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k) return false;
        map<string, int> mp;
        for(int i=0; i<=s.length()-k; i++){
            mp[s.substr(i, k)] ++;
        }
        for(auto it:mp){
            cout<<it.first<<": "<<it.second<<endl;
        }
        return mp.size() == pow(2, k);
    }
};