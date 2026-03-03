class Solution {
public:
    string trimTrailingVowels(string s) {
        for(int i=s.size()-1; i>=0; i--){
            char ch = s[i];
            if(ch == 'a' || ch == 'e' ||ch == 'i' ||ch == 'o' || ch == 'u') s.pop_back();
            else break;
        }
        return s;
    }
};