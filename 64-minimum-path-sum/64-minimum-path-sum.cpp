class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>> &grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j >=grid[0].size()){
            return 1e9;
        }
        if(i==grid.size()-1 && j == grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = grid[i][j] + min(solve(grid,i+1,j),solve(grid,i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0);
    }
};