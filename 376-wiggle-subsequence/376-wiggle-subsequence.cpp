class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(),mx = 1,mn=1;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<0) mn = mx + 1;
            else if(nums[i]-nums[i-1]>0) mx = mn +1;
        }
        return max(mn,mx);
    }
};