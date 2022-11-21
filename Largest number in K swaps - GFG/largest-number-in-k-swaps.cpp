// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    //vector<string> ans;
    //string ans="";
    void solve(string s,int i,int k,string &ans){
        if(i==s.length()-1 || k==0){
            if(ans < s){
                ans = s;
            }
            return;
        }
        for(int j=i+1;j<s.length();j++){
            if(s[i]<s[j]){
                swap(s[i],s[j]);
                solve(s,i+1,k-1,ans);
                swap(s[i],s[j]);
            }
        }
        solve(s,i+1,k,ans);
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       solve(str,0,k,ans);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends