class Solution {
public:
    int dp[501][501];
    int solve(vector<int> &p,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = max(p[i]+min(solve(p,i+2,j),solve(p,i+1,j-1)),p[j]+min(solve(p,i+1,j-1),solve(p,i,j-2)));
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int mx  = solve(piles,0,piles.size()-1);
        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
        }
        if(sum-mx > mx){
            return false;
        }
        return true;
    }
};