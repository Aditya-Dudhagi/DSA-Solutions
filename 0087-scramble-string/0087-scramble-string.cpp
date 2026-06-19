class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(string a, string b){
        if(a.compare(b) == 0) return true;
        if(a.length()<= 1) return false;

        string tmp = a + ' ' + b;
        if(mp.find(tmp) != mp.end()) return mp[tmp];

        int n = a.length();
        bool flag = false;
        
        // swap & no swap
        for(int i=1; i<=n-1; i++){
            if((solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0,n-i))) || 
                (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i,n-i)))){
                    flag = true;
                    break;
                }
            
        }
        return mp[tmp] = flag;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};