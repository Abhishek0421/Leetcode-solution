// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> res;
    void solve(int i,map<string,int> &mp,string &s,string t,vector<string> &temp){
        if(i==s.length()){
            if(t.length()==0){
                string ans="";
                for(auto x:temp){
                    ans = ans +x+ " ";
                }
                ans = ans.substr(0,ans.length()-1);
                res.push_back(ans);
            }
            return;
        }
        if(mp[t+s[i]]==1){
            temp.push_back(t+s[i]);
            solve(i+1,mp,s,"",temp);
            temp.pop_back();
        }
        solve(i+1,mp,s,t+s[i],temp);
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        map<string,int> mp;
        for(auto x:dict){
            mp[x]=1;
        }
        vector<string> temp;
        solve(0,mp,s,"",temp);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends