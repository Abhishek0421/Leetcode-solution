class TrieNode{
    public:
    TrieNode* child[26];
    bool flag;
    TrieNode() {
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        flag = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->child[word[i]-'a']){
                TrieNode* nnode = new TrieNode();
                node->child[word[i]-'a'] = nnode;
            }
            node = node->child[word[i]-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->child[word[i]-'a']){
                return false;
            }
            node = node->child[word[i]-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto x:prefix){
            if(!node->child[x-'a']){
                return false;
            }
            node = node->child[x-'a'];
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