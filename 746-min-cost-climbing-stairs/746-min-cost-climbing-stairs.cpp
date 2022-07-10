class Solution {
public:
    int dp[1001];
    int solve(vector<int> &cost,int i){
        if(i>=cost.size()){
            return 0;
        }
        if(i==cost.size()-1){
            return dp[i] = 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i] =  min(cost[i]+solve(cost,i+1),cost[i+1]+solve(cost,i+2));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return solve(cost,0);
    }
};