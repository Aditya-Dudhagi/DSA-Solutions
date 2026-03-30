class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0; i<2; i++){
            if(s1[i] == s2[i] && s1[i+2] == s2[i+2]) continue;
            else if(s1[i] == s2[i+2] && s1[i+2] == s2[i]) continue;
            else return false;
        }
        return true;
    }
};