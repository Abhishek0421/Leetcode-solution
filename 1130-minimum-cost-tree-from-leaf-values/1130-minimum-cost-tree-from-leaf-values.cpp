class Solution {
public:
    int dp[41][41];
    int mx(vector<int> &arr,int s,int e){
        int res = INT_MIN;
        for(int i=s;i<=e;i++){
            res = max(arr[i],res);
        }
        return res;
    }
    int solve(vector<int> &arr,int s,int e){
        if(s>=e){
            return 0;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int ans = INT_MAX;
        for(int i=s;i<e;i++){
            int cost = solve(arr,s,i) + solve(arr,i+1,e) + mx(arr,s,i)*mx(arr,i+1,e);
            ans = min(ans,cost);
        }
        return dp[s][e] =  ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,n-1);
    }
};