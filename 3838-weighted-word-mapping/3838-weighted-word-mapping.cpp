class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        map<int, char> mpp;
        for(int i=0; i<26; i++){
            mpp[i] = 'z' -  i;
        }
        for(int i=0; i<words.size(); i++){
            int cnt = 0;
            for(int j=0; j<words[i].size(); j++){
                cnt += weights[words[i][j]-'a'];
                cnt %= 26;
            }
            ans  = ans + mpp[cnt];
        }
        return ans;
    }
};