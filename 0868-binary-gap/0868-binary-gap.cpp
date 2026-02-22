class Solution {
public:
    int binaryGap(int n) {
        int last_one = -1, dist = 0;
        for(int i=0; i<32; i++){
            if(n&(1<<i)){
                if(last_one != -1){
                    dist = max(dist, abs(last_one - i));
                    last_one = i;
                } else last_one = i;
            }
        }
        return dist;
    }
};