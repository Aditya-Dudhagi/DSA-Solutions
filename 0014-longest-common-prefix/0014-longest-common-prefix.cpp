struct Node {
    Node* links[26];
    bool flag;
    int child = 0;

    bool containsKey(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag = true;
    }

    void increaseChild(){
        child++;
    }

    int getChild(){
        return child;
    }
};

class Trie{
private:
    Node* root;
public: 
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
                node->increaseChild();
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    string commonPref(string word){
        Node* node = root;
        string longest = "";

        while(node){
            if(node->getChild() > 1 || node->isEnd() == true) break;

            for(int i=0; i<26; i++){
                char ch = i+97;
                if(node->containsKey(char(i+97))){
                    longest += ch;
                    node = node->get(ch);
                    break;
                }
            }
            
        }
        return longest;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(string st: strs){
            trie.insert(st);
        }

        string ans = "";

        for(int i=0; i<strs.size(); i++){
            string pref = trie.commonPref(strs[i]);
            cout<<pref<<" ";
            cout<<i<<endl;
            if(pref.size()<ans.size() || ans.empty()){
                ans = pref;
            } else continue;
        }
        return ans;
    }
};