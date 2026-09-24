class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long sum = 0;
        int n = s.size();
        vector<int> suff(n, 0);

        for(int i=shifts.size()-1; i>=0; i--){
            sum += shifts[i];
            int ch = s[i]-'a';
            ch = (ch+sum%26)%26;
            s[i] = ch + 'a';
        }
        return s;
    }
};