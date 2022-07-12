class Trie{
    public:
    static const int CHARSIZE = 26; 
    Trie* character[CHARSIZE]; 
    bool isLeaf; 
    vector<int> index; 
    Trie(){
        this->isLeaf = false; 
        for (int i = 0; i < CHARSIZE; i++){
            this->character[i] = nullptr;
        }
    }
    
    void insert (string & s, int i){
        Trie * curr = this; 
        for (int i = 0; i < s.size(); i++){
            
            if (curr->character[s[i] - 'a'] == nullptr) curr->character[s[i] - 'a'] = new Trie(); 
            curr = curr->character[s[i] - 'a']; 
            if (curr->character[s[s.size() - 1 - i] - 'a'] == nullptr) curr->character[s[s.size() - 1 -i] -'a'] = new Trie(); 
            curr = curr->character[s[s.size() - 1 - i] - 'a']; 
        }
        curr->isLeaf = true; 
        curr->index.push_back (i); 
    }
    int find (Trie * curr, int p, int s, string & pref, string & suff, bool prefix){
        // how to find the length of a trie. 
        int large = -1; 
        if (p >= pref.size() && s >= suff.size() && curr->isLeaf) large = curr->index.back();// depth of this; 
        if (prefix){
            // if prefix; 
            int index = -1; 
            if (p >= pref.size()){
                for (int i = 0; i < CHARSIZE; i++){
                    if (curr->character[i] != nullptr){
                        index = max (index, find (curr->character[i], p, s, pref, suff, false));                        
                    }
                }
                return max (large, index); 
            }
            else {
                if (curr->character[pref[p] - 'a'] == nullptr) return -1;                
                return max (large, find (curr->character[pref[p] - 'a'], p + 1, s, pref, suff, false)); 
            }
        }
        else {
            if (s >= suff.size()){
                int index = -1; 
                for (int i = 0; i < CHARSIZE; i++){
                    if (curr->character[i] != nullptr){
                        index = max (index, find (curr->character[i], p, s, pref, suff, true)); 
                        
                    }
                }
                return max (large, index); 
            }
            else {
                if (curr->character[suff[s] - 'a'] == nullptr) return -1;
                return max (large, find (curr->character[suff[s] - 'a'], p, s + 1, pref, suff, true));
            }
        }
        return large;
    }
    
};
class WordFilter {
public:
    WordFilter(vector<string>& words) {
      
        trie = new Trie(); 
        int i = 0; 
        for (auto & word : words){
           trie->insert (word, i); 
            i++;
        }
        
    }
    
    int f(string pref, string suff) {
  
        reverse (suff.begin(), suff.end()); 
        return trie->find (trie, 0, 0, pref, suff, true);
        
    }
    Trie * trie; 
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */