class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string binary = "";
        for(char ch : s){
            string bin = bitset<8>(ch).to_string();
            binary = binary + bin;
        }
        return isPalindrome(binary);
    }
};