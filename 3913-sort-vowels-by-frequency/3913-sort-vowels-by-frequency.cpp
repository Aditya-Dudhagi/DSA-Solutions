class Solution {
public:
    string sortVowels(string s) {
        map<char, int> mp;
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        for(char ch:s){
            if(st.count(ch)) mp[ch]++;
        }
        vector<pair<char, int>> fin;
        for(char ch:s){
            if(st.count(ch)){
                fin.push_back({ch, mp[ch]});
                st.erase(ch);
            }
        }

        sort(fin.begin(), fin.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });

        int j=0;
        st = {'a', 'e', 'i', 'o', 'u'};
        for(int i=0; i<s.size(); i++){
            if(st.count(s[i])){ // if vowel
                if(fin[j].second>0){
                    s[i] = fin[j].first;
                    fin[j].second--;
                }
                if(fin[j].second == 0) j++;
            }
        }
        return s;
    }
};