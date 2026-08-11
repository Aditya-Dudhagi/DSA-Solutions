struct Node{
    Node* links[26];
    bool flag;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag = true;
    }

};

class Trie {
private:
Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch: word){
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string prefix) {
        Node* node = root;
        for(char ch : prefix){
            if(node->containsKey(ch)){
                node = node->get(ch);
            }
            else return false;
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix){
            if(node->containsKey(ch)){
                node = node->get(ch);
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */