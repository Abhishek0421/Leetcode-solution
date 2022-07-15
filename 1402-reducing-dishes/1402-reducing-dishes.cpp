class Solution {
public:
    int dp[501][501];
    int solve(vector<int> &s,int i,int t){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        return dp[i][t] = max((t+1)*s[i] + solve(s,i+1,t+1),solve(s,i+1,t));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp,-1,sizeof(dp));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,0);
    }
};