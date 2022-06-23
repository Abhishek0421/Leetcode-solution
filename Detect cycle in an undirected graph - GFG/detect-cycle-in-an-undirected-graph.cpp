// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visi(V,0);
        vector<int> parent(V,-1);
        
        for(int i=0;i<V;i++){
            if(!visi[i]){
                queue<int> q;
                q.push(i);
                parent[i]=-1;
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    visi[i]=1;
                    for(auto x:adj[u]){
                        if(!visi[x]){
                            q.push(x);
                            parent[x]=u;
                            visi[x]=1;
                        }
                        else{
                            if(parent[u]!=x){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends