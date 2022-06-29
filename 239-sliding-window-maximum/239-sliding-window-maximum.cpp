class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            if(i==k-1){
                res.push_back((--mp.end())->first);
            }
        }
        for(int i=k;i<n;i++){
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            res.push_back((--mp.end())->first);
        }
        return res;
    }
};