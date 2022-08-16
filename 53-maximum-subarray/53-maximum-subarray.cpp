class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum+nums[i]>nums[i]){
                sum = sum + nums[i];
                ans = max(ans,sum);
            }
            else{
                sum = nums[i];
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};