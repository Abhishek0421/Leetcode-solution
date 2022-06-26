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
        k++;
        while(k--){
            int size=q.size();
            while(size--){
                int i=q.front().first;
                int d=q.front().second;
                q.pop();
                for(auto x:mp[i]){
                    int a=x.first;
                    int wt=x.second;
                    if(dist[a]>d+wt){
                        dist[a]=d+wt;
                        q.push({a,dist[a]});
                    }
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        else return dist[dst];
        
    }
};