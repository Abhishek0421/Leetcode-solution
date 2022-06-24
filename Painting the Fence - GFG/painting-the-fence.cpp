// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int dp[5001][3];
    int solve(int n,int k,int i,int prevcol,int count){
        if(i>n){
            return 1;
        }
        if(dp[i][count]!=-1){
            return dp[i][count];
        }
        int ans = 0;
        for(int j=1;j<=k;j++){
            if(prevcol==j && count==2){
               continue;
            }
            else{
                if(prevcol==j){
                    ans = ans + solve(n,k,i+1,j,count+1);
                }
                else{
                    ans = ans + solve(n,k,i+1,j,1);
                }
                ans%=1000000007;
            }
        }
        return dp[i][count]=ans;
    }
    long long countWays(int n, int k){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(n,k,1,0,0);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends