class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto f = lower_bound(nums.begin(),nums.end(),target);
        auto l = upper_bound(nums.begin(),nums.end(),target);
        if(f-l==0){
            return {-1,-1};
        }
        int s = f-nums.begin();
        int e = nums.size()-1;
        if(l==nums.end()){
            return {s,e};
        }
        e = (l-nums.begin())-1;
        return {s,e};
    }
};