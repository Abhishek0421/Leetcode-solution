class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto x:flights){
            mp[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        k++;
        while(k--){
            int size=q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                int u = it.first;
                int d = it.second;
                for(auto x:mp[u]){
                    int v = x.first;
                    int wt = x.second;
                    if(dist[v] > d + wt){
                        dist[v] = d+wt;
                        q.push({v,dist[v]});
                    }
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        else return dist[dst];
        
    }
};