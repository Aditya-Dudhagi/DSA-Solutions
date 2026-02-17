class Solution {
public:

    void sieve_of_eratosthenes(int n, vector<int> &prime){

        prime.assign(n, 1);

        if(n > 0) prime[0] = 0;
        if(n > 1) prime[1] = 0;

        for(int i = 2; i * i < n; i++){
            if(prime[i] == 1){
                for(int j = i * i; j < n; j += i){
                    prime[j] = 0;
                }
            }
        }
    }

    int countPrimes(int n) {

        if(n <= 1) return 0;

        vector<int> prime;

        sieve_of_eratosthenes(n, prime);

        int cnt = 0;

        for(int i = 2; i < n; i++){
            if(prime[i] == 1)
                cnt++;
        }

        return cnt;
    }
};
