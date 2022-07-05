class Solution {
public:
    //int solve(vector<int> &num,int i)
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
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
               // cout<<a<<" ";
                q.pop();
                len++;
                //cout<<len<<" ";
                if(mp[a-1]==1){
                    q.push(a-1);
                    mp[a-1]=0;
                }
                if(mp[a+1]==1){
                    q.push(a+1);
                    mp[a+1]=0;
                }
            }
            cout<<"\n";
            ans = max(ans,len);
        }
        return ans;
    }
};