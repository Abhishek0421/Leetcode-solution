// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int solve(vector<int> &p,int i,int n,int c,int t,vector<vector<vector<int>>> &dp){
    if(t==2){
        return 0;
    }
    if(i>=n){
        return 0;
    }
    if(dp[i][t][c]!=-1){
        return dp[i][t][c];
    }
    if(c==0){
       return dp[i][t][c]  =max(solve(p,i+1,n,c,t,dp),-p[i]+solve(p,i+1,n,1,t,dp));
    }
    return dp[i][t][c] = max(solve(p,i+1,n,c,t,dp),p[i]+solve(p,i+1,n,0,t+1,dp));
}
int maxProfit(vector<int>&price){
    //Write your code here..
    vector<vector<vector<int>>> dp(price.size() + 1, vector<vector<int>> (3, vector<int> (2, -1)));
    return solve(price,0,price.size(),0,0,dp);
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends