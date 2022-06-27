class Solution {
public:
    int countHousePlacements(int n) {
    long long int mod = 1000000007;
    vector<int> dp(n+1, 0); 
    dp[0] = 1;
    dp[1] = 2;
    for(int i=2;i<=n;i++)
    {
         int take =  dp[i-2]; 
    
    
         int notTake = dp[i-1];
    
         dp[i] = (take  + notTake ) % mod;
    }
    
    int ans = dp[n];
    
    return ((ans % mod) * (ans % mod)) % mod;
    
}
};