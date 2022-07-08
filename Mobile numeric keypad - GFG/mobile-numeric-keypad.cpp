// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long dp[10][26];
	int k[4][3]={{1,2,3},
	             {4,5,6},
	             {7,8,9},
	             {-1,0,-1}};
	long long int solve(int i,int j,int n){
	    if(i<0 || j<0 || i>=4 || j>=3 || k[i][j]==-1){
	        return 0;
	    }
	    if(n==1){
	        return 1;
	    }
	    if(dp[k[i][j]][n]!=-1){
	        return dp[k[i][j]][n];
	    }
	    long long int ans = 0;
	    ans += solve(i,j,n-1);
	    ans += solve(i+1,j,n-1);
	    ans += solve(i-1,j,n-1);
	    ans += solve(i,j+1,n-1);
	    ans += solve(i,j-1,n-1);
	    
	    return dp[k[i][j]][n]=ans;
	}
	long long getCount(int N)
	{
		// Your code goes here
		long long int res=0;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<4;i++){
		    for(int j=0;j<3;j++){
		        res+=solve(i,j,N);
		    }
		}
		return res;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends