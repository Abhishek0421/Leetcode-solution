class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        queue<int> q;
        vector<int> v;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            v.push_back(u);
            for(auto x:adj[u]){
                in[x]--;
                if(in[x]==0){
                    q.push(x);
                }
            }
        }
        if(v.size()==numCourses){
            return true;
        }
        return false;
    }
};