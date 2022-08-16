class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=i+1;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]>=nums[j])
                {
                   swap(nums[i],nums[j]);
                }
            }
        }
    }
};