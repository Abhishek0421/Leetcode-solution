// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //vector<int> v
    int solve(int n,vector<vector<int>> &m,int i,int j,vector<vector<int>> &dp){
        if(j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==n-1){
            return m[i][j];
        }
        return dp[i][j] = m[i][j]+ max(max(solve(n,m,i+1,j,dp),solve(n,m,i+1,j-1,dp)),solve(n,m,i+1,j+1,dp));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int ans = INT_MIN;
        vector<vector<int>> dp(N+1,vector<int> (N+1,-1));
        for(int j=0;j<N;j++){
            ans = max(ans,solve(N,Matrix,0,j,dp));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends