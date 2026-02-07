class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<char> st;
        int delcnt = 0;

        for(int i=0; i<n; i++){
            if(!st.empty() && st.top() == 'b' && s[i] == 'a'){
                st.pop();
                delcnt++;
            } else st.push(s[i]);
        }
        return delcnt;
    }
};