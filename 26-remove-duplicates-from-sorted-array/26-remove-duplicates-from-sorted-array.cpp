class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 1;
        int q = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[q]!=nums[q-1]){
                nums[p] = nums[q];
                p++;
                q++;
            }
            else{
                q++;
            }
        }
        return p;
    }
};