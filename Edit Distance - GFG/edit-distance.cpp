// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int dp[101][101];
    int solve(string s,string t,int i,int j){
        if(i>=s.length()) return t.length()-j;
        if(j>=t.length()) return s.length()-i;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j] = solve(s,t,i+1,j+1);
        }
        return dp[i][j] = 1 + min(min(solve(s,t,i+1,j),solve(s,t,i+1,j+1)),solve(s,t,i,j+1));
    }
    int editDistance(string s, string t) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends