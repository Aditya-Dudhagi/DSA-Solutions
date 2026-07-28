class Solution {
public:
    int sum (int num){
        int s = 0;
        while(num>0){
            s += num%10;
            num /= 10;
        }
        return s;
    }
    int largestInteger(int n, int s) {

        for(int i=pow(10, n)-1; i>=0; i--){
            if(sum(i) == s) return i;
        }
        return -1;
    }
};