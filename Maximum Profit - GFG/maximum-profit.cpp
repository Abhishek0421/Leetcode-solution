// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[1001][201];
    int solve(int k,int i,int j,int a[],int n){
        
        if(k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(j>=n){
            return 0;
        }
        if(a[i]<a[j]){
            return dp[i][k] = max(a[j]-a[i] + solve(k-1,j,j+1,a,n) , solve(k,i,j+1,a,n));
        }
        else{
            return dp[i][k] =  solve(k,j,j+1,a,n);
        }
        return 0;
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(K,0,1,A,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends