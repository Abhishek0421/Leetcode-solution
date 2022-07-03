// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int mod = 1e9+7;
    int dfs(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0){
            return 0;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = (dfs(grid,i+1,j,dp)+dfs(grid,i,j+1,dp))%mod;
    }
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    // Code here
	    vector<vector<int>> grid(n,vector<int> (m,1));
	    vector<vector<int>> dp(n,vector<int> (m,-1));
	    for(auto x:blocked_cells){
	        grid[x[0]-1][x[1]-1]=0;
	    }
	    return dfs(grid,0,0,dp)%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends