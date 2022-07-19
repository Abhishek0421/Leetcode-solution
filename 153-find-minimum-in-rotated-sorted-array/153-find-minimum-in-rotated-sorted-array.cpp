class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            ans = min(ans,nums[mid]);
            if(nums[e] < nums[mid]){
               s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};