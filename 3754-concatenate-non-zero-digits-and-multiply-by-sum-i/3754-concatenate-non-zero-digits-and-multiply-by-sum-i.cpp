class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        long long sum = 0, x =0;
        int tmp = n;
        string number = "";
        while(tmp>0){
            if(tmp%10 != 0){
                sum += tmp%10;
                number.push_back(tmp%10 + '0');
            }
            tmp /= 10;
        }
        reverse(number.begin(), number.end());
        x = stoll(number);
        x*=sum;
        return x;
    }
};