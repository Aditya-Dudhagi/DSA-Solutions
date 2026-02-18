class Solution {
public:
    
    int integerReplacement(int n) {
        int cnt = 0;
        long nn = n;
        while(nn!=1){
            if(nn%2 == 0){
                nn/=2;
            }  
            else if(nn == 3 || (nn&3) == 1) nn--;
            else nn++;
            cnt++;
        }
        return cnt;
    }
};