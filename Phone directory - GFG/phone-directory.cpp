// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class TrieNode{
    public:
       TrieNode* child[26];
       bool flag;
       TrieNode(){
           for(int i=0;i<26;i++){
               child[i]=NULL;
           }
           flag = false;
       }
};
class Solution{
public:
    TrieNode* insert(TrieNode* root,string &s){
        TrieNode* node = root;
        for(auto x:s){
            if(!node->child[x-'a']){
                TrieNode* nnode = new TrieNode();
                node->child[x-'a']=nnode;
            }
            node = node->child[x-'a'];
        }
        node->flag = true;
        return root;
    }
    void search(TrieNode* root,string &s,vector<vector<string>> &v){
        TrieNode* node = root;
        int j=0;
        for(auto x:s){
            if(!node->child[x-'a']){
                return;
            }
            v[j].push_back(s);
            j++;
            node = node->child[x-'a'];
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> v(s.length());
        TrieNode* root=new TrieNode();
        root = insert(root,s);
        set<string> st;
        for(int i=0;i<n;i++){
            st.insert(contact[i]);
        }
        while(st.size()>0){
            auto it = *st.begin();
            st.erase(st.begin());
            search(root,it,v);
        }
        for(int i=0;i<v.size();i++){
            if(v[i].size()==0){
                v[i].push_back("0");
            }
            else{
                sort(v[i].begin(),v[i].end());
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends