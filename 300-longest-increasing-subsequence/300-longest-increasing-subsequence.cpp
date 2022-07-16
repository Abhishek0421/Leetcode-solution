class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int ans=0;
        for(int i=0;i<n;i++){
            int m=0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    m = max(m,dp[j]);
                }
            }
            dp[i] = m+1;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};