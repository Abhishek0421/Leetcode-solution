// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int s,vector<int> &visi,vector<int> &currv,vector<int> adj[]){
        visi[s]=1;
        currv[s]=1;
        for(auto x:adj[s]){
            if(!visi[x]){
                if(dfs(x,visi,currv,adj)){
                    return true;
                }
                
            }
            else{
                if(currv[x]==1){
                    return true;
                }
            }
        }
        currv[s]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visi(V,0);
        vector<int> currv(V,0);
        for(int i=0;i<V;i++){
            if(!visi[i]){
                
                if(dfs(i,visi,currv,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends