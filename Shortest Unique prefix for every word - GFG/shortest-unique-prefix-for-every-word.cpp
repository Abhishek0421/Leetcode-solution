// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class TrieNode{
    public:
        TrieNode* child[26];
        bool f;
        int cntprefix;
        TrieNode(){
            for(int i=0;i<26;i++){
                this->child[i]=NULL;
            }
            this->f = false;
            this->cntprefix=0;
        }
};
class Solution
{
    public:
    TrieNode* insert(TrieNode* root,string &s){
       // TrieNode* root = new TrieNode();
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(!node->child[s[i]-'a']){
                TrieNode* nnode = new TrieNode();
                node->child[s[i]-'a'] = nnode;
            }
            node = node->child[s[i]-'a'];
            node->cntprefix++;
        }
        node->f = true;
        return root;
    }
    string  res(TrieNode* root,string &s){
        int j=0;
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(node->cntprefix==1){
                break;
            }
            node = node->child[s[i]-'a'];
            j++;
        }
        return s.substr(0,j);
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        vector<string> v;
        TrieNode* root = new TrieNode();
        for(int i=0;i<n;i++){
            root = insert(root,arr[i]);
        }
        for(int i=0;i<n;i++){
            string s = res(root,arr[i]);
            v.push_back(s);
        }
        return v;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends