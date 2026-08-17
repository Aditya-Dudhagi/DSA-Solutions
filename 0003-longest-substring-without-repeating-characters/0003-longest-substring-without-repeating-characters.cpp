class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int cnt = 0;
        map<char, int> mpp;
        int i=0, n = s.size();

        for(int j = 0; j<n; j++){
            mpp[s[j]]++;
            if(mpp[s[j]] == 2){
                while(mpp[s[j]] != 1){
                    mpp[s[i]]--;
                    i++;
                }
                ans = max(ans, j-i+1);
            }
            ans = max(ans, j-i+1);
            // j++;
        }
        return ans;
    }
};