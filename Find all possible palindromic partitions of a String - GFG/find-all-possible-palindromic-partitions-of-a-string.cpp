// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool is_pal(string s){
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> res;
    void solve(string &s,int i,string t,vector<string> &v){
        if(i==s.length()){
            int size=0;
            for(auto x:v){
                size+=x.length();
            }
            if(size==s.length()){
                res.push_back(v);
            }
            return;
        }
        //string temp = t+s[i];
        if(is_pal(t+s[i])){
            v.push_back(t+s[i]);
            solve(s,i+1,"",v);
            v.pop_back();
        }
        solve(s,i+1,t+s[i],v);
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string> v;
        solve(S,0,"",v);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends