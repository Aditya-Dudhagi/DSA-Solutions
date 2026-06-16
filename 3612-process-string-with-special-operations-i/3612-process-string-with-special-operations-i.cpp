class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '*'){
                if(result.size()>0) result.pop_back();
            } else if(s[i] == '#'){
                result = result + result;
            } else if(s[i] == '%'){
                if(result.size()>0) reverse(result.begin(), result.end());
            } else {
                result += s[i];
            }
        }
        return result;
    }
};