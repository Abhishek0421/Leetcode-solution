//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int par(int u,vector<int> &parent){
	    if(parent[u]==u){
	        return u;
	    }
	    return parent[u] = par(parent[u],parent);
	}
	void mst(int u,int v,vector<int> &rank,vector<int> &parent){
	    u = par(u,parent);
	    v = par(v,parent);
	    
	    if(rank[u]>rank[v]){
	        parent[v] = u; 
	    }
	    else if(rank[v]>rank[u]){
	        parent[v]=u;
	    }
	    else{
	        parent[u]=v;
	        rank[v]++;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans =0;
        vector<int> dis;
        vector<int> rank(V,0);
        vector<int> parent(V,-1);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        set<pair<int,pair<int,int> >> st;
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                st.insert({x[1],{i,x[0]}});
            }
        }
        
        while(!st.empty()){
            auto it = *st.begin();
            st.erase(st.begin());
            int d = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(par(u,parent)!=par(v,parent)){
                mst(u,v,rank,parent);
                ans+=d;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


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