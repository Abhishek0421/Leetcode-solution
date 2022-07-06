class Solution {
public:
    int solve(int i,int j,vector<int> &v,vector<vector<int>> &dp,map<int,int> &mp){
        if(mp.find(v[i]+v[j])==mp.end()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = 1+solve(j,mp[v[i]+v[j]],v,dp,mp);
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int,int> mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        int ans =0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(mp.find(arr[i]+arr[j])!=mp.end()){
                    ans=max(ans,solve(i,j,arr,dp,mp));
                } 
            }
        }
        if(ans==0){
            return 0;
        }
        return ans+2;
    }
};