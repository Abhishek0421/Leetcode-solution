class Solution {
public:
    bool b_s(vector<int> &nums,int i,int target){
        int s = i;
        int e = nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int x = (nums[i]+nums[j]);
                x = 0 - x;
                vector<int> ans;
                if(b_s(nums,j+1,x)){
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(x);
                    res.push_back(ans);
                }
                while(j+1<n-1 && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i+1<n-2 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};