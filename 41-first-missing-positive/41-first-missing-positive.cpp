class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(abs(nums[i]) > 0 && abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if(nums[i-1] > 0) {
                return i;
            }
        }
        return n + 1;
    }
};