class Solution {
public:
    void dfs(int start,vector<int> &visi,unordered_map<int,vector<int>> &mp){
        visi[start]=1;
        for(auto x:mp[start]){
            if(visi[x]==0){
                dfs(x,visi,mp);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections){
        unordered_map<int ,vector<int>> mp;
        int x=connections.size();
        for(auto y:connections){
            mp[y[0]].push_back(y[1]);
            mp[y[1]].push_back(y[0]);
        }
        vector<int> visi(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(visi[i]==0){
                count++;
                dfs(i,visi,mp);
            }
        }
        if(x<n-1){
            return -1;
        }
        else{
            return count-1;
        }
    }
};