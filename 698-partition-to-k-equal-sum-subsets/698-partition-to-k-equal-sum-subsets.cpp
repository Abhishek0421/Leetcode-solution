class Solution {
public:
    bool solve(vector<int> &nums,int k,int x,vector<int> &subset,vector<int> &taken,int cur,int idx)
    {
        if(idx>=nums.size()) return false;
        if(k==1) return true;
        if(cur>x) return false;
        if(cur==x)
            return solve(nums,k-1,x,subset,taken,0,0);
        for(int i=idx;i<nums.size();i++)
        {
            if(cur+nums[i]>x or taken[i]) continue;
            if(taken[i]==0)
            {
                taken[i]=1;
                if(solve(nums,k,x,subset,taken,cur+nums[i],i+1))
                    return true;
                else
                taken[i]=0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%k or k>n) return false;
        int x=sum/k;
        vector<int> subset(k,0);
        vector<int> taken(n,0);
        sort(begin(nums),end(nums),greater<int>());// For avoid extra calculation
        return solve(nums,k,x,subset,taken,0,0);
    }
};