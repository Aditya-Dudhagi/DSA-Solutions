class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                v++;
            } else if(ch == ' ' || (ch>='0' && ch<= '9')){
                continue;
            } else c++;
        }
        if(c == 0) return 0;
        return floor(v/c);
    }
};