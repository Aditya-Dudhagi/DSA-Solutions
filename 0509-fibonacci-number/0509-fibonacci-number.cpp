class Solution {
public:
    int t[31];
    Solution(){
        memset(t, -1, sizeof(t));
    }
    int solve(int n){
        if(n<=1) return n;
        if(t[n] != -1) return t[n];
        return t[n] = solve(n-1) + solve(n-2);
    }
    int fib(int n) {
        return solve(n);
    }

};