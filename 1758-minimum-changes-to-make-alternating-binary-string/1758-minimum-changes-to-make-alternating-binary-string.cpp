class Solution {
public:
    int minOperations(string s) {
        int miss1 = 0, miss2 = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]-'0' != (i%2)) miss1++;
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]-'0' != (i+1)%2) miss2++;
        }
        return min(miss1, miss2);
    }
};