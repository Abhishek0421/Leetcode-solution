// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    int dp[1001][1001];
    int mod = 1e9+7;
    int solve(int i,int j,string &str){
        if(i==j) return 1;
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(str[i]==str[j]){
            return dp[i][j] =  (((1 + solve(i+1,j,str))%mod + solve(i,j-1,str))%mod)%mod;
        }
        return dp[i][j]=((solve(i+1,j,str) + solve(i,j-1,str))%mod +(mod - solve(i+1,j-1,str))%mod)%mod;
    }
    long long int  countPS(string str)
    {
       //Your code here
       memset(dp,-1,sizeof(dp));
       return solve(0,str.length()-1,str);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends