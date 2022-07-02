class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        int s = 1;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>v[s-1]){
                v.push_back(nums[i]);
                s++;
            }
            else{
                auto it = lower_bound(v.begin(),v.end(),nums[i]);
                int idx = it - v.begin();
                v[idx] = nums[i];
            }
        }
        return v.size();
    }
};