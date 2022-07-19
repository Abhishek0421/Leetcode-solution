class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(i==s.length() && j<t.length()){
            return 0;
        }
        if(j==t.length()){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j] = solve(i+1,j+1,s,t,dp) + solve(i+1,j,s,t,dp);
        }
        return dp[i][j] = solve(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(),vector<int> (t.length(),-1));
        return solve(0,0,s,t,dp);
    }
};