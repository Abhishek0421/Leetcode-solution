class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>> &t){
        if(i==t.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = t[i][j] + min(solve(i+1,j+1,t),solve(i+1,j,t));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,triangle);
    }
};