class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size() == 1) return s;
        int n = s.size();
        vector<char> chars;
        for(int i=0; i<n/2; i++){
            chars.push_back(s[i]);
        }
        sort(chars.begin(), chars.end());
        for(int i=0; i<n/2; i++){
            s[i] = s[n-i-1] = chars[i];
        }
        return s;
    }
};