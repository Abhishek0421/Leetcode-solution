class Solution {
public:
    bool check(int i,vector<int> &nums,int target,int sum,vector<vector<int>> &dp){
        if(i==nums.size()) return false;
        if(sum == target) return true;
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(sum + nums[i] <= target){
            return dp[i][sum] = check(i+1,nums,target,sum+nums[i],dp) || check(i+1,nums,target,sum,dp);
        }
        return dp[i][sum] = check(i+1,nums,target,sum,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==0){
            vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
            return check(0,nums,sum/2,0,dp);
        }
        return false;
    }
};