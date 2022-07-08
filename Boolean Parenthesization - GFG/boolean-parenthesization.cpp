// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int solve(string &s ,int i,int j,int f){
        if(i>j)return 0;
        if(i==j){
            if(f){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        if(dp[i][j][f]!=-1) return dp[i][j][f];
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            int lt = solve(s,i,k-1,1);
            int lf = solve(s,i,k-1,0);
            int rt = solve(s,k+1,j,1);
            int rf = solve(s,k+1,j,0);
            if(s[k]=='|'){
                if(f){
                    ans += lt * rt + lt*rf + lf*rt;
                }
                else{
                    ans += lf*rf;
                }
            }
            else if(s[k]=='&'){
                if(f){
                    ans += lt*rt;
                }
                else{
                    ans += lf*rf + lf*rt + lt*rf;
                }
            }
            else{
                if(f){
                    ans += lt*rf + rt*lf;
                }
                else{
                    ans += lf*rf + lt*rt;
                }
            }
        }
        return dp[i][j][f] = ans%1003;
    }
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends