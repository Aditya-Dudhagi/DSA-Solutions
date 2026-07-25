class Solution {
public:
    int maxProduct(int n) {
        int first = 0, sec = 0;
        while(n>0){
            int ldig = n%10;
            if(ldig>first) {
                sec = first;
                first = ldig;
            } else if(ldig > sec) sec = ldig;
            n /= 10;
        }
        return first*sec;
    }
};