// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class TrieNode{
    public:
       TrieNode* child[26];
       bool flag;
       TrieNode(){
           for(int i=0;i<26;i++){
               this->child[i]=NULL;
           }
           this->flag = false;
       }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    TrieNode* insert(string &s,TrieNode* root){
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(!node->child[s[i]-'a']){
                TrieNode* nnode = new TrieNode();
                node->child[s[i]-'a']=nnode;
            }
            node = node->child[s[i]-'a'];
        }
        node->flag = true;
        return root;
    }
    bool search(string &s,TrieNode* root){
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(!node->child[s[i]-'a']){
                return false;
            }
            node = node->child[s[i]-'a'];
        }
        return node->flag;
    }
    bool func(string &s,int j,TrieNode* root){
       if(j==s.size()) return true;
       string t;
       for(int i=j;i<s.size();i++){
           t.push_back(s[i]);
           if(search(t,root) and func(s,i+1,root)) return 1;
       }
       return 0;
   }
    int wordBreak(string A, vector<string> &B) {
        //code here
        TrieNode* root = new TrieNode();
        for(int i=0;i<B.size();i++){
            root = insert(B[i],root);
        }
        return func(A,0,root);
        
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends