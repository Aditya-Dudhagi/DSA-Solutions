class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> charac(26, 0);

        for(int i=0; i<s.size(); i++){
            charac[s[i]-'a']++;
            charac[t[i]-'a']--;
        }

        for(int i=0; i<26; i++){
            if(charac[i] != 0) return false;
        }
        return true;
    }
};