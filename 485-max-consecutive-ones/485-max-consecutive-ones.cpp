class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,ans=-1,count=0;
        while(i<nums.size()){
            if(nums[i]==1){
                count++;
                i++;
            }
            else{
                count=0;
                i++;
            }
            ans = max(count,ans);
        }
        return ans;
    }
};