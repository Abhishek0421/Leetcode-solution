// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
        int n = S.length();
        int dp[n][n];
        int start=0,len=0;
        for(int g=0;g<n;g++){
            for(int i=0,j=i+g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if(g==1){
                    if(S[i]==S[j]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(S[i]==S[j] && dp[i+1][j-1]==1){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                if(dp[i][j]==1){
                    if(len >= j-i+1) continue;
                    start = i;
                    len = j-i+1;
                }
            }
        }
        return S.substr(start,len);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends