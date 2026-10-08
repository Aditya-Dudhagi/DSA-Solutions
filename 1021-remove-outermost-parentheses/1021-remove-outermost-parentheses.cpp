class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') {
                if(cnt>0) {
                    ans += s[i];
                }
                    cnt++;
            }
            else{
                if(cnt>1){
                    ans += s[i];
                }
                    cnt--;
            }

        }
        
        return ans;
    }
};