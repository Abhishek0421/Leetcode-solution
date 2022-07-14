class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return true;
        }
        int steps = nums[0];
        
        int i=0;
        while(i<n-1){
            if(steps==0){
            return false;
            }
            steps--;
            i++;
            
            if(steps < nums[i]){
                steps = nums[i];
            }
        }
        return true;
    }
};