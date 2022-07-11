class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &m,vector<vector<int>> &dp){
        if(i<0||j<0||i>=m.size()||j>=m[0].size()){
            return -1e9;
        }
        if(i==m.size()-1 && j==m[0].size()-1){
            if(m[i][j]>0){
                return 0;
            }
            return m[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left = solve(i,j+1,m,dp);
        int right = solve(i+1,j,m,dp);
        if(max(left,right)+m[i][j]>0){
            return dp[i][j]=0;
        }
        return dp[i][j] = m[i][j] +max(left,right);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(),vector<int> (dungeon[0].size(),-1));
        int ans = solve(0,0,dungeon,dp);
        if(ans<0){
            return ans*(-1)+1;
        }
        return 1;
    }
};