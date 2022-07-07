class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1=0;
        int c2=0;
        int e1 = INT_MIN;
        int e2 = INT_MIN;
        for(int i=0;i<n;i++){
            if(e1==nums[i]) c1++;
            else if(e2==nums[i])c2++;
            else if(c1==0){e1=nums[i];c1=1;}
            else if(c2==0){e2=nums[i];c2=1;}
            else{c1--;c2--;}
        }
        c1=0;
        c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==e1) c1++;
            else if(nums[i]==e2) c2++;
        }
        if(c1 > n/3 && c2>n/3){
            return {e1,e2};
        }
        else if(c1>n/3){
            return {e1};
        }
        else if(c2>n/3){
            return {e2};
        }
        return {};
    }
};