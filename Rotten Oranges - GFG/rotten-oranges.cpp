// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    vector<int> mi={0,0,-1,1};
    vector<int> mj={-1,1,0,0};
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n,vector<int> (m,INT_MAX));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    v[i][j]=0;
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();
            for(int i=0;i<4;i++){
                if(x+mi[i]>=0 && x+mi[i]<n && y+mj[i]>=0 && y+mj[i]<m){
                    if(grid[x+mi[i]][y+mj[i]]==1){
                        if(v[x+mi[i]][y+mj[i]] > v[x][y]+1){
                           v[x+mi[i]][y+mj[i]] = v[x][y]+1;
                           q.push({x+mi[i],y+mj[i]});
                        }
                        
                    }
                    
                }
            }
        }
       // cout<<count<<"\n";
        int ans =-1;
        for(auto x:v){
            for(auto y:x){
                if(y!=0 && y!=INT_MAX){
                   // cout<<y<<" ";
                    count--;
                    ans = max(ans,y);
                }
            }
            //cout<<"\n";
        }
     //   cout<<count<<"\n";
        if(count==0){
            return ans;
        }
        return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends