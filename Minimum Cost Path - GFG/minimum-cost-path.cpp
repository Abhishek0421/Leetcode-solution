// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	vector<int> mi={1,-1,0,0};
	vector<int> mj={0,0,1,-1};
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        set<pair<int,pair<int,int>>> st;
        st.insert({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];
        while(st.size()>0){
            auto it = *st.begin();
            st.erase(st.begin());
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x==n-1 && y == m-1){
                break;
            }
            for(int k=0;k<4;k++){
                int i = x +mi[k];
                int j = y +mj[k];
                if(i>=0 && j>=0 && i<n && j<m){
                    if(dist[i][j]>grid[i][j]+d){
                        dist[i][j] = grid[i][j]+d;
                        st.insert({dist[i][j],{i,j}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends