class Solution {
public:
    bool hasAlternatingBits(int n) {
        // int bit = n&1;
        // // int size = log2(n);
        // // string binary = bitset<size>(n).to_string();
        // while(n>0){
        //     if(n&1 != bit) return false;
        //     n >>=1;
        //     bit ^= 1;
        // }
        // return true;
        
        long x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    

    }
};