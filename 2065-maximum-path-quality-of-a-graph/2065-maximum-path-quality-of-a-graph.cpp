class Solution {
public:
    int ans = -1;
    void dfs(int s,int currTime ,int maxTime,int val,vector<int> &value,vector<vector<pair<int,int>>> &adj){
        if(currTime>maxTime){
            return;
        }
        int temp = value[s];
        val+=temp;
        value[s]=0;
        if(s==0){
            ans = max(ans,val);
        }
        
        for(auto x:adj[s]){
            dfs(x.first,currTime+x.second,maxTime,val,value,adj);
        }
        value[s]=temp;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        dfs(0,0,maxTime,0,values,adj);
        return ans;
    }
};