class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> hash(26, 0);
        int maxi = INT_MIN;
        int n = s.size();
        int i=0, j=0;
        while(j<n){
            hash[s[j]-'a']++;
            if(hash[s[j]-'a'] > 2){
                while(hash[s[j]-'a']>2){
                    hash[s[i]-'a']--;
                    i++;
                }
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};