// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int helper(int n,int x,int y,vector<int> &dp){
    if(n==0)return dp[n]=0;
    if(n==1)return dp[n]=1;
    if(dp[n]!=-1)return dp[n];
    int a=1,b=1,c=1;
    if(n-x>=0) a=helper(n-x,x,y,dp);
    if(n-y>=0) b=helper(n-y,x,y,dp);
    if(n-1>=0) c=helper(n-1,x,y,dp);
    if(a==0 || b==0 || c==0)return dp[n]=1;
    return dp[n]=0;
}
int findWinner(int N, int X, int Y)
{
 vector<int> dp(N+1,-1);
 return helper(N,X,Y,dp);
}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends