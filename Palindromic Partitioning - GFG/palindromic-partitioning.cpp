// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501];
    bool is_pal(string &s,int i,int j){
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string &str,int i,int n){
        if(i>=n){
            return 0;
        }
        if(is_pal(str,i,n-1)){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        int mincost = INT_MAX;
        for(int k=i;k<n;k++){
            if(is_pal(str,i,k)){
                int cost = 1 + solve(str,k+1,n);
                mincost=min(mincost,cost);
            }
        }
        return dp[i] = mincost;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.length())-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends