class Solution {
public:
    vector<int> mi{1,-1,0,0};
    vector<int> mj{0,0,1,-1};
    int solve(vector<vector<int>> &a,int i,int j,vector<vector<int>> &dp){
        
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int ans = 1;
        for(int k=0;k<4;k++){
            int x = i+mi[k];
            int y = j+mj[k];
            if(x>=a.size() || y>=a[0].size() || x<0 || y<0 || a[i][j]>=a[x][y]){
                continue;
            }
            ans =max(ans ,1 + solve(a,x,y,dp));
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        int ans = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,solve(matrix,i,j,dp));
            }
        }
        return ans;
    }
};