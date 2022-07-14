class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump=1;
        int step=nums[0];
        int maxr = nums[0];
        int ma=INT_MIN;
        if(n==1) return 0;
        else if(nums[0]==0) return -1;
        else{
            for(int i=1;i<n;i++){
                if(i==n-1){
                    return jump;
                }
                maxr = max(maxr,i+nums[i]);
                step--;
                if(step==0){
                    jump++;
                    if(i>=maxr){
                        return -1;
                    }
                    step = maxr-i;
                }
            }
        }
        return jump;
    }
};