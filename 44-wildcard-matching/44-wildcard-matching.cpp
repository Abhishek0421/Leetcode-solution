class Solution {
public:
    bool solve(string &s,string& p,int i,int j,vector<vector<int>> &dp){
        if(i==s.length() && j==p.length()){
            return true;
        }
        if(j==p.length()){
            return false;
        }
        if(i==s.length()){
            bool f = true;;
            while(j<p.length()){
                if(p[j]!='*'){
                    f = false;
                    break;
                }
                j++;
            }
            return f;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j]){
            return dp[i][j] = solve(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='?'){
            return dp[i][j] = solve(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j] = solve(s,p,i,j+1,dp) || solve(s,p,i+1,j,dp);
        }
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p){
        vector<vector<int>> dp(s.length()+1,vector<int> (p.length()+1,-1));
        return solve(s,p,0,0,dp);
    }
};