// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<int> mi={0,0,-1,1};
	    vector<int> mj={-1,1,0,0};
	    vector<vector<int>> v(n,vector<int> (m,INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                v[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    while(!q.empty()){
	        auto it = q.front();
	        int x = it.first;
	        int y = it.second;
	        q.pop();
	        for(int i=0;i<4;i++){
	            if(x+mi[i]>=0 && x+mi[i]<n && y+mj[i]>=0 && y+mj[i]<m && grid[x+mi[i]][y+mj[i]]==0){
	                if(v[x+mi[i]][y+mj[i]] > v[x][y]+1){
	                    v[x+mi[i]][y+mj[i]] = v[x][y]+1;
	                    q.push({x+mi[i],y+mj[i]});
	                }
	            }
	        }
	    }
	   // for(auto x:v){
	   //     for(auto y:x){
	   //         cout<<y<<" ";
	   //     }
	   //     cout<<"\n";
	   // }
	    return v;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends