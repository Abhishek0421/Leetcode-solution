// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code her
	    vector<int> dis(n,1e9);
	    for(int i=0;i<n-1;i++){
	        for(auto x:edges){
	            int u = x[0];
	            int v = x[1];
	            int wt= x[2];
	            if(dis[u]+wt < dis[v]){
	                dis[v]=dis[u]+wt;
	            }
	        }
	    }
	    bool f=false;
	    for(auto x:edges){
	        int u = x[0];
	        int v = x[1];
	        int wt = x[2];
	        if(dis[u]+wt<dis[v]){
	            f=true;
	            break;
	        }
	    }
	    if(f){
	        return true;
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends