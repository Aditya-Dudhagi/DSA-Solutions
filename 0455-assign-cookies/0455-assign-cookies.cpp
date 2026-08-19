class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int cnt = 0;
        int ind = 0;
        for(int i=0; i<s.size(); i++){
            if(ind == g.size()) break;
            if(s[i] >= g[ind]){
                cnt++;
                ind++;
            } else continue;

        }
        return cnt;
    }
};