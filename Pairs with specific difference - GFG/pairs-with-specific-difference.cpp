// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    
    int solve(int arr[],int n,int k,int i,int j,vector<vector<int>> &dp){
        if(j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0,ntake=0;
        if(arr[i]-arr[j]<k){
            take = arr[i]+arr[j]+solve(arr,n,k,j-1,j-2,dp);
        }
        ntake = solve(arr,n,k,i-1,j-1,dp);
        return dp[i][j] = max(take,ntake);
    }
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        //Your code goes here 
        
        vector<vector<int>> dp(N+1,vector<int> (N+1,-1));
        sort(arr,arr+N);
        
        return solve(arr,N,K,N-1,N-2,dp);
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends