// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long mod;
    long long solve(string str)
    {
        int n = str.length();
        long long dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i+1==j)
                {
                    if(str[i]==str[j])
                    {
                        dp[i][j]+=3%mod;
                    }
                    else
                        dp[i][j]+=2%mod;
                }
                else if(str[i]==str[j])
                {
                    dp[i][j]+=(dp[i+1][j-1]%mod+1%mod+dp[i+1][j]%mod+dp[i][j-1]%mod-dp[i+1][j-1]%mod)%mod;
                }
                else
                    dp[i][j]+=(mod + dp[i+1][j]%mod+dp[i][j-1]%mod-dp[i+1][j-1]%mod)%mod;
            }
        }
        return dp[0][n-1]%mod;
    }
    long long int  countPS(string str)
    {
        mod=1e9+7;
        return solve(str);
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