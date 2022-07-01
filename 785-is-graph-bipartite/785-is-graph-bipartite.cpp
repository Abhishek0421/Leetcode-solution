class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // unordered_map<int,vector<int> > mp;
        // for(int i=0;i<graph.size();i++){
        //     m[i]
        // }
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> colour(n,-1);
        
        queue<int> q;
        for(int i=0;i<n;i++){
        if(visited[i]) continue;
        int s = i;
        q.push(s);
        colour[s]=i;
        visited[s]=1;
        while(!q.empty()){
            s = q.front();
            q.pop();
            for(auto x:graph[s]){
                if(!visited[x]){
                    q.push(x);
                    visited[x]=1;
                    colour[x] = colour[s]-1;
                }
                else{
                    if(colour[x]==colour[s]){
                        return false;
                    }
                }
            }
        }
    }
        return true;
    }
};