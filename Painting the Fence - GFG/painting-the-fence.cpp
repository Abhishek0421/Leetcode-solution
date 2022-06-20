// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long  dp[5001][3];
    long long solve(int prevcol,int i,int prev,int n,int k){
        if(i>n){
            return 1;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        long long ans = 0;
        for(int j=1;j<=k;j++){
            if(prev==2 && prevcol==j){
                continue;
            }
            else{
                if(prevcol==j){
                    ans+=solve(j,i+1,prev+1,n,k);
                }
                else{
                    ans+=solve(j,i+1,1,n,k);
                }
                ans%=1000000007;
            }
        }
        
        return dp[i][prev] = ans;
    }
    long long countWays(int n, int k){
        // code here
        memset(dp,-1,sizeof(dp));
       // vector<int> col(k+1,0);
        return solve(0,1,0,n,k);
       
        //return 0;
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