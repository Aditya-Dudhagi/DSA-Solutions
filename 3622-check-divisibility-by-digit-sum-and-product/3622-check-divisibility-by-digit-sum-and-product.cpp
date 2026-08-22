class Solution {
public:
    bool checkDivisibility(int n) {
        int tmp = n;
        int sum = 0, prod = 1;

        while(tmp>0){
            int digi = tmp%10;
            sum += digi;
            prod *= digi;
            tmp /= 10;
        }

        sum += prod;

        return n%sum == 0;

    }
};