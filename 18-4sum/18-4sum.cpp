class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int start = j+1;
                int end = n-1;
                long long  target2 = target-(nums[i]+nums[j]*(1ll));
                while(start<end){
                    if(nums[start]+nums[end] < target2){
                        start++;
                    }
                    else if(nums[start]+nums[end]>target2){
                        end--;
                    }
                    else{
                        vector<int> v(4);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[start];
                        v[3]=nums[end];
                        ans.push_back(v);
                        while(start<end && nums[start]==v[2]){
                            start++;
                        }
                        while(start<end && nums[end]==v[3]){
                            end--;
                        }
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]){
                    j++;
                }
            }
            while(i+1<n && nums[i+1]==nums[i]){
                i++;
            }
        }
        return ans;
    }
};