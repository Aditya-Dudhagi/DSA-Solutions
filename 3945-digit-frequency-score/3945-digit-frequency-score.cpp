class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int, int> mp;
        while(n>0){
            mp[n%10]++;
            n/= 10;
        }

        int score = 0;
        for(auto [num, fre]: mp){
            score += num*fre;
        }
        return score;
    }
};