class Solution {
public:
    int safemod(int a, int n){
        return (a%n + n)%n;
    }
    int minOperations(string s) {
        int ans = INT_MAX;
        int n = s.size();
        for(int i=0; i<n; i++){
            string tmp = s;
            rotate(tmp.begin(), tmp.begin() + i, tmp.end());
            int cnt = 0;
            if(tmp == s) cnt = 0;
            else cnt = i;
            for(int j=0; j<n/2; j++){
                cnt += min(safemod(tmp[j] - tmp[n-j-1], 26), safemod(tmp[n-j-1]-tmp[j], 26));
            }
            ans = min(ans, cnt);
        }

        return ans;
    }
};