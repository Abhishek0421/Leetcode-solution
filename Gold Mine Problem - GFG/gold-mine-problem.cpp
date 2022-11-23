//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>> &M, int n, int m, vector<vector<int>> &memo, int i, int j){
        if(i<0 or i>=n or j<0 or j>=m){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        int upperRight = solve(M,n,m,memo,i+1,j+1);
        int right = solve(M,n,m,memo,i,j+1);
        int lowerRight = solve(M,n,m,memo,i-1,j+1);
        
        memo[i][j] = M[i][j] + max(right, max(upperRight,lowerRight));
        
        return memo[i][j];
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int maxAmount = -1;
        vector<vector<int>> memo(n, vector<int>(m, -1));
        
        for(int i=0; i<n; i++){
            maxAmount = max(maxAmount, solve(M,n,m,memo,i,0));
        }
        
        return maxAmount;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends