class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mp;
        for(auto e1:nums1)
        {
            for(auto e2:nums2)
            {
                mp[e1+e2]++;
            }
        }
        int count=0;
        for(auto e1:nums3)
        {
            for(auto e2:nums4)
            {
                if(mp.find(-(e1+e2))!=mp.end())
                {
                    count+=mp[-(e1+e2)];
                }
            }
        }
        return count;
    }
};