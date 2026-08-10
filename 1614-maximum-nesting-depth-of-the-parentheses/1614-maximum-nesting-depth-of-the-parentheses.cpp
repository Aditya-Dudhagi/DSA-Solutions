class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int cnt = 0;
        for(char ch: s){
            if(ch == '('){
                cnt++;
            } else if(ch == ')'){
                ans = max(ans, cnt);
                cnt--;
            }
        }
        return ans;
    }
};