//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int s ,vector<int> adj[],vector<int> &visi,stack<int> &st){
        visi[s]=1;
        for(auto x:adj[s]){
            if(visi[x]) continue;
            dfs(x,adj,visi,st);
        }
        st.push(s);
    }
    void dfs2(int s ,vector<int> adj[],vector<int> &visi){
        visi[s]=1;
        for(auto x:adj[s]){
            if(visi[x]) continue;
            dfs2(x,adj,visi);
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> visi(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visi[i]){
                dfs(i,adj,visi,st);
            }
        }
        vector<int> graph[V];
        for(int i=0;i<V;i++){
            visi[i]=0;
            for(int j=0;j<adj[i].size();j++){
                graph[adj[i][j]].push_back(i);
            }
        }
        int ans =0;
        while(st.size()>0){
            int i = st.top();
            st.pop();
            if(!visi[i]){
                ans++;
                dfs2(i,graph,visi);
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
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends