class Solution {
public:
    bool isPrime(int n){
        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        return primes.count(n);             
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(; left<=right; left++){
            int set = __builtin_popcount(left);
            if(isPrime(set)) ans++;
        }
        return ans;
    }
};