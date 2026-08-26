class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int l = 0, r = 0;
        int ones = 0;
        string ans = "";
        while(r<n){
            if(s[r] == '1') ones++;

            while(ones>k){
                if(s[l] == '1') ones--;
                l++;
            }

            while(ones == k && s[l] == '0') l++;


            if(ones == k){
                string tmp = s.substr(l, r-l+1);

                if(ans == "" || tmp.size() < ans.size()){
                    ans = tmp;
                }
                else if(ans.size() == tmp.size() && tmp < ans) ans = tmp;
            }
            r++;
        }
        return ans;
    }
};