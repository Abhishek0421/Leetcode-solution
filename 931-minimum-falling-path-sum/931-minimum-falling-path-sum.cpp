class Solution {
public:
    int dp[101][101];
    int solve(int si,int sj,vector<vector<int>> &matrix){
        if(sj>=matrix[0].size() || sj<0){
            return 1e9;
        }
        if(si==matrix.size()-1){
            return matrix[si][sj];
        }
        if(dp[si][sj]!=-1){
            return dp[si][sj];
        }
        int r = matrix[si][sj]+solve(si+1,sj+1,matrix);
        int l = matrix[si][sj]+solve(si+1,sj-1,matrix);
        int d = matrix[si][sj]+solve(si+1,sj,matrix);
        return dp[si][sj] = min({r,l,d});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int j=0;j<matrix[0].size();j++){
            ans =min(ans,solve(0,j,matrix));
        }
        return ans;
    }
};