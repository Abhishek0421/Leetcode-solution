// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> dist(V,INT_MAX);
        vector<int> parent(V,-1);
        vector<int> mst(V,0);
        set<pair<int,int>> st;
        st.insert({0,0});
        dist[0]=0;
        while(!st.empty()){
            auto it = *st.begin();
            st.erase(st.begin());
            int d = it.first;
            int u = it.second;
            mst[u]=1;
            for(auto x:adj[u]){
                int wt = x[1];
                int v = x[0];
                if(mst[v]==0 && dist[v]>wt){
                    parent[v]=u;
                    dist[v] = wt ;
                    st.insert({dist[v],v});
                }
            }
        }
        int sum=0;
        for(auto x:dist){
            sum+=x;
            //cout<<x<<"\n";
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends