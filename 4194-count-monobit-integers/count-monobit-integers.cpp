class Solution {
public:
    int countMonobit(int n) {
        int ans = 0;
        if(n == 0) return 1;
        else if(n == 1) return 2;
        else ans = 2;
        for(int i=2; i<=n; i++){
            int size = int(log2(i)) + 1;
            if(__builtin_popcount(i) == size) ans++;
        }

        return ans;
    }
};