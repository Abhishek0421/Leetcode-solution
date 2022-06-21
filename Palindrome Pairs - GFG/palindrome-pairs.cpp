// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    struct trienode{  // make structure of trie..
      	bool isendofword;
        trienode* children[26];
    };
    trienode* getnode(){   // for generating new trienode
        struct trienode* ne=new trienode;
        ne->isendofword=false;
        for(int i=0;i<26;i++){
            ne->children[i]=NULL;
        }
        return ne;
    }
    void insert(trienode* root,string &key){   //  insertion in trienode
        struct trienode* cp=root;
        for(int i=0;i<key.size();i++){
            int ind=key[i]-'a';
            if(cp->children[ind]==NULL){
                cp->children[ind]=getnode();
            }
            cp=cp->children[ind];
        }
        cp->isendofword=true;
    }
    bool search(trienode* root,string &key){  // searching in trienode
        struct trienode* cp=root;
        for(int i=0;i<key.size();i++){
            int ind=key[i]-'a';
            if(cp->children[ind]==NULL){   // if not found return false;
                return false;
            }
            cp=cp->children[ind];
        }
        return cp->isendofword==true; // check if it is end of word or not.
    }
    bool ispalindrome(string t){ // to check if it is palindrome or not
        int i=0,j=t.size()-1;
        while(i<j){
            if(t[i++]!=t[j--]){
                return false;
            }
        }
        return true;
    }
    bool palindromepair(int N, string words[]) {
        // code here
        if(N==1) return 0;
        struct trienode* rt=getnode();
        map<string,int> mp;
        for(int i=0;i<N;i++){
            reverse(words[i].begin(),words[i].end());
            mp[words[i]]=i; // mapping words to index
            insert(rt,words[i]); // inserting words
            reverse(words[i].begin(),words[i].end());
        }
       
        if(mp.count("")){
            for(int i=0;i<N;i++){
                if(words[i]!="" && ispalindrome(words[i])){
                    return 1;  // making a seperate case for empty strings
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<words[i].size();j++){
                string left=words[i].substr(0,j),right=words[i].substr(j);  // breaking string in 2 parts
                if(search(rt,left) && ispalindrome(right) && mp[left]!=i){  // as discussed
                    return 1;
                }
                if(search(rt,right) && ispalindrome(left) && mp[right]!=i){// as discussed
                    return 1;
                }
            }
        }
        return 0;
    }

};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends