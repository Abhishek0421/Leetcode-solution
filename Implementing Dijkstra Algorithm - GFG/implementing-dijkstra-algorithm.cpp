//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dis(V,INT_MAX);
        vector<int> visi(V,0);
        set<pair<int,int> > st;
        st.insert({0,S});
        dis[S]=0;
        while(!st.empty()){
            auto it = *st.begin();
            st.erase(st.begin());
            int u = it.second;
            int d = it.first;
            for(auto x:adj[u]){
                int v = x[0];
                int wt = x[1];
                if(dis[v] > d + wt){
                    dis[v] = d+wt;
                    st.insert({dis[v],v});
                }
            }
        }
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends