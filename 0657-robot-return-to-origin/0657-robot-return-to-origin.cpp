class Solution {
public:
    bool judgeCircle(string moves) {
        int U = 1, D = -1, R = 1, L = -1;
        int dx = 0, dy = 0;
        for(char ch : moves){
            if(ch == 'U') dy++;
            else if(ch == 'D') dy--;
            else if(ch == 'R') dx++;
            else dx--;
        }
        return (dx == 0) && (dy == 0);
    }
};