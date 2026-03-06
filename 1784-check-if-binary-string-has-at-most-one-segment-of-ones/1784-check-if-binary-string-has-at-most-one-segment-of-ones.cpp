class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        char lastch = s[0];
        int i=1;
        while(s[i] == '1'){
            i++;
        }
        while(s[i] == '0') i++;

        return i==s.size();
    }
};