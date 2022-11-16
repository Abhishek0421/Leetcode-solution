class Solution {
public:
    void dfs(int start,vector<int> &visi,vector<int> &v,unordered_map<int,vector<int>> &graph){
        visi[start]=1;
        v.push_back(start);
        for(auto x:graph[start]){
            if(visi[x]==0){
                dfs(x,visi,v,graph);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visi(n,0);
        vector<int> v;
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i && (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])){
                    graph[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(visi[i]==0){
                dfs(i,visi,v,graph);
                ans = ans + v.size() - 1;
                v.clear();
            }
        }
        return ans;
    }
};