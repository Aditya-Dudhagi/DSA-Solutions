class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int start = -1, end = -1;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i+1);
            }
            else if(s[i] == ')'){
                start = st.top();
                st.pop();
                end = i;
                reverse(s.begin() + start, s.begin() + end);
            }
        }
        string ans = "";
        for(char ch : s){
            if(ch != '(' && ch != ')') ans += ch;
        }
        return ans;
    }
};