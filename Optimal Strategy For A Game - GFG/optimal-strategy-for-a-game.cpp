// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int solve(int arr[],int i,int j,int n,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] = max(arr[i]+min(solve(arr,i+2,j,n,dp),solve(arr,i+1,j-1,n,dp)),arr[j]+min(solve(arr,i+1,j-1,n,dp),solve(arr,i,j-2,n,dp)));
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(arr,0,n-1,n,dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends