class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
       
        for(int i=0; i<tokens.size(); i++){
            string ch = tokens[i];
            if(ch == "+" || ch=="-"||ch=="/" || ch=="*"){
                
                int second = stoi(st.top());
                st.pop();
                int first = stoi(st.top());
                st.pop();
                if(ch == "+") st.push(to_string(first+second));
                if(ch == "-") st.push(to_string(first-second));
                if(ch == "/") st.push(to_string(first/second));
                if(ch == "*") st.push(to_string(first*second));
            } else {
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};