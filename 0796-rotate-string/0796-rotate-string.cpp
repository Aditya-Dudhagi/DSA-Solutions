class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()) return false;

        string con = s+s;

        if(con.find(goal) < con.length()) return true;
        else return false;

    }
};