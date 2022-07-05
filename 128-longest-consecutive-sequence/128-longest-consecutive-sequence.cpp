class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]=1;
        }
        int ans=0;
        for(auto x:nums){
            if(mp[x]==0){
                continue;
            }
            queue<int> q;
            q.push(x);
            mp[x]=0;
            int len=0;
            while(!q.empty()){
                int a=q.front();
                q.pop();
                len++;
                if(mp[a-1]==1){
                    q.push(a-1);
                    mp[a-1]=0;
                }
                if(mp[a+1]==1){
                    q.push(a+1);
                    mp[a+1]=0;
                }
            }
            ans = max(ans,len);
        }
        return ans;
    }
};