class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        int mod = 1e9+7;
        dp[0]=1;
        dp[1]=1;
        for(int i =2;i<=n;i++){
            int sum = 0;
            for(int j=1;j<=i;j++)
                sum += dp[j-1]*dp[i-j];
            dp[i] = sum;
        }
        return dp[n];
    }
};