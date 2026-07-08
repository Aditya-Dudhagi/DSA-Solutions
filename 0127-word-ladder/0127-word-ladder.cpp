class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        set<string> st;
        for(string s:wordList) st.insert(s);
        int steps = 0;

        while(!q.empty()){
            string tmp = q.front().first;
            int curr = q.front().second;
            q.pop();
            if(tmp == endWord) return curr;

            for(int i=0; i<tmp.size(); i++){
                for(char c='a'; c<='z'; c++){
                    string tmp2 = tmp;
                    tmp2[i] = c;
                    if(st.find(tmp2)!=st.end()){
                        q.push({tmp2, curr+1});
                        st.erase(tmp2);
                    }
                }
            }
        }
        return 0;
    }   
};