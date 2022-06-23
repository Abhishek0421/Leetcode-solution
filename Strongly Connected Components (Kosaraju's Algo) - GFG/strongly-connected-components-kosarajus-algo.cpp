// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int s,vector<int> adj[],vector<int> &visi){
        visi[s]=1;
        for(auto x:adj[s]){
            if(!visi[x]){
                dfs(x,adj,visi);
            }
        }
    }
    void topo(int s,vector<int> adj[],vector<int> &visi,vector<int> &v){
        visi[s]=1;
        for(auto x:adj[s]){
            if(!visi[x]){
                topo(x,adj,visi,v);
            }
        }
        v.push_back(s);
    }
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> visi(V,0);
        vector<int> tsort;
        for(int i=0;i<V;i++){
            if(visi[i]==0){
                topo(i,adj,visi,tsort);
            }
        }
        reverse(tsort.begin(),tsort.end());
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            visi[i]=0;
            for(auto x:adj[i]){
                transpose[x].push_back(i);
            }
        }
        int count=0;
        for(auto x:tsort){
            if(!visi[x]){
                count++;
                dfs(x,transpose,visi);
            }
        }
        return count;
    }
};

// { Driver Code Starts.


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