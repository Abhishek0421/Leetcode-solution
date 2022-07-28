class Solution {
public:
    void dfs(int s,unordered_map<int,vector<int>> &adj,vector<int> &visi,vector<int> &count,vector<int> &res){
        visi[s]=1;
        for(auto x:adj[s]){
            if(visi[x]) continue;
            dfs(x,adj,visi,count,res);
            count[s] += count[x];
            res[s] += res[x] + count[x];
        }
        count[s]+=1;
    }
    void dfs2(int s,int n,unordered_map<int,vector<int>> &adj,vector<int> &visi,vector<int> &count,vector<int> &res){
        visi[s]=1;
        for(auto x:adj[s]){
            if(visi[x]) continue;
            res[x] =  res[s] - count[x] + n - count[x];
            dfs2(x,n,adj,visi,count,res);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> count(n,0);
        vector<int> visi(n,0);
        vector<int> visi1(n,0);
        vector<int> res(n,0);
        
         dfs(0,adj,visi,count,res);
         dfs2(0,n,adj,visi1,count,res);
        return res;
    }
};
